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

bool glowStatus = false;

void glow(uintptr_t targetDLL) {
    int defusingPlayer = 0;
    int playerDefuser = 0;
    uintptr_t GlowObjectMananger = readMemory(targetDLL + hazedumper::signatures::dwGlowObjectManager);
    bool glowStatus = true;
    while (glowStatusTrue(false) == true) {
        for (int i = 0; i < 64; i++) {
            uintptr_t allPlayers = readMemory(targetDLL + hazedumper::signatures::dwEntityList + i * 0x10);
            if (allPlayers != NULL) {
                uintptr_t allPlayersTeam = readMemory(allPlayers + hazedumper::netvars::m_iTeamNum);
                uintptr_t glowIndex = readMemory(allPlayers + hazedumper::netvars::m_iGlowIndex);
                uintptr_t playerGlow = GlowObjectMananger + glowIndex * 0x38;
                defusingPlayer = readMemory(allPlayers + hazedumper::netvars::m_bIsDefusing);

                if (defusingPlayer == 1) {
                    writeMemory(playerGlow + 0x8, 1.0f);
                    writeMemory(playerGlow + 0xC, 1.0f);
                    writeMemory(playerGlow + 0x10, 1.0f);
                    writeMemory(playerGlow + 0x10, 0.5f);
                }
                else if (allPlayersTeam == 2) {
                    writeMemory(playerGlow + 0x8, 0.9f);
                    writeMemory(playerGlow + 0x10, 0.9f);
                    writeMemory(playerGlow + 0x14, 0.5f);
                }
                else if (allPlayersTeam == 3) {
                    writeMemory(playerGlow + 0xC, 0.9f);
                    writeMemory(playerGlow + 0x10, 0.9f);
                    writeMemory(playerGlow + 0x14, 0.5f);
                }

                writeMemory(playerGlow + 0x28, true);
                writeMemory(playerGlow + 0x29, false);
            }
        }
        Sleep(20);
    }
}

void glowStatusChange() {
    glowStatus = glowStatus ? false : true;
}

bool glowStatusTrue(bool changeStatus) {
    if (changeStatus) { glowStatusChange(); }
    return glowStatus;
}