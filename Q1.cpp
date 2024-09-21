

#include <iostream>  
#include <fstream>  
#include <string>  
using namespace std;  

struct Employee {  
    int id;  
    string name;  
    string position;  
};  

void addEmployee() {  
    Employee emp;  
    ofstream outFile("employees.dat", ios::app | ios::binary);  
    
    cout << "Enter Employee ID: ";  
    cin >> emp.id;  
    cin.ignore();  
    cout << "Enter Employee Name: ";  
    getline(cin, emp.name);  
    cout << "Enter Employee Position: ";  
    getline(cin, emp.position);  

    outFile.write(reinterpret_cast<char*>(&emp), sizeof(emp));  
    outFile.close();  
    cout << "Employee added successfully!";  
}  

void searchEmployee(int id) {  
    Employee emp;  
    ifstream inFile("employees.dat", ios::binary);  
    bool found = false;  

    while (inFile.read(reinterpret_cast<char*>(&emp), sizeof(emp))) {  
        if (emp.id == id) {  
            cout << "Employee Found!" ;  
            cout << "ID: " << emp.id ;  
            cout << "Name: " << emp.name ;  
            cout << "Position: " << emp.position;  
            found = true;  
            break;  
        }  
    }  

    if (!found) {  
        cout << "Employee not found!";  
    }  

    inFile.close();  
}  

void deleteEmployee(int id) {  
    Employee emp;  
    ifstream inFile("employees.dat", ios::binary);  
    ofstream outFile("temp.dat", ios::binary);  
    bool found = false;  

    while (inFile.read(reinterpret_cast<char*>(&emp), sizeof(emp))) {  
        if (emp.id == id) {  
            found = true;  
            cout << "Employee with ID " << emp.id << " deleted!";  
        } else {  
            outFile.write(reinterpret_cast<char*>(&emp), sizeof(emp));  
        }  
    }  

    inFile.close();  
    outFile.close();  
    
    remove("employees.dat");  
    rename("temp.dat", "employees.dat");

    if (!found) {  
        cout << "Employee not found!" ;  
    }  
}  

void displayAllEmployees() {  
    Employee emp;  
    ifstream inFile("employees.dat", ios::binary);  
    cout << "Employee Records:" ;  

    while (inFile.read(reinterpret_cast<char*>(&emp), sizeof(emp))) {  
        cout << "ID: " << emp.id << " Name: " << emp.name << " Position: " << emp.position;  
    }  

    inFile.close();  
}  

int main() {  
    int choice, id;  

    do {  
        cout << "\nEmployee Management System";  
        cout << "1. Add Employee" ;  
        cout << "2. Search Employee" ;  
        cout << "3. Delete Employee" ;  
        cout << "4. Display All Employees" ;  
        cout << "5. Exit" << endl;  
        cout << "Enter your choice: ";  
        cin >> choice;  

        switch (choice) {  
            case 1:  
                addEmployee();  
                break;  
            case 2:  
                cout << "Enter Employee ID to search: ";  
                cin >> id;  
                searchEmployee(id);  
                break;  
            case 3:  
                cout << "Enter Employee ID to delete: ";  
                cin >> id;  
                deleteEmployee(id);  
                break;  
            case 4:  
                displayAllEmployees();  
                break;  
            case 5:  
                cout << "Exiting..." ;  
                break;  
            default:  
                cout << "Invalid choice! Please try again.";  
        }  
    } while (choice != 5);  

    return 0;  
}
