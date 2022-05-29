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

void forceUpdate(uintptr_t engineDLL) {
    uintptr_t test = readMemory(engineDLL + hazedumper::signatures::dwClientState);
    writeMemory(test + hazedumper::signatures::clientstate_delta_ticks, ptrdiff_t(-1));
}