#include <iostream>
using namespace std;

int naiveMultiplication(int x, int y)
{
    int mul=0;
    while (y!=0)
    {
        mul = mul+x;
        y --;
    }
    return mul;

}

int main()
{
    int a, b;
    cout << "Enter First number : ";
    cin >> a;
    cout << "\nEnter Second number : ";
    cin >> b;

	cout<<"\nMultiplication is: "<< naiveMultiplication(a,b) <<"\n";

	return 0;
}


