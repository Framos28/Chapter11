/*
Francisco Ramos
Chapter 11
3/8/2023
CMPR 121
*/

//include pre and post condition!!

#include <iostream>;
#include<iomanip>
#include "input.h"
#include "movieData.h"
#include "soccerPlayer.h"
#include "corporateSalesData.h"
#include "weatherStatistics.h"
#include <iomanip>;



using namespace std;

int menuOption();
void Challenge2();
void Challenge3();
//void Challenge5();
void Challenge6();
//void Challenge8();
//void Challenge12();



int main()
{
    do
    {
        switch (menuOption())
        {
        case 0: exit(0); break;
        case 2: Challenge2(); break;
        case 3: Challenge3(); break;
        //case 5: Challenge5(); break;
        case 6: Challenge6(); break;
       // case 8: Challenge8(); break;
      //  case 12: Challenge12(); break;*/
        default: cout << "\t\tERROR - Invalid option. Please re-enter."; break;
        }
        cout << "\n";
        system("pause");
    } while (true);

    return EXIT_SUCCESS;
}

//pre condition: none
//post condition: returns int (0 - 12)
int menuOption()
{
    system("cls");

    cout << "\nChapter 11 - Created by Francisco Ramos";
    cout << "\n" << string(80, char(205));
    cout << "\n2. Movie Profit";
    cout << "\n3. Corperate Sales Data";
    cout << "\n5. Movie Profit";
    cout << "\n6. Soccer Scores";
    cout << "\n8. Movie Profit";
    cout << "\n12. Movie Profit";


    cout << "\n" << string(80, char(196));
    cout << "\n0. EXIT";
    cout << "\n" << string(80, char(205));
    

    return inputInteger("\nMake a selection: ", 0, 12);
}


void Challenge2()
{
    int size = inputInteger("\nEnter the size of the array: ", true);// only accpets pos ints
    //calls structure for 2 movies
    MovieData* movies = new MovieData[size]; //creating an array will make it easier and will require less work than movie1, movie2

    for (int i = 0; i < size; i++)
    {
        strcpy_s((movies + i)->title, inputString("\nEnter the movie name: ", true).c_str());
        movies[i].Directors = inputString("\nEnter the directors name: ", true);
        (movies + i)->yearRealase, inputInteger("\nEnter the year realeased: ", 1923, 2023);
        movies[i].runningTime = inputInteger("\nEnter the running time in mins: ", 60, 180);
        movies[i].productionCost = inputInteger("\nWhat was the production cost: ", 1, 1000000);
        movies[i].firstYearRevenure = inputInteger("\nHow much money did this film bring?", true);
    }

    for (int i = 0; i < size; i++)
    {
        cout << "\nTitle: " << (movies + i)->title; // dereferncing 
        cout << "\nDirectors: " << (movies + i)->Directors; // dereferncing 
        cout << "\Year released: " << (movies + i)->yearRealase; // dereferncing 
        cout << "\nRunning time: " << (movies + i)->runningTime; // dereferncing 
        double revenue = (movies + i)->firstYearRevenure - (movies + i)->productionCost;
        if ((movies + i)->productionCost < (movies + i)->firstYearRevenure)
        {
            cout << "\nThe movie has a profit of: $" << revenue << " Dollars.";
        }
        else
            cout << "\nThe movie has a profit loss of :$" << abs(revenue) << " Dollars."; // use the abs for absolute value of a neg number

    }
    delete[] movies;
}

void Challenge3()
{
    int size = 1; //varriable for division and quartersales

    coroperateSalesData* sales = new coroperateSalesData[size];

    for (int i = 0; i < size; i++) // retrieves the information for the divisions from the user
    {
        strcpy_s((sales + i)->divisionName, inputString("\nEnter the name of the division: ", true).c_str());
        sales[i].firstQuarterSales, inputInteger("\nHow much did the division earn this quarter? ", 1, 1000000);
        sales[i].secondQuarterSales, inputInteger("\nHow much did the division earn the second quarter? ", 1, 1000000);
        sales[i].thirdQuarterSales, inputInteger("\nHow much did the division earn the third quarter? ", 1, 1000000);
        sales[i].fourthQuarterSales, inputInteger("\nHow much did the division earn the fourth quarter? ", 1, 1000000);
       
    }

    for (int i = 0; i < size; i++) //displays every divisions information
    {
        cout << "\nDivision: " << (sales + i)->divisionName; 
        cout << "\nFirst Quarter sales: " << (sales + i)->firstQuarterSales;
        cout << "\nSecond Quarter sales: " << (sales + i)->secondQuarterSales;
        cout << "\nThird Quarter sales: " << (sales + i)->thirdQuarterSales;
        cout << "\nFourth Quarter sales: " << (sales + i)->fourthQuarterSales;

        double totalAnnualSales = (sales + i)->firstQuarterSales + (sales + i)->secondQuarterSales + (sales + i)->thirdQuarterSales + (sales + i)->fourthQuarterSales;
        double averageSales = (totalAnnualSales / size); //fix this
    }
    delete[] sales;
}

void Challenge5() // Weather Statistics
{
    int size = 12;
    //calls structure for 2 movies
    weatherStatistics* weather = new weatherStatistics[size]; //creating an array will make it easier and will require less work than movie1, movie2

    for (int i = 0; i < size; i++)
    {
        weather[i].highTemp = inputInteger("\nEnter the running time in mins: ", 60, 180);
        weather[i].lowTemp = inputInteger("\nWhat was the production cost: ", 1, 1000000);
     
    }

    for (int i = 0; i < size; i++)
    {
        cout << "\nTitle: " << (weather + i)->title; // dereferncing 
        cout << "\nDirectors: " << (movies + i)->Directors; // dereferncing 
        cout << "\Year released: " << (movies + i)->yearRealase; // dereferncing 
        cout << "\nRunning time: " << (movies + i)->runningTime; // dereferncing 
        double revenue = (movies + i)->firstYearRevenure - (movies + i)->productionCost;
        if ((movies + i)->productionCost < (movies + i)->firstYearRevenure)
        {
            cout << "\nThe movie has a profit of: $" << revenue << " Dollars.";
        }
        else
            cout << "\nThe movie has a profit loss of :$" << abs(revenue) << " Dollars."; // use the abs for absolute value of a neg number

    }
    delete[] movies;
}

void Challenge6()
{
    int playerSize = inputInteger("Enter the amount of players on the team: ", 1, 12);

    soccerPlayers* player = new soccerPlayers[playerSize]; // dynamic allocation 

    int total = 0;

    int mostScored = 0;
    int highestScored = 0;
    int index = 0;

    //input of players
    for (int i = 0; i < playerSize; i++)
    {
        (player + i)->name, inputString("\nEnter the players name: ", true);
        (player + i)->jerseyNumber, inputInteger("\nEnter the players Jersery number: ", 0, 99);
        (player + i)->pointScored, inputInteger("\nHow many goals did the player score? .", 0,10);

        total += (player + i)->pointScored;
       

        if ((player + i)->pointScored > highestScored)
        {
            highestScored = (player + i)->pointScored;
            index = i;
        }
    }

    for (int i = 0; i < playerSize; i++)
    {
        cout << setw(10) << left << player[i].jerseyNumber << setw(20) << player[i].pointScored << right << player[i].name;
           
    }

    cout << "\n\n Total scores of the team: " << total;
    cout << "\n\n Player # " << player[index].jerseyNumber << "scored the highest";

    

    delete[] player;
}

//void Challenge8()
//{
//}
//
//void Challenge12()
//{
//}
