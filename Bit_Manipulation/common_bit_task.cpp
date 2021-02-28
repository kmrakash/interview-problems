#include <iostream>
#include <cassert>
using namespace std;

void checkEvenOdd(int N)
{
    if (N & 1) // Bit Masking
        cout << "ODD"
             << "\n";
    else
        cout << "EVEN"
             << "\n";
}

// * To check Even And Odd
bool isOdd(int n)
{
    return (n & 1);
}

// * To get bit value of ith position : position starts from 0th index
int getBit(int n, int i)
{
    return (((1 << i) & n) > 0);
}

// * To set the bit value of ith position
// ? bit of 1 : 0 0 0 0 0 0 0 1
// ? Example : n = 5 ( 0 0 0 0 0 1 0 1 ) , i = 2
// ?           mask = 0 0 0 0 0 1 0 0   returns a positive number if ith position is set else 0
int setBit(int n, int i)
{
    int mask = 1 << i;
    int ans = n | mask;
    return ans;
}

/**
 * * To clear the bits of first i position
 * ? bit of -1 : 1 1 1 1 1 1 1 1
 * 
 *  Example : n = 21 ( 0 0 0 1 0 1 0 1 ) , i = 2
 *            mask =   1 1 1 1 1 1 0 0 
 *            ans =    0 0 0 1 0 1 0 0 -> 20 (n AND mask)
 **/
int clearBits(int n, int i)
{
    int mask = -1 << i;
    int ans = n & mask;
    return ans;
}

// * To clear the bits from ith position to jth position
/**
 *  Example : n = 31 ( 0 0 0 1 1 1 1 1 ) , i=1 , j = 3
 *            mask = ( 1 1 1 1 0 0 0 1 )
 *            ans =  ( 0 0 0 1 0 0 0 1 ) -> 17 (n AND mask)
 * 
 *          Creation of mask :
 *                           a = 1 1 1 1 0 0 0 0
 *                           b = 0 0 0 0 0 0 0 1
 *                        mask = 1 1 1 1 0 0 0 1 (a OR b)
 **/
int clearBitsRangeIToJ(int n, int i, int j)
{
    int ones = (~0); // 1 1 1 1 1 1 1 1
    int a = ones << (j + 1);
    int b = (1 << i) - 1;
    int mask = a | b;
    int ans = n & mask;
    return ans;
}

int main()
{
    // int number, i;
    // cin >> number >> i;

    // checkEvenOdd(number);
    // cout << isOdd(number) << "\n";
    assert(isOdd(5) == 1);
    assert(isOdd(10) == 0);
    assert(getBit(5, 2) == 1);
    assert(getBit(5, 1) == 0);
    assert(setBit(5, 2) == 5);
    assert(setBit(5, 1) == 7);
    assert(clearBits(21, 2) == 20);
    assert(clearBits(21, 3) == 16);
    assert(clearBits(15, 2) == 12);
    assert(clearBitsRangeIToJ(31, 1, 3) == 17);
    assert(clearBitsRangeIToJ(63, 2, 3) == 51);
    cout << "You are all Good"
         << "\n";
    return 0;
}