#include <iostream>
#include <vector>
using namespace std;

void sortPancakes(std::vector<int>& pancakes) 
{
    int n = pancakes.size();
    for (int i = 0; i < n - 1; i++) 
    {
        for (int j = 0; j < n - i - 1; j++) 
        {
            if (pancakes[j] < pancakes[j + 1]) 
            {
                std::swap(pancakes[j], pancakes[j + 1]);
            }
        }
    }
}

int main() 
{
    setlocale(LC_ALL, "ru");
    vector<int> pancakes = { 4, 2, 6, 1, 5, 3 }; //сами радиусы оладий
    sortPancakes(pancakes);

    cout << "Сортировка завершена." << endl;
    for (int i = 0; i < pancakes.size(); i++) 
    {
        cout << pancakes[i] << " ";
    }
    cout << endl;

    return 0;
}