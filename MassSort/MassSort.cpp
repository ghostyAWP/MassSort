//Задание: Сгенерировать массив случайных чисел и отсортировать его минимум тремя способами, числа в массиве не должны повторяться.
#include <iostream>
#include <ctime>
#include <windows.h>
#include <cstdlib>
using namespace std;

void swap(int arr[], int i)/*функция, меняющая элементы местами*/
{
	int buff;
	buff = arr[i];
	arr[i] = arr[i - 1];
	arr[i - 1] = buff;
} 
int FillArray(int arr[], const int SIZE)  /*функция генерирования случайного массива*/
{
	for (int i = 0; i < SIZE;)
	{
		bool alreadyHere = false;
		int newRandomValue = rand() % 100;
		for (int j = 0; j < i; j++)/*проверка элементов на уникальность*/
		{
			if (arr[j] == newRandomValue)
			{
				alreadyHere = true;
				break;
			}
		}
		if (!alreadyHere)
		{
			arr[i] = newRandomValue;
			i++;
		}
	}
	for (int i = 0; i < SIZE; i++)
		cout << arr[i] << " ";
	return 0;
}

int BubleSort(int arr[], const int SIZE) /*функция сортировки массива методом пузырька*/
{
	int surr = 0;
	for (int i = 0; i < SIZE; i++)
	{
		for (int j = 0; j < SIZE - 1; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				surr = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = surr;
			}
		}
	}
	for (int i = 0; i < SIZE; i++)
	{
		cout << arr[i] << " ";
	}
	return 0;
}
int ChoiceSort(int arr[], const int SIZE)/*функция сортировки массива методом выбора*/
{
	int min = 0;
	int buf = 0;
	for (int i = 0; i < SIZE; i++)
	{
		min = i;
		for (int j = i + 1; j < SIZE; j++)
		{
			min = arr[j] < arr[min] ? j : min;
		}
		if (i != min)
		{
			buf = arr[i];
			arr[i] = arr[min];
			arr[min] = buf;
		}
	}
	for (int i = 0; i < SIZE; i++)
	{
		cout << arr[i] << " ";
	}
	return 0;
}
int InsertSotr(int arr[], const int SIZE)/*функция сортировки массива методом вставки*/
{
	int buf = 0;
	for (int i = 1; i < SIZE; i++)
	{
		buf = arr[i];
		for (int j = i - 1; j >= 0 && arr[j] > buf; j--)
		{
			arr[j + 1] = arr[j];
			arr[j] = buf;
		}
	}
	for (int i = 0; i < SIZE; i++)
	{
		cout << arr[i] << " ";
	}
	return 0;
}
void ShakerSort(int* arr, int SIZE)/*функция сортировки массива методом шейкера*/
{
	int leftMark = 1;
	int rightMark = SIZE - 1;
	while (leftMark <= rightMark)
	{
		for (int i = rightMark; i >= leftMark; i--)
			if (arr[i - 1] > arr[i]) swap(arr, i);
		leftMark++;


		for (int i = leftMark; i <= rightMark; i++)
			if (arr[i - 1] > arr[i]) swap(arr, i);
		rightMark--;
	}
	for (int i = 0; i < SIZE; i++)
	{
		cout << arr[i] << " ";
	}
}

int main()
{
	setlocale(LC_ALL, "Ru");
	srand(time(NULL));
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE); /*позволяет менять цвет консоли*/
	const int SIZE = 15;
	int arr[SIZE]{};


	cout << "Заполняем массив: ";
	FillArray(arr, SIZE);
	cout << endl;

	cout << "Сортируем массив пузырьком: ";
	BubleSort(arr, SIZE);
	cout << endl;
	cout << endl;

	cout << "Заполняем массив снова: ";
	FillArray(arr, SIZE);
	cout << endl;

	cout << "Сортируем массив выбором: ";
	ChoiceSort(arr, SIZE);
	cout << endl;
	cout << endl;

	cout << "Заполняем массив снова: ";
	FillArray(arr, SIZE);
	cout << endl;

	cout << "Сортируем массив вставками: ";
	InsertSotr(arr, SIZE);
	cout << endl;
	cout << endl;

	cout << "Заполняем массив снова: ";
	FillArray(arr, SIZE);
	cout << endl;

	cout << "Сортируем массив шейкером: ";
	ShakerSort(arr, SIZE);
	cout << endl;
	cout << endl;
}
