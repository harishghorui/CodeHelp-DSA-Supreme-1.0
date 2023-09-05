#include <iostream>
using namespace std;

void add2Numbers() {
  int a, b;
  cout << "Enter Number 'a': ";
  cin >> a;
  cout << "Enter Number 'b': ";
  cin >> b;

  cout << "Sum is " << a+b;
}

void countTillN(int n) {
  for(int num = 1; num <= n; num++) {
    cout << num << " ";
  }
}

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

int printNSum(int n) {
  int sum = 0;
  for(int i = 1; i <= n; i++) {
    sum += i;
  }
  return sum;
}

int printNEvenSum(int n) {
  int sum = 0;
  for(int i = 2; i <= n; i += 2) {
    sum += i;
  }
  return sum;
}

float printAreaOfCircle(float radius) {
  float area = 3.14 * radius * radius;
  return area;
}

int factorial(int n) {
  int fact = 1;
  for(int i = 1; i <= n; i++) {
    fact *= i;
  }
  return fact;
}

void checkPrimeNum(int n) {
  if(n == 1 || n == 0) {
    cout << n << " is neither Prime nor Composite";
    return;
  }
  for(int i = 2; i < n; i++) {
    if(n%i == 0) {
      cout << "Not a Prime Number";
      return;
    }
  }
  cout << "Prime Number";
}

int printPrimeNumbers(int n) {
  for(int i = 2; i < n; i++) {
    if(n%i == 0) {
      return 0;
    }
  }
  return n;
}

void printDigitsOfNumber(int num) {
  /* recursion funtion
  if(num <= 0) {
    return;
  }
  
  int remNum = num/10;
  printDigitsOfNumber(remNum);
  int digit = num % 10;
  
  cout << digit << endl;
  */
  
  for(; num > 0; num /= 10) {
    int digit = num % 10;
    cout << digit << " ";
  }
}

int countSetbit(int n) {
  int count = 0;
  while(n != 0) {
    if(n & 1) {
      count++;
    }
    n = n >> 1;
  }
  return count;
}

int reverseInteger(int x) {
  //Leetcode Prob- Reverse Integer
  int ans = 0;
  while(x > 0) {
    int digit = x % 10;
    ans = ans * 10 + digit;
    x = x / 10;
  }
  return ans;
}

int setKthBit(int n, int k) {
  int mask = 1 << k;
  return n | mask;
}

int main() {

  int n, k;
  cout << "Enter Number: ";
  cin >> n;
  cout << "Enter Kth Bit: ";
  cin >> k;
  cout << setKthBit(n, k);
  
  // int n;
  // cout << "Enter Number: ";
  // cin >> n;
  // cout << reverseInteger(n);
  
  // int n;
  // cout << "Enter N: ";
  // cin >> n;
  // cout << countSetbit(n);
  
  // int num;
  // cout << "Enter Number: ";
  // cin >> num;
  // printDigitsOfNumber(num);
  
  /* Array
  int row, col;
  cout << "Enter row & col: ";
  cin >> row >> col;
  int arr[row][col];
  
  cout << "Enter " << row*col << " elements: " << endl;
  for(int i = 0; i < row; i++) {
    for (int j=0; j < col; j++) {
      cin >> arr[i][j];
    }
  }
  
  //printArray
  for(int i = 0; i < row; i++) {
    for (int j=0; j < col; j++) {
      cout << arr[i][j] << " " ;
    }
    cout << endl;
  } */

  // int n;
  // cout << "Enter N: ";
  // cin >> n;
  // if(n > 1) {
  //   for(int i = 2; i <= n; i++) {
  //     int ans = printPrimeNumbers(i);
  //     if(ans > 0) {
  //       cout << ans << " ";
  //     }
  //   }
  // } else {
  //   cout << n << " is neither a Prime nor Composite";
  // }
  
  // int n;
  // cout << "Enter N: ";
  // cin >> n;
  // checkPrimeNum(n);
  
  // float radius;
  // cout << "Enter Radius: ";
  // cin >> radius;
  // cout << "Area of Circle is " << printAreaOfCircle(radius);
  
  
  // int n;
  // cout << "Enter N: ";
  // cin >> n;
  // cout << "Sum is " << printNEvenSum(n);

  
  // int n;
  // cout << "Enter N: ";
  // cin >> n;
  // cout << "Sum is " << printNSum(n);
  
  // int marks;
  // cout << "Enter your Marks: ";
  // cin >> marks;
  // cout << "Your Grade is: " << printGrade(marks);
  
  // bool a = true;
  // bool b = true;
  // //cout << (a^b);

  //add2Numbers();
  // int n;
  // cout << "Enter N: ";
  // cin >> n;
  // countTillN(n);
  
  // int a = -6;
  // a = a >> 1;
  // cout << a;

  // int age;
  // cout << "Enter Age: ";
  // cin >> age;
  // (age >= 18) ? cout << "Can Vote" : cout << "Cannot Vote";

  return 0;
}