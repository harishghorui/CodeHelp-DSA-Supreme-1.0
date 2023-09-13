#include <iostream>
using namespace std;

char printGrade(int marks) {
  // if(marks >= 90) return 'A';
  // else if(marks >= 80) return 'B';
  // else if(marks >= 70) return 'C';
  // else if(marks >= 60) return 'D';
  // else if(marks >= 40) return 'E';
  // else return 'F';

  switch(marks/10){
    case 10:
    case 9: return 'A'; break;
    case 8: return 'B'; break;
    case 7: return 'C'; break;
    case 6: return 'D'; break;
    case 5: return 'E'; break;
    default: return 'F'; break;
  }
}


int main() {

    int marks;
    cout << "Enter your Marks: ";
    cin >> marks;
    cout << "Your Grade is: " << printGrade(marks);
    
}