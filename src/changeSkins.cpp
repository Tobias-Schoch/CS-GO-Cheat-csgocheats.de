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
#include "skins.hpp"
#include "MyMem.h"
#include "cheats.h"

bool skinChangerStatus = false;

void skinChangerStatusChange() {
    skinChangerStatus = skinChangerStatus ? false : true;
}

bool skinChangerStatusTrue(bool changeStatus) {
    if (changeStatus) { skinChangerStatusChange(); }
    return skinChangerStatus;
}

void changeSkinInMemory(int weaponEnt, int paintkit) {
    writeMemory(weaponEnt + hazedumper::netvars::m_iItemIDHigh, ptrdiff_t(-1));
    writeMemory(weaponEnt + hazedumper::netvars::m_nFallbackPaintKit, ptrdiff_t(paintkit));
    writeMemory(weaponEnt + hazedumper::netvars::m_nFallbackSeed, ptrdiff_t(320));
    writeMemory(weaponEnt + hazedumper::netvars::m_flFallbackWear, 0.0001f);
}

void changeKnifeInMemory(int weaponEnt, int paintkit) {
    writeMemory(weaponEnt + hazedumper::netvars::m_iItemIDHigh, ptrdiff_t(-1));
    writeMemory(weaponEnt + hazedumper::netvars::m_OriginalOwnerXuidLow, ptrdiff_t(0));
    writeMemory(weaponEnt + hazedumper::netvars::m_OriginalOwnerXuidHigh, ptrdiff_t(0));
    writeMemory(weaponEnt + hazedumper::netvars::m_nFallbackPaintKit, ptrdiff_t(paintkit));
    writeMemory(weaponEnt + hazedumper::netvars::m_nFallbackSeed, ptrdiff_t(320));
}

void skinChanger(uintptr_t targetDLL) {
    int weapon = 0;
    int weaponEnt = 0;
    short weaponID = 0;
    int knife = 12;
    uintptr_t sequence = 0;
    uintptr_t r = 0;
    uintptr_t KnifeViewModel = 0;
    uintptr_t model = 0;
    uintptr_t ezezez = 0;
    uintptr_t ezezez2 = 0;
    uintptr_t tesing = 0;
    uintptr_t myPlayerHealth = 0;
    int paintkit = 0;
    int random_sequence = 0;
    int current_animation = 0;
    bool skinStatus = true;

    while (skinChangerStatusTrue(false) == true) {
        uintptr_t myPlayer = readMemory(targetDLL + hazedumper::signatures::dwLocalPlayer);
        myPlayerHealth = readMemory(myPlayer + hazedumper::netvars::m_iHealth);
        if (myPlayer != NULL && myPlayerHealth > 0) {
            for (int j = 0; j <= 2; j++) {

                weapon = readMemory(myPlayer + hazedumper::netvars::m_hMyWeapons + j * 0x4) & 0xFFF;
                weaponEnt = readMemory(targetDLL + hazedumper::signatures::dwEntityList + (weapon - 1) * 0x10);
                weaponID = readMemory(weaponEnt + hazedumper::netvars::m_iItemDefinitionIndex);

                if (weaponID == 507) {
                    ezezez = readMemory(weaponEnt + 0x3250);

                    ezezez2 = ezezez - (566 - 476) - knife;
                    tesing = readMemory(KnifeViewModel + 0x258);
                    if (ezezez2 == tesing) {
                        paintkit = 415;
                        writeMemory(KnifeViewModel + 0x258, ptrdiff_t(ezezez)); // nmodelindex
                        changeKnifeInMemory(weaponEnt, paintkit);
                    } else if ((ezezez2 + (501 - 476)) == tesing) {
                        paintkit = 415;
                        writeMemory(KnifeViewModel + 0x258, ptrdiff_t(ezezez)); // nmodelindex
                        changeKnifeInMemory(weaponEnt, paintkit);
                    }
                }


                // get numbers sv_precacheinfo 

                switch (weaponID) {
                case 1:
                    paintkit = skins::id::desertEagle;
                    break;
                case 2:
                    paintkit = skins::id::dualBerettas;
                    break;
                case 507:
                case 515:
                    paintkit = skins::id::knifeCT;
                    break;
                case 41:
                case 42:
                    paintkit = skins::id::knifeCT;
                    KnifeViewModel = readMemory(myPlayer + hazedumper::netvars::m_hViewModel) & 0xfff;
                    KnifeViewModel = readMemory(targetDLL + hazedumper::signatures::dwEntityList + (KnifeViewModel - 1) * 0x10);

                    ezezez = readMemory(weaponEnt + 0x3250);
                    ezezez = ezezez + (566 - 476) + knife;

                    writeMemory(KnifeViewModel + 0x258, ptrdiff_t(ezezez)); // nmodelindex
                    writeMemory(weaponEnt + 0x258, ptrdiff_t(ezezez)); // nmodelindex
                    writeMemory(weaponEnt + 0x3250, ptrdiff_t(ezezez)); // iviewmodelindex
                    writeMemory(weaponEnt + 0x3254, ptrdiff_t(ezezez + 1)); // worldmodelindex
                    writeMemory(weaponEnt + hazedumper::netvars::m_iItemDefinitionIndex, 507); // itemdefinition
                    writeMemory(weaponEnt + 0x34, 507); // itemdefinition
                    changeKnifeInMemory(weaponEnt, paintkit);
                    break;
                case 59:
                    paintkit = skins::id::knifeCT;
                    KnifeViewModel = readMemory(myPlayer + hazedumper::netvars::m_hViewModel) & 0xfff;
                    KnifeViewModel = readMemory(targetDLL + hazedumper::signatures::dwEntityList + (KnifeViewModel - 1) * 0x10);
                   
                    ezezez = readMemory(weaponEnt + 0x3250);
                    ezezez = ezezez + (566 - 501) + knife;

                    writeMemory(KnifeViewModel + 0x258, ptrdiff_t(ezezez)); // nmodelindex
                    writeMemory(weaponEnt + 0x258, ptrdiff_t(ezezez)); // nmodelindex
                    writeMemory(weaponEnt + 0x3250, ptrdiff_t(ezezez)); // iviewmodelindex
                    writeMemory(weaponEnt + 0x3254, ptrdiff_t(ezezez + 1)); // worldmodelindex
                    writeMemory(weaponEnt + hazedumper::netvars::m_iItemDefinitionIndex, 507); // itemdefinition
                    writeMemory(weaponEnt + 0x34, 507); // itemdefinition
                    changeKnifeInMemory(weaponEnt, paintkit);

                    break;
                case 3:
                    paintkit = skins::id::fiveSeveN;
                    break;
                case 4:
                    paintkit = skins::id::glock18;
                    break;
                case 7:
                    paintkit = skins::id::ak47; //675/959
                    break;
                case 8:
                    paintkit = skins::id::aug;
                    break;
                case 9:
                    paintkit = skins::id::awp;
                    break;
                case 10:
                    paintkit = skins::id::famas;
                    break;
                case 11:
                    paintkit = skins::id::g3sg1;
                    break;
                case 13:
                    paintkit = skins::id::galil;
                    break;
                case 16:
                    paintkit = skins::id::m4a4;
                    break;
                case 17:
                    paintkit = skins::id::mac10;
                    break;
                case 19:
                    paintkit = skins::id::p90;
                    break;
                case 24:
                    paintkit = skins::id::ump45;
                    break;
                case 25:
                    paintkit = skins::id::xm1014;
                    break;
                case 26:
                    paintkit = skins::id::ppBizon;
                    break;
                case 28:
                    paintkit = skins::id::negev;
                    break;
                case 32:
                    paintkit = skins::id::p2000;
                    break;
                case 33:
                    paintkit = skins::id::mp7;
                    break;
                case 34:
                    paintkit = skins::id::mp9;
                    break;
                case 36:
                    paintkit = skins::id::p250;
                    break;
                case 38:
                    paintkit = skins::id::scar250;
                    break;
                case 39:
                    paintkit = skins::id::sg553;
                    break;
                case 40:
                    paintkit = skins::id::ssg08;
                    break;
                case 60:
                    paintkit = skins::id::m4a1s;
                    break;
                case 61:
                    paintkit = skins::id::usps; //653/504
                    break;
                }
                changeSkinInMemory(weaponEnt, paintkit);
            }
        }
    }
}

/*else if (weaponID == 515) {
    ezezez = readMemory(weaponEnt + 0x3240);
    ezezez2 = ezezez - 65 - knife - 15;
    tesing = readMemory(KnifeViewModel + 0x258);
    if (ezezez2 == tesing || ezezez == tesing) {
        random_sequence = rand() % 2;

        paintkit = 415;
        ezezez = readMemory(weaponEnt + 0x3240);
        writeMemory(KnifeViewModel + 0x258, ptrdiff_t(ezezez)); // nmodelindex
        changeKnifeInMemory(weaponEnt, paintkit);
        current_animation = readMemory(KnifeViewModel + ptrdiff_t(0x28BC));

        if (current_animation == 3) {
            writeMemory(KnifeViewModel + 0x28BC, ptrdiff_t(5));
        }
        else if (current_animation == 9) {
            if (random_sequence == 0) {
                writeMemory(KnifeViewModel + 0x28BC, ptrdiff_t(8));
            }
            else {
                writeMemory(KnifeViewModel + 0x28BC, ptrdiff_t(10));
            }
        }
        else if (current_animation == 1) {
            writeMemory(KnifeViewModel + 0x28BC, ptrdiff_t(2));
        }
        else if (current_animation == 12) {
            if (random_sequence == 0) {
                writeMemory(KnifeViewModel + 0x28BC, ptrdiff_t(13));
            }
            else {
                writeMemory(KnifeViewModel + 0x28BC, ptrdiff_t(15));
            }
        }
    }
}
else if (weaponID == 523) {
    ezezez = readMemory(weaponEnt + 0x3240);
    ezezez2 = ezezez - 65 - knife - 40;
    tesing = readMemory(KnifeViewModel + 0x258);
    if (ezezez2 == tesing || ezezez == tesing) {
        random_sequence = rand() % 2;

        paintkit = 415;
        ezezez = readMemory(weaponEnt + 0x3240);
        writeMemory(KnifeViewModel + 0x258, ptrdiff_t(ezezez));
        changeKnifeInMemory(weaponEnt, paintkit);
        current_animation = readMemory(KnifeViewModel + 0x28BC);

        if (current_animation == 12) {
            if (random_sequence == 0) {
                writeMemory(KnifeViewModel + 0x28BC, ptrdiff_t(14));
            }
            else {
                writeMemory(KnifeViewModel + 0x28BC, ptrdiff_t(15));
            }
        }
    }
}*/

/*else if (weaponID == 515) {
                    ezezez = readMemory(weaponEnt + 0x3250);
                    ezezez2 = ezezez - (593 - 501) - knife;
                    tesing = readMemory(KnifeViewModel + 0x258);
                    if ((ezezez2 + 25) == tesing || ezezez == tesing) {
                        random_sequence = rand() % 2;

                        paintkit = 415;
                        ezezez = readMemory(weaponEnt + 0x3250);
                        writeMemory(KnifeViewModel + 0x258, ptrdiff_t(ezezez)); // nmodelindex
                        changeKnifeInMemory(weaponEnt, paintkit);
                        current_animation = readMemory(KnifeViewModel + ptrdiff_t(0x28BC));

                        if (current_animation == 3) {
                            writeMemory(KnifeViewModel + 0x28BC, ptrdiff_t(5));
                        }
                        else if (current_animation == 9) {
                            if (random_sequence == 0) {
                                writeMemory(KnifeViewModel + 0x28BC, ptrdiff_t(8));
                            }
                            else {
                                writeMemory(KnifeViewModel + 0x28BC, ptrdiff_t(10));
                            }
                        }
                        else if (current_animation == 1) {
                            writeMemory(KnifeViewModel + 0x28BC, ptrdiff_t(2));
                        }
                        else if (current_animation == 12) {
                            if (random_sequence == 0) {
                                writeMemory(KnifeViewModel + 0x28BC, ptrdiff_t(13));
                            }
                            else {
                                writeMemory(KnifeViewModel + 0x28BC, ptrdiff_t(15));
                            }
                        }
                    }
                }*/