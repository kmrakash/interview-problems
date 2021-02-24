/**
 *  Given two 32-bit number N and M . Your task is insert M in N from ith position to jth Position
 *  Example : N = 1 0 1 0 0 0 0 0 0 0 1 , 
 *            M = 1 0 1 0 1 , i = 2 and j = 6
 * Expected Output : 1 0 1 0 1 0 1 0 1 0 1
 *  position:                6 5 4 3 2  
 *
 * 
 **/

#include <iostream>
using namespace std;
#define deb(x) cout << #x << " " << x << "\n"

int clearBitsRangeIToJ(int n, int i, int j)
{
    int ones = (~0); // 1 1 1 1 1 1 1 1
    int a = ones << (j + 1);
    int b = (1 << i) - 1;
    int mask = a | b;
    int ans = n & mask;
    return ans;
}

int replaceBits(int N, int M, int i, int j)
{
    int N_ = clearBitsRangeIToJ(N, i, j);
    return N_ | (M << i);
}

int main()
{
    int N, M, i, j;
    cin >> N >> M >> i >> j;
    cout << replaceBits(N, M, i, j) << "\n";
    return 0;
}