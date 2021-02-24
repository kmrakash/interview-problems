#include <iostream>
using namespace std;

int convertToBinary(int n)
{
    int p = 1;
    int binary = 0;
    while (n)
    {
        binary += (n & 1) * p;
        n >>= 1;
        p *= 10;
    }
    return binary;
}

int main()
{
    int decimal;
    cin >> decimal;

    cout << convertToBinary(decimal) << "\n";
    return 0;
}