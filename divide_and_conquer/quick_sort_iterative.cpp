#include <iostream>
using namespace std;

#define N 10

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

void quick_sort(int arr[], int n) {
  int low = 0;
  int high = n - 1;
  int stack[n];
  int top = -1;
  stack[++top] = low;
  stack[++top] = high;
  while (top >= 0) {
    high = stack[top--];
    low = stack[top--];
    int p = pivot(arr, low, high);
    if (p - 1 > low) {
      stack[++top] = low;
      stack[++top] = p - 1;
    }
    if (p + 1 < high) {
      stack[++top] = p + 1;
      stack[++top] = high;
    }
  }
}

int main(int argc, char *argv[]) {
  int arr[N];
  for (int i = 0; i < N; i++)
    arr[i] = N - i;
  quick_sort(arr, N);
  for (int i = 0; i < N; i++)
    cout << arr[i] << " ";
  cout << endl;
  return 0;
}
