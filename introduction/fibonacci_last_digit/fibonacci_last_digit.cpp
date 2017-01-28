#include <cstdlib>
#include <iostream>
#include <vector>

using std::vector;
using std::cin;
using std::cout;

/* Complie:
g++ -pipe -O2 -std=c++11 fibonacci_last_digit.cpp -o fibonacci_last_digit
g++ -pipe -O2 -std=c++14 <filename> -lm
./a.out
*/

int get_fibonacci_last_digit_naive(const vector<int>& numbers) { //const vector<int>& numbers
    int n = numbers.size();
    if (n <= 1)
        return n;

    int previous = 0;
    int current  = 1;

    for (int i = 0; i < n - 1; ++i) {
        int tmp_previous = previous;
        previous = current;
        current = (tmp_previous + current);
    }

    return current % 10;
}

int get_fibonacci_last_digit(const vector<int>& numbers) { //const vector<int>& numbers
    int n = numbers.size();
    if (n <= 1)
        return n;

    int previous = 0;
    int current  = 1;

    for (int i = 0; i < n - 1; ++i) {
        int tmp_previous = previous;
        previous = current;
        current = (tmp_previous + current) % 10;
    }

    return current;
}

int main() {
/*
  while (true) {
    int n = rand() % 40 + 2;
    //int n = rand() % 4 + 2;
    //int n = rand() % 100 + 2;
    cout << n << "\n";
    vector<int> a;
    for (int i = 0; i < n; ++i) {
      a.push_back(rand() % 1000);
      //a.push_back(rand() % 10);
    }
    for (int i = 0; i < n; ++i) {
      cout << a[i] << ' ';
    }
    cout << "\n";
    long long res1 = get_fibonacci_last_digit_naive(a);
    long long res2 = get_fibonacci_last_digit(a);
    if (res1 != res2) {
      cout << "Wrong answer: " << res1 << ' ' << res2 << "\n";
      break;
    }
    else {
      cout << "OK\n";
    }
  }

  int n;
  cin >> n;
  int c = get_fibonacci_last_digit(n);
  cout << c << '\n';
*/

  int n;
  cin >> n;
  vector<int> numbers(n);
  /*for (int i = 0; i < n; ++i) {
      cin >> numbers[i];
  }*/

  int result = get_fibonacci_last_digit(numbers);
  cout << result << "\n";
  return 0;

}
