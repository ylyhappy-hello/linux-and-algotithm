#include <iostream>
const int N = 1e5 + 10;
int q[N], tmp[N], n;
void mergesort(int l, int r, int q[]) {
  if (l >= r) {
    return;
  }
  int mid = l + r >> 1, i = l, j = mid + 1, k = 0;
  mergesort(l, mid, q), mergesort(mid + 1, r, q);
  while (i <= mid && j <= r) {
    if (q[i] <= q[j]) {
      tmp[k++] = q[i++];
    } else {
      tmp[k++] = q[j++];
    }
  }
  while (i <= mid) {
    tmp[k++] = q[i++];
  }
  while (j <= r) {
    tmp[k++] = q[j++];
  }

  for (int i = l, j = 0; i <= r; i++, j++){
    q[i] = tmp[j];
  }
}
int main() {
  std::cin >> n;
  for (int i = 0; i < n; i ++){
    std::cin >> q[i];
  }
  mergesort(0, n - 1, q);
  for (int i = 0; i < n; i++) {
    std::cout << q[i] << " ";
  }
}
