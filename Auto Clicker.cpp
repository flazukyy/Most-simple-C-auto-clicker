#include <iostream>
#include <windows.h>
#include <thread>
#include <chrono>

int x, y, cps;
bool click;

void Menu() {
    std::cout << "clicks per second: ";
    std::cin >> cps;
}

void Clicker() {
    std::cout << "\033[2J\033[1;1H";
    std::cout << "Press \"ALT\" to turn on auto clicker\nPress \"Right Click\" to stop auto clicker";

    while (true) {
        if (GetAsyncKeyState(0x57) || GetAsyncKeyState(0x2C)) continue;
        if (GetAsyncKeyState(VK_MENU)) click = true;
        if (GetAsyncKeyState(VK_RBUTTON)) click = false;

        if (click) {
            mouse_event(MOUSEEVENTF_LEFTDOWN, x, y, 0, 0);
            mouse_event(MOUSEEVENTF_LEFTUP, x, y, 0, 0);
        }

        std::this_thread::sleep_for(std::chrono::milliseconds(1000 / cps));
    }
}

int main()
{
    Menu();
    Clicker();
    return 0;
}