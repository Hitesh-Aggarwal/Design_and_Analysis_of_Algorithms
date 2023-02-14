#include <iostream>
using namespace std;

#define CAP 17
#define N 5

typedef struct item {
  int id;
  float value;
  int weight;
  float ratio;
  float fraction;
} item;

void printItems(item *arr, int n) {
  cout << "Bag Contents:" << endl << endl;
  cout << "ID\tVALUE\tWEIGHT\tRATIO\tFRACTION" << endl;
  for (int i = 0; i < n; i++) {
    cout << arr[i].id << "\t" << arr[i].value << "\t" << arr[i].weight << "\t"
         << arr[i].ratio << "\t" << arr[i].fraction << endl;
  }
}

void insertion_sort(item *arr) {
  int i = 0;
  for(int j=1; j<N; j++) {
    item temp = arr[j];
    i = j-1;
    while (i>=0 && arr[i].ratio < temp.ratio){
      arr[i+1] = arr[i];
      i--;
    }
    arr[i+1] = temp;
  }
}

void find_solution(item arr[], item solution[], int *n, float *profit) {
  insertion_sort(arr);
  *n = 0;
  *profit = 0;
  int w = 0;
  for(int i=0; i<N; i++) {
    if (w >= CAP) return;
    if (arr[i].weight + w <= CAP) {
      w+=arr[i].weight;
      solution[(*n)++] = arr[i];
      *profit += arr[i].value;
    }
    else {
      int diff = CAP-w;
      w = CAP;
      arr[i].fraction = (float)diff/arr[i].weight;
      arr[i].value = arr[i].fraction * arr[i].value;
      arr[i].weight = diff;
      solution[(*n)++] = arr[i];
      *profit += arr[i].value;
    }
  }
}

int main() {
  int n = 0; // number of items in solution
  float profit=0;
  item arr[N] = {{1, 10, 2}, {2, 8, 4}, {3,18, 6},
                   {5, 9, 3}, {6, 60, 10}};

  item *solution = new item[N];

  for (int i = 0; i < N; i++){
    arr[i].ratio = ((float)arr[i].value / arr[i].weight);
    arr[i].fraction = 1;
  }

  find_solution(arr,solution,&n,&profit);

  printItems(solution,n);

  cout << endl << "Total Profit: " << profit << endl;

  delete[] solution;

  return 0;
}
