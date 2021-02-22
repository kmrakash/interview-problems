// Condition : Atleast one element must be present in the input array
#include <bits/stdc++.h>
using namespace std;

// Debugging
#define deb(x) cout << #x << " " << x << '\n'

// ! Using Three loops
// ? Time Complexity : O(N^3)
// ? Space Complexity : O(1)
int Method1(int arr[], int n)
{
    int sum = 0;
    int max_sum = INT32_MIN;

    for (int i = 0; i < n; i++) // O(N*N*N)
    {
        for (int j = 0; j < n; j++)
        {
            sum = 0;
            for (int k = i; k <= j; k++)
            {
                sum += arr[k];
                max_sum = max(max_sum, sum);
                if (sum < 0)
                    sum = 0;
            }
        }
    }
    return max_sum;
}

// ! Using two loops
// ? Time Complexity : O(N^2)
// ? Space Complexity : O(1)
int Method2(int arr[], int n)
{
    int sum = 0;
    int max_sum = INT32_MIN;

    for (int i = 0; i < n; i++) // O(N^2)
    {
        sum = 0;
        for (int j = i; j < n; j++)
        {
            sum += arr[j];
            max_sum = max(max_sum, sum);
            if (sum < 0)
                sum = 0;
        }
    }
    return max_sum;
}

// ! Kandane Algorithm
// ? Time Complexity : O(N)
// ? Space Complexity : O(1)
int Method3(int arr[], int n)
{
    int sum = 0;
    int max_ending_here = arr[0]; // Since atleast one element must be present in the array

    for (int i = 0; i < n; i++) // )(N)
    {
        sum += arr[i];
        //deb(sum);
        max_ending_here = max(max_ending_here, sum);
        if (sum < 0)
            sum = 0;
        //deb(max_ending_here);
    }

    return max_ending_here;
}

int main()
{
    //Take Standard Input
    int n;
    cin >> n;
    int a[n + 1];
    for (int i = 0; i < n; i++)
        cin >> a[i];

    // Applying Logic
    int res = Method2(a, n);

    // Printing Output result
    cout << res << '\n';
    return 0;
}