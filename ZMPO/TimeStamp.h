#pragma once
#include "Date.h"
class TimeStamp : 
	public Date
{
public:
	TimeStamp();
	TimeStamp(double secondsFrom1970);
	~TimeStamp();

	TimeStamp operator+(int hours);
	TimeStamp operator-(int hours);

	int minuteDifference(TimeStamp other);
	void setTimeStamp();
	void printTimeStamp();
private:
	int hour;
	int minute;
	int second;
};

