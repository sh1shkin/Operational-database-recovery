#include "PartialMainWindow.h"
#include "ConnectionWindow.h"
#include "MainWindow.h"
#include <Windows.h>
#include <fstream>
using namespace System::IO;

namespace src {

    System::Void PartialMainWindow::btnDisconnect_Click(System::Object^ sender, System::EventArgs^ e) {
        if (db_connect1 != nullptr && db_connect1->State == ConnectionState::Open) {
            db_connect1->Close();
        }
        if (db_connect2 != nullptr && db_connect2->State == ConnectionState::Open) {
            db_connect2->Close();
        }
        ConnectionWindow^ connectionWindow = gcnew ConnectionWindow();
        connectionWindow->Show();
        this->Hide();
    }

    System::Void PartialMainWindow::btnConnectDB2_Click(System::Object^ sender, System::EventArgs^ e) {
        OpenFileDialog^ openFileDialog = gcnew OpenFileDialog();
        openFileDialog->Filter = "Config files (*.ini;*.conf;*.txt)|*.ini;*.conf;*.txt|All files (*.*)|*.*";
        openFileDialog->FilterIndex = 1;
        openFileDialog->RestoreDirectory = true;

        if (openFileDialog->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
            String^ filePath = openFileDialog->FileName;
            String^ nameDBMS2 = nullptr;
            String^ Server2 = nullptr;
            String^ DataBase2 = nullptr;
            String^ User2 = nullptr;

            try {
                array<String^>^ lines = File::ReadAllLines(filePath);
                for each (String ^ line in lines) {
                    line = line->Trim();
                    if (line->StartsWith("#") || line->IndexOf("=") == -1) continue;

                    array<String^>^ parts = line->Split('=');
                    if (parts->Length == 2) {
                        String^ key = parts[0]->Trim();
                        String^ value = parts[1]->Trim();
                        if (key == "dbms") nameDBMS2 = value;
                        else if (key == "server") Server2 = value;
                        else if (key == "database") DataBase2 = value;
                        else if (key == "user") User2 = value;
                    }
                }

                // Проверка, что все параметры загружены
                if (String::IsNullOrEmpty(nameDBMS2) || String::IsNullOrEmpty(Server2) ||
                    String::IsNullOrEmpty(DataBase2) || String::IsNullOrEmpty(User2)) {
                    lstLogs->Items->Add(DateTime::Now.ToString() + ": Не все параметры конфигурации загружены!");
                    return;
                }

                // Проверка пароля
                String^ password = TextBoxPassword->Text;
                if (String::IsNullOrEmpty(password)) {
                    lstLogs->Items->Add(DateTime::Now.ToString() + ": Пароль не введен!");
                    return;
                }

                String^ connectionString;
                if (nameDBMS2 == "MS SQL") {
                    connectionString = "Driver={SQL Server};Server=" + Server2 +
                        ";Database=" + DataBase2 +
                        ";Uid=" + User2 +
                        ";Pwd=" + password + ";";
                }
                else if (nameDBMS2 == "Oracle") {
                    connectionString = "Driver={Oracle in instantclient_23_8};DBQ=" + Server2 +
                        "/" + DataBase2 +
                        ";Uid=" + User2 +
                        ";Pwd=" + password + ";";
                }
                else {
                    lstLogs->Items->Add(DateTime::Now.ToString() + ": Выберите тип базы данных для DB2!");
                    return;
                }

                db_connect2 = gcnew OdbcConnection(connectionString);
                db_connect2->Open();
                lstLogs->Items->Add(DateTime::Now.ToString() + ": Подключение к БД2 (" + nameDBMS2 + ") успешно установлено");
                lblDB2Status->Text = "БД2: Подключено";
                lblDB2Status->ForeColor = System::Drawing::Color::FromArgb(22, 163, 74);

                // Переход к MainWindow
                MainWindow^ mainWindow = gcnew MainWindow(db_connect1, db_connect2, nameDBMS, nameDB, nameUser, nameDBMS2, DataBase2, User2);
                mainWindow->Show();
                this->Hide();
            }
            catch (Exception^ ex) {
                lstLogs->Items->Add(DateTime::Now.ToString() + ": Ошибка подключения к БД2: " + ex->Message);
            }
        }
    }

    System::Void PartialMainWindow::btnGetID_Click(System::Object^ sender, System::EventArgs^ e) {
        try {
            if (db_connect1->State != ConnectionState::Open) {
                db_connect1->Open();
            }

            OdbcCommand^ cmd = gcnew OdbcCommand();
            cmd->Connection = db_connect1;

            bool getInput = false, getOutput = false;
            if (nameDBMS == "MS SQL" && nameDB == L"CoilsDB1") {
                getInput = true;
                getOutput = true;
                for (int i = 0; i < queryParams1->Length; i++) {
                    if ((i == 0 && !getInput) || (i == 1 && !getOutput)) continue;

                    String^ column = queryParams1[i][0];
                    String^ table = column == "sic_id2" ? "input" : "output";
                    String^ query = String::Format("SELECT MAX(t.{0}) FROM sta_{1}_coils t", column, table);
                    cmd->CommandText = query;
                    Object^ result = cmd->ExecuteScalar();
                    if (result != nullptr && result != DBNull::Value) {
                        if (column == "sic_id2") {
                            txtID2In->Text = result->ToString();
                        }
                        else if (column == "soc_id2") {
                            txtID2Out->Text = result->ToString();
                        }
                    }
                }
            }
            else if (nameDB == L"FREEPDB1" && (nameUser == L"coils_user" || nameUser == L"COILS_USER")) {
                getInput = true;
                getOutput = true;
                for (int i = 0; i < queryParams->Length; i++) {
                    if ((i == 0 && !getInput) || (i == 1 && !getOutput)) continue;

                    String^ column = queryParams[i][0];
                    String^ table = column == "id2in" ? "input" : "output";
                    cmd->CommandText = String::Format("SELECT MAX(t.{0}) FROM {1}_coils t", column, table);
                    Object^ result = cmd->ExecuteScalar();
                    if (result != nullptr && result != DBNull::Value) {
                        if (column == "id2in") {
                            txtID2In->Text = result->ToString();
                        }
                        else if (column == "id2out") {
                            txtID2Out->Text = result->ToString();
                        }
                    }
                }
            }
            else {
                getOutput = true;
            }

            lstLogs->Items->Add(DateTime::Now.ToString() + ": ID успешно получены из БД1");
        }
        catch (Exception^ ex) {
            lstLogs->Items->Add(DateTime::Now.ToString() + ": Ошибка при получении ID: " + ex->Message);
        }
    }

    System::Void PartialMainWindow::PartialMainWindow_FormClosing(System::Object^ sender, System::Windows::Forms::FormClosingEventArgs^ e) {
        if (db_connect1 != nullptr && db_connect1->State == ConnectionState::Open) {
            db_connect1->Close();
        }
        if (db_connect2 != nullptr && db_connect2->State == ConnectionState::Open) {
            db_connect2->Close();
        }
        Application::Exit();
    }
    System::Void PartialMainWindow::btnClosed_Click(System::Object^, System::EventArgs^) {
        if (connectForm != nullptr) {
            connectForm->Close();
            connectForm = nullptr;
        }
    }
}