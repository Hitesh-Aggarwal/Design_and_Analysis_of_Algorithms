#include <iostream>
using namespace std;

#define N 4
#define CAP 20

typedef struct item {
  int id;
  int weight;
  int value;
} item;

void fill_knapsack(item *items, int *C) {
  for (int i = 0; i <= N; i++)
    C[i * (CAP + 1) + 0] = 0;
  for (int w = 0; w <= CAP; w++)
    C[w] = 0;
  for (int i = 1; i <= N; i++) {
    for (int w = 1; w <= CAP; w++) {
      if (items[i-1].weight <= w) {
        if (items[i-1].value + C[(i - 1) * (CAP + 1) + (w - items[i-1].weight)] >
            C[(i - 1) * (CAP + 1) + w])
          C[i * (CAP + 1) + w] =
              items[i-1].value + C[(i - 1) * (CAP + 1) + (w - items[i-1].weight)];
        else
          C[i * (CAP + 1) + w] = C[(i - 1) * (CAP + 1) + w];
      } else
        C[i * (CAP + 1) + w] = C[(i - 1) * (CAP + 1) + w];
    }
  }
}

void print_solution(item *items) {
  int C[N + 1][CAP + 1];
  fill_knapsack(items, (int *)C);
  int i = N, k = CAP;
  while (i > 0 && k > 0) {
    if (C[i][k] != C[i - 1][k]) {
      cout << items[i-1].id << " ";
      k = k - items[i-1].weight;
      i = i - 1;
    } else
      i = i - 1;
  }
  cout << "\nTotal Cost: " << C[N][CAP] << endl;
}

int main(int argc, char *argv[]) {
  item items[N] = {{1, 3, 10}, {2, 8, 4}, {3, 9, 9}, {4, 8, 11}};
  print_solution(items);
  return 0;
}
