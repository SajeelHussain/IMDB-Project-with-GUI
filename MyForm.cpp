#include "MyForm.h"
#include <iostream>
using namespace System;
using namespace System::Windows::Forms;
[STAThread]

void main()
{
    Application::EnableVisualStyles();
    Application::SetCompatibleTextRenderingDefault(false);
    sajeel::MyForm form;
    Application::Run(% form);
}
