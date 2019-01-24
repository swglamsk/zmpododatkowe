// ZMPO.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Date.h"
#include "TimeStamp.h"

int main()
{

	Date date3 = Date(1548294371);
	Date date = Date(1548294371);
	Date date2 = Date(1327369571);
	date.printDate();
	date2.printDate();
	(date - 20).printDate();
	(date2 + 20).printDate();
	std::cout << (date > date2) << std::endl;
	std::cout << (date < date2) << std::endl;
	std::cout << (date == date3) << std::endl;

	TimeStamp timestamp = TimeStamp(1327369571);
	TimeStamp timestamp2 = TimeStamp(1548294371);

	timestamp.printTimeStamp();
	timestamp2.printTimeStamp();
	timestamp.printDate();
	(timestamp - 20).printTimeStamp();
	(timestamp2 + 10).printTimeStamp();

	
    return 0;
}

