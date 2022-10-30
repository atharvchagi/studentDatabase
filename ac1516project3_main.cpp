#include "ac1516_header.h"
int main()
{
    cout << "1.Add" << endl
         << "2.Remove" << endl
         << "3.Display" << endl
         << "4.Search" << endl
         << "5.Results" << endl
         << "6.Quit" << endl;
    cout << "Enter choice: ";
    int choice;
    cin >> choice;
    cin.ignore();
    int ID;

    switch (choice)
    {
    case Add:
        addStudent();
        cout << "Student has been added to the database.";
        break;

    case Remove:
        cout << "Enter the student ID of the student: ";
        cin >> ID;
        removeStudent(ID);
        break;

    case Display:
        display();
        break;

    case Search:
        cout << "Enter the student ID of the student: ";
        cin >> ID;
        search(ID);
        break;

    case Results:
        exportResults();
        break;

    case Quit:
        cout << "Goodbye!";
        exit(1);
        break;

    default:
        cout << "Invalid choice";
        break;
    }
}
