#include "stdafx.h"
#include "Date.h"



Date::Date()
{
	secondsfrom1970 = 0;
}
Date::Date(double seconds)
{
	secondsfrom1970 = seconds;
}

Date::~Date()
{
}

Date Date::operator+(int days)
{
	double tempSeconds = 86400 * days;
	return Date(this->secondsfrom1970 + tempSeconds);
}

Date Date::operator-(int days)
{
	double tempSeconds = 86400 * days;
	return Date(this->secondsfrom1970 - tempSeconds);
}

bool Date::operator<(Date other)
{
	if (this->secondsfrom1970 < other.secondsfrom1970)
		return true;
	else
		return false;
}

bool Date::operator<=(Date other) 
{
	if (this->secondsfrom1970 <= other.secondsfrom1970)
		return true;
	else
		return false;
}

bool Date::operator>(Date other) 
{
	if (this->secondsfrom1970 > other.secondsfrom1970)
		return true;
	else
		return false;
}

bool Date::operator>=(Date other)
{
	if (this->secondsfrom1970 >= other.secondsfrom1970)
		return true;
	else
		return false;
}

bool Date::operator==(Date other) 
{
	if (this->secondsfrom1970 == other.secondsfrom1970)
		return true;
	else
		return false;
}

int Date::daysDifference(Date other)
{
	
	return (secondsfrom1970 - other.secondsfrom1970) / 86400;
}
void Date::setDate()
{
	int daysPassed = secondsfrom1970 / 86400;
	year = 1970;
	month = 1;
	day = 1;
	bool isLeap;
	int daysInMonth;
	while (1)
	{
		isLeap = (year % 4) == 0;

		for (int i = 0; i < 12; i++)
		{
			daysInMonth = months[i];

			if (i == 1 && isLeap)
				daysInMonth++;

			if (daysPassed < daysInMonth)
			{
				day = daysPassed + 1;
				daysPassed = 0;
				break;
			}

			daysPassed -= daysInMonth;
			month++;
		}
		if (daysPassed == 0)
			break;
		month = 1;
		year++;

	}



}

void Date::printDate()
{
	setDate();
	std::cout << day << "d " << month << "m " << year << "y"<<std::endl;

}
