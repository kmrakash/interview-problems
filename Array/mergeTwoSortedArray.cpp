#include <bits/stdc++.h>
using namespace std;

// ! Using Extra Space
// ? Time Complexity : O(n+m)
// ? Space Complexity : O(n+m)
void Method1(int arr1[], int arr2[], int n, int m)
{
    int res[n + m + 1]; // O(n+m)
    int i = 0, j = 0, k = 0;
    arr1[n] = 1e9;
    arr2[m] = 1e9;

    while (i != n or j != m) // O(n+m)
    {
        int first = arr1[i];
        int second = arr2[j];
        if (first < second)
        {
            res[k++] = first;
            i++;
        }
        else
        {
            res[k++] = second;
            j++;
        }
    }

    k = 0;
    while (k != n) // O(n)
    {
        arr1[k] = res[k];
        k++;
    }
    j = 0;
    while (k != (n + m)) // O(m)
    {
        arr2[j++] = res[k++];
    }
}

// ! Without Using Extra Space
// ? Time Complexity: O(n*m)
// ? Space Complexity : O(1)
void Method2(int arr1[], int arr2[], int n, int m)
{
    for (int i = m - 1; i >= 0; i--) // O(m)
    {

        int j, last = arr1[n - 1];
        for (j = n - 2; j >= 0 && arr1[j] > arr2[i]; j--) //O(n) * O(m)
            arr1[j + 1] = arr1[j];

        if (j != n - 2 || last > arr2[i])
        {
            arr1[j + 1] = arr2[i];
            arr2[i] = last;
        }
    }
}

int nextGap(int gap)
{
    if (gap == 1)
        return 0;
    else
        return (gap / 2) + (gap % 2);
}

// ! Without using Extra Space and More Efficient
// ? Time Complexity : O(n+m)
// ? Space Complexity : O(1)
void Method3(int arr1[], int arr2[], int n, int m)
{
    int gap = n + m, i, j;
    for (gap = nextGap(gap); gap > 0; gap = nextGap(gap))
    {

        // From First Array
        for (i = 0; i + gap < n; i++)
        {
            if (arr1[i] > arr1[i + gap])
                swap(arr1[i], arr1[i + gap]);
        }

        // From Both Array
        for (j = gap > n ? gap - n : 0; i < n && j < m; i++, j++)
        {
            if (arr1[i] > arr2[j])
                swap(arr1[i], arr2[j]);
        }

        // From Second Array
        if (j < m)
        {
            for (j = 0; j + gap < m; j++)
            {
                if (arr2[j] > arr2[j + gap])
                    swap(arr2[j], arr2[j + gap]);
            }
        }
    }
}

int main()
{
    int n, m;
    cin >> n >> m;
    int arr1[n + 1], arr2[m + 1];
    for (int i = 0; i < n; i++)
        cin >> arr1[i];
    for (int j = 0; j < m; j++)
        cin >> arr2[j];

    Method3(arr1, arr2, n, m);

    // After Merging The Array
    for (int i = 0; i < n; i++)
        cout << arr1[i] << " ";
    for (int j = 0; j < m; j++)
        cout << arr2[j] << " ";

    return 0;
}