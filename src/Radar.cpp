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

bool radarStatus = false;

void radar(uintptr_t targetDLL) {
    while (radarStatusTrue(false) == true) {
        for (int i = 0; i < 32; i++) {
            uintptr_t radarEntities = readMemory(targetDLL + hazedumper::signatures::dwEntityList + i * 0x10);
            if (radarEntities != NULL) {
                writeMemory(radarEntities + hazedumper::netvars::m_bSpotted, true);
            }
        }
        Sleep(10);
    }
}

void radarStatusChange() {
    radarStatus = radarStatus ? false : true;
}

bool radarStatusTrue(bool changeStatus) {
    if (changeStatus) { radarStatusChange(); }
    return radarStatus;
}
