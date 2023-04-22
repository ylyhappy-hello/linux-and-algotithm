#include<iostream>
#include<string>
using namespace std;
int p[1000];
int t[1000];
// d is , q is 
void rabin_karp(string &T, string &P, int d, int q){
  int n = T.size(), m = P.size();
  cout << "T.size()" << n << "   " << "P.size()" << m << endl;
  int h = 1;
  for (int i = 0; i < m - 1; i ++){
    h *= d;
  }
  cout << "expect h is 531441, actual h is " << h << endl;
  h %= q;
  for (int i = 0; i < m; i ++){
    p[i] = (d * p[i] + P[i]) % q;
    t[i] = (d * t[i] + T[i]) % q;
    cout << "p[" << i << "] is " << p[i] << "     t[" << i << "] is " << t[i] << endl;
  }

  for (int s = 0; s < n - m; s ++){
    if (compare(p, t + s, m)){
      for (
    }
  }

}
bool compare(int *a, int *b, int count){
  while(count --){
    if (*(a++)!=*(b++)) {
      return false;
    }  
  }
  return true;
}
int main(){
  string T = "Hello Hello Hello world!!!";
  string P = "Hello"; 
  int a[] = { 1, 2, 3, 4};
  int b[] = { 1, 2, 3, 4};
  // if (compare(a, b, 4)){
  //   cout << "hello world!!!" << endl;
  // }
  rabin_karp(T, P, 27, 13);
  return 0;
}
