#include <algorithm>
#include <iostream>
#include <vector>

using std::vector;

/* Complie:
g++ -pipe -O2 -std=c++11 majority_element.cpp -o majority_element
g++ -pipe -O2 -std=c++14 majority_element.cpp -lm
*/

/*
Majority Element
*/

int get_majority_element(vector<int> &a, int left, int right) {
  if (left == right) return -1;
  if (left + 1 == right) return a[left];
  
  sort(a.begin(), a.end());
  int count = 1;
  int element = -1;
  for(int i = 0; i < a.size(); i++) {
	  if(a[i] == element) {
		  count++;
	  }
	  else{
		  element = a[i];
		  count = 1;
	  }
	  if(count > a.size()/2)
		  return 1;
  }
  return -1;
}

int main() {
  int n;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < a.size(); ++i) {
    std::cin >> a[i];
  }
  std::cout << (get_majority_element(a, 0, a.size()) != -1) << '\n';
}
