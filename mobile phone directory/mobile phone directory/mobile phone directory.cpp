#include <iostream>
#include <algorithm>
using namespace std;

void printContacts(int contacts[], int size) 
{
    cout << "Контакты:" << endl;
    for (int i = 0; i < size; i++) 
    {
        cout << "Контакты " << (i + 1) << ": " << contacts[i] << endl;
    }
    cout << endl;
}

void sortMobileNumbers(int mobileNumbers[], int homeNumbers[], int size) 
{
    sort(mobileNumbers, mobileNumbers + size);
    for (int i = 0; i < size; i++) 
    {
        for (int j = i + 1; j < size; j++) 
        {
            if (mobileNumbers[j] == mobileNumbers[i]) 
            {
                int tempMobileNumber = mobileNumbers[i];
                int tempHomeNumber = homeNumbers[i];
                mobileNumbers[i] = mobileNumbers[j];
                homeNumbers[i] = homeNumbers[j];
                mobileNumbers[j] = tempMobileNumber;
                homeNumbers[j] = tempHomeNumber;
            }
        }
    }
    printContacts(mobileNumbers, size);
}

void sortHomeNumbers(int mobileNumbers[], int homeNumbers[], int size) 
{
    for (int i = 0; i < size; i++) 
    {
        for (int j = i + 1; j < size; j++) 
        {
            if (homeNumbers[j] == homeNumbers[i]) 
            {
                int tempMobileNumber = mobileNumbers[i];
                int tempHomeNumber = homeNumbers[i];
                mobileNumbers[i] = mobileNumbers[j];
                homeNumbers[i] = homeNumbers[j];
                mobileNumbers[j] = tempMobileNumber;
                homeNumbers[j] = tempHomeNumber;
            }
        }
    }
    printContacts(homeNumbers, size);
}

int main() 
{
    setlocale(LC_ALL, "ru");
    const int SIZE = 5;
    int mobileNumbers[SIZE] = { 1111111, 3333333, 2222222, 4444444, 5555555 };
    int homeNumbers[SIZE] = { 9999999, 7777777, 5555555, 1111111, 3333333 };
    int choice;

    do 
    {
        cout << "---------------------------------" << endl;
        cout << "Меню:" << endl;
        cout << "1. Сортировка мобильных номеров" << endl;
        cout << "2. Сортировка домашних номеров" << endl;
        cout << "3. Вывести все номера" << endl;
        cout << "4. Выход" << endl;
        cout << "Сделайте свой выбор: ";
        cin >> choice;
        cout << "---------------------------------" << endl;
        switch (choice) 
        {
        case 1:
            sortMobileNumbers(mobileNumbers, homeNumbers, SIZE);
            break;

        case 2:
            sortHomeNumbers(mobileNumbers, homeNumbers, SIZE);
            break;

        case 3:
            printContacts(mobileNumbers, SIZE);
            printContacts(homeNumbers, SIZE);
            break;

        case 4:
            cout << "Выход из программы..." << endl;
            break;

        default:
            cout << "Выбор инвалидный, выбери от 1 до 4." << endl;
            break;
        }
    } while (choice != 4);

    return 0;
}