#include <cstdlib>
#include <iostream>
#include <vector>

using std::vector;
using std::cin;
using std::cout;
using std::endl;

/* Complie:
g++ -pipe -O2 -std=c++11 change.cpp -o change
g++ -pipe -O2 -std=c++14 <filename> -lm
./a.out
*/

/*
Changing Money
*/
int get_change(int m) {
  // Create Array of denominations, that is, 1, 5, and 10.
  int deno[] = {1, 5, 10};
  int n = sizeof(deno) / sizeof(deno[0]);

  // Initialize result
  //vector<int> ans;
  int size = 0;

  // Traverse through all denomination
  for (int i=n-1; i>=0; i--){
    // Find denominations
    while (m >= deno[i]){
      m -= deno[i];
      //ans.push_back(deno[i]);
      size++;
    }
  }

  return size;
}


int main() {
  int m;
  cin >> m;
  cout << get_change(m) << '\n';
}
