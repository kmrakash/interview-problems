/*

    A good Subarrays is a subarray whose sum is divisible by N , where N is Number of element in arrayp

    ! Solving Technique : Pigeonhole Principle
*/

#include <iostream>
#include <unordered_map>
#include <algorithm>
#include <cassert>
using namespace std;

long long Nc2(int n)
{

    int r = 2;
    long long p = 1, k = 1;
    if (n - r < r)
        r = n - r;

    if (r != 0)
    {
        while (r)
        {
            p *= n;
            k *= r;
            long long m = __gcd(p, k);
            p /= m;
            k /= m;

            n--;
            r--;
        }
    }

    else
        p = 1;

    return p;
}

int CountGoodSubArray(int arr[], int n)
{
    int cum[n + 1]; // Cummulative sum
    cum[0] = 0;
    int cumSUm = 0;
    for (int i = 0; i < n; i++)
    {
        cumSUm += arr[i];
        cum[i + 1] = cumSUm % n;
    }

    // frequency
    unordered_map<int, int> freq;
    for (int i = 0; i <= n; i++)
    {
        freq[cum[i]]++;
    }

    long long sum = 0;
    for (auto f : freq)
    {
        if (f.second >= 2)
        {
            sum += Nc2(f.second);
        }
    }

    return sum;
}

int main()
{

    //Testing Some Test Case
    int a1[] = {1, 3, 2, 6, 4};
    assert(CountGoodSubArray(a1, 5) == 3);

    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    cout << CountGoodSubArray(arr, n) << "\n";

    return 0;
}