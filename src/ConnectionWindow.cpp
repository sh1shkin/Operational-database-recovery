#include "ConnectionWindow.h"
#include "PartialMainWindow.h"
#include <Windows.h>

namespace src {
    System::Void ConnectionWindow::connect1_Click(System::Object^ sender, System::EventArgs^ e) {
        try {
            String^ connectionString;
            if (comboBox1->Text == "MS SQL") {
                connectionString = "Driver={SQL Server};Server=" + TextBoxServer->Text +
                    ";Database=" + TextBoxDataBase->Text +
                    ";Uid=" + TextBoxUser->Text +
                    ";Pwd=" + TextBoxPassword->Text + ";";
            }
            else if (comboBox1->Text == "Oracle") {
                connectionString = "Driver={Oracle in instantclient_23_8};DBQ=" + TextBoxServer->Text +
                    "/" + TextBoxDataBase->Text +
                    ";Uid=" + TextBoxUser->Text +
                    ";Pwd=" + TextBoxPassword->Text + ";";
            }
            else {
                MessageTextConnect->Text = "Выберите тип базы данных!";
                return;
            }

            db_connect = gcnew OdbcConnection(connectionString);
            db_connect->Open();
            MessageTextConnect->Text = "Соединение успешно установлено!";
            PartialMainWindow^ form2 = gcnew PartialMainWindow(db_connect, comboBox1->Text, TextBoxDataBase->Text, TextBoxUser->Text);
            form2->Show();
            this->Hide();
        }
        catch (Exception^ ex) {
            MessageTextConnect->Text = "Ошибка подключения: " + ex->Message;
        }
    }

    System::Void ConnectionWindow::CheckConnect_Click(System::Object^ sender, System::EventArgs^ e) {
        try {
            String^ connectionString;
            if (comboBox1->Text == "MS SQL") {
                connectionString = "Driver={SQL Server};Server=" + TextBoxServer->Text +
                    ";Database=" + TextBoxDataBase->Text +
                    ";Uid=" + TextBoxUser->Text +
                    ";Pwd=" + TextBoxPassword->Text + ";";
            }
            else if (comboBox1->Text == "Oracle") {
                connectionString = "Driver={Oracle in instantclient_23_8};DBQ=" + TextBoxServer->Text +
                    "/" + TextBoxDataBase->Text +
                    ";Uid=" + TextBoxUser->Text +
                    ";Pwd=" + TextBoxPassword->Text + ";";
            }
            else {
                MessageTextConnect->Text = "Выберите тип базы данных!";
                return;
            }

            OdbcConnection^ testConnection = gcnew OdbcConnection(connectionString);
            testConnection->Open();
            MessageTextConnect->Text = "Тестовое соединение успешно!";
            testConnection->Close();
        }
        catch (Exception^ ex) {
            MessageTextConnect->Text = "Ошибка тестового подключения: " + ex->Message;
        }
    }
}