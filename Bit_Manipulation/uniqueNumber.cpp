#include <iostream>
#include <cassert>
using namespace std;

int getUnique(int arr[], int n)
{
    if (n <= 0)
        return -1;
    if (n == 1)
        return arr[0];

    int ans = 0;
    for (int i = 0; i < n; i++)
        ans ^= arr[i];
    return ans;
}

int main()
{

    // assert(getUnique(7, 7) == 6);
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    // Print Result
    cout << getUnique(arr, n) << "\n";
    return 0;
}