#include <iostream>
using namespace std;

struct node {
  char c;
  int freq;
  struct node *left;
  struct node *right;
};

class stack {
  int size = 0;
  int arr[10000];

public:
  bool isEmpty() { return (size == 0); }
  bool isFull() { return (size == 10000); }

  int get_size() { return size; }

  char *printStack() {
    if (size <= 0) return NULL;
    char *str = new char[size];
    for (int i = 0; i < size; i++)
      str[i] = (arr[i] == 0) ? '0' : '1';
    return str;
  }

  void push(int i) {
    if (!isFull()) {
      arr[size] = i;
      size++;
    }
  }

  int pop() {
    if (!isEmpty()) {
      size = size - 1;
      return arr[size];
    }
    return -1;
  }
};

class heap {
  node *arr[128];
  int size = 0;

  int left(int i) { return 2 * i + 1; }
  int right(int i) { return left(i) + 1; }
  int parent(int i) { return (i + 1) / 2 - 1; }

public:
  int get_size() { return size; }
  void heapify(int i) {
    int l = left(i);
    int r = right(i);
    int min;
    if (l >= size) return; // leaf node
    if (r >= size)
      if (arr[i]->freq < arr[l]->freq) min = i;
    if (arr[i]->freq < arr[l]->freq && arr[i]->freq < arr[r]->freq)
      min = i;
    else if (arr[l]->freq < arr[i]->freq && arr[l]->freq < arr[r]->freq)
      min = l;
    else
      min = r;
    if (min != i) {
      node *temp = arr[i];
      arr[i] = arr[min];
      arr[min] = temp;
      heapify(min);
    }
  }

  void insert(node *item) {
    arr[size] = item;
    size++;
    int i = size - 1;
    while (i > 0) {
      int par = parent(i);
      if (arr[i]->freq < arr[par]->freq) {
        // swap
        node *temp = arr[i];
        arr[i] = arr[par];
        arr[par] = temp;
      }
      i = par;
    }
  }

  node *pop() {
    node *n = arr[0];
    size = size - 1;
    arr[0] = arr[size];
    heapify(0);
    return n;
  }

  void printHeap() {
    for (int i = 0; i < size; i++)
      cout << arr[i]->c << "\t" << arr[i]->freq << endl;
  }
};

node *createNode() {
  node *n = new node();
  n->c = 0;
  n->freq = 0;
  n->left = NULL;
  n->right = NULL;
  return n;
}

int compute_size(char *s) {
  int i = 0;
  while (s[i] != '\0')
    i++;
  return i * 8;
}

int *compute_frequency(char *s) {
  int *A = new int[128];
  for (int i = 0; i < 128; i++)
    A[i] = 0;
  for (int i = 0; s[i] != '\0'; i++)
    A[(int)s[i]]++;
  return A;
}

node *generateTree(char *s, int *freq_arr) {
  heap *h = new heap();
  for (int i = 0; i < 128; i++) {
    if (freq_arr[i] > 0) {
      node *newnode = createNode();
      newnode->freq = freq_arr[i];
      newnode->c = i;
      h->insert(newnode);
    }
  }
  while (h->get_size() > 1) {
    node *node1 = h->pop();
    node *node2 = h->pop();
    node *newnode = createNode();
    newnode->c = '#';
    newnode->freq = node1->freq + node2->freq;
    newnode->left = node1;
    newnode->right = node2;
    h->insert(newnode);
  }
  node *root = h->pop();
  delete h;
  return root;
}

void generateCodes_aux(node *root, stack *s, int *total, char **codes) {
  if (!root)
    return;
  else if (root->c != '#') {
    char *code = s->printStack();
    codes[(int)root->c] = code;
    *total += s->get_size() * root->freq;
    cout << root->c << "\t" << code << endl;
  } else {
    s->push(0);
    generateCodes_aux(root->left, s, total, codes);
    s->pop();

    s->push(1);
    generateCodes_aux(root->right, s, total, codes);
    s->pop();
  }
}

void generateCodes(node *root, int *total, char **codes) {
  stack *sc = new stack();
  generateCodes_aux(root, sc, total, codes);

  delete sc;
}

void delete_tree(node *root) {
  if (!root) return;
  if (root->left) delete_tree(root->left);
  if (root->right) delete_tree(root->right);
  if (root->left == NULL && root->right == NULL) delete root;
}

void append(char *a, char *b, int *size_a) {
  for (int i = 0; b[i] != '\0'; i++)
    a[(*size_a)++] = b[i];
}

char *encode_message(char *str, char **codes) {
  char *result = new char[10000];
  int k = 0;
  for (int i = 0; str[i] != '\0'; i++) {
    append(result, codes[(int)str[i]], &k);
  }
  return result;
}

int main() {
  char s[100] = "This is a line of texT";
  char **codes = new char *[128];
  cout << "String size: " << compute_size(s) << " bits\n";
  int *A = compute_frequency(s);
  node *root = generateTree(s, A);
  int total = 0;
  generateCodes(root, &total, codes);
  char *res = encode_message(s, codes);
  cout << "After huffman coding: " << total << " bits\n";
  cout << "Encoded message:\n";
  cout << res << endl;

  delete_tree(root);
  for (int i = 0; i < 128; i++)
    delete[] codes[i];
  delete[] codes;
  delete[] A;
  delete res;
  return 0;
}
