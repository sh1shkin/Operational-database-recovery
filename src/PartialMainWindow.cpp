#include "PartialMainWindow.h"
#include "ConnectionWindow.h"
#include "MainWindow.h"
#include <Windows.h>
#include <fstream>
using namespace System::IO;
using namespace System::Collections::Generic; // Явно указано пространство имён

namespace src {

    // Инициализация путей при загрузке формы
    System::Void PartialMainWindow::PartialMainWindow_Load(System::Object^ sender, System::EventArgs^ e) {
        try {
            String^ mainConfigPath = Path::Combine(Path::GetDirectoryName(Application::ExecutablePath), "app.conf");
            if (File::Exists(mainConfigPath)) {
                array<String^>^ lines = File::ReadAllLines(mainConfigPath);
                for each (String ^ line in lines) {
                    line = line->Trim();
                    if (line->StartsWith("#") || line->IndexOf("=") == -1)
                        continue;

                    array<String^>^ parts = line->Split('=');
                    if (parts->Length >= 2) {
                        String^ key = parts[0]->Trim();
                        String^ value = String::Join("=", parts, 1, parts->Length - 1)->Trim();
                        if (key == "last_config_db1") PathConfig1 = value;
                        else if (key == "last_config_db2") PathConfig2 = value;
                    }
                }
                if (!String::IsNullOrEmpty(PathConfig1)) {
                    lstLogs->AppendText(DateTime::Now.ToString() + ": Загружен путь для DB1: " + PathConfig1 + "\n");
                    if (!File::Exists(PathConfig1)) {
                        lstLogs->AppendText(DateTime::Now.ToString() + ": Конфигурационный файл для DB1 не найден: " + PathConfig1 + "\n");
                    }
                }
                if (!String::IsNullOrEmpty(PathConfig2)) {
                    lstLogs->AppendText(DateTime::Now.ToString() + ": Загружен путь для DB2: " + PathConfig2 + "\n");
                    if (!File::Exists(PathConfig2)) {
                        lstLogs->AppendText(DateTime::Now.ToString() + ": Конфигурационный файл для DB2 не найден: " + PathConfig2 + "\n");
                    }
                }
            }
            else {
                // Создаём пустой app.conf, если он не существует
                List<String^>^ mainConfigLines = gcnew List<String^>(2); // Исправлено: явная инициализация
                mainConfigLines->Add("last_config_db1=");
                mainConfigLines->Add("last_config_db2=");
                File::WriteAllLines(mainConfigPath, mainConfigLines);
                lstLogs->AppendText(DateTime::Now.ToString() + ": Создан новый основной конфигурационный файл: " + mainConfigPath + "\n");
            }
        }
        catch (Exception^ ex) {
            lstLogs->AppendText(DateTime::Now.ToString() + ": Ошибка при чтении основного конфигурационного файла: " + ex->Message + "\n");
        }
    }

    // Обработчик для отключения баз данных
    System::Void PartialMainWindow::btnDisconnect_Click(System::Object^ sender, System::EventArgs^ e) {
        try {
            if (db_connect1 != nullptr && db_connect1->State == ConnectionState::Open) {
                db_connect1->Close();
                lstLogs->AppendText(DateTime::Now.ToString() + ": Подключение к DB1 закрыто.\n");
            }
            if (db_connect2 != nullptr && db_connect2->State == ConnectionState::Open) {
                db_connect2->Close();
                lstLogs->AppendText(DateTime::Now.ToString() + ": Подключение к DB2 закрыто.\n");
            }
            ConnectionWindow^ connectionWindow = gcnew ConnectionWindow();
            connectionWindow->Show();
            this->Close();
        }
        catch (Exception^ ex) {
            lstLogs->AppendText(DateTime::Now.ToString() + ": Ошибка при отключении баз данных: " + ex->Message + "\n");
        }
    }

    // Обработчик для подключения к DB1
    System::Void PartialMainWindow::btnConnectDB1_Click(System::Object^ sender, System::EventArgs^ e) {
        try {
            if (String::IsNullOrEmpty(PathConfig1)) {
                lstLogs->AppendText(DateTime::Now.ToString() + ": Путь к конфигурационному файлу для DB1 не задан!\n");
                return;
            }
            if (!File::Exists(PathConfig1)) {
                lstLogs->AppendText(DateTime::Now.ToString() + ": Конфигурационный файл для DB1 не найден: " + PathConfig1 + "\n");
                return;
            }

            array<String^>^ lines = File::ReadAllLines(PathConfig1);
            confDB1 = lines;
            for each (String ^ line in lines) {
                line = line->Trim();
                if (line->StartsWith("#") || line->IndexOf("=") == -1)
                    continue;

                array<String^>^ parts = line->Split('=');
                if (parts->Length >= 2) {
                    String^ key = parts[0]->Trim();
                    String^ value = String::Join("=", parts, 1, parts->Length - 1)->Trim();
                    if (key == "dbms") nameDBMS = value;
                    else if (key == "server") Server = value;
                    else if (key == "database") nameDB = value;
                    else if (key == "user") nameUser = value;
                    else if (key == "driver") Driver = value;
                    else if (key == "table_input") tableInput = value;
                    else if (key == "table_output") tableOutput = value;
                    else if (key == "column_input_id") columnInputId = value;
                    else if (key == "column_output_id") columnOutputId = value;
                    else if (key == "data_in_1") DataIn1 = value;
                    else if (key == "data_in_2") DataIn2 = value;
                    else if (key == "data_in_3") DataIn3 = value;
                    else if (key == "data_out_1") DataOut1 = value;
                    else if (key == "data_out_2") DataOut2 = value;
                    else if (key == "data_out_3") DataOut3 = value;
                }
            }

            if (String::IsNullOrEmpty(nameDBMS) || String::IsNullOrEmpty(Server) ||
                String::IsNullOrEmpty(nameDB) || String::IsNullOrEmpty(nameUser)) {
                lstLogs->AppendText(DateTime::Now.ToString() + ": Не все обязательные параметры конфигурации DB1 загружены!\n");
                return;
            }

            if (String::IsNullOrEmpty(TextBoxPassword->Text)) {
                lstLogs->AppendText(DateTime::Now.ToString() + ": Пароль не введен!\n");
                return;
            }

            String^ connectionString;
            if (nameDBMS == "Oracle") {
                connectionString = String::Format(
                    "Driver={0};DBQ={1}/{2};Uid={3};Pwd={4};",
                    Driver, Server, nameDB, nameUser, TextBoxPassword->Text);
            }
            else {
                lstLogs->AppendText(DateTime::Now.ToString() + ": Ошибка! Недопустимый тип базы данных: " + nameDBMS + "\n");
                return;
            }

            try {
                db_connect1 = gcnew OdbcConnection(connectionString);
                db_connect1->Open();
                lblConnectionInfo->Text = String::Format("DB1: {0}: {1}/{2}", nameDBMS, nameDB, nameUser);
                lstLogs->AppendText(DateTime::Now.ToString() + ": Подключение к DB1 успешно установлено\n");
            }
            catch (Exception^ ex) {
                MessageBox::Show("Ошибка подключения: " + ex->Message, "Ошибка");
                lstLogs->AppendText(DateTime::Now.ToString() + ": Ошибка подключения к DB1: " + ex->Message + "\n");
            }
        }
        catch (Exception^ ex) {
            MessageBox::Show("Ошибка чтения конфигурации: " + ex->Message, "Ошибка");
            lstLogs->AppendText(DateTime::Now.ToString() + ": Ошибка чтения конфигурации DB1: " + ex->Message + "\n");
        }
    }

    // Обработчик для подключения к DB2
    System::Void PartialMainWindow::btnConnectDB2_Click(System::Object^ sender, System::EventArgs^ e) {
        try {
            if (String::IsNullOrEmpty(PathConfig2)) {
                lstLogs->AppendText(DateTime::Now.ToString() + ": Путь к конфигурационному файлу для DB2 не задан!\n");
                return;
            }
            if (!File::Exists(PathConfig2)) {
                lstLogs->AppendText(DateTime::Now.ToString() + ": Конфигурационный файл для DB2 не найден: " + PathConfig2 + "\n");
                return;
            }

            array<String^>^ lines = File::ReadAllLines(PathConfig2);
            array<String^>^ lndb2 = lines;
            array<String^>^ lndb1 = confDB1;

            for each (String ^ line in lines) {
                line = line->Trim();
                if (line->StartsWith("#") || line->IndexOf("=") == -1)
                    continue;

                array<String^>^ parts = line->Split('=');
                if (parts->Length >= 2) {
                    String^ key = parts[0]->Trim();
                    String^ value = String::Join("=", parts, 1, parts->Length - 1)->Trim();
                    if (key == "dbms") nameDBMS2 = value;
                    else if (key == "server") Server2 = value;
                    else if (key == "database") DataBase2 = value;
                    else if (key == "user") User2 = value;
                    else if (key == "driver") Driver2 = value;
                    else if (key == "table_input") tableInput2 = value;
                    else if (key == "table_output") tableOutput2 = value;
                    else if (key == "column_input_id") columnInputId2 = value;
                    else if (key == "column_output_id") columnOutputId2 = value;
                }
            }

            if (String::IsNullOrEmpty(nameDBMS2) || String::IsNullOrEmpty(Server2) ||
                String::IsNullOrEmpty(DataBase2) || String::IsNullOrEmpty(User2) ||
                String::IsNullOrEmpty(tableInput2) || String::IsNullOrEmpty(tableOutput2) ||
                String::IsNullOrEmpty(columnInputId2) || String::IsNullOrEmpty(columnOutputId2)) {
                lstLogs->AppendText(DateTime::Now.ToString() + ": Не все параметры конфигурации DB2 загружены!\n");
                return;
            }

            String^ password = TextBoxPassword->Text;
            if (String::IsNullOrEmpty(password)) {
                lstLogs->AppendText(DateTime::Now.ToString() + ": Пароль не введен!\n");
                return;
            }

            String^ connectionString;
            if (nameDBMS2 == "MS SQL") {
                connectionString = String::Format(
                    "Driver={0};Server={1};Database={2};Uid={3};Pwd={4};",
                    Driver2, Server2, DataBase2, User2, password);
            }
            else {
                lstLogs->AppendText(DateTime::Now.ToString() + ": Ошибка! Недопустимый тип базы данных: " + nameDBMS2 + "\n");
                return;
            }

            try {
                db_connect2 = gcnew OdbcConnection(connectionString);
                db_connect2->Open();
                lstLogs->AppendText(DateTime::Now.ToString() + ": Подключение к MS SQL (" + nameDBMS2 + ") успешно установлено\n");
                MainWindow^ mainWindow = gcnew MainWindow(db_connect1, db_connect2, nameDBMS, nameDB, nameUser, nameDBMS2, DataBase2, User2, this, connectForm, lndb1, lndb2);
                mainWindow->Show();
                this->Hide();
            }
            catch (Exception^ ex) {
                MessageBox::Show("Ошибка подключения: " + ex->Message, "Ошибка");
                lstLogs->AppendText(DateTime::Now.ToString() + ": Ошибка подключения к MS SQL: " + ex->Message + "\n");
            }
        }
        catch (Exception^ ex) {
            MessageBox::Show("Ошибка чтения конфигурации: " + ex->Message, "Ошибка");
            lstLogs->AppendText(DateTime::Now.ToString() + ": Ошибка чтения конфигурации MS SQL: " + ex->Message + "\n");
        }
    }

    // Обработчик для получения ID из таблиц
    System::Void PartialMainWindow::btnGetID_Click(System::Object^ sender, System::EventArgs^ e) {
        try {
            // Проверяем, инициализировано ли подключение
            if (db_connect1 == nullptr) {
                lstLogs->AppendText(DateTime::Now.ToString() + ": Подключение к Oracle не инициализировано! Подключитесь к Oracle.\n");
                return;
            }

            // Проверяем наличие параметров таблицы и столбцов
            if (String::IsNullOrEmpty(tableInput) || String::IsNullOrEmpty(tableOutput) ||
                String::IsNullOrEmpty(columnInputId) || String::IsNullOrEmpty(columnOutputId)) {
                lstLogs->AppendText(DateTime::Now.ToString() + ": Параметры таблиц или столбцов не загружены! Проверьте конфигурацию.\n");
                return;
            }

            // Проверяем состояние подключения
            if (db_connect1->State != ConnectionState::Open) {
                lstLogs->AppendText(DateTime::Now.ToString() + ": Подключение к Oracle закрыто. Попытка восстановления...\n");
                try {
                    db_connect1->Open();
                    lstLogs->AppendText(DateTime::Now.ToString() + ": Подключение к Oracle восстановлено.\n");
                }
                catch (Exception^ ex) {
                    lstLogs->AppendText(DateTime::Now.ToString() + ": Ошибка при восстановлении подключения к Oracle: " + ex->Message + "\n");
                    return;
                }
            }

            // Выполняем запросы
            OdbcCommand^ cmd = gcnew OdbcCommand();
            cmd->Connection = db_connect1;


            // Получаем input ID
            String^ queryInput = String::Format("SELECT MAX(t.{0}) FROM {1} t", columnInputId, tableInput);
            cmd->CommandText = queryInput;
            Object^ resultInput = cmd->ExecuteScalar();
            if (resultInput != nullptr && resultInput != DBNull::Value) {
                txtID2In->Text = resultInput->ToString();
            }
            else {
                txtID2In->Text = "0";
                lstLogs->AppendText(DateTime::Now.ToString() + ": Не удалось получить input ID (возможно, таблица пуста).\n");
            }

            // Получаем output ID
            String^ queryOutput = String::Format("SELECT MAX(t.{0}) FROM {1} t", columnOutputId, tableOutput);
            cmd->CommandText = queryOutput;
            Object^ resultOutput = cmd->ExecuteScalar();
            if (resultOutput != nullptr && resultOutput != DBNull::Value) {
                txtID2Out->Text = resultOutput->ToString();
            }
            else {
                txtID2Out->Text = "0";
                lstLogs->AppendText(DateTime::Now.ToString() + ": Не удалось получить output ID (возможно, таблица пуста).\n");
            }

            lstLogs->AppendText(DateTime::Now.ToString() + ": ID успешно получены из Oracle.\n");
        }
        catch (Exception^ ex) {
            lstLogs->AppendText(DateTime::Now.ToString() + ": Ошибка при получении ID: " + ex->Message + "\n");
        }
    }

    // Обработчик для обновления конфигурации DB1
    System::Void PartialMainWindow::btnUpdateconfig1_Click(System::Object^ sender, System::EventArgs^ e) {
        try {
            OpenFileDialog^ openFileDialog = gcnew OpenFileDialog();
            openFileDialog->Filter = "Конфигурационные файлы (*.conf)|*.conf|Все файлы (*.*)|*.*";
            openFileDialog->Title = "Выберите конфигурационный файл для DB1";
            openFileDialog->InitialDirectory = Path::GetDirectoryName(Application::ExecutablePath);

            if (openFileDialog->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
                String^ newConfigPath = openFileDialog->FileName;
                PathConfig1 = newConfigPath;

                // Обновляем основной конфигурационный файл (app.conf)
                String^ mainConfigPath = Path::Combine(Path::GetDirectoryName(Application::ExecutablePath), "app.conf");
                List<String^>^ mainConfigLines = gcnew List<String^>(2); // Исправлено: явная инициализация
                bool lastConfigDb1Updated = false;

                if (File::Exists(mainConfigPath)) {
                    array<String^>^ lines = File::ReadAllLines(mainConfigPath);
                    for each (String ^ line in lines) {
                        if (line->Trim()->StartsWith("last_config_db1=")) {
                            mainConfigLines->Add("last_config_db1=" + newConfigPath);
                            lastConfigDb1Updated = true;
                        }
                        else {
                            mainConfigLines->Add(line);
                        }
                    }
                }
                if (!lastConfigDb1Updated) {
                    mainConfigLines->Add("last_config_db1=" + newConfigPath);
                }

                // Записываем обновлённый основной конфигурационный файл
                File::WriteAllLines(mainConfigPath, mainConfigLines);
                lstLogs->AppendText(DateTime::Now.ToString() + ": Конфигурационный файл для DB1 обновлен: " + PathConfig1 + "\n");

                // Читаем настройки из нового конфигурационного файла
                if (File::Exists(PathConfig1)) {
                    array<String^>^ lines = File::ReadAllLines(PathConfig1);
                    confDB1 = lines;
                    for each (String ^ line in lines) {
                        line = line->Trim();
                        if (line->StartsWith("#") || line->IndexOf("=") == -1)
                            continue;

                        array<String^>^ parts = line->Split('=');
                        if (parts->Length >= 2) {
                            String^ key = parts[0]->Trim();
                            String^ value = String::Join("=", parts, 1, parts->Length - 1)->Trim();
                            if (key == "dbms") nameDBMS = value;
                            else if (key == "server") Server = value;
                            else if (key == "database") nameDB = value;
                            else if (key == "user") nameUser = value;
                            else if (key == "driver") Driver = value;
                            else if (key == "table_input") tableInput = value;
                            else if (key == "table_output") tableOutput = value;
                            else if (key == "column_input_id") columnInputId = value;
                            else if (key == "column_output_id") columnOutputId = value;
                            else if (key == "data_in_1") DataIn1 = value;
                            else if (key == "data_in_2") DataIn2 = value;
                            else if (key == "data_in_3") DataIn3 = value;
                            else if (key == "data_out_1") DataOut1 = value;
                            else if (key == "data_out_2") DataOut2 = value;
                            else if (key == "data_out_3") DataOut3 = value;
                        }
                    }
                    lstLogs->AppendText(DateTime::Now.ToString() + ": Настройки для DB1 загружены из: " + PathConfig1 + "\n");
                }
                else {
                    lstLogs->AppendText(DateTime::Now.ToString() + ": Конфигурационный файл для DB1 не найден: " + PathConfig1 + "\n");
                }
            }
        }
        catch (Exception^ ex) {
            lstLogs->AppendText(DateTime::Now.ToString() + ": Ошибка при обновлении конфигурации DB1: " + ex->Message + "\n");
        }
    }

    // Обработчик для обновления конфигурации DB2
    System::Void PartialMainWindow::btnUpdateconfig2_Click(System::Object^ sender, System::EventArgs^ e) {
        try {
            OpenFileDialog^ openFileDialog = gcnew OpenFileDialog();
            openFileDialog->Filter = "Конфигурационные файлы (*.conf)|*.conf|Все файлы (*.*)|*.*";
            openFileDialog->Title = "Выберите конфигурационный файл для DB2";
            openFileDialog->InitialDirectory = Path::GetDirectoryName(Application::ExecutablePath);

            if (openFileDialog->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
                String^ newConfigPath = openFileDialog->FileName;
                PathConfig2 = newConfigPath;

                // Обновляем основной конфигурационный файл (app.conf)
                String^ mainConfigPath = Path::Combine(Path::GetDirectoryName(Application::ExecutablePath), "app.conf");
                List<String^>^ mainConfigLines = gcnew List<String^>(2); // Исправлено: явная инициализация
                bool lastConfigDb2Updated = false;

                if (File::Exists(mainConfigPath)) {
                    array<String^>^ lines = File::ReadAllLines(mainConfigPath);
                    for each (String ^ line in lines) {
                        if (line->Trim()->StartsWith("last_config_db2=")) {
                            mainConfigLines->Add("last_config_db2=" + newConfigPath);
                            lastConfigDb2Updated = true;
                        }
                        else {
                            mainConfigLines->Add(line);
                        }
                    }
                }
                if (!lastConfigDb2Updated) {
                    mainConfigLines->Add("last_config_db2=" + newConfigPath);
                }

                // Записываем обновлённый основной конфигурационный файл
                File::WriteAllLines(mainConfigPath, mainConfigLines);
                lstLogs->AppendText(DateTime::Now.ToString() + ": Конфигурационный файл для DB2 обновлен: " + PathConfig2 + "\n");

                // Читаем настройки из нового конфигурационного файла
                if (File::Exists(PathConfig2)) {
                    array<String^>^ lines = File::ReadAllLines(PathConfig2);
                    for each (String ^ line in lines) {
                        line = line->Trim();
                        if (line->StartsWith("#") || line->IndexOf("=") == -1)
                            continue;

                        array<String^>^ parts = line->Split('=');
                        if (parts->Length >= 2) {
                            String^ key = parts[0]->Trim();
                            String^ value = String::Join("=", parts, 1, parts->Length - 1)->Trim();
                            if (key == "dbms") nameDBMS2 = value;
                            else if (key == "server") Server2 = value;
                            else if (key == "database") DataBase2 = value;
                            else if (key == "user") User2 = value;
                            else if (key == "driver") Driver2 = value;
                            else if (key == "table_input") tableInput2 = value;
                            else if (key == "table_output") tableOutput2 = value;
                            else if (key == "column_input_id") columnInputId2 = value;
                            else if (key == "column_output_id") columnOutputId2 = value;
                        }
                    }
                    lstLogs->AppendText(DateTime::Now.ToString() + ": Настройки для DB2 загружены из: " + PathConfig2 + "\n");
                }
                else {
                    lstLogs->AppendText(DateTime::Now.ToString() + ": Конфигурационный файл для DB2 не найден: " + PathConfig2 + "\n");
                }
            }
        }
        catch (Exception^ ex) {
            lstLogs->AppendText(DateTime::Now.ToString() + ": Ошибка при обновлении конфигурации DB2: " + ex->Message + "\n");
        }
    }

    // Обработчик закрытия формы
    System::Void PartialMainWindow::PartialMainWindow_FormClosing(System::Object^ sender, System::Windows::Forms::FormClosingEventArgs^ e) {
        try {
            if (db_connect1 != nullptr && db_connect1->State == ConnectionState::Open) {
                db_connect1->Close();
                lstLogs->AppendText(DateTime::Now.ToString() + ": Подключение к DB1 закрыто при закрытии формы.\n");
            }
            if (db_connect2 != nullptr && db_connect2->State == ConnectionState::Open) {
                db_connect2->Close();
                lstLogs->AppendText(DateTime::Now.ToString() + ": Подключение к DB2 закрыто при закрытии формы.\n");
            }
            Application::Exit();
        }
        catch (Exception^ ex) {
            lstLogs->AppendText(DateTime::Now.ToString() + ": Ошибка при закрытии формы: " + ex->Message + "\n");
        }
    }

    // Обработчик кнопки закрытия
    System::Void PartialMainWindow::btnClosed_Click(System::Object^ sender, System::EventArgs^ e) {
        this->Close();
    }

    // Обработчики для перетаскивания формы
    void PartialMainWindow::PartialMainWindow_MouseDown(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
        if (e->Button == System::Windows::Forms::MouseButtons::Left) {
            isDragging = true;
            dragStartPoint = gcnew Point(e->X, e->Y);
        }
    }

    void PartialMainWindow::PartialMainWindow_MouseMove(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
        if (isDragging) {
            Point^ p = PointToScreen(Point(e->X, e->Y));
            this->Location = Point(p->X - dragStartPoint->X, p->Y - dragStartPoint->Y);
        }
    }

    void PartialMainWindow::PartialMainWindow_MouseUp(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
        if (e->Button == System::Windows::Forms::MouseButtons::Left) {
            isDragging = false;
        }
    }
}