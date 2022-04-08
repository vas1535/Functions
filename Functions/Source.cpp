//Functions
#include<iostream>
using namespace std;

int Add(int a, int b)
{
	int c = a + b;
	return c;
}
int Sub(int a, int b)
{
	return a - b;
}
int Mul(int a, int b)
{
	return a * b;
}
double Div(int a, int b)
{
	return a / b;
}


void main()
{
	setlocale(LC_ALL, "");
	int a, b;
	cout << "¬ведите два числа: "; cin >> a >> b;
	int c = Add(a, b);
	cout << a << " + " << b << " = " << c << endl;
}