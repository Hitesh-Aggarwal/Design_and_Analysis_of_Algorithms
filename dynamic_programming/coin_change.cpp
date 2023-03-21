#include <iostream>
using namespace std;

#define N 5
#define GOAL 19

void fill_arrays(int *coins, int *C, int *S) {
  C[0] = 0;
  for (int i = 1; i <= GOAL; i++) {
    int min = 100;
    for (int w = 0; w < N; w++)
      if (coins[w] <= i)
        if (min > 1 + C[i - coins[w]]) {
          min = 1 + C[i - coins[w]];
          C[i] = min;
          S[i] = coins[w];
        }
  }
}

void print_sol(int *coins) {
  int C[GOAL + 1], S[GOAL + 1];
  fill_arrays(coins, C, S);
  int i = GOAL;
  while (i > 0) {
    cout << S[i] << " ";
    i = i - S[i];
  }
  cout << "\nTotal number of coins: " << C[GOAL] << endl;
}

int main(int argc, char *argv[]) {
  int coins[N] = {1, 2, 5, 7, 8};
  print_sol(coins);
  return 0;
}
