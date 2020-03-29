#pragma once
#include <sstream>
#include "IStringable.h"


class Date : public IStringable
{
private:
	int day;
	int month;
	int year;
public:
	Date() : day(0), month(0), year(0) {}
	Date(int _day, int _month, int _year) : day(_day),
		month(_month), year(_year)
	{
		if (day < 1 || day>31) day = 31;
		if (month < 1 || month >12) month = 12;
	}

	std::string ToString() override
	{
		std::stringstream date;
		date << day << "." << month << "." << year << " ";
		return date.str();

	}
};
