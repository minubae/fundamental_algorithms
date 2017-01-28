#include <cstdlib>
#include <iostream>
#include <vector>

using std::vector;
using std::cin;
using std::cout;
using std::endl;

/* Complie:
g++ -pipe -O2 -std=c++11 gcd.cpp -o gcd
g++ -pipe -O2 -std=c++14 <filename> -lm
./a.out
*/

/*
Greatest Common Divisor
*/

int gcd_naive(int a, int b) {
  int current_gcd = 1;
  for (int d = 2; d <= a && d <= b; d++) {
    if (a % d == 0 && b % d == 0) {
      if (d > current_gcd) {
        current_gcd = d;
      }
    }
  }
  return current_gcd;
}

int gcd_fast(int a, int b){
  if (b==0){
    return a;
  }
  int a_r = (int) a%b;
  return gcd_fast(b, a_r);
}

int main() {

  int a, b;
  cin >> a >> b;
  cout << gcd_fast(a, b) << endl;
  return 0;
}
