#include <iostream>
using namespace std;

#define N 100

int pivot(int arr[], int low, int high) {
  int i = low - 1;
  int temp;
  for (int j = low; j <= high; j++) {
    if (arr[j] < arr[high]) {
      i++;
      temp = arr[i];
      arr[i] = arr[j];
      arr[j] = temp;
    }
  }
  temp = arr[high];
  arr[high] = arr[i + 1];
  arr[i + 1] = temp;
  return i + 1;
}

void quick_sort(int arr[], int low, int high) {
  if (low < high) {
    int p = pivot(arr, low, high);
    quick_sort(arr, low, p - 1);
    quick_sort(arr, p + 1, high);
  }
}

int main(int argc, char *argv[]) {
  int arr[N];
  for (int i = 0; i < N; i++)
    arr[i] = N - i;
  quick_sort(arr, 0, N - 1);
  for (int i = 0; i < N; i++)
    cout << arr[i] << " ";
  cout << endl;
  return 0;
}
