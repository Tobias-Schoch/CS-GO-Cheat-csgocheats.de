#include <iostream>
#include <windows.h>
#include <stdio.h> 
#include <stdlib.h>
#include <tlhelp32.h>
#include <string>
#include <thread>
#include <cstdio>
#include <chrono>
#include <ctime>
#include <cmath>
#include "hazedumper.hpp"
#include "cheats.h"
#include "tui.h"
#include "MyMem.h"
#pragma comment(lib, "urlmon.lib")

int targetProcessID = NULL;
uintptr_t targetDLL = NULL;
uintptr_t engineDLL = NULL;
int paintkit;



int main() {
    std::wstring str(L"Kennylele's Cheat [Private Edition]");
    SetConsoleTitle(str.c_str());
    printTitle();

    targetProcessID = getPid(L"csgo.exe");
    csgoFound(targetProcessID);

    targetDLL = getModule(targetProcessID, L"client.dll");
    engineDLL = getModule(targetProcessID, L"engine.dll");
    dllFound(targetDLL, engineDLL);

    Sleep(3000);
    consoleOutput();

    while (true) {
        if (GetAsyncKeyState(VK_F1) & 0x8000) {
            if (skinChangerStatusTrue(true) == true) {
                std::thread threadSkin(skinChanger, targetDLL);
                threadSkin.detach();
            }
            consoleOutput();
        } else if (GetAsyncKeyState(VK_F2) & 0x8000) {
            if (bhopStatusTrue(true) == true) {
                std::thread threadBhop(bhop, targetDLL);
                threadBhop.detach();
            }
            consoleOutput();
        } else if (GetAsyncKeyState(VK_F3) & 0x8000) {
            if (radarStatusTrue(true) == true) {
                std::thread threadRadar(radar, targetDLL);
                threadRadar.detach();
            }
            consoleOutput();
        } else if (GetAsyncKeyState(VK_F4) & 0x8000) {
            if (flashStatusTrue(true) == true) {
                std::thread threadFlash(flash, targetDLL);
                threadFlash.detach();
            }
            consoleOutput();
        } else if (GetAsyncKeyState(VK_F5) & 0x8000) {
            if (glowStatusTrue(true) == true) {
                std::thread threadGlow(glow, targetDLL);
                threadGlow.detach();
            }
            consoleOutput();
        } else if (GetAsyncKeyState(VK_F6) & 0x8000) {
            std::thread threadRefresh(forceUpdate, engineDLL);
            threadRefresh.detach();
            consoleOutput();
        }
        Sleep(150);
    }
}