#pragma once
#include <string>;

using namespace std; //included for the use of string


// structure created to hold arrays for movie values
struct MovieData
{
	char title[80] = "unknown";

	string Directors = "unknown";

	int yearRealase = 0;
	int runningTime = 0;

	double productionCost = 0;
	double firstYearRevenure = 0;

};