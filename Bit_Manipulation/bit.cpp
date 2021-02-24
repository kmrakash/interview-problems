#include <iostream>
using namespace std;
int main()
{
    int a, b;
    while (cin >> a >> b)
    {
        cout << "-----------------------------------------------------------"
             << "\n";
        cout << "BITWISE AND OF " << a << " and " << b << " is: " << (a & b) << "\n";
        cout << "BITWISE OR OF " << a << " and " << b << " is: " << (a | b) << "\n";
        cout << "BITWISE XOR OF " << a << " and " << b << " is: " << (a ^ b) << "\n";
        cout << "NEGATION OF " << a << " is: " << (~a) << "\n";
        cout << "NEGATION OF " << b << " is: " << (~b) << "\n";
        cout << "LEFT SHIFT OF " << a << " is: " << (a << 1) << "\n";
        cout << "RIGHT SHIFT OF " << a << " is: " << (a >> 1) << "\n";
        cout << "LEFT SHIFT OF " << b << " is: " << (b << 1) << "\n";
        cout << "RIGHT SHIFT OF " << b << " is: " << (b >> 1) << "\n";
        cout << "----------------------------------------------------------"
             << "\n"
             << "\n";
    }
    return 0;
}