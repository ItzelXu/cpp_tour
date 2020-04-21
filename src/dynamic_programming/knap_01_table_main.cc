#include <iostream>
#include <map>
#include <string>
#include <vector>

#include "src/lib/utility.h"

int knapSack01(std::vector<int> &weights, std::vector<int> &values, int i,
               int W) {
  std::vector<std::vector<int>> d(values.size() + 1, std::vector<int>(W + 1));

  // we shift all indexes of i by 1
  for (int i = 0; i <= weights.size(); i++) {
    for (int w = 0; w <= W; w++) {
      if (i == 0 || w == 0) {
        d[i][w] = 0;
      } else if (weights[i - 1] > w) {
        d[i][w] = d[i - 1][w];
      } else {
        d[i][w] = std::max(values[i] + d[i - 1][w - weights[i]], d[i - 1][w]);
      }
    }
  }

  return d[values.size()][W];
}

int main() {
  std::vector<int> values = {60, 100, 120};
  std::vector<int> weights = {10, 20, 30};

  int W = 50;
  int n = knapSack01(weights, values, values.size() - 1, W);
  std::cout << "n: " << n << std::endl;
  return 0;
}