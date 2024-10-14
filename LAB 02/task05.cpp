// 5. You&#39;re developing a program to manage a seating chart for a conference held in a hall with multiple rows
// of seats. Each row has a different seat capacity. To efficiently handle the seating arrangements, you decide to use
// a dynamic array. Implement a C++ code that allocates memory for the seating chart and allows attendees&#39; names
// to be inputted for each seat. Choose and implement the appropriate type of dynamic array for this scenario.
#include <iostream>
using namespace std;

int main() {
    int numRows;
    cout << "Enter the number of rows: ";
    cin >> numRows;
    
    // Allocate memory for the seating chart
    string **seatingChart = new string *[numRows];
    int *numSeats = new int[numRows];
    
    // Initialize each row with the appropriate number of seats
    for (int i = 0; i < numRows; i++) {
        cout << "Enter the number of seats in row " << i + 1 << ": ";
        cin >> numSeats[i];
        seatingChart[i] = new string[numSeats[i]];
    }

    // Input attendee names for each seat
    for (int i = 0; i < numRows; i++) {
        cout << "Enter attendee names for row " << i + 1 << ": " << endl;
        for (int j = 0; j < numSeats[i]; j++) {
            cout << "Seat " << j + 1 << ": ";
            cin >> seatingChart[i][j];
        }
    }

    // Display the seating chart
    cout << "\nSeating Chart:" << endl;
    for (int i = 0; i < numRows; i++) {
        cout << "Row " << i + 1 << ": ";
        for (int j = 0; j < numSeats[i]; j++) {
            cout << seatingChart[i][j] << " ";
        }
        cout << endl;
    }

    // Deallocate memory
    for (int i = 0; i < numRows; i++) {
        delete[] seatingChart[i];
    }
    delete[] seatingChart;
    delete[] numSeats;

    return 0;
}
