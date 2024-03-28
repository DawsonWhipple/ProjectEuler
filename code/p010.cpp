/***********************************************
* Title:        Project Euleur Problem 10: Summation of Primes
* Author:       Dawson Whipple
* Date:         3/28/24
* Description:  The sum of the primes below 10 is 2 + 3 + 5 + 7 = 17.
*               Find the sum of all the primes below two million.
************************************************/
//Notes:
//Took ~5 minutes to calculate answer
//was able to reuse code from problems 3 and 7 regarding prime number calculations
//had to make the answer a long long int again, theres definetly a better method to do this
//C++
#include <iostream>
#include <math.h>

using std::cout;

//This function is being reused from problem 3
//checks if the given number is prime
bool isPrime(int value){
    bool isPrime = true;

    //1 and 0 are not primes
    if(value == 1 || value == 0)
        return false;

    //check if value is prime
    for (int i = 2; i <= value/2; ++i) {
        //if value is ever divisible by i, then value is not prime
        if (value % i == 0) {
            isPrime = false;
            break;
        }
    }
    return isPrime;
}
//finds the sum of all prime numbers less than the given max number
long long int sumOfPrimesBelow(int maxNumber){
    long long int sum = 0;
    for(int i = 0; i < maxNumber; i++){
        //only add prime numbers
        if(isPrime(i))
            sum += i;
    }
    return sum;
}

int main(){
    int maxNumber = 10;
    cout << "The sum of all prime numbers less than " << maxNumber << " is: " << sumOfPrimesBelow(maxNumber) << '\n';
    maxNumber = 100;
    cout << "The sum of all prime numbers less than " << maxNumber << " is: " << sumOfPrimesBelow(maxNumber) << '\n';
    maxNumber = 2000000;
    cout << "The sum of all prime numbers less than " << maxNumber << " is: " << sumOfPrimesBelow(maxNumber) << '\n';
    return 0;
}