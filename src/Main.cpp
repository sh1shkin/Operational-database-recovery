#include "PartialMainWindow.h"
#include <Windows.h>

using namespace System;
using namespace System::Windows::Forms;

[STAThread]
int main() {
    Application::EnableVisualStyles();
    Application::SetCompatibleTextRenderingDefault(false);
    src::PartialMainWindow^ form = gcnew src::PartialMainWindow();
    Application::Run(form);
    return 0;
}