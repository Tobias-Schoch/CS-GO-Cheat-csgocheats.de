#include <windows.h>
#include <tlhelp32.h>
#include <string>
#include <iostream>
#include "MyMem.h"

HANDLE handle;

int getPid(std::wstring programName) {
	int targetProcessID = NULL;

	PROCESSENTRY32W processEntry;
	processEntry.dwSize = sizeof processEntry;

	HANDLE snapProcesses = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);

	while (targetProcessID == NULL) {
		if (std::wstring(processEntry.szExeFile) == programName) {
			targetProcessID = processEntry.th32ProcessID;
		}
		Process32NextW(snapProcesses, &processEntry);
	}
	CloseHandle(snapProcesses);
	handle = OpenProcess(PROCESS_ALL_ACCESS, 0, targetProcessID);
	return targetProcessID;
}


int getModule(int targetProcessID, std::wstring targetModuleName) {
	DWORD targetDLL = NULL;

	MODULEENTRY32W moduleEntry;
	moduleEntry.dwSize = sizeof moduleEntry;
	HANDLE snapModules = CreateToolhelp32Snapshot(TH32CS_SNAPMODULE, targetProcessID);

	while (targetDLL == NULL) {
		if (moduleEntry.szModule == targetModuleName) {
			targetDLL = (uintptr_t)moduleEntry.modBaseAddr;
		}
		Module32Next(snapModules, &moduleEntry);
	}
	CloseHandle(snapModules);
	return targetDLL;
}

/* READ MEMORY */
int readMemory(uintptr_t addr) {
	int pseudo;
	ReadProcessMemory(handle, (void*)addr, &pseudo, sizeof(pseudo), NULL);
	return pseudo;
}

std::string readMemoryString(uintptr_t addr) {
	std::string pseudo;
	ReadProcessMemory(handle, (void*)addr, &pseudo, sizeof(pseudo), NULL);
	return pseudo;
}

void writeMemory(uintptr_t addr, ptrdiff_t pseudo) {
	WriteProcessMemory(handle, (void*)addr, &pseudo, sizeof(pseudo), NULL);
}
void writeMemory(uintptr_t addr, float pseudo) {
	WriteProcessMemory(handle, (void*)addr, &pseudo, sizeof(pseudo), NULL);
}
void writeMemory(uintptr_t addr, bool pseudo) {
	WriteProcessMemory(handle, (void*)addr, &pseudo, sizeof(pseudo), NULL);
}
void writeMemory(uintptr_t addr, DWORD pseudo) {
	WriteProcessMemory(handle, (void*)addr, &pseudo, sizeof(pseudo), NULL);
}
void writeMemory(uintptr_t addr, short pseudo) {
	WriteProcessMemory(handle, (void*)addr, &pseudo, sizeof(pseudo), NULL);
}


