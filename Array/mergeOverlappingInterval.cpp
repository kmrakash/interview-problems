#include <bits/stdc++.h>
using namespace std;

// ! Optimised Approach
// ? Time complexity : O(NLogN) + O(N)
// ? Space Complexity : O(N)
vector<pair<int, int>> Method(vector<pair<int, int>> intervals)
{
    sort(intervals.begin(), intervals.end()); // O(NLogN)
    vector<pair<int, int>> ans;
    ans.reserve(intervals.size());
    ans.push_back(intervals[0]);

    for (auto interval : intervals) // O(N)
    {
        if (interval.first <= ans.back().second)
        {
            // ans.back().first = min(ans.back().first, interval.first); This line does not used since we have already sorted the pairs
            ans.back().second = max(ans.back().second, interval.second);
        }
        else
        {
            ans.push_back(interval);
        }
    }

    return ans;
}

int main()
{
    // Standard input
    int n;
    cin >> n;
    vector<pair<int, int>> v;
    v.reserve(n + 1);
    for (int i = 0; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        v.push_back(make_pair(a, b));
    }

    // Apply Logic
    vector<pair<int, int>> res = Method(v);

    //Print output
    for (auto p : res)
    {
        cout << p.first << " " << p.second << "\n";
    }

    return 0;
}