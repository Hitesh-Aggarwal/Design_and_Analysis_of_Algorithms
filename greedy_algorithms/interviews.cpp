#include <iostream>
using namespace std;

#define N 6

typedef struct Candidate {
  int id;
  int start_time;
  int end_time;
} Candidate;

typedef struct Interviewer {
  int id;
  Candidate *list;
  int n;

  ~Interviewer() { delete[] list; }
} Interviewer;

void insertion_sort(Candidate *list) {
  int i;
  Candidate temp;
  for (int j = 1; j < N; j++) {
    i = j - 1;
    temp = list[j];
    while (i >= 0 && list[i].end_time > temp.end_time) {
      list[i + 1] = list[i];
      i--;
    }
    list[i + 1] = temp;
  }
}

void printCandidates(Candidate *list) {
  for (int i = 0; i < N; i++)
    cout << list[i].id << "\t" << list[i].start_time << "\t" << list[i].end_time
         << endl;
}

void create_new_interviewer(Interviewer *list, int n) {
  list[n].id = n + 1;
  list[n].n = 0;
  list[n].list = new Candidate[N];
}

void assignCandidates(Candidate *c_list,
                      Interviewer *i_list,
                      int *n) { // n is number of interviewrs
  insertion_sort(c_list);
  create_new_interviewer(i_list, 0);
  i_list[0].list[i_list[0].n] = c_list[0];
  i_list[0].n++;

  *n = 1;
  Candidate cur;
  int min;
  int flag;

  for (int i = 1; i < N; i++) {
    cur = c_list[i];
    min = 0;
    flag = 0;
    for (int j = 0; j < (*n); j++) { // loop through interviewrs list
      if (cur.start_time >=
          i_list[j].list[i_list[j].n - 1].end_time) { // Interviewer is free
        flag = 1;
        if (i_list[min].n > i_list[j].n)
          min = j;
      }
    }
    if (flag == 1) {
      // assign current candidate to min interviewer
      i_list[min].list[i_list[min].n] = cur;
      i_list[min].n++;
    } else {
      create_new_interviewer(i_list, *n);
      i_list[*n].list[i_list[*n].n] = cur;
      i_list[*n].n++;
      *n = *n + 1;
    }
  }
}

void printInterviews(Interviewer *list, int n) {
  for (int i = 0; i < n; i++) {
    cout << list[i].id << endl;
    for (int j = 0; j < list[i].n; j++)
      cout << list[i].list[j].id << " ";
    cout << endl;
  }
}

int main(int argc, char *argv[]) {
  Candidate candidates[N] = {
      {1, 5, 9}, {2, 1, 2}, {3, 3, 4}, {4, 0, 6}, {5, 5, 7}, {6, 8, 9}};
  Interviewer list[N];
  int n = 0;
  assignCandidates(candidates, list, &n);
  printCandidates(candidates);
  cout << endl;
  printInterviews(list, n);
  return 0;
}
