/*void revealRank() {
    uintptr_t playerBase = readMemory(targetDLL + dwPlayerResource);
    uintptr_t playerBase2 = 0;

    playerBase2 = readMemory(playerBase + dwRadarBase);
    playerBase2 = readMemory(playerBase2 + 0x74);

    uintptr_t rankOffset = 0;
    std::string rankName = "";
    std::string playerName = "";
    uintptr_t winsOffset = 0;
    uintptr_t moneyEntities = 0;
    uintptr_t moneyOffset = 0;

    while (rankStatus == true) {
        for (int i = 0; i < 64; i++) {
            moneyEntities = readMemory(targetDLL + dwEntityList + i * 0x10);
            playerName = readMemory(playerBase2 + 0x300 + (0x174 * (i - 1)));
            rankOffset = readMemory(playerBase + m_iCompetitiveRanking + (i * 0x04));
            moneyOffset = readMemory(moneyEntities + m_iAccountID);
            winsOffset = readMemory(playerBase + m_iCompetitiveWins + (i * 0x04));
            switch (rankOffset) {
            case 0:
                rankName = "Unranked";
                break;
            case 1:
                rankName = "Silver I";
                break;
            case 2:
                rankName = "Silver II";
                break;
            case 3:
                rankName = "Silver III";
                break;
            case 4:
                rankName = "Silver IV";
                break;
            case 5:
                rankName = "Silver Elite";
                break;
            case 6:
                rankName = "Silver Elite Master";
                break;
            case 7:
                rankName = "Gold Nova 1";
                break;
            case 8:
                rankName = "Gold Nova 2";
                break;
            case 9:
                rankName = "Gold Nova 3";
                break;
            case 10:
                rankName = "Gold Nova 4";
                break;
            case 11:
                rankName = "Master Guardian 1";
                break;
            case 12:
                rankName = "Master Guardian 2";
                break;
            case 13:
                rankName = "Master Guardian Elite";
                break;
            case 14:
                rankName = "Distinguished Master Guardian";
                break;
            case 15:
                rankName = "Legendary Eagle";
                break;
            case 16:
                rankName = "Legendary Eagle Master";
                break;
            case 17:
                rankName = "Supreme Master First Class";
                break;
            case 18:
                rankName = "The Global Elite";
                break;

            }
            if (winsOffset != 0) {
                //std::cout << std::flush;
                std::cout << playerName << ": has Rank " << rankName << " and " << winsOffset << " wins and has " << moneyOffset << "$" << std::endl;
                winsOffset = readMemory(playerBase + m_iAccountID + (i * 0x04));
                std::cout << winsOffset << std::endl;
            }
        }
        Sleep(10000);
    }
}*/