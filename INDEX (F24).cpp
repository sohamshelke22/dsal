#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>

using namespace std;

struct Employee {
    char name[20];
    int id;
    int salary;
};

struct Index {
    int id;
    int pos;
};

class EmployeeManager {
    Employee emp;
    Index idx;

public:
    void create();
    void display();
    void update();
    void remove();
    void append();
    void search();
};

void EmployeeManager::create() {
    ofstream dataFile("EMP.DAT", ios::binary);
    ofstream indexFile("IND.DAT", ios::binary);

    char ch = 'y';
    int pos = 0;

    while (ch == 'y') {
        cout << "\nEnter Name: ";
        cin >> emp.name;
        cout << "Enter ID: ";
        cin >> emp.id;
        cout << "Enter Salary: ";
        cin >> emp.salary;

        dataFile.write((char*)&emp, sizeof(emp));

        idx.id = emp.id;
        idx.pos = pos++;
        indexFile.write((char*)&idx, sizeof(idx));

        cout << "Add another record? (y/n): ";
        cin >> ch;
    }

    dataFile.close();
    indexFile.close();
}

void EmployeeManager::display() {
    ifstream dataFile("EMP.DAT", ios::binary);
    ifstream indexFile("IND.DAT", ios::binary);

    cout << "\nEmployee Records:\n";
    cout << left << setw(20) << "Name" << setw(10) << "ID" << setw(10) << "Salary" << endl;

    while (indexFile.read((char*)&idx, sizeof(idx))) {
        dataFile.seekg(idx.pos * sizeof(Employee));
        dataFile.read((char*)&emp, sizeof(emp));

        if (emp.id != -1) {
            cout << left << setw(20) << emp.name << setw(10) << emp.id << setw(10) << emp.salary << endl;
        }
    }

    dataFile.close();
    indexFile.close();
}

void EmployeeManager::update() {
    int id, pos = -1;
    cout << "\nEnter ID to update: ";
    cin >> id;

    fstream indexFile("IND.DAT", ios::in | ios::binary);
    while (indexFile.read((char*)&idx, sizeof(idx))) {
        if (idx.id == id) {
            pos = idx.pos;
            break;
        }
    }
    indexFile.close();

    if (pos == -1) {
        cout << "Record not found!\n";
        return;
    }

    cout << "Enter new name: ";
    cin >> emp.name;
    emp.id = id;
    cout << "Enter new salary: ";
    cin >> emp.salary;

    fstream dataFile("EMP.DAT", ios::in | ios::out | ios::binary);
    dataFile.seekp(pos * sizeof(Employee));
    dataFile.write((char*)&emp, sizeof(emp));
    dataFile.close();

    cout << "Record updated successfully!\n";
}

void EmployeeManager::remove() {
    int id, pos = -1;
    cout << "\nEnter ID to delete: ";
    cin >> id;

    fstream indexFile("IND.DAT", ios::in | ios::out | ios::binary);
    while (indexFile.read((char*)&idx, sizeof(idx))) {
        if (idx.id == id) {
            pos = idx.pos;
            break;
        }
    }

    if (pos == -1) {
        cout << "Record not found!\n";
        return;
    }

    emp.id = -1;
    emp.salary = -1;
    strcpy(emp.name, "");

    fstream dataFile("EMP.DAT", ios::in | ios::out | ios::binary);
    dataFile.seekp(pos * sizeof(Employee));
    dataFile.write((char*)&emp, sizeof(emp));
    dataFile.close();

    idx.id = -1;
    indexFile.seekp(pos * sizeof(Index));
    indexFile.write((char*)&idx, sizeof(idx));
    indexFile.close();

    cout << "Record deleted successfully!\n";
}

void EmployeeManager::append() {
    ifstream indexIn("IND.DAT", ios::binary);
    indexIn.seekg(0, ios::end);
    int pos = indexIn.tellg() / sizeof(Index);
    indexIn.close();

    ofstream dataFile("EMP.DAT", ios::app | ios::binary);
    ofstream indexFile("IND.DAT", ios::app | ios::binary);

    cout << "\nEnter Name: ";
    cin >> emp.name;
    cout << "Enter ID: ";
    cin >> emp.id;
    cout << "Enter Salary: ";
    cin >> emp.salary;

    dataFile.write((char*)&emp, sizeof(emp));

    idx.id = emp.id;
    idx.pos = pos;
    indexFile.write((char*)&idx, sizeof(idx));

    dataFile.close();
    indexFile.close();

    cout << "Record appended successfully!\n";
}

void EmployeeManager::search() {
    int id, pos = -1;
    cout << "\nEnter ID to search: ";
    cin >> id;

    ifstream indexFile("IND.DAT", ios::binary);
    while (indexFile.read((char*)&idx, sizeof(idx))) {
        if (idx.id == id) {
            pos = idx.pos;
            break;
        }
    }
    indexFile.close();

    if (pos == -1) {
        cout << "Record not found!\n";
        return;
    }

    ifstream dataFile("EMP.DAT", ios::binary);
    dataFile.seekg(pos * sizeof(Employee));
    dataFile.read((char*)&emp, sizeof(emp));
    dataFile.close();

    if (emp.id == -1) {
        cout << "Record not found!\n";
    } else {
        cout << "\nRecord Found:\n";
        cout << "Name: " << emp.name << "\nID: " << emp.id << "\nSalary: " << emp.salary << endl;
    }
}

int main() {
    EmployeeManager manager;
    int choice;
    char again;

    do {
        cout << "\n--- Employee Menu ---\n";
        cout << "1. Create\n2. Display\n3. Update\n4. Delete\n5. Append\n6. Search\n7. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1: manager.create(); break;
            case 2: manager.display(); break;
            case 3: manager.update(); break;
            case 4: manager.remove(); break;
            case 5: manager.append(); break;
            case 6: manager.search(); break;
            case 7: return 0;
            default: cout << "Invalid choice!\n";
        }

        cout << "\nBack to main menu? (y/n): ";
        cin >> again;
    } while (again == 'y');

    return 0;
}
