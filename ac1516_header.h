#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <iomanip>
using namespace std;

const int TESTnum = 5;
enum Menu
{
    Add = 1,
    Remove = 2,
    Display = 3,
    Search = 4,
    Results = 5,
    Quit = 6
};

struct Student
{
    string name;
    int stuID;
    int testsTaken;
    int *ptrScores;
    double avg;
};

int getNumber();
void addStudent();
void removeStudent(int ID);
void display();
void search(int ID);
int findMinimum(int arr[], int size);
void exportResults();
