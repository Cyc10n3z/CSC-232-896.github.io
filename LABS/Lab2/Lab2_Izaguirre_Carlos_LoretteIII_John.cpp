/*------------------------------------------------------------------------------------
 * Author:        Carlos Izaguirre  and  John Lorette III
 * Date:          6/15/2020
 * Trace Folder:  LABS\Lab2\
 * File Name:     Lab2_Izaguirre_Carlos_LoretteIII_John.cpp
 * Description:   C++ Program that uses an array of structures to store weather data 
 *                for every month of the year, and then cacluclates the totals for each
 *                weather data for the entire year.
 ------------------------------------------------------------------------------------*/
#include<iostream>
#include<memory>
using namespace std;

//Structure for a particular month's weather data
struct Weather{
   double totalRainfall;
   double averageTemp;
};
//Enumerator for all the months in a year
enum Month {
    JANUARY, FEBRUARY, MARCH, APRIL, MAY, JUNE, JULY,
    AUGUST, SEPTEMBER, OCTOBER, NOVEMBER, DECEMBER
};
//Function prototype(s)
Weather yearlyWeatherData(const Weather[]);
string getMonthName(Month);

//The program's main method, or control function
int main() {
   //Variable(s) for an array of 'Weather' structures
   const int NUM_MONTHS = 12;
   Weather monthlyWeather[NUM_MONTHS], yearlyWeather;
   //C26812 Warning: The enum type 'Month' is unscoped. Prefer 'enum class' over 'enum'(Enum.3).
   Month monthly;//Enum loop counter 
   string monthName = "";//String representation of a month
   
   //Get the weather data for each month as input from the user
   for (monthly = JANUARY; monthly <= DECEMBER; monthly = static_cast<Month>(monthly + 1)) {
      monthName = getMonthName(monthly);
      cout << "Enter the total rainfall in inches for the month of " + monthName + ": ";
      cin >> monthlyWeather[monthly].totalRainfall;
      
      cout << "Enter the average temperature in Fahrenheit for the month of " + monthName + ": ";
      cin >> monthlyWeather[monthly].averageTemp;
      cout << endl;
   }
   //Call the "yearlyWeatherData()" function to calculate and then display the weather data for the year
   yearlyWeather = yearlyWeatherData(monthlyWeather);
   cout << "\n\nThe total yearly rainfall is: " << yearlyWeather.totalRainfall;
   cout << "\nThe average yearly daytime temperature is: " << yearlyWeather.averageTemp;
   cout << endl;
   //Exit the main function, with 0 indicating success   
   return 0;
}
/**
   Function "yearlyWeatherData()" accepts an array of structures for a year's weather data. Then
   the function calculates the total rainfall and average temperature for the entire year. Return
   a structure of the same type with all the aggregate data for the total year.
   
   @param -- monthlyWeather[] (Array of 'Weather' structures)
   @return -- totalYear (Structure for the whole years calculated 'Weather' data)
*/
Weather yearlyWeatherData(const Weather monthlyWeather[]) {
   //Variable(s) for calculating the total rainfall and average temperature for the whole year
   Weather totalYear = {0.0, 0.0};
   Month month;

   //Calculate the total rainfall and average temperature for the whole year
   for (month = JANUARY; month <= DECEMBER; month = static_cast<Month>(month + 1)) {
      totalYear.totalRainfall += monthlyWeather[month].totalRainfall;
      totalYear.averageTemp += monthlyWeather[month].averageTemp;
   }
   totalYear.averageTemp /= 12;
   //Return the 'totalYear' Weather structure
   return totalYear;
}
/**
   Function "getMonthName()" takes a month's enumerator as a parameter and then
   returns the corresponding months name as a string.

   @param -- Month m (Enumerator object)
   @return -- name (String representation of 'm' month)
*/
string getMonthName(Month m) {
   //Switch statement for returning the month as a string from an Enumerator object 'm'
   switch (m)
   {
      case JANUARY:     return "January";
                        break;
      case FEBRUARY:    return "February";
                        break;
      case MARCH:       return "March";;
                        break;
      case APRIL:       return "April";
                        break;
      case MAY:         return "May";
                        break;
      case JUNE:        return "June";
                        break;
      case JULY:        return "July";
                        break;
      case AUGUST:      return "August";
                        break;
      case SEPTEMBER:   return "September";
                        break;
      case OCTOBER:     return "October";
                        break;
      case NOVEMBER:    return "November";
                        break;
      case DECEMBER:    return "December";
                        break;
      default:          return "Error.";//Default case as an "Error"?
                        break;
   }
   //IF there is any other value for 'm' outside the switch statement
   return "That is not a month of the year.";
}