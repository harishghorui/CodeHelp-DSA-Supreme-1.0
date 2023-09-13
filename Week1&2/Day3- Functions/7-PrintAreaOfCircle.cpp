#include <iostream>
using namespace std;

float printAreaOfCircle(float radius) {
  float area = 3.14 * radius * radius;
  return area;
}

int main() {
  
    float radius;
    cout << "Enter Radius: ";
    cin >> radius;
    cout << "Area of Circle is " << printAreaOfCircle(radius);
  
}