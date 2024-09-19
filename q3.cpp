//Write a C++ program to create a class Student with data members Roll_No, Student_Name, Class. Write
//member functions to accept and display Student information also display count of students. (Use Static
//data member and Static member function)



#include <iostream>  
#include <string>  
using namespace std;  

class Student {  
private:  
    int Roll_No;  
    string Student_Name;  
    string Class;  
    static int Student_Count;  

public:  
     
    Student() {  
        Roll_No = 0;  
        Student_Name ;
		Class; 
    }  

 
    void acceptInfo() {  
        cout << "\nEnter Roll No: ";  
        cin >> Roll_No;  
        cout << "\nEnter Student Name: ";  
        cin.ignore();  
        getline(cin, Student_Name);  
        cout << "\nEnter Class: ";  
        getline(cin, Class);  
        Student_Count++;  
    }  

    void displayInfo() const {  
        cout << "\nRoll No: " << Roll_No;  
        cout << "\nStudent Name: " << Student_Name;  
        cout << "\nClass: " << Class ;  
    }  


    static void displayCount() {  
        cout << "\nTotal Students: " << Student_Count;  
    }  
};  
  
int Student::Student_Count = 0;  

int main() {  
    int numStudents;  
    cout << "\nEnter the number of students: ";  
    cin >> numStudents;  
    Student* students = new Student[numStudents];  

    
    for (int i = 0; i < numStudents; i++) {   
        students[i].acceptInfo(); 
//		students[i].displayInfo();  
    }  

 
    cout << "\nStudent Information:";  
    for (int i = 0; i < numStudents; i++) {   
        students[i].displayInfo();  
    }  


    Student::displayCount();  

   
    delete[] students;  

    return 0;  
}