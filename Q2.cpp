//Write a program to print the area of two rectangles having sides (4,5) and (5,8) respectively by creating a
//class named 'Rectangle' with a function named 'Area' which returns the area. Length

#include <iostream> 
using namespace std; 

class Rectangle {  
private:  
    double length;  
    double width;  
public:  
   Rectangle(double l, double w) : length(l), width(w) {}
  
    double Area() {  
        return length*width;  
    }  
};  

int main() {  
    Rectangle r1(4, 5);  
    Rectangle r2(5, 8); 
    cout  <<"\n"<< r1.Area() ;  
    cout  << "\n"<<r2.Area() ;  

    return 0;  
}