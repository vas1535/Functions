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
	cout << "Введите размер массива: "; cin >> n;

	int* arr = new int[n];
	cout << typeid(arr).name() << endl;
	FillRand(arr, n);
	Print(arr, n);
	int value;
	cout << "Введите добавляемое значение: "; cin >> value;
	arr = push_back(arr, n, value);
	Print(arr, n);
	arr = Pop_back(arr, n);
	Print(arr, n);
	delete[] arr;//Heap (Куча)
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
	int rows;   //количество строк двумерного динамического массива
	int cols;   //количество элементов строки
	cout << "Введите количество строк: ";      cin >> rows;
	cout << "Введите количество элементов строки: ";      cin >> cols;
	cout << "Укажите ячейку в которую разместить доп.элемент числа" << endl;;

	//1)Создаём массив указателей
	int** arr = new int* [rows];
	//2)Создаём строки двумерного массива 
	for (int i = 0; i < rows; i++)
	{
		arr[i] = new int[cols] {};
	}

	//3) Обращение к элементам двумерного динамического массива:

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
		//[] - оператор индексирования (subscript operator)
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
	//1. Создаем буферный массив нужного размера, в данном случае на 1 элемент больше:
	int* buffer = new int[n + 1];
	//2. Копируем все данные из исходного массива в буферный:
	for (int i = 0; i < n; i++) buffer[i] = arr[i];
	//3. После того, как данные скопированы в новый массив, старый массив уже не нужен:
	delete[] arr;
	//4. Подменяем адрес старого массива адресом нового массива:
	arr = buffer;
	//5. Только после всего этого в новый элемент можно добавить значение:
	arr[n] = value;
	//6. После добавления элемента в массив, количество его элементов увеличится на 1:
	n++;
	//7. Mission complete - элемент добавлен
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



