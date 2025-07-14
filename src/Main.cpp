#include "ConnectionWindow.h"
#include <Windows.h>

using namespace System;
using namespace System::Windows::Forms;

[STAThread]
int main() {
    Application::EnableVisualStyles();
    Application::SetCompatibleTextRenderingDefault(false);
    src::ConnectionWindow^ form = gcnew src::ConnectionWindow();
    Application::Run(form);
    return 0;
}