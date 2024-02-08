#include <iostream>
using namespace std;

int bubbleSort(int arr[], int n)
{
    int swaps = 0;

    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
                swaps++;
            }
        }
    }
    return swaps;
}

int selectionSort(int arr[], int n)
{
    int swaps = 0;
    for (int i = 0; i < n - 1; i++)
    {
        int minIndex = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[minIndex])
            {
                minIndex = j;
            }
        }
        if (minIndex != i)
        {
            swap(arr[i], arr[minIndex]);
            swaps++;
        }
    }
    return swaps;
}

int main() 
{
    setlocale(LC_ALL, "ru");
    srand(time(NULL));

    float totalBubbleSwaps = 0;
    float totalSelectionSwaps = 0;

    for (int k = 0; k < 10; k++)
    {
        int arr[1000];
        for (int i = 0; i < 1000; i++)
        {
            arr[i] = rand() % 1000;
        }

        int bubbleArr[1000];
        copy(arr, arr + 1000, bubbleArr);

        int selectionArr[1000];
        copy(arr, arr + 1000, selectionArr);

        int bubbleSwaps = bubbleSort(bubbleArr, 1000);
        int selectionSwaps = selectionSort(selectionArr, 1000);

        cout << "Число перестановок для метода пузырька: " << bubbleSwaps << endl;
        cout << "Число перестановок для метода выбора: " << selectionSwaps << endl;

        totalBubbleSwaps += bubbleSwaps;
        totalSelectionSwaps += selectionSwaps;
    }

    float averageBubbleSwaps = totalBubbleSwaps / 10;
    float averageSelectionSwaps = totalSelectionSwaps / 10;

    cout << "Среднее число перестановок для метода пузырька: " << averageBubbleSwaps << endl;
    cout << "Среднее число перестановок для метода выбора: " << averageSelectionSwaps << endl;

    return 0;
}