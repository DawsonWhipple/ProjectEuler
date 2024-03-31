/***********************************************
* Title:        Project Euleur Problem 12: Highly Divisible Triangular Number
* Author:       Dawson Whipple
* Date:         3/30/24
* Description:  The sequence of triangle numbers is generated by adding the natural numbers. So the 7th triangle number would be 1 + 2 + 3 + 4 + 5 + 6 + 7 = 28. 
                The first ten terms would be: 1, 3, 6, 10, 15, 21, 28, 36, 45, 55, ...
*               Let us list the factors of the first seven triangle numbers:
*               1:  1
*               3:  1,3
*               6:  1,2,3,6
*               10: 1,2,5,10
*               15: 1,3,5,15
*               21: 1,3,7,21
*               28: 1,2,4,7,14,28
*               We can see that 28 is the first triangle number to have over five divisors.
*               What is the value of the first triangle number to have over five hundred divisors?
************************************************/
//Notes:
//easier than I thought it'd be initially
//C++
#include <iostream>
#include <math.h>

using std::cout;

//returns the number of divisors that a given number has
int checkDivisors(int number){
    int numOfDivisors = 0;
    for(int i = 1; i <= number; i++){
        //increment if the current index is a divisor
        if(!(number % i))
            numOfDivisors++;
    }
    return numOfDivisors;
}

int searchTriangleNumbers(int numOfDivisors){
    int currentTriangleNumber = 1;
    //start at 2 for adding natural numbers, loop infinitly until the triangle number is found
    for(int i = 2; true; i++){
        if(checkDivisors(currentTriangleNumber) >= numOfDivisors)
            break;
        //adds the current index (the next natural number) to find the next triangle number
        currentTriangleNumber += i;
    }
    return currentTriangleNumber;
}

int main(){
    int numOfDivisors = 5;
    cout << "The first triangle number to have " << numOfDivisors << " divisors is: " << searchTriangleNumbers(numOfDivisors) << '\n';
    numOfDivisors = 10;
    cout << "The first triangle number to have " << numOfDivisors << " divisors is: " << searchTriangleNumbers(numOfDivisors) << '\n';
    numOfDivisors = 100;
    cout << "The first triangle number to have " << numOfDivisors << " divisors is: " << searchTriangleNumbers(numOfDivisors) << '\n';
    numOfDivisors = 500;
    cout << "The first triangle number to have " << numOfDivisors << " divisors is: " << searchTriangleNumbers(numOfDivisors) << '\n';
    return 0;
}