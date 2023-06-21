#include <stdio.h>
#include "main.h"

/**
* print_remaining_days - takes a date and prints how many days are
* left in the year, taking leap years into account
* @month: month in number format
* @day: day of month
* @year: year
* Return: void
*/

void print_remaining_days(int month, int day, int year)
{
	int daysInMonth[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

	if (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0))

	{
	daysInMonth[2] = 29;   February has 29 days in a leap year
	}
	if (month < 1 || month > 12)
	{
	printf("Invalid date: %02d/%02d/%04d\n", month, day, year);
	return;
	}

	if (day < 1 || day > daysInMonth[month])
	{
	printf("Invalid date: %02d/%02d/%04d\n", month, day, year);
	return;
	}
	int dayOfYear = 0;

	for (int i = 1; i < month; i++)

	{
	dayOfYear += daysInMonth[i];
	}

	dayOfYear += day;

	printf("Day of the year: %d\n", dayOfYear);
	printf("Remaining days: %d\n", 365 + (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0)) - dayOfYear);
}

