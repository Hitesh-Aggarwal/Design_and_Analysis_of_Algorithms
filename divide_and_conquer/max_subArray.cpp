#include <iostream>
#include <limits.h>
using namespace std;

#define N 10

void max_subarray_brute_force(int arr[], int n, int *i, int *j, int *max_sum) {
  for (int p = 0; p < n; p++) {
    int sum = arr[p];
    for (int q = p + 1; q < n; q++) {
      sum += arr[q];
      if (sum > *max_sum) {
        *max_sum = sum;
        *i = p;
        *j = q;
      }
    }
  }
}

void cross_sum(int arr[], int low, int mid, int high, int *i, int *j, int *max_sum) {
  int left_sum_max = INT_MIN;
  int right_sum_max = INT_MIN;
  int left_sum = 0;
  int right_sum = 0;
  int p = mid, q = mid;
  int p_max = mid, q_max = mid;
  while (p >= low) {
    left_sum += arr[p];
    if (left_sum > left_sum_max) {
      left_sum_max = left_sum;
      p_max = p;
    }
    p--;
  }
  while (q <= high) {
    right_sum += arr[q];
    if (right_sum > right_sum_max) {
      right_sum_max = right_sum;
      q_max = q;
    }
    q++;
  }

  if ((left_sum_max + right_sum_max - arr[mid]) > *max_sum) {
    *max_sum = left_sum_max + right_sum_max - arr[mid];
    *i = p_max;
    *j = q_max;
  }
}

void max_subarray_divide_and_conquer(int arr[], int low, int high, int *i, int *j, int *max_sum) {
  if (low == high) {
    if (arr[low] > *max_sum) {
      *max_sum = arr[low];
      *i = low;
      *j = high;
    }
  } else {
    int mid = low + (high - low) / 2;
    max_subarray_divide_and_conquer(arr, low, mid, i, j, max_sum);
    max_subarray_divide_and_conquer(arr, mid + 1, high, i, j, max_sum);
    cross_sum(arr, low, mid, high, i, j, max_sum);
  }
}

void printArray(int *arr, int n) {
  for (int i = 0; i < n; i++)
    cout << arr[i] << " ";
  cout << endl;
}

int main(int argc, char *argv[]) {
  int arr[N] = {25, -30, 64, -50, 2, 53, 3, -20, 13, 32};
  printArray(arr, N);
  int i = 0, j = N - 1, max_sum = INT_MIN;
  // max_subarray_brute_force(arr, n, &i, &j, &max_sum);
  // cout << i << " " << j << " " << max_sum << endl;
  max_subarray_divide_and_conquer(arr, 0, N - 1, &i, &j, &max_sum);
  cout << i << " " << j << " " << max_sum << endl;
  return 0;
}
