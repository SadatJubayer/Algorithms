#include <iostream>
using namespace std;

void swapFunction(int x, int y)
{
    x = x + y;
    y = x - y;
    x = x - y;

    cout << "\nAfter swapping: " << x << " "<< y <<endl;
}

int main()
{
    int a, b;
    cout << "Enter two numbers for swapping : ";
    cin >> a;
    cin >> b;

    swapFunction(a,b);

	return 0;
}


