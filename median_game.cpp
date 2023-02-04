#include <iostream>
using namespace std;
int n;

int find_median(int *arr, int l, int h) {
  int n = (h - l + 1);
  if (n % 2 == 1)
    return arr[(h + l) / 2];
  else
    return -1;
}

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

void merge_sort(int arr[], int low, int high) {
  if (low < high) {
    int mid = low + (high - low) / 2;
    merge_sort(arr, low, mid);
    merge_sort(arr, mid + 1, high);
    merge(arr, low, mid, high);
  }
}

void take_input(int *arr) {
  for (int i = 0; i < n; i++) {
    cout << "Enter arr[" << i << "]: ";
    cin >> arr[i];
  }
}

void print_array(int *arr, int n) {
  for (int i = 0; i < n; i++)
    cout << arr[i] << " ";
  cout << endl;
}

void delete_elt(int *arr, int val) {
  int i;
  for (i = 0; i < n; i++) {
    if (arr[i] == val)
      break;
  }
  if (i < n) {
    for (int j = i; j < n; j++)
      arr[j] = arr[j + 1];
    n = n - 1;
  }
}

int find_min(int *arr, int size) {
  int min = 0;
  for (int i = 0; i < size; i++)
    if (arr[min] > arr[i])
      min = i;
  return min;
}

int main(int argc, char *argv[]) {
  int *arr;
  cout << "Enter n: ";
  cin >> n;
  arr = new int[n];
  take_input(arr);
  merge_sort(arr, 0, n - 1);
  while (n > 2) {
    print_array(arr, n);
    int med_size = (n % 2 == 0) ? ((n / 2) * (n / 2 - 1))
                                : (((n - 1) / 2) * ((n - 1) / 2));
    int *medians = new int[med_size];
    int k = 0;
    for (int size = 3; size <= n; size += 2) {
      for (int i = 0; i < n - size + 1; i++) {
        int med = find_median(arr, i, i + size - 1);
        medians[k++] = med;
      }
    }
    print_array(medians, med_size);
    int min = find_min(medians, med_size);
    delete_elt(arr, medians[min]);
    delete[] medians;
  }
  int sum = 0;
  for (int i = 0; i < n; i++)
    sum += arr[i];
  cout << sum << endl;
  delete[] arr;
  return 0;
}
