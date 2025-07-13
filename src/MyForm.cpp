#include "MyForm.h"

#include <Windows.h>
#include <iostream>
using namespace src;

int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {
    setlocale(LC_ALL, "ru");
    Application::EnableVisualStyles();
    Application::SetCompatibleTextRenderingDefault(false);
    Application::Run(gcnew MyForm);
    return 0;

}