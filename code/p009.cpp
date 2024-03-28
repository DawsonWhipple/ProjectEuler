/***********************************************
* Title:        Project Euleur Problem 9: Special Pythagorean Triplet
* Author:       Dawson Whipple
* Date:         3/28/24
* Description:  A Pythagorean triplet is a set of three natural numbers, a < b < c, for which, a^2 + b^2 = c^2
*               For example, 3^2 + 4^2 = 9 + 16 = 25 = 5^2.
*               There exists exactly one Pythagorean triplet for which a + b + c = 1000.
*               Find the product abc.
************************************************/
//Notes:
//If there are multiple possible pythagorean triplets for a given DESIRED_NUM then I don't think this solution will work correctly
//However I am not going to worry about this because that is outside the scope of this problem
//C++
#include <iostream>
#include <math.h>

using std::cout;

#define DESIRED_SUM 1000

//taken from problem 6
//return the squared value of the number given
int squareNumber(int number){
    //square the sum
    return pow(number, 2);
}

//This function ended up being uneccasary as I actually generated pythagorean triplet
//so I did not have to check numbers
//checks if the given values make a pythagorean triplet
// bool isPythagoreanTriplet(int a, int b, int c){
//     //a^2 + b^2 = c^2
//     return (squareNumber(a) + squareNumber(b) == squareNumber(c));
// }

//calculates the c value in the equation a^2 + b^2 = c^2
double calculateC(int a, int b){
    int aSquared = squareNumber(a);
    int bSquared = squareNumber(b);
    // cout << "a squared: " << aSquared << "b squared: " << bSquared << '\n';
    double cSquared = squareNumber(a) + squareNumber(b);
    return sqrt(double(cSquared));
}

int findProductFor(int number){
    double c;
    int product = 0;
    //compare numbers, creates a pythagorean triplet out of current iteration count of loops
    for(int a = 1; a < number; a++){
        for(int b = a; b < number; b++){
            c = calculateC(a, b);
            //check the sum
            if(a + b + c == number){
                product = a*b*c;
            }
        }   
    }
    return product;
}

int main(){
    cout << "The product of the pythagorean triplet that sums to " << DESIRED_SUM << " is: " << findProductFor(DESIRED_SUM);
    return 0;
}