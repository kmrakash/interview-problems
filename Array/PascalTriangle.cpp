#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int numRows;
    cin >> numRows;

    vector<vector<int>> pascal;
    pascal.push_back({1});
    pascal.push_back({1, 1});

    for (int i = 1; i < numRows - 1; i++) // O(numRows^2)
    {
        vector<int> newPascal;
        newPascal.clear();
        for (int j = 0; j < pascal[i].size() + 1; j++)
        {
            if (j == 0 || j == pascal[i].size())
            {
                newPascal.push_back(1);
            }
            else
            {
                int newValue = pascal[i][j] + pascal[i][j - 1];
                newPascal.push_back(newValue);
            }
        }
        pascal.push_back(newPascal);
    }

    for (int i = 0; i < pascal.size(); i++)
    {
        for (int j = 0; j < pascal[i].size(); j++)
        {
            cout << pascal[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}