/*
    Input : 3 3 2 1 3 1 1
    Output : 2
*/
#include <iostream>
using namespace std;

int UniqueNumber(int arr[], int n)
{
    int bits[64] = {0};

    int mask = 1;
    int count = 0;
    for (int m = 0; m < 64; m++)
    {
        count = 0;
        mask = 1 << m;
        for (int i = 0; i < n; i++)
            if ((arr[i] & mask) > 0)
                count++;

        bits[m] = count % 3;
    }
    int ans = 0;
    int p = 1;
    for (int i = 0; i < 64; i++)
    {
        ans += (bits[i] * p);
        p *= 2;
    }
    return ans;
}

int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    cout << UniqueNumber(arr, n) << "\n";

    return 0;
}