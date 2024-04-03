/***********************************************
* Title:        Project Euleur Problem 12: Highly Divisible Triangular Number
* Author:       Dawson Whipple
* Date:         4/2/24
* Description:  Starting from a positive integer n, at each step we subtract from n the largest perfect cube not exceeding n, until n becomes 0.
*               For example, with n = 100 the procedure ends in 4 steps
*               100 ->{-4^3} 36 ->{-3^3} 9 ->{-2^3} 1 ->{-1^3} 0.
*               Let D(n) denote the number of steps of the procedure. Thus D(100) = 4.
*               Let S(N) denote the sum of D(n) for all positive integers n strictly less than N.
*               For example, S(100) = 512.
*
*               Find S(10^{17}).
************************************************/
//Notes:
//DOES NOT WORK, code is functional but compute time is wayyy too long 
//Need to come up with a more efficient algorithm
//NOT SOLVED
//C++
#include <iostream>
#include <math.h>

using std::cout;

//returns the largest perfect cube less than the value of number
long long int largestPerfectCube(long long int number){
    //start from the highest possible perfect cube number, if the given number is perfect cube
    if(number == 1)
        return 1;
    for(long long int current = 1; current <= number; current++){
        //once current exceeds number then the previous value will be the alrgest perfect cube
        if((current * current * current) > number){
            current--;
            return (current * current * current);
        }
    }
    return 0;
}
//returns the largest perfect cube less than the value of number
int numberOfSteps(long long int number){
    int steps = 0;
    int n = number;
    while(n){
        steps++;
        n -= largestPerfectCube(n);
        //cout << n;
        //cout << "test: " << number;
    }
    return steps;
}
//returns the sum of all perfect cubes less than the value of number
long long int sumOfPerfectCubes(long long int number){
    long long int sum = 0;
    for(long long int current = number-1; current >= 1; current--){
        sum += numberOfSteps(current);
    }
    return sum;
}

int main(){
    //10^17
    //should be using arrays but long long int happens to work for now
    // int number[18] = {0};
    // number[0] = 1;

    long long int num = 63;

    cout << "Largest perfect cube of " << num << " is: " << largestPerfectCube(num);
    cout << " It takes " << numberOfSteps(num) << " steps to get to 0" <<'\n';
    cout << "Sum of largest perfect cubes of " << num << " is: " << sumOfPerfectCubes(num) << '\n';
    num = 64;
    cout << "Largest perfect cube of " << num << " is: " << largestPerfectCube(num);
    cout << " It takes " << numberOfSteps(num) << " steps to get to 0" <<'\n';
    cout << "Sum of largest perfect cubes of " << num << " is: " << sumOfPerfectCubes(num) << '\n';
    num = 100;
    cout << "Largest perfect cube of " << num << " is: " << largestPerfectCube(num);
    cout << " It takes " << numberOfSteps(num) << " steps to get to 0" <<'\n';
    cout << "Sum of largest perfect cubes of " << num << " is: " << sumOfPerfectCubes(num) << '\n';
    //max:9223372036854775807 value for long long int
    num = 10000000000000000;
    cout << "Largest perfect cube of " << num << " is: " << largestPerfectCube(num);
    cout << " It takes " << numberOfSteps(num) << " steps to get to 0" <<'\n';
    cout << "Sum of largest perfect cubes of " << num << " is: " << sumOfPerfectCubes(num) << '\n';

    return 0;
}