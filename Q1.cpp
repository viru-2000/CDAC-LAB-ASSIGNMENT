//Student Database Management System
//File handling has been effectively used for each feature of this project
//Operation
//1. Add Records
//2. List Records
//3. Modify Records
//4. Delete Records

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
    ofstream outFile("employees.dat", ios::app);  
    
    cout << "Enter Employee ID: ";  
    cin >> emp.id;  
    cin.ignore();  
    cout << "Enter Employee Name: ";  
    getline(cin, emp.name);  
    cout << "Enter Employee Position: ";  
    getline(cin, emp.position);  

   
    outFile.close();  
    cout << "Employee added successfully!" << endl;  
}  

void searchEmployee(int id) {  
    Employee emp;  
    ifstream inFile("employees.dat", ios::app);  
    bool found = false;  

    while (inFile.read(reinterpret_cast<char*>(&emp), sizeof(emp))) {  
        if (emp.id == id) {  
            cout << "Employee Found!" << endl;  
            cout << "ID: " << emp.id << endl;  
            cout << "Name: " << emp.name << endl;  
            cout << "Position: " << emp.position << endl;  
            found = true;  
            break;  
        }  
    }  

    if (!found) {  
        cout << "Employee not found!" << endl;  
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
            cout << "Employee with ID " << emp.id << " deleted!" << endl;  
        } else {  
            outFile.write(reinterpret_cast<char*>(&emp), sizeof(emp));  
        }  
    }  

    inFile.close();  
    outFile.close();  
    
    remove("employees.dat"); 
    rename("temp.dat", "employees.dat"); 

    if (!found) {  
        cout << "Employee not found!" << endl;  
    }  
}  

void displayAllEmployees() {  
    Employee emp;  
    ifstream inFile("employees.dat", ios::binary);  
    cout << "Employee Records:" << endl;  

    while (inFile.read(reinterpret_cast<char*>(&emp), sizeof(emp))) {  
        cout << "ID: " << emp.id << " Name: " << emp.name << " Position: " << emp.position << endl;  
    }  

    inFile.close();  
}  

int main() {  
    int choice, id;  

    do {  
        cout << "\nEmployee Management System" << endl;  
        cout << "1. Add Employee" << endl;  
        cout << "2. Search Employee" << endl;  
        cout << "3. Delete Employee" << endl;  
        cout << "4. Display All Employees" << endl;  
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
                cout << "Exiting..." << endl;  
                break;  
            default:  
                cout << "Invalid choice! Please try again." << endl;  
        }  
    } while (choice != 5);  

    return 0;  
}