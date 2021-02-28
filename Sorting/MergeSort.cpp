#include <iostream>
using namespace std;
#define deb(x) cout << #x << " " << x << "\n";

void Merge(int arr[], int l, int m, int h)
{
    int _len1 = m - l + 1; // Length  of Left subarray
    int _len2 = h - m;
    // deb(_len1);
    // deb(_len2);
    // Create two Subarray
    int left[_len1];
    int right[_len2];

    int k = l;
    // Copy The Data;
    for (int i = 0; i < _len1; i++)
        left[i] = arr[k++];
    for (int j = 0; j < _len2; j++)
        right[j] = arr[k++];

    k = l;
    int i = 0, j = 0;
    while (i < _len1 && j < _len2)
    {
        if (left[i] < right[j])
        {
            arr[k] = left[i];
            i++;
        }
        else
        {
            arr[k] = right[j];
            j++;
        }
        k++;
    }

    while (i != _len1)
    {
        arr[k] = left[i];
        i++;
        k++;
    }

    while (j != _len2)
    {
        arr[k] = right[j];
        j++;
        k++;
    }
}

void MergeSort(int arr[], int low, int high)
{
    if (low >= high)
        return;

    int mid = low + (high - low) / 2;
    MergeSort(arr, low, mid);
    MergeSort(arr, mid + 1, high);
    Merge(arr, low, mid, high);
}

int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    MergeSort(arr, 0, n - 1);

    // Output Array
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << "\n";
    return 0;
}