#pragma once

#include <Windows.h>
#include "MemoryUtil.h"

class Bypasser {

public:

	Bypasser (HANDLE application) : m_applicationHandle(application), m_memoryUtil(application) { };

	bool InitNtDll (), NtOpenFile (), LdrLoadDll ();

private:

	HANDLE     m_applicationHandle;
	FARPROC    m_ntOpenFile, m_ldrLoadDll;
	MemoryUtil m_memoryUtil;

};