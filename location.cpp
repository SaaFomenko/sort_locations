#include <iostream>
#include "define.h"



Location::Location(
		std::string city, std::string street, int house, int flat
		)
{
	this->city = city;
	this->street = street;
	this->house = house;
	this->flat = flat;
}

std::string Location::strGet(std::string splitter)
{
	std::string house = std::to_string(this->house);
	std::string flat = std::to_string(this->flat);

	return (this->city + splitter + this->street + splitter +
		house + splitter + flat + "\n");
}

bool Location::strSet(std::string row, field index)
{
	const int min_str = 2;
	bool check = false;
	
	if (index == field::city)
	{
		if (row.length() > min_str)
		{
			this->city = row;
			check = true;
		}
	}

	if (index == field::street)
	{
		if (row.length() > min_str)
		{
		  this->street = row;
		 	check = true;					     
		}
	}
	
	if (index == field::house)
	{
		try
		{
			this->house = std::stoi(row);
			check = true;
		}
		catch(std::invalid_argument e)
		{
			check = false;
		}
	}

	if (index == field::flat)
	{
		try
		{
			this->flat = std::stoi(row);
			check = true;
		}
		catch(std::invalid_argument e)
		{
			check = false;
		}
	}

	return check;
}
