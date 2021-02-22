//* Test Case are only valid if atleast 0 or 1 is present and only one number is missing in range [0, N]
// * Every element is unique in the test case

#include <bits/stdc++.h>
using namespace std;

// ! Sorting Approach
// ? Time Complexity : O(NlogN)
// ? Space Complexity : O(1)
int Method1(int arr[], int N)
{
    sort(arr, arr + N); // O(NlogN)
    // Handling Base Cases
    if (arr[N - 1] != N)
        return N;
    if (arr[0] != 0)
        return 0;

    for (int i = 1; i < N; i++) // O(N)
    {
        int expectedNum = arr[i - 1] + 1;
        if (expectedNum != arr[i])
            return expectedNum;
    }
    return -1; // No Missing Number
}

// ! Using HashSet
// * Fun Fact: Set always contains unique elements
// ? Time Complexity : O(N)
// ? Space Complexity : O(N)
int Method2(int arr[], int N)
{
    unordered_set<int> hashSet;
    for (int i = 0; i < N; i++) // O(N)
        hashSet.insert(arr[i]); // O(1)

    int expectedNum = N + 1;
    for (int i = 0; i < expectedNum; i++) // O(N)
    {
        if (hashSet.find(i) == hashSet.end()) // O(1)
            return i;
    }
    return -1;
}

// ! Using Bit Manipulation Approach :-> For finding missing number in range [0, n]
// * Fun Fact : XOR of two same number is 0 and XOR of 0 and N is N
// ? Time Complexity : O(N)
// ? Space Complexity : O(1)
int Method3(int arr[], int N)
{
    int missing = N;
    for (int i = 0; i < N; i++)
        missing ^= (i ^ arr[i]);
    return missing;
}

// ! Using Sum Method : Mathematical Approach
// ? Time Complexity : O(N)
// ? Space Complexity : O(1)
int Method4(int arr[], int N)
{
    int expectedSum = N * (N + 1) / 2; // O(1)
    int actualSum = 0;
    for (int i = 0; i < N; i++) // O(N)
        actualSum += arr[i];
    return expectedSum - actualSum;
}

int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    cout << Method3(arr, n) << "\n";
    return 0;
}