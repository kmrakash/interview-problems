#include <bits/stdc++.h>
using namespace std;

// ! Method - 1 : Just sort the array
// ? Time complexity : O(NlogN)
// ? Space complexity : O(1)
void method1(int arr[], int lenght)
{
    sort(arr, arr + lenght); // O(NlogN)
}

// ! Method 2 : Use counting sort method
// ? Time Complexity : O(N) + O(N) -> O(N)
// ? Space Complexity : O(1)
void method2(int arr[], int lenght)
{
    int zero = 0;
    int one = 0;
    int two = 0;

    // Count Each item
    for (int i = 0; i < lenght; i++) // O(N)
    {
        if (arr[i] == 0)
            zero++;
        else if (arr[i] == 1)
            one++;
        else
            two++;
    }

    int i = 0; // O(N)
    while (zero--)
        arr[i++] = 0;
    while (one--)
        arr[i++] = 1;
    while (two--)
        arr[i++] = 2;
}

// ! Method 3 : Dutch national flag algorithm -> using three pointer low , mid and high
// ? Time Complexity : O(N)
// ? Space Complexity : O(1)
// * This can be further optimised by reducing unecessary swaps like if low == mid or high == mid
void swap(int &a, int &b) // Reference pointer it points to same address variable that is passed
{
    int temp = a;
    a = b;
    b = temp;
}

void sort012(int arr[], int lenght)
{
    int low = 0;
    int mid = 0;
    int high = lenght - 1;

    while (mid <= high)
    {
        if (arr[mid] == 0)
        {
            swap(arr[low], arr[mid]);
            low++;
            mid++;
        }
        else if (arr[mid] == 2)
        {
            swap(arr[high], arr[mid]);
            high--;
        }
        else
            mid++;
    }
}

int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    //sort012(arr, n);

    method2(arr, n);
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << "\n";
    return 0;
}