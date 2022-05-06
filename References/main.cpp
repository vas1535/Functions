//References
#include<iostream>
using namespace std;

void main()
{
	setlocale(LC_ALL, "");
	int a = 2;
	int& ra = a;    //reference to 'a' - ссылка на переменную 'a'
	ra += 3;
	cout << a << endl;
	a += 3;
	cout << ra << endl;

}