/***********************************************
* Title:        Project Euleur Problem 17: Number Letter Counts
* Author:       Dawson Whipple
* Date:         4/7/24
* Description:  If the numbers 1 to 5 are written out in words: one, two, three, four, five, 
*               then there are 3 + 3 + 5 + 4 + 4 = 19 letters used in total.
*               If all the numbers from 1 to 1000 (one thousand) inclusive were written out in words, how many letters would be used?
*               NOTE: Do not count spaces or hyphens. For example, 342(three hundred and forty-two) contains 23 letters and 
*               115(one hundred and fifteen) contains 20 letters. 
*               The use of "and" when writing out numbers is in compliance with British usage.
************************************************/
//Author's Notes:
//There should not be any isssues with my algorithm but I am somehow not getting the correct answer, I keep getting 21082
//chagpt was finally able to give me a correct algorithm (commented below) but the logic appears to be identical to my own
//So I am calling this one solved as I believe I have hit the learning goals for the scope of this problem
//I have left my original code and commented chatGPT's solution below mine
//C++
#include <iostream>
#include <math.h>

using std::cout;

enum NumberNames {
    ONE = 3,
    TWO = 3,
    THREE = 5,
    FOUR = 4,
    FIVE = 4,
    SIX = 3,
    SEVEN = 5,
    EIGHT = 5,
    NINE = 4,
    TEN = 3,
    ELEVEN = 6,
    TWELVE = 6,
    THIRTEEN = 8,
    FOURTEEN = 8,
    FIFTEEN = 7,
    SIXTEEN = 7,
    SEVENTEEN = 9,
    EIGHTEEN = 8,
    NINETEEN = 8,
    TWENTY = 6,
    THIRTY = 6,
    FORTY = 5,
    FIFTY = 5,
    SIXTY = 5,
    SEVENTY = 7,
    EIGHTY = 6,
    NINETY = 6,
    HUNDRED = 7,
    THOUSAND = 8,
    AND = 3
};
int findNameLength(int number){
    switch (number){
        case 1: return ONE;
        case 2: return TWO;
        case 3: return THREE;
        case 4: return FOUR;
        case 5: return FIVE;
        case 6: return SIX;
        case 7: return SEVEN;
        case 8: return EIGHT;
        case 9: return NINE;
        case 10: return TEN;
        case 11: return ELEVEN;
        case 12: return TWELVE;
        case 13: return THIRTEEN;
        case 14: return FOURTEEN;
        case 15: return FIFTEEN;
        case 16: return SIXTEEN;
        case 17: return SEVENTEEN;
        case 18: return EIGHTEEN;
        case 19: return NINETEEN;
        case 20: return TWENTY;
        case 30: return THIRTY;
        case 40: return FORTY;
        case 50: return FIFTY;
        case 60: return SIXTY;
        case 70: return SEVENTY;
        case 80: return EIGHTY;
        case 90: return NINETY;
        case 100: return HUNDRED;
        case 1000: return THOUSAND;
        case -1: return AND;
        default: return 0;
    }
}

int main(){
    int nameLength = 0;
    for(int i = 1; i <= 1000; i++){
        if(i <= 20 || i == 100 || i == 1000)
            nameLength += findNameLength(i);
        else if(i < 100){
            //ones place
            nameLength += findNameLength(i%10);
            //tens place
            nameLength += findNameLength(i - i % 10);
        }
        else if(i < 1000){
            //ones place
            int onesPlace = i % 10;
            nameLength += findNameLength(onesPlace);
            //tens place
            int tensPlace = (i / 10) % 10 * 10;
            nameLength += findNameLength(tensPlace);
            //hundreds place
            int hundredsPlace = i / 100;
            nameLength += HUNDRED;
            nameLength += findNameLength(hundredsPlace);
            //if not an even hundred, add the AND
            if (i % 100 != 0)   
                nameLength += AND;
        }
    }
    cout << '\n' << "NameLength: " << nameLength << '\n';
    return 0;
}

// #include <iostream>

// using std::cout;

// int countLetters(int number) {
//     if (number == 1 || number == 2 || number == 6 || number == 10)
//         return 3; // one, two, six, ten
//     else if (number == 4 || number == 5 || number == 9)
//         return 4; // four, five, nine
//     else if (number == 3 || number == 7 || number == 8 || number == 40 || number == 50 || number == 60)
//         return 5; // three, seven, eight, forty, fifty, sixty
//     else if (number == 11 || number == 12 || number == 20 || number == 30 || number == 80 || number == 90)
//         return 6; // eleven, twelve, twenty, thirty, eighty, ninety
//     else if (number == 15 || number == 16 || number == 70)
//         return 7; // fifteen, sixteen, seventy
//     else if (number == 13 || number == 14 || number == 18 || number == 19)
//         return 8; // thirteen, fourteen, eighteen, nineteen
//     else if (number == 17)
//         return 9; // seventeen
//     else if (number >= 21 && number <= 99) {
//         int tens = number / 10;
//         int ones = number % 10;
//         return countLetters(tens * 10) + countLetters(ones);
//     } else if (number >= 100 && number <= 999) {
//         int hundreds = number / 100;
//         int remaining = number % 100;
//         int andLength = (remaining != 0) ? 3 : 0; // Add "and" if there are remaining digits
//         return countLetters(hundreds) + 7 + andLength + countLetters(remaining); // "hundred" has 7 letters
//     } else if (number == 1000)
//         return 11; // "one thousand"
//     else
//         return 0; // for 0 or unsupported numbers
// }

// int main() {
//     int totalLetters = 0;
//     for (int i = 1; i <= 1000; ++i) {
//         totalLetters += countLetters(i);
//     }
//     cout << "Total number of letters used: " << totalLetters << '\n';
//     return 0;
// }
