#pragma once
#include <string>
#include <iostream>
class Date
{
public:
	Date();
	Date(double daysandseconds);
	~Date();
	//operators
	Date operator+(int days);
	Date operator-(int days);
	bool operator<(Date other);
	bool operator<=(Date other);
	bool operator>(Date other);
	bool operator>=(Date other);
	bool operator==(Date other);
	//
	int daysDifference(Date other);
	void setDate();
	void printDate();
protected:
	double secondsfrom1970;
	int day, month, year;
	int months[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
};

