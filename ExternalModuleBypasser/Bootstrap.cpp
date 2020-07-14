#include <iostream>
#include <windows.h>
#include <string>
#include "Bypasser.h"

int main () {

	auto terminate = []() {
		system ("pause");
		exit   (-1);
	};

	SetConsoleTitleA ("External LoadLibrary bypasser for CS:GO.");

	std::cout << "Try find process CS:GO..." << std::endl;

	HWND hwnd = FindWindowA (NULL, "Counter-Strike: Global Offensive");

	if (!hwnd) {
		std::cout << "Can't find CS:GO window. Please make sure csgo is running." << std::endl;
		terminate ();
	}

	DWORD processId;

	GetWindowThreadProcessId (hwnd, &processId);

	if (!processId) {
		std::cout << "Can't find process id." << std::endl;
		terminate ();
	}

	std::cout << "Complete. Process id: " << processId << "." << "\n" << std::endl;

	HANDLE handle = OpenProcess (PROCESS_ALL_ACCESS, FALSE, processId);

	if (!handle) {
		std::cout << "Can't get process handle. Please run application with administrator privillegies." << std::endl;
		terminate ();
	}
	
	Bypasser bypasser (handle);

	std::cout << "Try to initilize bypasser..." << std::endl;

	if (!bypasser.InitNtDll ()) {
		std::cout << "Can't init ntdll." << std::endl;
		terminate ();
	}

	std::cout << "Bypasser initialized." << "\n" << std::endl;
	std::cout << "Bypass NtOpenFile..."  << std::endl;

	if (!bypasser.NtOpenFile ()) {
		std::cout << "Can't bypass NtOpenFile." << std::endl;
		terminate ();
	}

	std::cout << "NtOpenFile bypassed." << "\n" << std::endl;
	std::cout << "Bypass LdrLoadDll..." << std::endl;

	if (!bypasser.LdrLoadDll ()) {
		std::cout << "Can't bypass LdrLoadDll." << std::endl;
		terminate ();
	}

	std::cout << "LdrLoadDll bypassed." << "\n" << std::endl;

	std::cout << "VAC ring0 bypassed."  << std::endl;
	terminate ();

}