#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>
#include <stack>
#include <unordered_map>
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
const int N = 1e+5 + 10;

void naivestirngmathcer(string T, string P){
  int n = T.length();
  int m = P.length();
  for (int i = 0; i < n - m + 1; i ++){
    // compare 按照字典序比较大小， 大于返回， 小于返回， 等于返回1
    if (P.compare(T.substr(i,m)) == 0){
      cout << "Pattern occurs with shift" << i << "\n";
    }
  }
}

int main()
{
    ios::sync_with_stdio(false);  //提高cin速度,但是不可以使用scanf,scanf有时候有问题,还是cin吧...
    cin.tie(nullptr);
    naivestirngmathcer("aaaabbab","ab");
    return 0;
}
