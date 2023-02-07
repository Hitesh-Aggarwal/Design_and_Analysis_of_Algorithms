#include <iostream>
using namespace std;

int main(int argc, char *argv[]) {
  int n;    // no of rectangles
  int h, w; // height and width
  cout << "Enter n: ";
  cin >> n;
  cout << "Enter h: ";
  cin >> h;
  cout << "Enter w: ";
  cin >> w;
  int i = 1;
  int j = n * h * w;
  int mid = i;
  while (i < j) {
    mid = (i + j) / 2;
    int num_sqrs = (mid / w) * (mid / h);
    if (num_sqrs == n)
      break;
    else if (num_sqrs > n)
      j = mid;
    else
      i = mid + 1;
  }
  cout << mid << endl;
  return 0;
}
