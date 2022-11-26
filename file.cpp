#include <iostream>
#include <fstream>
#include "define.h"

const std::string msg::err_fin = "Не удалось отрыть файл, проверьте права доступа и его наличие по адресу: ";
const std::string msg::err_fout  = "Не удалось создаь файл, проверьте права доступа по адресу: ";

std::ifstream File::in(const char* path)
{
	std::ifstream fin (path);

	if (!fin.is_open())
	{
		std::cout << msg::err_fin << path << std::endl;	
	}

	return fin;	
}

std::ofstream File::out(const char* path)
{
	std::ofstream fout (path);

	if (!fout.is_open())
	{
		std::cout << msg::err_fout << path << std::endl;	
	}

	return fout;
}
