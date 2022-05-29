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
#include "MyMem.h"
#pragma comment(lib, "urlmon.lib")

std::string skinString = "F1 - SkinChanger ";
std::string bhopString = "F2 - BHOP ";
std::string radarString = "F3 - Radar ";
std::string flashString = "F4 - Anti Flash ";
std::string glowString = "F5 - Glow ";
std::string forceString = "F6 - Force Full Update ";

void printTitle() {
    std::cout << "  _  __                      _      _        _____      _            _       " << std::endl;
    std::cout << " | |/ /                     | |    | |      |  __ \\    (_)          | |      " << std::endl;
    std::cout << " | ' / ___ _ __  _ __  _   _| | ___| | ___  | |__) | __ ___   ____ _| |_ ___ " << std::endl;
    std::cout << " |  < / _ \\ '_ \\| '_ \\| | | | |/ _ \\ |/ _ \\ |  ___/ '__| \\ \\ / / _` | __/ _ \\" << std::endl;
    std::cout << " | . \\  __/ | | | | | | |_| | |  __/ |  __/ | |   | |  | |\\ V / (_| | ||  __/" << std::endl;
    std::cout << " |_|\\_\\___|_| |_|_| |_|\\__, |_|\\___|_|\\___| |_|   |_|  |_| \\_/ \\__,_|\\__\\___|" << std::endl;
    std::cout << "                        __/ |                                                " << std::endl;
    std::cout << "                       |___/                                                 \n" << std::endl;
}

void consoleOutput() {
    system("CLS");
    printTitle();

    std::cout << "\n" << skinString;
    std::cout << (skinChangerStatusTrue(false) ? "[ + ]" : "[ - ]") << std::endl;
    std::cout << bhopString;
    std::cout << (bhopStatusTrue(false) ? "[ + ]" : "[ - ]") << std::endl;
    std::cout << radarString;
    std::cout << (radarStatusTrue(false) ? "[ + ]" : "[ - ]") << std::endl;
    std::cout << flashString;
    std::cout << (flashStatusTrue(false) ? "[ + ]" : "[ - ]") << std::endl;
    std::cout << glowString;
    std::cout << (glowStatusTrue(false) ? "[ + ]" : "[ - ]") << std::endl;
    std::cout << forceString << std::endl;
}

void dllFound(uintptr_t targetDLL, uintptr_t engineDLL) {
    if (targetDLL != NULL && engineDLL != NULL) {
        std::cout << "Found client.dll: " << targetDLL << std::endl;
        std::cout << "Found engine.dll: " << engineDLL << std::endl;
    } else {
        std::cout << "Modules couldn't be load. Rush B and restart the cheat." << std::endl;
    }
}

void csgoFound(uintptr_t targetProcessID) {
    std::cout << "Found csgo.exe: " << targetProcessID << std::endl;
}