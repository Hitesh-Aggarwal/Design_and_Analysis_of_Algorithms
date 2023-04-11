#include <iostream>
using namespace std;
#define N 8

int q[N];

bool isPlaceOk(int r, int c) {
  for (int i = 0; i < r; i++)
    if ((q[i] == c) || (i + q[i] == r + c) || (i - q[i] == r - c)) return false;
  return true;
}

void print_solution() {
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      if (q[i] == j)
        cout << " X ";
      else
        cout << " - ";
    }
    cout << endl;
  }
  cout << endl;
}

void place_queens(int k) {
  if (k >= N)
    print_solution();
  else {
    for (int c = 0; c < N; c++) {
      if (isPlaceOk(k, c)) {
        q[k] = c;
        place_queens(k + 1);
      }
    }
  }
}

int main(int argc, char *argv[]) {
  place_queens(0);
  return 0;
}
