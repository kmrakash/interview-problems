/**
 *  * Input:- array of number from [0, n] in which one number is missing and one number is repeating
 *  * Output :- return missing and repeating number
**/

#include <bits/stdc++.h>
using namespace std;

// ! Using Extra Array
// ? Time Complexity : O(N)
// ? Space Complexity : O(N)
int *Method1(int arr[], int n)
{
    int temp[n + 2];
    temp[0] = -2;                   // Not Used
    for (int i = 1; i < n + 2; i++) // O(N)
        temp[i] = 0;
    int missing = -1;
    int repeating = -1;

    for (int i = 0; i < n; i++) // O(N)
    {
        if (temp[arr[i]] != -1)
            temp[arr[i]] = -1;
        else
        {
            repeating = arr[i];
        }
    }

    for (int i = 1; i < (n + 2); i++) // O(N)
    {
        if (temp[i] == 0)
        {
            missing = i;
            break;
        }
    }

    static int ans[2];
    ans[0] = repeating;
    ans[1] = missing;
    return ans;
}

// ! Using HashSet and Bit Manipulation

int *Method2(int arr[], int n)
{
    unordered_set<int> hasSet;
    for (int i = 0; i < n; i++)
        hasSet.insert(arr[i]);

    int missing = -1;
    for (int i = 1; i < n + 1; i++)
    {
        if (hasSet.find(i) == hasSet.end())
        {
            missing = i;
            break;
        }
    }

    arr[n] = missing;

    int repeating = 0;
    for (int i = 0; i < n + 1; i++)
    {
        repeating ^= (i ^ arr[i]);
    }

    static int ans[2];
    ans[0] = repeating;
    ans[1] = missing;
    return ans;
}

int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    int *ans = Method1(arr, n);

    cout << ans[0] << " " << ans[1] << "\n";
    return 0;
}