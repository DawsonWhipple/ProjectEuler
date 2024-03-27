/***********************************************
* Title:        Project Euleur Problem 4: Largest Palindrome Product
* Author:       Dawson Whipple
* Date:         3/27/24
* Description:  A palindromic number reads the same both ways. The largest palindrome made from the product of two 2-digit numbers is 9009 = 91 * 99.
*               Find the largest palindrome made from the product of two 3-digit numbers.
************************************************/
//Notes:
//I assumed that the first found palindrome would be the largest but that ended up to not necassarily be true
//compute time is reasonable for the required calculation but scaling will become very slow
//even at only 4 digits it takes more than a second to compute
//could create a class for these functions but thats outside the scope of requirements for this project
//C++
#include <iostream>
#include <math.h>
using std::cout;

//finds if the given value is a palindrome
bool isPalindrome(int num){
    int n = num;
    int rev = 0;
    int digit;
    //create a reversed number to compare for palindrome
    do{
        digit = num % 10;
        rev = (rev * 10) + digit;
        num = num / 10;
    } while (num != 0);

    if(n == rev)
        return true;
    else return false;
}

//finds the largest number of the given amount of digits
//ex. amountOfDigits = 3, max = 999
int findMax(int amountOfDigits){
    int max = 0;
    int placeCount = 1;
    //sets the maximum number to be all 9's for length of amount of digits
    while(amountOfDigits){
        max += 9*placeCount;
        placeCount *= 10;
        amountOfDigits--;
    }
    return max;
}

//finds the largest palindrome between two values of length of digits
int findLargestPalindrome(int amountOfDigits){
    //the maximum number to search based on the amount of digits in the two multiples
    int max = findMax(amountOfDigits);
    int largestPalindrome = -1;
    for(int i = max; i > 0; i--){
        for(int j = i; j > 0; j--){
           int currentNum = i * j;
            //compares all values found because the first palindrome is not necassarily the largest palindrome
            if(!isPalindrome(currentNum))
                continue;
            if(largestPalindrome < currentNum)
                largestPalindrome = currentNum;
        }
    }
    return largestPalindrome;
}   

int main(){
    int amountOfDigits = 2;
    cout << "Largest Palindrome for " << amountOfDigits << " digits: " << findLargestPalindrome(amountOfDigits) << '\n';
    amountOfDigits = 3;
    cout << "Largest Palindrome for " << amountOfDigits << " digits: " << findLargestPalindrome(amountOfDigits) << '\n';
    amountOfDigits = 4;
    cout << "Largest Palindrome for " << amountOfDigits << " digits: " << findLargestPalindrome(amountOfDigits) << '\n';
    return 0;
}