#include <iostream>
using namespace std;

class date
{
private:
    int day;
    int month;
    int year;

public:
    void enterData()
    {
        cout << "Enter day: ";
        cin >> day;
        cout << "Enter month: ";
        cin >> month;
        cout << "Enter year: ";
        cin >> year;
    }

    int getYear() const { return year; }
    int getMonth() const { return month; }
    int getDay() const { return day; }
};

void swap(date &a, date &b)
{
    date temp = a;
    a = b;
    b = temp;
}

void selectionSort(date A[], int len)
{
    int minIndex;

    for (int i = 0; i < len - 1; i++)
    {
        minIndex = i;

        for (int j = i + 1; j < len; j++)
        {
            if (A[j].getYear() < A[minIndex].getYear() ||
                (A[j].getYear() == A[minIndex].getYear() && A[j].getMonth() < A[minIndex].getMonth()) ||
                (A[j].getYear() == A[minIndex].getYear() && A[j].getMonth() == A[minIndex].getMonth() && A[j].getDay() < A[minIndex].getDay()))
            {
                minIndex = j;
            }
        }

        if (minIndex != i)
        {
            swap(A[i], A[minIndex]);
        }
    }
}

int main()
{
    date d[5];

    for (int i = 0; i < 5; i++)
    {
        cout << "Enter data for date " << i + 1 << ": " << endl;
        d[i].enterData();
    }

    selectionSort(d, 5);

    cout << "Sorted dates:" << endl;
    for (int i = 0; i < 5; i++)
    {
        cout << d[i].getDay() << "/" << d[i].getMonth() << "/" << d[i].getYear() << endl;
    }

    return 0;
}
