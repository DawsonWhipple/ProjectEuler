/***********************************************
* Title:        Project Euleur Problem 1: Multiples of 3 or 5
* Author:       Dawson Whipple
* Date:         3/26/24
* Description:  If we list all the natural numbers below 10 that are multiples of 3 or 5, we get 3, 5, 6 and 9. The sum of these multiples is 23.
*               Find the sum of all the multiples of 3 or 5 below 1000
************************************************/
//C++
#include <iostream>

int findSum(int max){
    int sum = 0;
    for(int count = 0; count < max; count++){
        if(!(count % 3))
            sum += count;
        else if(!(count % 5))
            sum += count;
    }
    return sum;
}

int main(){
    std::cout << findSum(1000);
    return 0;
}