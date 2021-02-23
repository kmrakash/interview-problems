#include <bits/stdc++.h>
using namespace std;

// ! Additional Memory Approach
// ? Time Complexity : O(M*N)
// ? Space Complexity : O(M+N)
void Method(vector<vector<int>> &Matrix)
{
    set<int> rowIndex; // O(rowSize)
    set<int> colIndex; // O(colSize)
    int rowSize = Matrix.size();
    int colSize = Matrix[0].size();
    for (int row = 0; row < rowSize; row++) // O(rowSize*colSize)
    {
        for (int col = 0; col < colSize; col++)
        {
            if (Matrix[row][col] == 0)
            {
                rowIndex.insert(row);
                colIndex.insert(col);
            }
        }
    }

    // // Convert all row zero
    // for (auto r : rowIndex) // O(rowSize*colSize)
    // {
    //     // cout << "Converting: " << r << "th index ";
    //     // cout << "\n";
    //     int i = 0;
    //     while (i != colSize)
    //     {
    //         Matrix[r][i++] = 0;
    //     }
    // }
    // // Convert all column zero
    // for (auto c : colIndex) // O(rowSize*colSize)
    // {
    //     // cout << c << " ";
    //     // cout << "\n";
    //     int j = 0;
    //     while (j != rowSize)
    //     {
    //         Matrix[j++][c] = 0;
    //     }
    // }

    for (int i = 0; i < rowSize; i++) // O(rowSize*colSize)
    {
        for (int j = 0; j < colSize; j++)
        {
            if (rowIndex.find(i) != rowIndex.end() || colIndex.find(j) != colIndex.end())
            {
                Matrix[i][j] = 0;
            }
        }
    }
}

// ! Efficient Approach
// ? Time Complexity : O(M*N)
// ? Space Complexity : 0(1)
void Method2(vector<vector<int>> &Matrix)
{
    bool isCol = false;
    int rowSize = Matrix.size();
    int colSize = Matrix[0].size();
    bool isFirst = Matrix[0][0] == 0;

    for (int row = 0; row < rowSize; row++) // O(rowSize*colSize)
    {

        if (Matrix[row][0] == 0)
        {
            isCol = true;
        }
        for (int col = 0; col < colSize; col++)
        {
            if (Matrix[row][col] == 0)
            {
                Matrix[row][0] = 0;
                Matrix[0][col] = 0;
            }
        }
    }

    for (int row = 1; row < rowSize; row++)
    {
        for (int col = 1; col < colSize; col++)
        {
            if (Matrix[row][0] == 0 || Matrix[0][col] == 0)
            {
                Matrix[row][col] = 0;
            }
        }
    }

    if (isFirst)
    {
        for (int j = 0; j < colSize; j++)
        {
            Matrix[0][j] = 0;
        }
    }

    // Check if Matrix first Cell is zero

    if (isCol)
    {
        for (int i = 0; i < rowSize; i++)
        {
            Matrix[i][0] = 0;
        }
    }
}

int main()
{ // Take Standard Input
    int m, n;
    cin >> m >> n;
    vector<vector<int>> matrix;
    vector<int> temp;
    int t;
    matrix.reserve(m);
    temp.reserve(n);
    for (int row = 0; row < m; row++)
    {
        for (int col = 0; col < n; col++)
        {
            cin >> t;
            temp.push_back(t);
        }
        matrix.push_back(temp);
        temp.clear();
    }

    // Apply Logic
    Method2(matrix);

    // Print Matrix
    for (int row = 0; row < m; row++)
    {
        for (int col = 0; col < n; col++)
        {
            cout << matrix[row][col] << " ";
        }
        cout << "\n";
    }

    return 0;
}

/**  TEST CASES
 * 
 * -----------------------------------------------
 *  Test Case 1:
 *      Input : 3 4
 *              0 1 2 0
                3 4 5 2
                1 3 1 5

    Expected Output: 0 0 0 0
                     0 4 5 0
                     0 3 1 0
 * -----------------------------------------------
 * 
 * Test Case 2:
 * Input:  3 4
           1 2 3 4
           0 8 9 5
           3 2 4 1
 * 
 * Expected Output: 
 *                  0 2 3 4
                    0 0 0 0
                    0 2 4 1
    ------------------------------------------------
 *                   
 **/