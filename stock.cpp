#include <iostream>
using namespace std;

#define N 100

void cross(int prices[], int low, int mid, int high, int *min_i, int *max_j,
           int *max_profit) {
  int i = mid, j = mid + 1;
  int left_profit = 0;
  int right_profit = 0;
  int p = i, q = i;
  while (i >= low) {
    if (prices[mid] - prices[i] > left_profit) {
      left_profit = prices[mid] - prices[i];
      p = i;
    }
    i--;
  }
  while (j <= high) {
    if (prices[j] - prices[mid] > right_profit) {
      right_profit = prices[j] - prices[mid];
      q = j;
    }
    j++;
  }
  if ((left_profit + right_profit) > *max_profit) {
    *max_profit = left_profit + right_profit;
    *min_i = p;
    *max_j = q;
  }
}

void maximise_profit(int prices[], int low, int high, int *min_i, int *max_j,
                     int *max_profit) {
  if (low < high) {
    int mid = low + (high - low) / 2;
    maximise_profit(prices, low, mid, min_i, max_j, max_profit);
    maximise_profit(prices, mid + 1, high, min_i, max_j, max_profit);
    cross(prices, low, mid, high, min_i, max_j, max_profit);
  }
}

int main(int argc, char *argv[]) {
  int prices[N] = {54,  59, 72, 84, 53, 30, 25, 36, 83, 4,  89, 92, 78, 81, 62,
                   31,  35, 65, 15, 21, 77, 27, 18, 13, 95, 34, 41, 74, 29, 39,
                   100, 28, 93, 32, 79, 75, 42, 3,  87, 80, 1,  38, 51, 40, 33,
                   16,  26, 50, 68, 61, 5,  97, 20, 56, 73, 76, 47, 96, 58, 2,
                   24,  60, 22, 94, 10, 11, 88, 43, 52, 55, 14, 69, 17, 57, 12,
                   7,   23, 86, 9,  99, 48, 70, 63, 44, 66, 67, 64, 8,  49, 6,
                   82,  71, 45, 37, 46, 85, 90, 98, 19, 91};
  int max_profit = 0;
  int min_i = 0;
  int max_j = 0;
  maximise_profit(prices, 0, N - 1, &min_i, &max_j, &max_profit);
  cout << min_i << " " << max_j << " " << max_profit << endl;
  return 0;
}
