//DynamicMemory
#include<iostream>
using namespace std;

#define tab "\t"

void FillRand(int arr[], const int n);
void FillRand(int** arr, const int rows, const int cols);
void Print(int* arr, const int n);
void Print(int** arr, const int rows, const int cols);
int* push_back(int arr[], int& n, int value);
int* insert(int* arr, int& n, int num, int& index);
int* Pop_back(int* arr, int& n);


#define DYNAMIC_MEMORY_1
//#define DYNAMIC_MEMORY_2

void main()
{
	setlocale(LC_ALL, "");
#ifdef DYNAMIC_MEMORY_1
	//newYN
	int n;
	cout << "������� ������ �������: "; cin >> n;

	int* arr = new int[n];
	cout << typeid(arr).name() << endl;
	FillRand(arr, n);
	Print(arr, n);
	int value;
	cout << "������� ����������� ��������: "; cin >> value;
	arr = push_back(arr, n, value);
	Print(arr, n);
	arr = Pop_back(arr, n);
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
#endif DYNAMIC_MEMORY_1

#ifdef DYNAMIC_MEMORY_2
	int rows;   //���������� ����� ���������� ������������� �������
	int cols;   //���������� ��������� ������
	cout << "������� ���������� �����: ";      cin >> rows;
	cout << "������� ���������� ��������� ������: ";      cin >> cols;
	cout << "������� ������ � ������� ���������� ���.������� �����" << endl;;

	//1)������ ������ ����������
	int** arr = new int* [rows];
	//2)������ ������ ���������� ������� 
	for (int i = 0; i < rows; i++)
	{
		arr[i] = new int[cols] {};
	}

	//3) ��������� � ��������� ���������� ������������� �������:

	FillRand(arr, rows, cols);
	Print(arr, rows, cols);
	for (int i = 0; i < rows; i++)delete[] arr[i];
	delete[] arr;
#endif // DYNAMIC_MEMORY_2

}

void FillRand(int arr[], const int n)
{
	for (int i = 0; i < n; i++)
	{
		*(arr + i) = rand() % 100;
	}
}
void FillRand(int** arr, const int rows, const int cols)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			arr[i][j] = rand() % 100;
		}
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
void Print(int** arr, const int rows, const int cols)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			cout << arr[i][j] << "\t";
		}
		cout << endl;
	}
}
int* push_back(int arr[], int& n, int value)
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
	return arr;
}

int* insert(int* arr, int& n, int num, int& index)
{
	int* buffer = arr;
	buffer = new int[n + 1]{};
	for (int i = n - 1; i >= index - 1; i--)
	{
		buffer[i + 1] = arr[i];
	}
	for (int i = 0; i <= index - 1; i++)
	{
		buffer[i] = arr[i];
	}

	delete[] arr;
	buffer[index] = num;
	arr = buffer;
	n++;
	return arr;
}
int* Pop_back(int* arr, int& n)
{
	int* parr = new int[n - 1]{};
	for (int i = 0; i < n - 1; i++)
	{
		parr[i] = arr[i];
	}
	delete[] arr;
	n--;
	arr = parr;
	return arr;
}



