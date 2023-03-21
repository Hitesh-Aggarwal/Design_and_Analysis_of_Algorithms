#include <iostream>
using namespace std;

#define N 13

int max(int a, int b) { return (a > b) ? a : b; }

int palindrome(char *str, int i, int j) {
  if (i > j) return 0;
  if (i == j) return 1;
  if (str[i] == str[j])
    return 2 + palindrome(str, i + 1, j - 1);
  else { return max(palindrome(str, i + 1, j), palindrome(str, i, j - 1)); }
  return 0;
}

int main(int argc, char *argv[]) {
  char str[N] = "psychologist";
  cout << "\nLength of longest palindrome: " << palindrome(str, 0, N - 1) << endl;
  return 0;
}
