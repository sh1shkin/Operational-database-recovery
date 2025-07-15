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
        this->Close();
    }

    System::Void PartialMainWindow::btnConnectDB2_Click(System::Object^ sender, System::EventArgs^ e) {
        OpenFileDialog^ openFileDialog = gcnew OpenFileDialog();
        openFileDialog->Filter = "Config files (*.ini;*.conf;*.txt;*.cfg)|*.ini;*.conf;*.txt;*.cfg|All files (*.*)|*.*";
        openFileDialog->FilterIndex = 1;
        openFileDialog->RestoreDirectory = true;

        if (openFileDialog->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
            String^ filePath = openFileDialog->FileName;
            String^ nameDBMS2 = nullptr;
            String^ Server2 = nullptr;
            String^ DataBase2 = nullptr;
            String^ User2 = nullptr;
            String^ Driver2 = nullptr;
            String^ tableInput = nullptr;
            String^ tableOutput = nullptr;
            String^ columnInputId = nullptr;
            String^ columnOutputId = nullptr;

            try {
                array<String^>^ lines = File::ReadAllLines(filePath);
                for each(String ^ line in lines) {
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
                        else if (key == "driver") Driver2 = value;
                        else if (key == "table_input") tableInput = value;
                        else if (key == "table_output") tableOutput = value;
                        else if (key == "column_input_id") columnInputId = value;
                        else if (key == "column_output_id") columnOutputId = value;
                    }
                }

                // Проверка, что все параметры загружены
                if (String::IsNullOrEmpty(nameDBMS2) || String::IsNullOrEmpty(Server2) ||
                    String::IsNullOrEmpty(DataBase2) || String::IsNullOrEmpty(User2) ||
                    String::IsNullOrEmpty(tableInput) || String::IsNullOrEmpty(tableOutput) ||
                    String::IsNullOrEmpty(columnInputId) || String::IsNullOrEmpty(columnOutputId)) {
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
                    connectionString = "Driver={" + Driver2 + "};Server=" + Server2 +
                        ";Database=" + DataBase2 +
                        ";Uid=" + User2 +
                        ";Pwd=" + password + ";";
                }
                else if (nameDBMS2 == "Oracle") {
                    connectionString = "Driver={" + Driver2 + "};DBQ=" + Server2 +
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
                // Переход к MainWindow
                MainWindow^ mainWindow = gcnew MainWindow(db_connect1, db_connect2, nameDBMS, nameDB, nameUser, nameDBMS2, DataBase2, User2, this, connectForm);
                mainWindow->tableInput = tableInput;
                mainWindow->tableOutput = tableOutput;
                mainWindow->columnInputId = columnInputId;
                mainWindow->columnOutputId = columnOutputId;
                mainWindow->Show();
                this->Hide();
            }
            catch (Exception^ ex) {
                lstLogs->Items->Add(DateTime::Now.ToString() + ": Ошибка подключения к БД2: " + ex->Message);
            }
        }
    }

    System::Void PartialMainWindow::btnGetID_Click(System::Object^ sender, System::EventArgs^ e) {
        for each (String ^ line in confDB1) {
            line = line->Trim();
            if (line->StartsWith("#") || line->IndexOf("=") == -1)
                continue;

            array<String^>^ parts = line->Split('=');
            if (parts->Length == 2) {
                String^ key = parts[0]->Trim();
                String^ value = parts[1]->Trim();

                if (key == "table_input") tableInput = value;
                else if (key == "table_output") tableOutput = value;
                else if (key == "column_input_id") columnInputId = value;
                else if (key == "column_output_id") columnOutputId = value;
            }
        }
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

                // Get input ID
                String^ queryInput = String::Format("SELECT MAX(t.{0}) FROM {1} t", columnInputId, tableInput);
                cmd->CommandText = queryInput;
                Object^ resultInput = cmd->ExecuteScalar();
                if (resultInput != nullptr && resultInput != DBNull::Value) {
                    txtID2In->Text = resultInput->ToString();
                }

                // Get output ID
                String^ queryOutput = String::Format("SELECT MAX(t.{0}) FROM {1} t", columnOutputId, tableOutput);
                cmd->CommandText = queryOutput;
                Object^ resultOutput = cmd->ExecuteScalar();
                if (resultOutput != nullptr && resultOutput != DBNull::Value) {
                    txtID2Out->Text = resultOutput->ToString();
                }
            }
            else if (nameDB == L"FREEPDB1" && (nameUser == L"coils_user" || nameUser == L"COILS_USER")) {
                getInput = true;
                getOutput = true;

                // Get input ID
                String^ queryInput = String::Format("SELECT MAX(t.{0}) FROM {1} t", columnInputId, tableInput);
                cmd->CommandText = queryInput;
                Object^ resultInput = cmd->ExecuteScalar();
                if (resultInput != nullptr && resultInput != DBNull::Value) {
                    txtID2In->Text = resultInput->ToString();
                }

                // Get output ID
                String^ queryOutput = String::Format("SELECT MAX(t.{0}) FROM {1} t", columnOutputId, tableOutput);
                cmd->CommandText = queryOutput;
                Object^ resultOutput = cmd->ExecuteScalar();
                if (resultOutput != nullptr && resultOutput != DBNull::Value) {
                    txtID2Out->Text = resultOutput->ToString();
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
            this->Close();
        }
    }

    void PartialMainWindow::PartialMainWindow_MouseDown(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e)
    {
        if (e->Button == System::Windows::Forms::MouseButtons::Left)
        {
            isDragging = true;
            dragStartPoint = gcnew Point(e->X, e->Y);
        }
    }

    void PartialMainWindow::PartialMainWindow_MouseMove(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e)
    {
        if (isDragging)
        {
            Point^ p = PointToScreen(Point(e->X, e->Y));
            this->Location = Point(p->X - dragStartPoint->X, p->Y - dragStartPoint->Y);
        }
    }

    void PartialMainWindow::PartialMainWindow_MouseUp(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e)
    {
        if (e->Button == System::Windows::Forms::MouseButtons::Left)
        {
            isDragging = false;
        }
    }
}