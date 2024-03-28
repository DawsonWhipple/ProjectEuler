/***********************************************
* Title:        Project Euleur Problem 7: 10001st Prime
* Author:       Dawson Whipple
* Date:         3/28/24
* Description:  By listing the first six prime numbers: 2, 3, 5, 7, 11, and 13, we can see that the 6th prime is 13.
*               What is the 10,001st prime number?
************************************************/
//Notes:
//I assumed the 10,001st prime would be much larger than it actually is
//C++
#include <iostream>
#include <math.h>

using std::cout;
//This function is being reused from problem 3
//checks if the given number is prime
bool isPrime(int value){
    bool isPrime = true;
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
//finds the nth prime, ex. 6th prime = 13
int findNthPrime(int n){
    int currentNumber = 0;
    //add 1 to n to account for the 0th index
    n++; 
    while(n){
        currentNumber++;
        if(isPrime(currentNumber)){
            n--;
        }
    }
    return currentNumber;
}

int main(){
    int nthNumber = 6;
    //could change the 'th' or 'st' depending on value but that's outside the scope of the problem
    cout << "The " << nthNumber << "th prime is: " << findNthPrime(nthNumber) << '\n';

    nthNumber = 10;
    cout << "The " << nthNumber << "th prime is: " << findNthPrime(nthNumber) << '\n';

    nthNumber = 100;
    cout << "The " << nthNumber << "th prime is: " << findNthPrime(nthNumber) << '\n';

    nthNumber = 10001;
    cout << "The " << nthNumber << "st prime is: " << findNthPrime(nthNumber) << '\n';
    return 0;
}