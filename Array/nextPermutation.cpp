#include <bits/stdc++.h>
using namespace std;
#define all(v) v.begin(), v.end()

/*
    ! Efficient Approach
    * Algorith: Step 1: Find the largest index k such that nums[k] < nums[k + 1]. If no such index exists, just reverse nums and done.
    *           Step 2:Find the largest index l > k such that nums[k] < nums[l].
    *           Step 3: Swap nums[k] and nums[l].
    *           Step 4: Reverse the sub-array nums[k + 1:].     

    ? Time Complexity : O(N)
    ? Space Complexity :  O(1)

*/
void Method(vector<int> &nums)
{
    int n = nums.size(), k, l;
    for (k = n - 2; k >= 0; k--) // O(N)
    {
        if (nums[k] < nums[k + 1])
            break;
    }
    if (k < 0)
        reverse(all(nums)); // O(N)
    else
    {
        for (l = n - 1; l > k; l--) // O(N)
            if (nums[l] > nums[k])
                break;
        swap(nums[k], nums[l]);                    //O(1)
        reverse(nums.begin() + k + 1, nums.end()); //O(N)
    }
}

int main()
{
    int n;
    cin >> n;
    vector<int> nums;
    nums.reserve(n);
    for (int i = 0; i < n; i++)
    {
        int t;
        cin >> t;
        nums.push_back(t);
    }

    // Logic
    Method(nums);
    //Built-in Method
    //next_permutation(all(nums));

    for (int i = 0; i < n; i++)
    {
        cout << nums[i] << " ";
    }
    cout << "\n";
    return 0;
}