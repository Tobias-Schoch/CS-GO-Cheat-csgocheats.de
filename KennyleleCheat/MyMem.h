#pragma once

int getPid(std::wstring);
int getModule(int, std::wstring);
int readMemory(uintptr_t);
std::string readMemoryString(uintptr_t);
void writeMemory(uintptr_t, ptrdiff_t);
void writeMemory(uintptr_t, float);
void writeMemory(uintptr_t, bool);
void writeMemory(uintptr_t, DWORD);
void writeMemory(uintptr_t, short);

template <typename datatype>
datatype ReadMemory(HANDLE hProcess, DWORD address)
{
	datatype buffer;
	ReadProcessMemory(hProcess, (LPCVOID)address, &buffer, sizeof(datatype), NULL);
	return buffer;
}

template <typename datatype>
void WriteMemory(HANDLE hProcess, DWORD address, datatype value)
{
	WriteProcessMemory(hProcess, (LPVOID)address, &value, sizeof(value), NULL);
}

