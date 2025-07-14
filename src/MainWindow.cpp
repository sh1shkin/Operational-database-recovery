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
    System::Void MainWindow::btnClosedCW_Click(System::Object^ sender, System::EventArgs^ e) {
        connectForm2->Close();
        connectForm1->Close();
        this->Close();
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