//DynamicMemory
#include<iostream>
using namespace std;

#define tab "\t"

void FillRand(int arr[], const int n);
void Print(int* arr, const int n);
void push_back(int arr[], int n, int value);

void main()
{
	setlocale(LC_ALL, "");
	//new
	int n;
	cout << "������� ������ �������: "; cin >> n;

	int* arr = new int[n];
	cout << typeid(arr).name() << endl;
	FillRand(arr, n);
	Print(arr, n);
	int value;
	cout << "������� ����������� ��������: "; cin >> value;
	push_back(arr, n, value);
	Print(arr, n+1);

	Print(arr, n);
	delete[] arr;//Heap (����)
	//Print(arr, n);
	//Memory leak

	/*const int SIZE = 5;
	int brr[SIZE];
	cout << typeid(brr).name() << endl;
	FillRand(brr, SIZE);
	Print(brr, SIZE);
	cout << sizeof(int) << endl;*/
}

void FillRand(int arr[], const int n)
{
	for (int i = 0; i < n; i++)
	{
		*(arr + i) = rand() % 100;
	}
}
void Print(int* arr, int n)
{
	cout << typeid(arr).name() << endl;	//RTTI - Runtime Type Information
	for (int i = 0; i < n; i++)
	{
		//[] - �������� �������������� (subscript operator)
		cout << arr[i] << tab;
	}
	cout << endl;
}
void push_back(int arr[], int n, int value)
{
	//1. ������� �������� ������ ������� �������, � ������ ������ �� 1 ������� ������:
	int* buffer = new int[n + 1];
	//2. �������� ��� ������ �� ��������� ������� � ��������:
	for (int i = 0; i < n; i++) buffer[i] = arr[i];
	//3. ����� ����, ��� ������ ����������� � ����� ������, ������ ������ ��� �� �����:
	delete[] arr;
	//4. ��������� ����� ������� ������� ������� ������ �������:
	arr = buffer;
	//5. ������ ����� ����� ����� � ����� ������� ����� �������� ��������:
	arr[n] = value;
	//6. ����� ���������� �������� � ������, ���������� ��� ��������� ���������� �� 1:
	n++;
	//7. Mission complete - ������� ��������
}