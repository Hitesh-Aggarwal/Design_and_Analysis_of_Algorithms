#include <iostream>
using namespace std;

#define N 5

struct Job {
  int profit;
  int deadline;
};

void insertion_sort(Job *arr) {
  int i = 0;
  for (int j = 1; j < N; j++) {
    Job temp = arr[j];
    i = j - 1;
    while (i >= 0 && arr[i].profit < temp.profit) {
      arr[i + 1] = arr[i];
      i--;
    }
    arr[i + 1] = temp;
  }
}

void SequenceJobs(Job *A) {
  int n = 0;
  for (int i = 0; i < N; i++)
    if (A[i].deadline > n) n = A[i].deadline;
  insertion_sort(A);
  Job *B = new Job[n];
  Job temp;
  const Job DEFAULT = {-1, -1};
  for (int i = 0; i < n; i++)
    B[i] = DEFAULT;
  for (int i = 0; i < N; i++) {
    temp = A[i];
    int j = temp.deadline - 1;
    if (temp.deadline <= n) {
      while (j >= 0 && B[j].deadline != -1)
        j--;
      if (j >= 0) B[j] = temp;
    }
  }
  for (int i = 0; i < n; i++)
    cout << B[i].profit << " " << B[i].deadline << endl;
  delete[] B;
}

int main() {
  Job A[N] = {{100, 2}, {19, 1}, {27, 2}, {25, 1}, {15, 3}};
  SequenceJobs(A);
  return 0;
}
