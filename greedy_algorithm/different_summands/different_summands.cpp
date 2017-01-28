#include <iostream>
#include <vector>

using std::vector;

/* Complie:
g++ -pipe -O2 -std=c++11 different_summands.cpp -o different_summands
g++ -pipe -O2 -std=c++14 <filename> -lm
./a.out
*/

/*
Different Summands
*/

vector<int> optimal_summands(int n) {
  vector<int> summands;
  if(n<=2) {
	  summands.push_back(n);
  }
  else {
	  int l = 1;
	  while(n > 2*l) {
		  summands.push_back(l);
		  n -= l;
		  l++;
	  }
	  summands.push_back(n);
  }
  return summands;
}

int main() {
  int n;
  std::cin >> n;
  vector<int> summands = optimal_summands(n);
  std::cout << summands.size() << '\n';
  for (size_t i = 0; i < summands.size(); ++i) {
    std::cout << summands[i] << ' ';
  }
}
