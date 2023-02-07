#include <iostream>
using namespace std;

#define N 10

int inv_count = 0;

void merge(int arr[], int low, int mid, int high) {
  int temp[high - low + 1];
  int k = 0, i = low, j = mid + 1;
  while (i <= mid && j <= high) {
    if (arr[i] <= arr[j])
      temp[k++] = arr[i++];
    else{
      temp[k++] = arr[j++];
      inv_count = inv_count + mid - i + 1;
    }
  }
  while (i <= mid)
    temp[k++] = arr[i++];
  while (j <= high)
    temp[k++] = arr[j++];
  k = 0;
  for (i = low; i <= high; i++)
    arr[i] = temp[k++];
}

void merge_sort(int arr[], int low, int high) {
  if (low < high) {
    int mid = low + (high - low) / 2;
    merge_sort(arr, low, mid);
    merge_sort(arr, mid + 1, high);
    merge(arr, low, mid, high);
  }
}

int main() {
  int arr[N];
  for (int i = 0; i < N; i++)
    arr[i] = N - i;

  merge_sort(arr, 0, N - 1);
  for (int i = 0; i < N; i++)
    cout << arr[i] << " ";
  cout << endl;
  cout << inv_count << endl;
  return 0;
}

