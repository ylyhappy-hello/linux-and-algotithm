#include<iostream>
#include<string>
using namespace std;
int p;
int t;
int debug = false;
int getMap(char &c){
  if (c >= '0' && c <= '9'){
    return c - 48;
  }
  if (c >= 'A' && c <= 'Z'){
    return c - 55;
  }
  if (c >= 'a' && c <= 'z'){
    return c - 61;
  }
  return 0;
}
void rabin_karp(string &T, string &P, int d, int q){
  int n = T.size(), m = P.size();
  int h = 1;
  for (int i = 0; i < m - 1; i ++){
    h *= d;
  }
  //h %= q; // 非常牛逼
  cout << "h = " << h << endl;
  for (int i = 0; i < m; i ++){
    p = (d * p + getMap(P[i]));// % q;
    t = (d * t + getMap(T[i]));// % q;
  }

  cout << "p = " << p << endl;
  for (int s = 0; s < n - m; s ++){
    if (p == t){
      if (T.substr(s,m).compare(P) == 0){
        cout << s << endl;
      }
    } 
    // t = (d * t - getMap(T[s + 1]) * h + getMap(T[s + 1 + m])) % q;
    t = (d * (t - getMap(T[s]) * h) + getMap(T[s + m])) % q;
    cout << "s = " << s << "\t" << t << endl;
  }

}
int main(){
  string T = "789987789987";
  string P = "789"; 
  rabin_karp(T, P, 10, 7001);
  return 0;
}
