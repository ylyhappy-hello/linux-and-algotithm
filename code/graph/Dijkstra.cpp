#include <iostream>
#include <algorithm>
#include <cstring>

const int N = 1000;

int g[N][N];
int dist[N];
int n, m;
bool st[N];
/*
这个dist在迭代的过程中就像是yxc老师讲的S集合， 已知的距离最近的点

*/

int dijkstra(){
  memset(dist, 0x3f, sizeof(dist));
  dist[1] = 0;

  for (int i = 0; i < n; i++){
    int t = -1;
    for (int j = 1; j <= n; j++){
      if (!st[j] && (t == -1 || dist[t] > dist[j])){
        t = j;
      }
      st[t] = true;
    }
    for (int j = 1; j <= n; j++){
      dist[j] = std::min(dist[j], dist[t] + g[t][j]);
    }
  }
  if (dist[n] == 0x3f3f3f3f){
    return -1;
  }
  return dist[n];
}

int main(){
  memset(g, 0x3f, sizeof(g));
  std::cin >> n >> m;
  for (int i = 0; i < m; i++){
    int x, y, z;
    std::cin >> x >> y >> z;
    // 考虑到x,y之间可能有多条边(重边)
    g[x][y] = std::min(g[x][y], z);
  }
  int t = dijkstra();
}

