#include "ConnectionWindow.h"
#include "PartialMainWindow.h"
#include <Windows.h>
#include <fstream>
#include <msclr/marshal_cppstd.h>
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
                MessageTextConnect->Text = "Конфигурация загружена!";
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

            // Создаём новое подключение
            OdbcConnection^ newConnection = gcnew OdbcConnection(connectionString);
            newConnection->Open();
            connections->Add(newConnection); // Добавляем в список подключений

            MessageTextConnect->Text = "Соединение успешно установлено!";

            // Создаём новую форму PartialMainWindow с новым подключением
            PartialMainWindow^ obj1 = gcnew PartialMainWindow(newConnection, nameDBMS, DataBase, User);
            obj1->Show();
            // Не скрываем текущую форму, чтобы пользователь мог создать ещё одно подключение
            // this->Hide(); // Убрано
        }
        catch (Exception^ ex) {
            MessageTextConnect->Text = "Ошибка подключения: " + ex->Message;
        }
    }
}