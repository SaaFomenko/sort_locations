#include <iostream>
#include <fstream>
#include "define.h"


const std::string msg::err_size = "Количество адресов должно быть челым числом и первой строчкой в файле, отделенным от других полей переводом строки,  ошибка ./int.txt в строке: ";
const std::string msg::err_name = "Название не может быть менее 3-х символов, ошибка ./int.txt в строке: ";
const std::string msg::err_num = "Номер должен быть целым числом, ошибка ./int.txt в строке: ";
const std::string msg::success = "Даннные преобразованы, результат смотрите в файле ./out.txt";


int main() {
	File file;

	std::string row = "";
	int row_count = 0;
	int size = 0;

	std::ifstream fin = file.in();

	if (!fin.is_open()) return 1;

	std::getline(fin, row);
	++row_count;
	try
	{
		size = std::stoi(row);
	}
	catch(std::invalid_argument e)
	{
		std::cout << msg::err_size << row_count << std::endl;
		return 1;
	}

	Location locations[size];
	
	bool check = false;

	for (int i = 0; i < size; ++i)
	{
		std::getline(fin, row);
		++row_count;
		check = locations[i].strSet(row, field::city);
		if (!check)
		{
			std::cout << msg::err_name << row_count << std::endl;

			return 1;
		}

		std::getline(fin, row);
		++row_count;
		check = locations[i].strSet(row, field::street);
		if (!check)
		{
			std::cout << msg::err_name << row_count << std::endl;

			return 1;
		}

		std::getline(fin, row);
		++row_count;
		check = locations[i].strSet(row, field::house);
		if (!check)
		{
			std::cout << msg::err_num << row_count << std::endl;

			return 1;
		}

		std::getline(fin, row);
		++row_count;
		check = locations[i].strSet(row, field::flat);
		if (!check)
		{
			std::cout << msg::err_num << row_count << std::endl;

			return 1;
		}
	}

	fin.close();

	Sort sort = Sort(locations, size);
	Location* sort_locations = sort.alphabet();

	std::ofstream fout = file.out();

	fout << size << std::endl;

	for (int i = 0; i < size; ++i)
	{
		fout << locations[i].strGet();
	}

	fout.close();

	std::cout << msg::success << std::endl;
 
  return 0;
}
