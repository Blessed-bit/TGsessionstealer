#pragma once
#include "Include.h"


void socket(int IpAddress) {
	socket = SOCKET("198.168.0.1:5555", sizeof(IpAddress), DWORD_P);
}