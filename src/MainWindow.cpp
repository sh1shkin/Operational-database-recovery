#include "MainWindow.h"
#include "ConnectionWindow.h"
#include "PartialMainWindow.h"
#include <Windows.h>
#include <msclr/marshal_cppstd.h>

namespace src {
    System::Void MainWindow::btnConfirmID_Click(System::Object^ sender, System::EventArgs^ e) {
        try {

            if (db_connect1->State != ConnectionState::Open) {
                db_connect1->Open();
                lstLogs->AppendText(DateTime::Now.ToString() + ": Соединение с Oracle восстановлено\n");
            }

            for each (String ^ line in lndb1) {
                line = line->Trim();
                if (line->StartsWith("#") || line->IndexOf("=") == -1) continue;

                array<String^>^ parts = line->Split('=');
                if (parts->Length == 2) {
                    String^ key = parts[0]->Trim();
                    String^ value = parts[1]->Trim();
                    if (key == "dbms") nameDBMS1 = value;
                    else if (key == "server") Server1 = value;
                    else if (key == "database") DataBase1 = value;
                    else if (key == "user") User1 = value;
                    else if (key == "driver") Driver1 = value;
                    else if (key == "table_input") tableInput1 = value;
                    else if (key == "table_output") tableOutput1 = value;
                    else if (key == "column_input_id") columnInputId1 = value;
                    else if (key == "column_output_id") columnOutputId1 = value;
                }
            }

            OdbcCommand^ cmd = gcnew OdbcCommand();
            cmd->Connection = db_connect1;

            if (nameDBMS1 == "Oracle") {

                String^ queryInput = String::Format("SELECT MAX(t.{0}) FROM {1} t", columnInputId1, tableInput1);
                cmd->CommandText = queryInput;
                Object^ resultInput = cmd->ExecuteScalar();
                if (resultInput != nullptr && resultInput != DBNull::Value) {
                    txtID2In->Text = resultInput->ToString();
                }
                lstLogs->AppendText(DateTime::Now.ToString() + ": Успешно выполнен запрос: " + queryInput + "\n");

                String^ queryOutput = String::Format("SELECT MAX(t.{0}) FROM {1} t", columnOutputId1, tableOutput1);
                cmd->CommandText = queryOutput;
                Object^ resultOutput = cmd->ExecuteScalar();
                if (resultOutput != nullptr && resultOutput != DBNull::Value) {
                    txtID2Out->Text = resultOutput->ToString();
                }
                lstLogs->AppendText(DateTime::Now.ToString() + ": Успешно выполнен запрос: " + queryOutput + "\n");
            }

            lstLogs->AppendText(DateTime::Now.ToString() + ": ID успешно получены из Oracle\n");
        }
        catch (Exception^ ex) {
            lstLogs->AppendText(DateTime::Now.ToString() + ": Ошибка при получении ID: " + ex->Message + "\n");
        }
    }

    System::Void MainWindow::btnAddRecords_Click(System::Object^ sender, System::EventArgs^ e) {
        // Чтение конфигурации
        for each (String ^ line in lndb2) {
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
                else if (key == "table_input") tableInput2 = value;
                else if (key == "table_output") tableOutput2 = value;
                else if (key == "column_input_id") columnInputId2 = value;
                else if (key == "column_output_id") columnOutputId2 = value;
                else if (key == "data_in_1") dataIn1 = value;
                else if (key == "data_in_2") dataIn2 = value;
                else if (key == "data_in_3") dataIn3 = value;
                else if (key == "data_out_1") dataOut1 = value;
                else if (key == "data_out_2") dataOut2 = value;
                else if (key == "data_out_3") dataOut3 = value;
            }
        }

        try {
            // Проверка и открытие соединений
            if (db_connect2 != nullptr && db_connect2->State != ConnectionState::Open) {
                db_connect2->Open();
                lstLogs->AppendText(DateTime::Now.ToString() + ": Соединение с MS SQL восстановлено\n");
            }

            OdbcCommand^ cmd = gcnew OdbcCommand();
            cmd->Connection = db_connect2;

            // Получение текущих ID
            int id2In = String::IsNullOrEmpty(txtID2In->Text) ? 0 : Convert::ToInt32(txtID2In->Text);
            int id2Out = String::IsNullOrEmpty(txtID2Out->Text) ? 0 : Convert::ToInt32(txtID2Out->Text);

            // Вставка входного рулона с явным ID
            String^ queryInput;
            if (nameDBMS2 == "MS SQL") {
                queryInput = String::Format(
                    "SET IDENTITY_INSERT {0} ON; "
                    "INSERT INTO {0} ({1}, {2}, {3}, {4}) "
                    "VALUES (?, ?, ?, ?); "
                    "SET IDENTITY_INSERT {0} OFF;",
                    tableInput2, columnInputId2, dataIn1, dataIn2, dataIn3);

                cmd->CommandText = queryInput;
                cmd->Parameters->Clear();
                cmd->Parameters->AddWithValue("@id2in", id2In + 1);
                cmd->Parameters->AddWithValue("@thickness", Convert::ToDecimal(txtThicknessIn->Text));
                cmd->Parameters->AddWithValue("@width", Convert::ToInt32(txtWidthIn->Text));
                cmd->Parameters->AddWithValue("@status", Convert::ToInt32(txtStatusIn->Text));
            }
            else {
                lstLogs->AppendText(DateTime::Now.ToString() + ": Недопустимый тип СУБД: " + nameDBMS2 + "\n");
                return;
            }

            cmd->ExecuteNonQuery();
            lstLogs->AppendText(DateTime::Now.ToString() + ": Успешно выполнен запрос: " + queryInput + "\n");
            lstLogs->AppendText(DateTime::Now.ToString() + ": Добавлена запись в " + tableInput2 + " с ID " + (id2In + 1) + "\n");

            // Вставка выходного рулона с явным ID
            String^ queryOutput;
            if (nameDBMS2 == "MS SQL") {
                queryOutput = String::Format(
                    "SET IDENTITY_INSERT {0} ON; "
                    "INSERT INTO {0} ({1}, {2}, {3}, {4}) "
                    "VALUES (?, ?, ?, ?); "
                    "SET IDENTITY_INSERT {0} OFF;",
                    tableOutput2, columnOutputId2, dataOut1, dataOut2, dataOut3);

                cmd->CommandText = queryOutput;
                cmd->Parameters->Clear();
                cmd->Parameters->AddWithValue("@id2out", id2Out + 1);
                cmd->Parameters->AddWithValue("@thickness", Convert::ToDecimal(txtThicknessOut->Text));
                cmd->Parameters->AddWithValue("@width", Convert::ToInt32(txtWidthOut->Text));
                cmd->Parameters->AddWithValue("@status", Convert::ToInt32(txtStatusOut->Text));
            }

            cmd->ExecuteNonQuery();
            lstLogs->AppendText(DateTime::Now.ToString() + ": Успешно выполнен запрос: " + queryOutput + "\n");
            lstLogs->AppendText(DateTime::Now.ToString() + ": Добавлена запись в " + tableOutput2 + " с ID " + (id2Out + 1) + "\n");

            // Обновление полей с ID
            txtID2In->Text = (id2In + 1).ToString();
            txtID2Out->Text = (id2Out + 1).ToString();
        }
        catch (Exception^ ex) {
            lstLogs->AppendText(DateTime::Now.ToString() + ": Ошибка при добавлении записей: " + ex->Message + "\n");
        }
    }

    System::Void MainWindow::btnCheckRecords_Click(System::Object^ sender, System::EventArgs^ e) {
        for each (String ^ line in lndb2) {
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
                else if (key == "table_input") tableInput2 = value;
                else if (key == "table_output") tableOutput2 = value;
                else if (key == "column_input_id") columnInputId2 = value;
                else if (key == "column_output_id") columnOutputId2 = value;
                else if (key == "data_in_1") dataIn1 = value;
                else if (key == "data_in_2") dataIn2 = value;
                else if (key == "data_in_3") dataIn3 = value;
                else if (key == "data_out_1") dataOut1 = value;
                else if (key == "data_out_2") dataOut2 = value;
                else if (key == "data_out_3") dataOut3 = value;
            }
        }
        try {
            if (db_connect2->State != ConnectionState::Open) {
                db_connect2->Open();
                lstLogs->AppendText(DateTime::Now.ToString() + ": Соединение с Oracle восстановлено\n");
            }

            dgvResults->Rows->Clear();
            OdbcCommand^ cmd = gcnew OdbcCommand();
            cmd->Connection = db_connect2;

            // Check input table
            String^ queryInput = String::Format(
                "SELECT {0} AS ID, 'Input' AS Type, {1} AS Thickness, {2} AS Width, {3} AS Status "
                "FROM {4} "
                "WHERE {0} IN (SELECT MAX({0}) FROM {4})",
                columnInputId2, dataIn1, dataIn2, dataIn3, tableInput2);
            cmd->CommandText = queryInput;
            OdbcDataReader^ reader = cmd->ExecuteReader();
            while (reader->Read()) {
                dgvResults->Rows->Add(
                    reader->GetValue(reader->GetOrdinal("ID"))->ToString(),
                    reader->GetString(reader->GetOrdinal("Type")),
                    reader->GetString(reader->GetOrdinal("Thickness"))->ToString(),
                    reader->GetString(reader->GetOrdinal("Width"))->ToString(), 
                    reader->GetString(reader->GetOrdinal("Status"))->ToString()); 
            }
            reader->Close();
            lstLogs->AppendText(DateTime::Now.ToString() + ": Проверены записи в " + tableInput2 + "\n");

            // Check output table
            String^ queryOutput = String::Format(
                "SELECT {0} AS ID, 'Output' AS Type, {1} AS Thickness, {2} AS Width, {3} AS Status "
                "FROM {4} "
                "WHERE {0} IN (SELECT MAX({0}) FROM {4})",
                columnOutputId2, dataOut1, dataOut2, dataOut3, tableOutput2);
            cmd->CommandText = queryOutput;
            reader = cmd->ExecuteReader();
            while (reader->Read()) {
                dgvResults->Rows->Add(
                    reader->GetValue(reader->GetOrdinal("ID"))->ToString(),
                    reader->GetString(reader->GetOrdinal("Type")),
                    reader->GetString(reader->GetOrdinal("Thickness"))->ToString(),
                    reader->GetString(reader->GetOrdinal("Width"))->ToString(),
                    reader->GetString(reader->GetOrdinal("Status"))->ToString());
            }
            reader->Close();
            lstLogs->AppendText(DateTime::Now.ToString() + ": Проверены записи в " + tableOutput2 + "\n");
        }
        catch (Exception^ ex) {
            lstLogs->AppendText(DateTime::Now.ToString() + ": Ошибка при проверке записей: " + ex->Message + "\n");
        }
    }

    System::Void MainWindow::btnDisconnect_Click(System::Object^ sender, System::EventArgs^ e) {
        if (db_connect1 != nullptr && db_connect1->State == ConnectionState::Open) db_connect1->Close();
        if (db_connect2 != nullptr && db_connect2->State == ConnectionState::Open) db_connect2->Close();
        ConnectionWindow^ connectionWindow = gcnew ConnectionWindow();
        connectionWindow->Show();
        this->Hide();
    }

    System::Void MainWindow::MainWindow_FormClosing(System::Object^ sender, System::Windows::Forms::FormClosingEventArgs^ e) {
        if (db_connect1 != nullptr && db_connect1->State == ConnectionState::Open) db_connect1->Close();
        if (db_connect2 != nullptr && db_connect2->State == ConnectionState::Open) db_connect2->Close();
        Application::Exit();
    }
    System::Void MainWindow::btnClosedCW_Click(System::Object^ sender, System::EventArgs^ e) {
        if (db_connect1 != nullptr && db_connect1->State == ConnectionState::Open) db_connect1->Close();
        if (db_connect2 != nullptr && db_connect2->State == ConnectionState::Open) db_connect2->Close();
        Application::Exit();
    }
    System::Void MainWindow::MainWindow_MouseDown(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
        if (e->Button == System::Windows::Forms::MouseButtons::Left) {
            isDragging = true;
            dragStartPoint = gcnew Point(e->X, e->Y);
        }
    }
    System::Void MainWindow::MainWindow_MouseMove(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
        if (isDragging) {
            Point^ p = PointToScreen(Point(e->X, e->Y));
            this->Location = Point(p->X - dragStartPoint->X, p->Y - dragStartPoint->Y);
        }
    }
    System::Void MainWindow::MainWindow_MouseUp(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
        isDragging = false;
    }
}