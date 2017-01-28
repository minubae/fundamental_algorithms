#include <cstdlib>
#include <iostream>
#include <vector>
#include<string>

using namespace std;

using std::vector;
using std::min;
using std::cin;
using std::cout;
using std::endl;

/* Complie:
g++ -pipe -O2 -std=c++11 fractional_knapsack.cpp -o fractional_knapsack
g++ -pipe -O2 -std=c++14 <filename> -lm
./a.out
*/

/*
Fractional Knapsack
*/

int get_best_index(vector<double>& ratios) {
  double tmp_ratio = 0;
  int best_index = 0;

  for (int i = 0; i < ratios.size(); i++) {
    if (ratios[i] > tmp_ratio) {
      tmp_ratio = ratios[i];
      best_index = i;
      //printf("Best Index: %d\n", i);
    }
  }
  return best_index;
}

double get_optimal_value(int capacity, vector<int> weights, vector<int> values) {
  double value = 0.0;
  int n = weights.size();
  vector<double> ratios(n);

  //printf("Size: %d\n", n);
  // string weight("Weight: ");
  for(int i = 0; i < n; i++){
    //printf("Value[%d] : %d \n", i, values[i]);
    //printf("Weight[%d] : %d \n", i, weights[i]);
    //cout << weight << weights[i] << '\n';
  }

  while (capacity > 0) {

    int best_index = get_best_index(ratios);

    if (weights[best_index] > 0) {

      double a = min((double)capacity, (double)weights[best_index]);
      double ratio = (double) values[best_index] / (double) weights[best_index];
      value += a * ratio;
      weights[best_index] -= a;
      capacity -= a;

      if (weights[best_index] == 0) {
        weights.erase(weights.begin() + best_index);
        values.erase(values.begin() + best_index);
        ratios.erase(ratios.begin() + best_index);
      }
    }
  }

  return value;
}

int main() {
  int n;
  int capacity;
  cin >> n >> capacity;
  vector<int> values(n);
  vector<int> weights(n);
  for (int i = 0; i < n; i++) {
    cin >> values[i] >> weights[i];
  }

  double optimal_value = get_optimal_value(capacity, weights, values);

  cout.precision(10);
  cout << optimal_value << endl;
  return 0;
}
