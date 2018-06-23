#include <iostream>
using namespace std;

int naiveMultiplicationVersion2(int x, int y)
{
    int product = 0;

    while(x)
    {
        if(x % 2 == 1)
            product = product + y;

        x >>= 1;
        y <<= 1;
    }

    return product;
}

int main()
{
    int a, b;
    cout << "Enter First number : ";
    cin >> a;
    cout << "\nEnter Second number : ";
    cin >> b;

	cout<<"\nMultiplication is: "<< naiveMultiplicationVersion2(a,b) <<"\n";

	return 0;
}


