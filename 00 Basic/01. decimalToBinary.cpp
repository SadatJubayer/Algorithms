#include<iostream>
using namespace std;

int decimalToBinary(int x)
{
    long long binary = 0;
    int remainder, i = 1, step = 1;

    while (x!=0)
    {
        remainder = x%2;
        x /= 2;
        binary += remainder*i;
        i *= 10;
    }
    return binary;
}

int main()
{
    int n;
    cout << "Enter Decimal number : ";
    cin >> n;

    int n;
    int b;
    int c;

	cout<<"Binary value is: "<< decimalToBinary(n);

	return 0;
}
