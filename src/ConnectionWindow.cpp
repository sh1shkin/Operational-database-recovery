#include "ConnectionWindow.h"
#include "PartialMainWindow.h"
#include <Windows.h>
#include <fstream>

using namespace System::IO;

namespace src {
    System::Void ConnectionWindow::CheckConnect_Click(System::Object^ sender, System::EventArgs^ e) {

        OpenFileDialog^ openFileDialog = gcnew OpenFileDialog();
        openFileDialog->Filter = "Config files (*.ini;*.conf;*.txt)|*.ini;*.conf;*.txt|All files (*.*)|*.*";
        openFileDialog->FilterIndex = 1;
        openFileDialog->RestoreDirectory = true;

        if (openFileDialog->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
            String^ filePath = openFileDialog->FileName;

            try {
                array<String^>^ lines = File::ReadAllLines(filePath);

                for each (String ^ line in lines) {
                    line = line->Trim();
                    if (line->StartsWith("#") || line->IndexOf("=") == -1)
                        continue;

                    array<String^>^ parts = line->Split('=');
                    if (parts->Length == 2) {
                        String^ key = parts[0]->Trim();
                        String^ value = parts[1]->Trim();

                        if (key == "dbms")
                            nameDBMS = value;
                        else if (key == "server")
                            Server = value;
                        else if (key == "database")
                            DataBase = value;
                        else if (key == "user")
                            User = value;
                    }
                }
            }
            catch (Exception^ ex) {
                MessageBox::Show("Ошибка чтения файла: " + ex->Message);
            }
        }
    }
    System::Void ConnectionWindow::connect1_Click(System::Object^ sender, System::EventArgs^ e) {
        try {
            String^ connectionString;
            if (nameDBMS == "MS SQL") {
                connectionString = "Driver={SQL Server};Server=" + Server +
                    ";Database=" + DataBase +
                    ";Uid=" + User +
                    ";Pwd=" + TextBoxPassword->Text + ";";
            }
            else if (nameDBMS == "Oracle") {
                connectionString = "Driver={Oracle in instantclient_23_8};DBQ=" + Server +
                    "/" + DataBase +
                    ";Uid=" + User +
                    ";Pwd=" + TextBoxPassword->Text + ";";
            }
            else {
                MessageTextConnect->Text = "Выберите тип базы данных!";
                return;
            }
            db_connect = gcnew OdbcConnection(connectionString);
            db_connect->Open();
            MessageTextConnect->Text = "Соединение успешно установлено!";

            PartialMainWindow^ form2 = gcnew PartialMainWindow(db_connect, nameDBMS, DataBase, User, this);
            form2->Show();
            this->Hide();
        }
        catch (Exception^ ex) {
            MessageTextConnect->Text = "Ошибка подключения: " + ex->Message;
        }
    }

    System::Void ConnectionWindow::ConnectionWindow_FormClosing(System::Object^ sender, System::Windows::Forms::FormClosingEventArgs^ e) {
        if (db_connect != nullptr && db_connect->State == ConnectionState::Open) {
            db_connect->Close();
        }
        Application::Exit(); // Завершаем приложение при закрытии формы
    }
    System::Void ConnectionWindow::btnClosedCW_Click(System::Object^ sender, System::EventArgs^ e) {
        if (this != nullptr) {
            this->Close();
        }
    }
    System::Void ConnectionWindow::ConnectionWindow_MouseDown(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
        if (e->Button == System::Windows::Forms::MouseButtons::Left) {
            isDragging = true;
            dragStartPoint = gcnew Point(e->X, e->Y);
        }
    }

    System::Void ConnectionWindow::ConnectionWindow_MouseMove(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
        if (isDragging) {
            Point^ p = PointToScreen(Point(e->X, e->Y));
            this->Location = Point(p->X - dragStartPoint->X, p->Y - dragStartPoint->Y);
        }
    }

    System::Void ConnectionWindow::ConnectionWindow_MouseUp(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
        isDragging = false;
    }

}
