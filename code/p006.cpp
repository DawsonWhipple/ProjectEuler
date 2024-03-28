/***********************************************
* Title:        Project Euleur Problem 6: Smallest Multiple
* Author:       Dawson Whipple
* Date:         3/28/24
* Description:  The sum of the squares of the first ten natural numbers is,
*               1^2 + 2^2 + ... + 10^2 = 385.
*               The square of the sum of the first ten natural numbers is,
*               (1 + 2 + ... + 10)^2 = 55^2 = 3025.
*               Hence the difference between the sum of the squares of the first ten natural numbers and the square of the sum is 3025 - 385 = 2640.
*               Find the difference between the sum of the squares of the first one hundred natural numbers and the square of the sum.
************************************************/
//Notes:
//runtime on this one is quite good, no noticible delay, atleast for the desired output
//C++
#include <iostream>
#include <math.h>

using std::cout;

//return the squared value of the number given
int squareNumber(int number){
    //square the sum
    return pow(number, 2);
}

//add all squared values from 1 - amountOfNumbers together, return value 
int sumOfSquares(int amountOfNumbers){
    int sum = 0;
    //add all numbers from 1 to amountOfNumbers together
    for(int i = 1; i <= amountOfNumbers; i++){
        //square initial number before adding
        sum += squareNumber(i);
    }
    return sum;
}
//add all values from 1 - amountOfNumbers together, then square final sum, return squared sum
int squareOfSum(int amountOfNumbers){
    int sum = 0;
    //add all numbers from 1 to amountOfNumbers together
    for(int i = 1; i <= amountOfNumbers; i++){
        sum += i;
    }
    //square the sum and return value
    return squareNumber(sum);
}

//returns the difference between the two given numbers
int findDifference(int num1, int num2){
    if(num1 > num2)
        return num1 - num2;
    else
        return num2 - num1;
}

//could pull this out into it's own function but would require changing to reference values
//outside the scope of this problem
// int findDifferenceBetweenSquares(int amountOfNumbers){
//     int squareSum = squareOfSum(amountOfNumbers);
//     int sumSquares = sumOfSquares(amountOfNumbers);
//     int difference = findDifference(squareSum, sumSquares);

//     return difference;
// }

int main(){
    //variable to store the max number to check all smaller numbers for divisibility
    int amountOfNumbers = 10;
    int squareSum = squareOfSum(amountOfNumbers);
    int sumSquares = sumOfSquares(amountOfNumbers);
    int difference = findDifference(squareSum, sumSquares);

    cout << "The sum of the squares of all numbers between 1 and " << amountOfNumbers << " is: " << sumSquares << '\n';
    cout << "The square of the sum of all numbers between 1 and " << amountOfNumbers << " is: " << squareSum << '\n';
    cout << "The difference between " << squareSum << " and " << sumSquares << " is: " << difference << '\n';

    amountOfNumbers = 100;
    squareSum = squareOfSum(amountOfNumbers);
    sumSquares = sumOfSquares(amountOfNumbers);
    difference = findDifference(squareSum, sumSquares);

    cout << "The sum of the squares of all numbers between 1 and " << amountOfNumbers << " is: " << sumSquares << '\n';
    cout << "The square of the sum of all numbers between 1 and " << amountOfNumbers << " is: " << squareSum << '\n';
    cout << "The difference between " << squareSum << " and " << sumSquares << " is: " << difference << '\n';

    return 0;
}