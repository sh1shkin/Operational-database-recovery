#include "PartialMainWindow.h"
#include "ConnectionWindow.h"

namespace src {
    System::Void PartialMainWindow::btnDisconnect_Click(System::Object^ sender, System::EventArgs^ e) {
        if (connect != nullptr && connect->State == ConnectionState::Open) {
            connect->Close();
        }
        ConnectionWindow^ connectionWindow = gcnew ConnectionWindow();
        connectionWindow->Show();
        this->Close();
    }

    System::Void PartialMainWindow::btnConnectDB2_Click(System::Object^ sender, System::EventArgs^ e) {
        ConnectionWindow^ connectionWindow = gcnew ConnectionWindow();
        connectionWindow->Show();
        this->Close();
    }

    System::Void PartialMainWindow::btnGetID_Click(System::Object^ sender, System::EventArgs^ e) {
        try {
            if (connect->State != ConnectionState::Open) {
                connect->Open();
            }

            OdbcCommand^ cmd = gcnew OdbcCommand();
            cmd->Connection = connect;

            // Определяем, какие запросы нужно выполнять
            bool getInput = false;
            bool getOutput = false;

            if (typeString == "MS SQL" && nameDB == L"CoilsDB1") {
                getInput = true;
                getOutput = true;
                // Выполняем запросы на основе глобального массива
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
                            // Можно использовать другие параметры из queryParams[i]
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
                // Выполняем запросы на основе глобального массива
                for (int i = 0; i < queryParams->Length; i++) {
                    if ((i == 0 && !getInput) || (i == 1 && !getOutput)) continue;

                    String^ column = queryParams[i][0];
                    String^ table = column == "id2in" ? "input" : "output";

                    cmd->CommandText = String::Format("SELECT MAX(t.{0}) FROM {1}_coils t", column, table);

                    Object^ result = cmd->ExecuteScalar();
                    if (result != nullptr && result != DBNull::Value) {
                        if (column == "id2in") {
                            txtID2In->Text = result->ToString();
                            // Можно использовать другие параметры из queryParams[i]
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


        }
        catch (Exception^ ex) {
            MessageBox::Show("Ошибка при получении ID: " + ex->Message);
        }
    }
}