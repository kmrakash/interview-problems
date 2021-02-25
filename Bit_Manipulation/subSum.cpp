/*
    To determine number of subsets (inlcluding empty subsets) with sum in range [A, B];
    Input : 3 -1 2
            1
            -2
            3
    Output : 5
    Explanation: 1, 0, (-2, 3), (1, -2), (1, -2, 3)  
*/

#include <iostream>
using namespace std;
int main()
{
    int n, a, b;
    cin >> n >> a >> b;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int bitlenght = 1 << n;
    int mask = 1;
    int count = 0;
    for (int i = 0; i < bitlenght; i++) // (O(2^n(Logn)))
    {
        mask = 1 << i;
        int sumSub = 0;
        int j = 0;
        while (mask)
        {
            if (mask & arr[i])
            {
                sumSub += arr[j];
            }
            mask <<= 1;
            j++;
        }
        if (sumSub >= a and sumSub <= b)
            count++;
    }

    cout << count << "\n";
    return 0;
}