#include <bits/stdc++.h>
using namespace std;
#define all(v) v.begin(), v.end()

/*
    ! Efficient Approach
    * Algorith: Step 1: Iterate from second last index and get a index_1 with a element lesser than next right element
    *           Step 2: If index_1 < 0 , every value is in decreasing order just reverse and return
    *           Step 3: If index_1 >= 0 ,Iterate from last and get a index_2 with a element greater than index_1 value
    *           Step 4: Swap(index_1 , index_2)
    *           Step 5: reverse every element to right of index_1
    
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