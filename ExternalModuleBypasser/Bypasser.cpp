#include "Bypasser.h"
#include <iostream>

bool Bypasser::InitNtDll () {

	HMODULE ntdllHandle = GetModuleHandleA ("ntdll.dll");

	if (!ntdllHandle) return false;

	m_ntOpenFile = GetProcAddress (ntdllHandle, "NtOpenFile"), m_ldrLoadDll = GetProcAddress (ntdllHandle, "LdrLoadDll");

	if (!m_ntOpenFile || !m_ldrLoadDll) return false;

	std::cout << "NTDLL handle: " << std::hex << "0x" << reinterpret_cast <DWORD> (ntdllHandle)  << "." << std::endl;
	std::cout << "NtOpenFile: "   << std::hex << "0x" << reinterpret_cast <DWORD> (m_ntOpenFile) << "." << std::endl;
	std::cout << "LdrLoadDll: "   << std::hex << "0x" << reinterpret_cast <DWORD> (m_ldrLoadDll) << "." << std::endl;
	return true;
}

bool Bypasser::NtOpenFile () {
	//Premium bypazz.
	return m_memoryUtil.WriteToMemory (reinterpret_cast <DWORD> (m_ntOpenFile), m_ntOpenFile, 10);
}

bool Bypasser::LdrLoadDll () {
	//Premium bypazz.
	return m_memoryUtil.WriteToMemory (reinterpret_cast <DWORD> (m_ntOpenFile), m_ldrLoadDll, 10);
}