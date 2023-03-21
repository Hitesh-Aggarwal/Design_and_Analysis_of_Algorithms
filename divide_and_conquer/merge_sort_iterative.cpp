#include <iostream>
using namespace std;

#define N 10

void merge(int arr[], int low, int mid, int high) {
  int temp[high - low + 1];
  int k = 0, i = low, j = mid + 1;
  while (i <= mid && j <= high) {
    if (arr[i] <= arr[j])
      temp[k++] = arr[i++];
    else
      temp[k++] = arr[j++];
  }
  while (i <= mid)
    temp[k++] = arr[i++];
  while (j <= high)
    temp[k++] = arr[j++];
  k = 0;
  for (i = low; i <= high; i++)
    arr[i] = temp[k++];
}

void merge_sort(int arr[], int n) {
  int right_end = n - 1;
  for (int size = 1; size <= n / 2; size *= 2) {
    for (int left_end = 0; left_end < n - (2 * size - 1); left_end += 2 * size) {
      right_end = left_end + 2 * size - 1;
      int mid = left_end + (right_end - left_end) / 2;
      cout << left_end << "\t" << right_end << "\t" << mid << endl;
      merge(arr, left_end, mid, right_end);
    }
    cout << right_end << "\t" << endl;
    merge(arr, 0, right_end, n - 1);
  }
}

int main() {
  int arr[N];
  for (int i = 0; i < N; i++)
    arr[i] = N - i;

  merge_sort(arr, N);
  for (int i = 0; i < N; i++)
    cout << arr[i] << " ";
  cout << endl;
  return 0;
}
