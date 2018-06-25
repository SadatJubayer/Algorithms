#include<iostream>
using namespace std;

int binaryToDecimal(int x)
{
    long int decimal=0, i=1, rem;

	while(x!=0)
	{
		rem=x%10;
		decimal=decimal+rem*i;
		i=i*2;
		x=x/10;
	}

	return decimal;
}

int main()
{
    long int binary;
    cout<<"Enter Binary number : ";
	cin>>binary;

	cout<<"Decimal value is: "<<binaryToDecimal(binary);

	return 0;

}
