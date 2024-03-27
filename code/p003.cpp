/***********************************************
* Title:        Project Euleur Problem 3: Largest Prime Factor
* Author:       Dawson Whipple
* Date:         3/27/24
* Description:  The prime factors of 13195 are 5, 7, 13 and 29.
*               What is the largest prime factor of the number 600,851,475,143?
************************************************/
//Note:
//This code is incredibly inefficient, took about an hour to calculate the answer.
//However it was infact able to find the correct answer.
//C++
#include <iostream>

//checks if the given number is prime
bool isPrime(long long int value){
    bool isPrime = true;
    //check if value is prime
    for (long long int i = 2; i <= value/2; ++i) {
        //std::cout << i << " ";
        //if value is ever divisible by i, then value is not prime
        if (value % i == 0) {
            isPrime = false;
            break;
        }
        //std::cout << i;
    }
    //std::cout << isPrime;
    return isPrime;
}

long long int largestPrimeFactor(long long int value){
    long long int largestPrime = 0;

    //loop through all values less than value/2 in descending order
    //the first prime factor found will be the largest prime factor
    for(long long int count = value/2 + 1; count > 0; count--){
        //if the value is divisble by the current count
        if(!(value % count)){
            //std::cout << count << " ";
            //if the count was found to be prime, it is the largest prime factor 
            if(isPrime(count)){
                largestPrime = count;
                break;
            }
            //std::cout << largestPrime;
        }
    }
    return largestPrime;
}

int main(){
    //600851475143
    std::cout << "Largest Prime Factor of 13195: " << largestPrimeFactor(13195) << '\n';
    std::cout << "Largest Prime Factor of 1315295: " << largestPrimeFactor(1315295) << '\n';
    std::cout << "Largest Prime Factor of 600851475143: " << largestPrimeFactor(600851475143) << '\n';
    //std::cout << "Is 600851475143 Prime?: " << isPrime(600851475143) << '\n';
    return 0;
}