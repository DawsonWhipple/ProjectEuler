/***********************************************
* Title:        Project Euleur Problem 14: Longest Collatz Sequence
* Author:       Dawson Whipple
* Date:         4/3/24
* Description:  The following iterative sequence is defined for the set of positive integers:
*               if n is even, n = n/2
*               if n is odd,  n = (3n+1)
*               Using the rule above and starting with 13, we generate the following sequence: 
*               13 -> 40 -> 20 -> 10  -> 5 -> 16 -> 8 -> 4 -> 2 -> 1.
*               It can be seen that this sequence (starting at 13 and finishing at 1) contains 10 terms. 
*               Although it has not been proved yet (Collatz Problem), it is thought that all starting numbers finish at 1.
*               Which starting number, under one million, produces the longest chain?
*               NOTE: Once the chain starts the terms are allowed to go above one million.
************************************************/
//Author's Notes:
//Had to change var's to long long int because some sequences go outside the integer limit
//C++
#include <iostream>
#include <math.h>

using std::cout;

//returns the length of the Collatz Sequence for the given n value
long long int findCollatzSequenceLength(long long int n){
    //length starts at 1 to account for the first number being in the sequence
    long long int length = 1;
    //loop until n is 1
    while(n != 1){
        //if n is odd
        if(n%2)
            n = 3*n + 1;
        //if n is not odd then it is even
        else
            n = n/2;
        length++;
        //cout << n << '\n';
        if(!n)
            break;
    }

    return length;
}
//finds the longest Collatz Sequence between 0 and n
int findLongestCollatzSequence(int n){
    long long int longestSequence = 0;
    int longestSequenceDigit = -1;

    for(int i = 1; i <= n; i++){
        long long int currentSequence = findCollatzSequenceLength(i);
        //store longest found, overwrite if found a new longest
        if(currentSequence > longestSequence){
            longestSequenceDigit = i;
            longestSequence = currentSequence;
            //cout << "UPDATE: longest found digit: " << longestSequenceDigit << ", length: " << longestSequence << '\n';
        }
    }
    return longestSequenceDigit;
}

int main(){
    int number = 13;
    int longestSequence = 0;
    int length = 0;
    cout << "The longest Collatz Sequence between 0 and " << number << " starts with: ";
    longestSequence = findLongestCollatzSequence(number);
    cout << longestSequence << ", and is ";
    length = findCollatzSequenceLength(longestSequence);
    cout << length << " digits long." << '\n';

    number = 1000;
    cout << "The longest Collatz Sequence between 0 and " << number << " starts with: ";
    longestSequence = findLongestCollatzSequence(number);
    cout << longestSequence << ", and is ";
    length = findCollatzSequenceLength(longestSequence);
    cout << length << " digits long." << '\n';

    number = 10000;
    cout << "The longest Collatz Sequence between 0 and " << number << " starts with: ";
    longestSequence = findLongestCollatzSequence(number);
    cout << longestSequence << ", and is ";
    length = findCollatzSequenceLength(longestSequence);
    cout << length << " digits long." << '\n';

    number = 1000000;
    cout << "The longest Collatz Sequence between 0 and " << number << " starts with: ";
    longestSequence = findLongestCollatzSequence(number);
    cout << longestSequence << ", and is ";
    length = findCollatzSequenceLength(longestSequence);
    cout << length << " digits long." << '\n';

    return 0;
}