#include <iostream>
using namespace std;

void addStrings(string&num1, int p1, string&num2, int p2, int carry, string&ans) {
	//base case
	if(p1 < 0 && p2 < 0) {
		if(carry > 0) {
			ans.push_back(carry + '0');
			return;
		}
		return;
	}

	//ek case solve
	int n1 = (p1 >= 0 ? num1[p1] : '0') - '0'; //condition case and convert to integer
	int n2 = (p2 >= 0 ? num2[p2] : '0') - '0';
	int csum = n1 + n2 + carry; //current sum
	int digit = csum % 10; // extracting digit to add in ans
	carry = csum / 10; // extracting digit to carry
	ans.push_back(digit + '0');

	//baaki RE dek lega
	addStrings(num1, p1-1, num2, p2-1, carry, ans);
}

int main() {
	string num1 = "456";
	string num2 = "77";
	
	int p1 = num1.size()-1; //create pointers to iterate on digits
	int p2 = num2.size()-1;
	int carry = 0;
	string ans = "";

	addStrings(num1, p1, num2, p2, carry, ans);
    //reverse(ans.begin(), ans.end()); //reverse not working else good
	cout << ans ;
  
}
