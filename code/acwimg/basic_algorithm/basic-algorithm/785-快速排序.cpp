#include <iostream>
const int N = 10e5 + 10;
int q[N];
void quick_sort(int l, int r, int q[]) {
  if (l >= r) {
    return;
  }
  int x = q[l + r >> 1], i = l - 1, j = r + 1;
  while (i < j) {
    while (q[++i] < x)
      ;
    while (q[--j] > x)
      ;
    if (i < j) {
      std::swap(q[i], q[j]);
    }
  }
  quick_sort(l, j, q), quick_sort(j + 1, r, q);
}
int main() {
  int n;
  std::cin >> n;
  for (int i = 0; i < n; i++) {
    std::cin >> q[i];
  }
  quick_sort(0, n - 1, q);
  for (int i = 0; i < n; i++) {
    std::cout << q[i] << " ";
  }
}
