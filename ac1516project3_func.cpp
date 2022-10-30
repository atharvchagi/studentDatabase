#include "ac1516_header.h"

void addStudent()

{
    string lName;
    string fName;
    int studentID;
    int numTests;

    Student newstd;

    cout << "Enter the last name: ";
    getline(cin, lName);
    cout << "Enter the first name: ";
    getline(cin, fName);
    cout << "Enter ID number:";
    cin >> studentID;
    cin.ignore();
    cout << "How many tests taken? ";
    cin >> numTests;
    cin.ignore();

    // int testScores[numTests];

    newstd.ptrScores;

    newstd.ptrScores = new int[numTests];

    for (int i = 0; i < numTests; ++i)
    {
        cout << "Enter test score #" << i + 1 << ": ";
        cin >> newstd.ptrScores[i];
    }

    newstd.name = lName + "," + fName;
    studentID;

    ofstream fout;

    fout.open("student.dat", ios::app);

    if (fout.fail())
    {
        cout << "Cannot open file for output.";
    }

    fout << "\n"
         << newstd.name << "," << studentID << "," << numTests << ",";

    for (int i = 0; i < numTests; ++i)
    {
        fout << newstd.ptrScores[i] << ",";
    }

    fout.close();
    delete[] newstd.ptrScores;
}

void removeStudent(int ID)
{
    int numStudents = getNumber();

    Student *std;
    std = new Student[numStudents];
    // Student std[numStudents];

    ifstream fin;

    fin.open("student.dat");

    string fName[numStudents];
    string lName[numStudents];
    int studentID[numStudents];
    string testsTaken[numStudents];
    string Dummy;
    int RealTestScores[10];

    for (int i = 0; i < numStudents; ++i)
    {
        getline(fin, lName[i], ',');
        getline(fin, fName[i], ',');

        std[i].name = lName[i] + "," + fName[i];

        getline(fin, Dummy, ',');

        studentID[i] = stoi(Dummy);

        getline(fin, testsTaken[i], ',');

        std[i].testsTaken = stoi(testsTaken[i]);

        int testScores[std[i].testsTaken];

        for (int j = 0; j < std[i].testsTaken; ++j)
        {
            getline(fin, Dummy, ',');
            testScores[i] = stoi(Dummy);
            RealTestScores[i] = testScores[i];
        }
    }

    bool match = false;
    int matchIndex;
    for (int i = 0; i < numStudents; ++i)
    {
        if (studentID[i] == ID)
        {
            match = true;
            matchIndex = i;
        }
    }

    if (!match)
    {
        cout << "Student does not exist";
    }

    if (match)
    {
        ofstream fout;

        fout.open("student.dat");

        if (fout.fail())
        {
            cout << "File couldn't be opened for output.";
        }

        for (int i = 0; i < numStudents; ++i)
        {
            if (i != matchIndex)
            {

                fout << std[i].name << "," << studentID[i] << "," << std[i].testsTaken << ",";

                for (int j = 0; j < std[i].testsTaken; ++j)
                {
                    fout << RealTestScores[j] << ",";
                }
            }
        }
        fout.close();
    }
    fin.close();
    delete[] std;
    cout << "Student has been removed.";
}

void display()
{
    ifstream fin;
    int numStudents = getNumber();
    Student *std;
    std = new Student[numStudents];

    fin.open("student.dat");

    string fName;
    string lName;
    string dummy;
    int numTests;

    for (int i = 0; i < numStudents; ++i)
    {
        getline(fin, lName, ',');
        getline(fin, fName, ',');

        std[i].name = lName + "," + fName;

        getline(fin, dummy, ',');

        std[i].stuID = stoi(dummy);

        getline(fin, dummy, ',');

        int numTests = stoi(dummy);

        std[i].testsTaken = numTests;

        std[i].ptrScores = new int[numTests];

        for (int j = 0; j < numTests; ++j)
        {
            getline(fin, dummy, ',');
            std[i].ptrScores[j] = stoi(dummy);
        }
    }

    for (int i = 0; i < numStudents; ++i)
    {
        cout << std[i].name;
        cout << setw(15) << std[i].stuID;
        for (int j = 0; j < std[i].testsTaken; ++j)
        {
            cout << setw(5) << std[i].ptrScores[j];
        }
    }
    fin.close();
    delete[] std->ptrScores;
    delete[] std;
}

void search(int ID)
{
    ifstream fin;
    int numStudents = getNumber();
    Student *std;

    std = new Student[numStudents];

    fin.open("student.dat");

    if (fin.fail())
    {
        cout << "File couldn't be opened";
    }
    string fName;
    string lName;
    string dummy;
    int matchIndex;
    int numTests;
    bool match = false;

    for (int i = 0; i < numStudents; ++i)
    {
        getline(fin, lName, ',');
        getline(fin, fName, ',');

        std[i].name = lName + "," + fName;

        getline(fin, dummy, ',');

        std[i].stuID = stoi(dummy);

        if (std[i].stuID == ID)
        {
            matchIndex = i;
            match = true;
        }

        getline(fin, dummy, ',');

        std[i].testsTaken = stoi(dummy);

        std[i].ptrScores = new int[std[i].testsTaken];

        for (int j = 0; j < std[i].testsTaken; ++j)
        {
            getline(fin, dummy, ',');
            std[i].ptrScores[j] = stoi(dummy);
        }
    }
    if (!match)
    {
        cout << "Student not found.";
    }
    else
    {
        cout << setw(30) << std[matchIndex].name;
        cout.width(15);
        cout << std[matchIndex].stuID;
        for (int j = 0; j < std[matchIndex].testsTaken; ++j)
        {
            cout << setw(5) << std[matchIndex].ptrScores[j];
        }
    }
    for (int i = 0; i < numStudents; ++i)
    {
        delete[] std[i].ptrScores;
    }
    delete[] std;
    fin.close();
}

int findMinimum(int arr[], int size)
{
    int min = 0;
    if (size == 5)
    {
        for (int i = 0; i < size; ++i)
        {
            if (min > arr[i])
            {
                min = arr[i];
            }
        }
    }
    return min;
}

void exportResults()
{
    ofstream fout;
    ifstream fin;
    fout.open("averages.dat");
    fin.open("student.dat");

    int numStudents = getNumber();

    Student *std = new Student[numStudents];

    string fName;
    string lName;
    string dummy;

    for (int i = 0; i < numStudents; ++i)
    {
        getline(fin, lName, ',');
        getline(fin, fName, ',');

        std[i].name = lName + "," + fName;

        getline(fin, dummy, ',');

        std[i].stuID = stoi(dummy);

        getline(fin, dummy, ',');

        std[i].testsTaken = stoi(dummy);

        std[i].ptrScores = new int[std[i].testsTaken];

        for (int j = 0; j < std[i].testsTaken; ++j)
        {
            getline(fin, dummy, ',');
            std[i].ptrScores[j] = stoi(dummy);
        }
    }
    int min;
    double sum;
    double avg;
    for (int i = 0; i < numStudents; ++i)
    {
        sum = 0;
        for (int j = 0; j < std[i].testsTaken; ++j)
        {
            sum += std[i].ptrScores[j];
        }
        min = findMinimum(std[i].ptrScores, std[i].testsTaken);
        sum -= min;
        if (std[i].testsTaken == 5)
        {
            avg = sum / (static_cast<double>(std[i].testsTaken) - 1);
        }
        else
        {
            avg = sum / (static_cast<double>(std[i].testsTaken));
        }
        fout << std[i].stuID << "\t" << avg << endl;
    }
    cout << "Results have been exported";
    fout.close();
    fin.close();
    for (int i = 0; i < numStudents; ++i)
    {
        delete[] std[i].ptrScores;
    }
    delete[] std;
}
