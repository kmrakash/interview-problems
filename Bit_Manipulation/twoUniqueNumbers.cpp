/*
    Input array must contain atleast two unique number
    Example : Input -> 5 2 1 2 3 5 7
              Output -> 3 7
*/
#include <iostream>
#include <cassert>
using namespace std;
#define deb(x) cout << #x << " " << x << "\n";

int getLastBit(int n)
{
    int i = 0;
    while (n > 0)
    {
        if (n & 1 == 1)
            break;
        else
        {
            n >>= 1;
            i++;
        }
    }
    return i;
}

int setBit(int n, int i)
{
    return (n & (1 << i)) > 0;
}

void UniqueNumbers(int arr[], int n)
{
    int res = 0;
    for (int i = 0; i < n; i++)
    {
        res = res ^ arr[i];
    }
    // deb(res);
    int last_bit = getLastBit(res);
    // deb(last_bit);
    int a = 0;
    for (int i = 0; i < n; i++)
    {
        if (setBit(arr[i], last_bit))
        {
            a ^= arr[i];
            //deb(arr[i]);
        }
    }
    int b = res ^ a;
    cout << a << " " << b << "\n";
}

int main()
{
    assert(getLastBit(4) == 2);
    assert(getLastBit(5) == 0);
    assert(setBit(4, 2) == 1);
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    UniqueNumbers(arr, n);
    return 0;
}