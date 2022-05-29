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


void gloveChanger(uintptr_t targetDLL) {
    bool gloveStatus = true;
    int paintkit = 0;
    int knife = 12;
    while (gloveStatus == true) {
        uintptr_t myPlayer = readMemory(targetDLL + hazedumper::signatures::dwLocalPlayer);
        uintptr_t myPlayerHealth = readMemory(myPlayer + hazedumper::netvars::m_iHealth);
        if (myPlayer != NULL && myPlayerHealth > 0) {

            

                uintptr_t weapon = readMemory(myPlayer + hazedumper::netvars::m_hMyWeapons + 0x8) & 0xFFF;
                uintptr_t weaponEnt = readMemory(targetDLL + hazedumper::signatures::dwEntityList + (weapon - 1) * 0x10);
                uintptr_t weaponID = readMemory(weaponEnt + hazedumper::netvars::m_iItemDefinitionIndex);

            }
       
    }
}