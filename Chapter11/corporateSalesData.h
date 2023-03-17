#pragma once

struct coroperateSalesData // structure that holds finanical information based on coroperate division sales
{
	char divisionName[80] = "Unknown";

	int firstQuarterSales = 4;

	int secondQuarterSales = 0;

	int thirdQuarterSales = 0;

	int fourthQuarterSales = 0;

	double totalAnnualSales = 0;

	double averageQuaterlySales = 0;

};