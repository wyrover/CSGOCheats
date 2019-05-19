#pragma once
#include <Windows.h>
#include <TlHelp32.h>
#include <comdef.h>

struct PModule
{
	DWORD dwBase;
	DWORD dwSize;
};

class memory
{
public:
	inline bool Attach(const char* ProcessName, DWORD dwAccess)
	{
		HANDLE handle = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, NULL);

		PROCESSENTRY32 entry;
		entry.dwSize = sizeof(entry);

		do
			if (!strcmp(_bstr_t(entry.szExeFile), ProcessName))
			{
				ProcessID = entry.th32ProcessID;
				CloseHandle(handle);
				_process = OpenProcess(dwAccess, false, ProcessID);
				return true;
			}
		while (Process32Next(handle, &entry));
		return false;
	}

	void CloseProcess(const char* ProcessName)
	{
		HANDLE HandleProcess;
		DWORD ProcessID;
		ProcessID = GetProcessIDbyName(ProcessName);
		HandleProcess = OpenProcess(PROCESS_ALL_ACCESS, false, ProcessID);
		TerminateProcess(HandleProcess, -1);
		CloseHandle(HandleProcess);
	}

	inline PModule GetModule(const char* ModuleName)
	{
		HANDLE module = CreateToolhelp32Snapshot(TH32CS_SNAPMODULE, ProcessID);
		MODULEENTRY32 entry;
		entry.dwSize = sizeof(entry);

		do
			if (!strcmp(_bstr_t(entry.szModule), ModuleName))
			{
				CloseHandle(module);
				return PModule{ reinterpret_cast<DWORD>(entry.hModule), entry.modBaseSize };
			}
		while (Module32Next(module, &entry));

		return PModule{ static_cast<DWORD>(false), static_cast<DWORD>(false) };
	}

	template <class T>
	T Read(const DWORD dwAddress)
	{
		T _read;
		ReadProcessMemory(_process, reinterpret_cast<LPVOID>(dwAddress), &_read, sizeof(T), NULL);
		return _read;
	}

	template <class T>
	void Write(const DWORD dwAddress, T value)
	{
		WriteProcessMemory(_process, reinterpret_cast<LPVOID>(dwAddress), &value, sizeof(T), NULL);
	}

	DWORD FindPattern(const DWORD start, const DWORD size, const char* signature, const char* mask) {
		BYTE* data = new BYTE[size];

		unsigned long bytesRead;
		if (!ReadProcessMemory(_process, reinterpret_cast<LPVOID>(start), data, size, &bytesRead)) {
			return NULL;
		}

		for (DWORD i = 0; i < size; i++) {
			if (DataCompare(static_cast<const BYTE*>(data + i), reinterpret_cast<const BYTE*>(signature), mask)) {
				return start + i;
			}
		}
		return NULL;
	}

	DWORD FindPatternArray(const DWORD start, const DWORD size, const char* mask, int count, ...) {
		char* sig = new char[count + 1];
		va_list ap;
		va_start(ap, count);
		for (int i = 0; i < count; i++) {
			char read = va_arg(ap, char);
			sig[i] = read;
		}
		va_end(ap);
		sig[count] = '\0';
		return FindPattern(start, size, sig, mask);
	}

	void Exit()
	{
		CloseHandle(_process);
	}

private:
	bool DataCompare(const BYTE* pData, const BYTE* pMask, const char* pszMask) {
		for (; *pszMask; ++pszMask, ++pData, ++pMask) {
			if (*pszMask == 'x' && *pData != *pMask) {
				return false;
			}
		}
		return (*pszMask == NULL);
	}
	DWORD GetProcessIDbyName(const char* szProcessName) {
		HANDLE hSnapshot;
		PROCESSENTRY32 pe = { sizeof(pe) };
		hSnapshot = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
		if (hSnapshot == INVALID_HANDLE_VALUE)
			return 0;
		if (!Process32First(hSnapshot, &pe))
			return 0;
		do {
			if (!lstrcmpi(pe.szExeFile, szProcessName))
				return pe.th32ProcessID;
		} while (Process32Next(hSnapshot, &pe));
		return 0;
	}
	HANDLE _process;
	DWORD ProcessID;
};