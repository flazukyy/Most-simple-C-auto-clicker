#include <iostream>
#include <windows.h>

using namespace std;

int x = 0, y = 0, cps;
bool click = false;

void Menu()
{
    cout << "Add CPS (click per second):" << endl;
    cin >> cps;
    return;
}

void Clicker()
{
    std::cout << "\033[2J\033[1;1H";
    std::cout << "Press \"ALT\" to turn on auto clicker\nPress \"Right Click\" to stop auto clicker";
    while (true)
    {
        if (GetAsyncKeyState(VK_MENU)) 
        {
            click = true;
        }

        if (GetAsyncKeyState(VK_RBUTTON)) 
        {
            click = false;
        }

        if (click == true)
        {
            mouse_event(MOUSEEVENTF_LEFTDOWN, x, y, 0, 0);
            mouse_event(MOUSEEVENTF_LEFTUP, x, y, 0, 0);
            Sleep(1000 / cps);
        }

        if (GetAsyncKeyState(VK_NUMPAD0)) {
            break;
        }
    }
    return;
}
int main()
{
    Menu();
    Clicker();
    return 0;
}
