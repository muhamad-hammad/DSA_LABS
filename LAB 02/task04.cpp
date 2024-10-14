// 4. You are tasked with developing a program to manage and display the Grade Point Average (GPA) for the
// core courses offered in the first semester of four departments: Software Engineering (SE), Artificial Intelligence
// (AI), Computer Science (CS), and Data Science (DS). Each department offers a distinct number of core courses
// for this semester: SE has 3 core courses, AI has 4 core courses, CS has 2 core courses, and DS has 1 core course.
// To efficiently store and present this data, which type of array structure would you employ? implement a solution
// using the chosen array structure to display the GPAs of the core courses for each department.

#include <iostream>
using namespace std;

int main()
{
    // Define the number of core courses for each department
    const int SE_COURSES = 3;
    const int AI_COURSES = 4;
    const int CS_COURSES = 2;
    const int DS_COURSES = 1;
    const int NUM_DEPARTMENTS = 4;

    float *gpa_data[NUM_DEPARTMENTS];

    gpa_data[0] = new float[SE_COURSES]; // Software Engineering
    gpa_data[1] = new float[AI_COURSES]; // Artificial Intelligence
    gpa_data[2] = new float[CS_COURSES]; // Computer Science
    gpa_data[3] = new float[DS_COURSES]; // Data Science

    int courses[] = {SE_COURSES, AI_COURSES, CS_COURSES, DS_COURSES};
    string departments[] = {"Software Engineering", "Artificial Intelligence", "Computer Science", "Data Science"};

    // Input GPA data for each department
    cout << "Enter GPA data for each department:" << endl;
    for (int k = 0; k < 4; k++)
    {
        cout << "Enter GPA for " << departments[k] << " core courses:\n";
        for (int i = 0; i < courses[k]; i++)
        {
            cout << "Course " << (i + 1) << ": ";
            cin >> gpa_data[k][i];
        }
    }

    // Display the GPA data for each department
    cout << "\nGPA Data for Core Courses:\n";
    for (int k = 0; k < 4; k++)
    {
        cout << departments[k] << ":\n";
        for (int i = 0; i < courses[k]; i++)
        {
            cout << "Course " << (i + 1) << ": " << gpa_data[k][i] << endl;
        }
        cout << endl;
    }

    // Deallocate memory
    for (int k = 0; k < 4; k++)
    {
        delete[] gpa_data[k];
    }
    return 0;
}