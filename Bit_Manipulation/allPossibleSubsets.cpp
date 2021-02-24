#include <iostream>
#include <string>
using namespace std;

void printAllSubsets(string s)
{

    int len = s.length();
    int bitLength = 1 << len;

    for (int i = 0; i < bitLength; i++)
    {
        string newString = "";
        int j = 0;
        int bit = i;
        while (bit)
        {
            int last_bit = bit & 1;
            if (last_bit)
                newString += s[j];
            bit >>= 1;
            j++;
        }
        cout << newString << "\n";
    }
}

int main()
{
    string input;
    cin >> input;

    printAllSubsets(input);
    return 0;
}