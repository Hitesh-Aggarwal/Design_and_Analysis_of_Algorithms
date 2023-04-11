#include <iostream>
using namespace std;

#define N 4
#define M 4

int graph[N][N] = {
    {1, 1, 1, 1},
    {1, 1, 1, 1},
    {1, 1, 1, 1},
    {1, 1, 1, 1},
};
int colors[N] = {-1, -1, -1, -1};

void colorise(int k, int color) {
  int flag = 1;
  for (int i = 0; i < N; i++)
    if (graph[k][i] == 1 && colors[i] == color) flag = 0;

  if (flag)
    colors[k] = color;
  else
    colors[k] = 0;
}

void colorise_graph(int k) {
  if (k == N) {
    for (int i = 0; i < N; i++)
      cout << colors[i] << " ";
    cout << endl;
  } else {
    for(int i=1; i<=M; i++) {
      colorise(k,i);
      if (colors[k] == 0) continue;
      colorise_graph(k+1);
      colors[k] = -1;
    }
  }
}

int main(int argc, char *argv[]) {
  colorise_graph(0);
  return 0;
}
