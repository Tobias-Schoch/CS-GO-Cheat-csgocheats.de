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

bool bhopStatus = false;

void bhop(uintptr_t targetDLL) {
    bool bhopStatus = true;
    uintptr_t myPlayer = readMemory(targetDLL + hazedumper::signatures::dwLocalPlayer);
    while (bhopStatusTrue(false) == true) {
        if (GetAsyncKeyState(VK_SPACE) & 0x8000) {
            BYTE flagStatus = readMemory(myPlayer + hazedumper::netvars::m_fFlags);
            if (flagStatus != NULL) {
                writeMemory(targetDLL + hazedumper::signatures::dwForceJump, 6);
            }
        }
    }

}

void bhopStatusChange() {
    bhopStatus = bhopStatus ? false : true;
}

bool bhopStatusTrue(bool changeStatus) {
    if (changeStatus) { bhopStatusChange(); }
    return bhopStatus;
}

