#include "MainWindow.h"
#include "ConnectionWindow.h"

namespace src {
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
}