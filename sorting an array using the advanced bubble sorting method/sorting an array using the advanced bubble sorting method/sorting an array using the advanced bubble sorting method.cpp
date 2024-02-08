#include <iostream>
using namespace std;

void bubbleSort(int arr[], int n) 
{
    bool swapped;
    for (int i = 0; i < n - 1; i++) 
    {
        swapped = false;
        for (int j = 0; j < n - i - 1; j++) 
        {
            if (arr[j] > arr[j + 1]) 
            {
                swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }
        if (!swapped) 
        { // Если на данной итерации не было перестановок, то массив уже отсортирован
            break;
        }
    }
}

int main() 
{
    setlocale(LC_ALL, "ru");
    int arr[] = { 64, 34, 25, 12, 22, 11, 90 }; //изменяй на свой вкус и цвет
    int n = sizeof(arr) / sizeof(arr[0]);

    bubbleSort(arr, n);

    cout << "Отсортированный массив: " << endl;
    for (int i = 0; i < n; i++) 
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}