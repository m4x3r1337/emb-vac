#pragma once

#include <Windows.h>

class MemoryUtil {

public:

	MemoryUtil (HANDLE application) : m_applicationHandle (application) {};

	bool WriteToMemory (DWORD address, LPCVOID buffer, SIZE_T size) {
		return WriteProcessMemory (m_applicationHandle, reinterpret_cast <LPVOID> (address), buffer, size, NULL);
	}
	
private:

	HANDLE m_applicationHandle;

};