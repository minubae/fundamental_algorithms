#include <cstdlib>
#include <iostream>
#include <vector>

using std::vector;
using std::cin;
using std::cout;
using std::endl;

/* Complie:
g++ -pipe -O2 -std=c++11 lcm.cpp -o lcm
g++ -pipe -O2 -std=c++14 <filename> -lm
./a.out
*/

/*
Least Common Multiple
*/
int gcd(int a, int b){
  if (b==0){
    return a;
  }
  int a_r = (int) a%b;
  return gcd(b, a_r);
}

long long lcm_naive(int a, int b) {
  for (long l = 1; l <= (long long) a * b; ++l)
    if (l % a == 0 && l % b == 0)
      return l;

  return (long long) a * b;
}

long long lcm(long long a, long long b) {
  // lcm(a,b)*gcd(a,b) = a*b
  // lcm(a,b) = a*b / gcd(a,b)
  return a*b / gcd(a,b);
}

int main() {
  int a, b;
  cin >> a >> b;
  cout << lcm(a, b) << endl;
  return 0;
}
