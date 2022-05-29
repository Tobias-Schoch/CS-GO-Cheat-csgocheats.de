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
#include "MyMem.h"
#include "cheats.h"

bool flashStatus = false;

void flash(uintptr_t targetDLL) {
    uintptr_t myPlayer = readMemory(targetDLL + hazedumper::signatures::dwLocalPlayer);
    bool flashStatus = true;
    while (flashStatusTrue(false) == true) {
        DWORD flashDuration = readMemory(myPlayer + hazedumper::netvars::m_flFlashMaxAlpha);
        if (flashDuration != 0.5) {
            writeMemory(myPlayer + hazedumper::netvars::m_flFlashMaxAlpha, 0.5f);
        }
        Sleep(10);
    }
}

void flashStatusChange() {
    flashStatus = flashStatus ? false : true;
}

bool flashStatusTrue(bool changeStatus) {
    if (changeStatus) { flashStatusChange(); }
    return flashStatus;
}
