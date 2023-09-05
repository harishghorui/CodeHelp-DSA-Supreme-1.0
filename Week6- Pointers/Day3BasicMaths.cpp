#include <iostream>
#include <math.h>
#include <vector>
using namespace std;

// Count Prime Numbers till < N
/* 1st Method
bool checkPrime1(int i) {
  for(int j = 2; j < i; j++) {
    if(i % j == 0) {
      return false;
    }
  }
  return true;
}
int countPrimeNo(int n) {
  int count = 0;
  
  for(int i = 2; i < n; i++) {
    if(checkPrime1(i)) {
      count++;
    }
  }
  return count;
} */

/* 2nd Method- Sqrt Approch
bool checkPrime(int i) {
  int sqrtI = sqrt(i);
  for(int j = 2; j <= sqrtI; j++) {
    if(i % j == 0) {
      return false;
    }
  }
  return true;
}
int countPrimeBySqrt(int n) {
  int count = 0;
  
  for(int i = 2; i < n; i++) {
    cout << "i = " <<i << endl;
    if(checkPrime(i)) {
      count++;
    }
    cout << endl << endl;
  }
  return count;
} */

// 3rd Method- Seive of Eratosthenes
int countPrimeBySeive(int n) {

  int ans = 0;
  vector<bool> prime(n, true);
  prime[0] = prime[1] = false;

  /*
  for(int i = 2; i < n; i++) {
    if(prime[i]) {
      ans++;
      
      int j = i * 2;
      while(j < n) {
        prime[j] = false;
        j += i;
      }
    }
  } // T.C -->> O(n log log n)
  */
  
  // Optimising Seive Inner and Outer Loop
  for(int i = 2; i*i <= n; i++) { //outer loop runs till sqrt(n)
    if(prime[i]) {
      
      int j = i*i; //inner loop starts from i*i instead of i*2
      while(j < n) {
        prime[j] = false;
        j += i;
      }
    }
  }
  // Counting primes
  for(int i = 2; i < n; i++) {
    if(prime[i]) {
      ans++;
    }
  }
  return ans;

  // T.C -->> O(n log log n)
}

// 4th Method- Segmented Seive (Prime in a Range)
vector<bool> normalSeive(int n) {

  vector<bool> prime(n, true);
  prime[0] = prime[1] = false;
  
  // Optimising Seive Inner and Outer Loop
  for(int i = 2; i*i <= n; i++) { //outer loop runs till sqrt(n)
    if(prime[i]) {
      
      int j = i*i; //inner loop starts from i*i instead of i*2
      while(j < n) {
        prime[j] = false;
        j += i;
      }
    }
  }
  return prime;
  // T.C -->> O(n log log n)
}

vector<bool> segmentedSieve(int L, int R) {
  //getting Primes till sqrtR using normal Sieve function
  vector<bool> sieve = normalSeive(sqrt(R));
  vector<int> basePrimes;
  for(int i = 0; i <= sieve.size(); i++) {
    if(sieve[i]) {
      basePrimes.push_back(i);
    }
  }

  vector<bool> segSieve(R-L+1, true);
  if(L == 0 || L == 1) {
    segSieve[L] = false;
  }

  for(auto prime : basePrimes) {
    int firstMultiple = (L/prime) * prime;
    if(firstMultiple < L) {
      firstMultiple += prime;
    }

    int j = max(firstMultiple, prime*prime);
    while(j <= R) {
      segSieve[j-L] = false;
      j += prime;
    }
  }

  return segSieve;
}
/* My Method- RunTime Error
bool checkPrime(int i) {
  int sqrtI = sqrt(i);
  for(int j = 2; j <= sqrtI; j++) {
    if(i % j == 0) {
      return false;
    }
  }
  return true;
}

vector<int> segmentedSieve(int m, int n) {
  vector<int> ans;
  cout << "Ans Vector Created: " << endl;
  int size_v = (n-m) + 1;
  
  vector<bool> seg_arr(size_v, true);
  for(int i = m; i <= n; i++) {
    seg_arr[0] = seg_arr[1] = false;
    if(seg_arr[i]) {
      if(checkPrime(i)) {
        ans.push_back(i);
        int multiple = i;
        while(multiple <= n) {
          seg_arr[multiple] = false;
          multiple += i;
        }
      }
      else {
        int multiple = i;
        while(multiple <= n) {
          seg_arr[multiple] = false;
          multiple += i;
        }
      }
    }
  }
  return ans;
} */

int gcd(int A, int B) {
  if(A == 0) return B;
  if(B == 0) return A;

  while(A > 0 && B > 0) {
    if(A > B) {
      A -= B;
    }
    else {
      B -= A;
    }
  }
  return A == 0 ? B : A ;
}

int lcm(int a, int b) {
  int gcdAB = gcd(a , b);
  int lcm = a * b / gcdAB ;
  return lcm;
}

int slowExponential(int a, int b) {
  int ans = 1;
  while(b > 0) {
    ans *= a;
    b--;
  }
  return ans;
} // T.C -->> O(b);

int fastExponential(int a, int b) {
  int ans = 1;
  while(b > 0) {
    if(b & 1) {
      // odd
      ans *= a;
    }
    a = a * a;
    b>>=1; // b = b/2
  }
  return ans;
} // T.C -->> O(logb)

int main() {
  // Count Prime - LeetCode 204
  // int n;
  // cout << "Enter N: " ;
  // cin >> n;

  // int count = countPrimeNo(n);
  // // int count = countPrimeBySqrt(n);
  // int count = countPrimeBySeive(n);
  // cout << "Count of Prime Numbers are: " << count;

  // Segmented Sieve- Prime Numbers in a Range
  int L, R;
  cout << "Enter M & N: " ;
  cin >> L >> R;
  
  vector<bool> segSieve = segmentedSieve(L, R);
  for(int i = 0; i < segSieve.size(); i++) {
    if(segSieve[i]) {
      cout << i + L << " ";
    }
  }
  
  // GFG Problem- Product of Primes

  /* Find GCD(Greatest Common Divisor) & LCM(Least Common Multiple)
  int a , b;
  cout << "Enter A & B: ";
  cin >> a >> b;

  //cout << gcd(a , b);
  //cout << lcm(a , b);
  */

  /* Slow/Normal Exponential & Fast Exponential
  int a, b;
  cout << "Enter A & B: ";
  cin >> a >> b;

  cout << "SlowExponential: " << slowExponential(a , b) << endl;
  cout << "FastExponential: " << fastExponential(a , b) << endl;
  */
  // GFG Problem- Modular Exponentiation for large numbers (SOLVED)

  return 0;
}