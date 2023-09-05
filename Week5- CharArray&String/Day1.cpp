#include <iostream>
using namespace std;

int getLength(char length[]) {
  int count = 0;
  for(int i = 0; i < length[i] != '\0'; i++) {
    count++;
  }
  return count;
}

int getFullLength(char full_length[]) {
  int count = 0;
  for(int i = 0; i < full_length[i] != '\0'; i++) {
    count++;
  }
  return count;
}

void reverseChar(char name[]) {
  int i = 0;
  int n = getFullLength(name);
  int j = n-1;

  while(i <= j) {
    swap(name[i], name[j]);
    i++;
    j--;
  }
}

void replaceSpaces(char ch[]) {
  int i = 0;
  int n = sizeof(ch);

  while(i < n) {
    if(ch[i] == ' ') {
      ch[i] = '@';
    }
    i++;
  }
}

bool findPalindrome(char ch[]) {
  int i = 0;
  int n = getLength(ch);
  int j = n-1;

  while(i < j) {
    if(ch[i] != ch[j]) {
      return false;
    }
    i++;
    j--;
  }
  return true;
}

void convertIntoUppercase(char ch[]) {
  int n = getLength(ch);
  for(int i = 0; i < n; i++) {
    if(ch[i] >= 'a' && ch[i] <= 'z') {//ignores if char already uppercase
      ch[i] = ch[i] - 'a' + 'A';
    }
  }
}

void convertIntoLowercase(char ch[]) {
  int n = getLength(ch); 
  for(int i = 0; i < n; i++) {
    if(ch[i] >= 'A' && ch[i] <= 'Z') {//ignores if char already lowercase
      ch[i] = ch[i] - 'A' + 'a';
    }
  }
}

int main() {

  // Convert into LowerCase
  /*
  char ch[100];
  cout << "Enter UpperCase Character: ";
  cin.getline(ch, 50);
  convertIntoLowercase(ch);
  cout << ch;
  */

  // Convert into UpperCase
  /*
  char ch[100];
  cout << "Enter LowerCase Character: ";
  cin.getline(ch, 50);
  convertIntoUppercase(ch);
  cout << ch;
  */
  
  // Find Palindrome or Not
  /*
  char ch[100];
  cout << "Enter Character: ";
  cin >> ch;
  if(findPalindrome(ch)) {
    cout << "Palindrome Character";
  }
  else {
    cout << "Not Palindrome";
  } */
  
  // Replace all spaces with @
  /*
  char ch[100];
  cout << "Enter Characters: ";
  cin.getline(ch, 50);
  replaceSpaces(ch);
  cout << ch;
  */
  
  // Reverse a String
  /*
  char name[100];
  cout << "Enter Name: ";
  cin.getline(name, 50);
  reverseChar(name);
  cout << "Reversed Name: " << name;
  */
  
  // char length[100];
  // cout << "Enter First Name: ";
  // cin >> length;
  // cout << getLength(length);

  // char full_length[100];
  // cout << "Enter Full Name: ";
  // cin.getline(full_length, 50);
  // cout << getFullLength(full_length);

  // char name[100];
  // cin.getline(name, 50);
  // cout << name;

  // char ch[100];
  // ch[0] = 'a';
  // ch[1] = 'b';
  // cin >> ch[2];
  // cout << ch[0] << ch[1] << ch[2];
 
  // char name[100];
  // cout << "Enter your Name: ";
  // cin >> name;
  // cout << "Hello " << name;

  return 0;  
}