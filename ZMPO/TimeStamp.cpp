#include "stdafx.h"
#include "TimeStamp.h"


TimeStamp::TimeStamp()
{
}

TimeStamp::TimeStamp(double secondsPassed) : Date(secondsPassed)
{

}

TimeStamp::~TimeStamp()
{
}

TimeStamp TimeStamp::operator+(int hours)
{
	return TimeStamp(this->secondsfrom1970 + (3600 * hours));
}

TimeStamp TimeStamp::operator-(int hours)
{
	return TimeStamp(this->secondsfrom1970 - (3600 * hours));
}
int TimeStamp::minuteDifference(TimeStamp other)
{
	return (secondsfrom1970 / 60) - (other.secondsfrom1970 / 60);
}

void TimeStamp::setTimeStamp()
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
	
	int seconds = ((int)secondsfrom1970 % 86400);
	hour = seconds / 3600;
	minute = (seconds % 3600) / 60;
	second = (seconds % 3600) % 60;


}

void TimeStamp::printTimeStamp()
{
	setTimeStamp();
	std::cout << day << "d " << month << "m " << year << "y " << hour << "h " << minute << "m " << second << "s" << std::endl;

}