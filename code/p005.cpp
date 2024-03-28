/***********************************************
* Title:        Project Euleur Problem 5: Smallest Multiple
* Author:       Dawson Whipple
* Date:         3/28/24
* Description:  2520 is the smallest number that can be divided by each of the numbers from 1 to 10 without any remainder.
*               What is the smallest positive number that is evenly divisible by all of the numbers from to 1 to 20?
************************************************/
//Notes:
//accidentally divided and modulused by 0 to start and was getting errors
//changed values i and number to start at 1 and fixed problem
//
//This code does not work for maxSearch values > than 23 as the output number is larger than the integer limit
//Could make it work with long long int but that's outside the scope of the problem
//C++
#include <iostream>
#include <math.h>

using std::cout;
//compares number to see if it is divisble by all numbers 1 to maxSearch
bool compareNumbers(int number, int maxSearch){
    bool isDivisible = true;
    for(int i = 1; i < maxSearch; i++){
        //if any value is not divisible, then this number is not valid
        if(number % i){
            isDivisible = false;
            break;
        }
    }
    return isDivisible;
}
//finds the smallest number that is evenly divisble by all numbers from 1 to maxSearch
int findSmallestMultiple(int maxSearch){
    int number = 1;
    bool found = false;
    while(!found){
        if(compareNumbers(number, maxSearch))
            found = true;
        else number++;
    }
    return number;
}

int main(){
    //variable to store the max number to check all smaller numbers for divisibility
    int evenlyDivisbleBy = 10;
    cout << "The largest number that is evenly divisible be all numbers less than " 
         << evenlyDivisbleBy << " is: " << findSmallestMultiple(evenlyDivisbleBy) << '\n';
    evenlyDivisbleBy = 20;
    cout << "The largest number that is evenly divisible be all numbers less than " 
         << evenlyDivisbleBy << " is: " << findSmallestMultiple(evenlyDivisbleBy) << '\n';
    evenlyDivisbleBy = 24;
    cout << "The largest number that is evenly divisible be all numbers less than " 
         << evenlyDivisbleBy << " is: " << findSmallestMultiple(evenlyDivisbleBy) << '\n';
    return 0;
}