#include "ConnectionWindow.h"
#include "MainWindow.h"
#include "PartialMainWindow.h"
#include <Windows.h>
#include <iostream>

using namespace src;

[STAThread]
int main() {
    Application::EnableVisualStyles();
    Application::SetCompatibleTextRenderingDefault(false);
    Application::Run(gcnew ConnectionWindow());
    return 0;
}