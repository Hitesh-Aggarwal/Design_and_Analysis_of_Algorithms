#include <iostream>
using namespace std;

#define N 6

typedef struct activity {
  int id;
  int startime;
  int finishtime;
} activity;

void printActivities(activity *arr, int n) {
  cout << endl << "Activities:" << endl;
  cout << "ID\tStart\tFinish\n";
  for (int i = 0; i < n; i++)
    cout << arr[i].id << "\t" << arr[i].startime << "\t" << arr[i].finishtime
         << endl;
}

void insertion_sort(activity *arr) {
  int i = 0;
  for (int j = 1; j < N; j++) {
    activity temp = arr[j];
    i = j - 1;
    while (i >= 0 && arr[i].finishtime > temp.finishtime) {
      arr[i + 1] = arr[i];
      i--;
    }
    arr[i + 1] = temp;
  }
}

void solve(activity *arr, activity *sol, int *n) {
  *n = 0;
  int f = 0;
  for (int i = 0; i < N; i++) {
    if (arr[i].startime >= f){
      sol[(*n)++] = arr[i];
      f = arr[i].finishtime;
    }
  }
}

int main(int argc, char *argv[]) {
  int n; // number of activities in solution
  activity arr[N] = {{1, 0, 4}, {2, 2, 3},   {3, 4, 9},
                     {4, 7, 8}, {5, 10, 16}, {6, 13, 14}};
  activity *sol = new activity[N];
  insertion_sort(arr);
  printActivities(arr, N);
  solve(arr, sol, &n);
  printActivities(sol, n);
  delete[] sol;
  return 0;
}
