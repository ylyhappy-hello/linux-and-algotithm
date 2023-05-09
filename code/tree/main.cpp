#include "treenode/treenode.h"
#include <iostream>
using std::cout;

int main(){
  TreeNode t1(1), t2(2), t3(3), t4(4),t5(5), t6(6), t7(7), t8(8), t9(9), t10(10);
  t1.left = &t2;
  t1.right = &t3;
  t2.left = &t6;
  t2.right = &t7;
  t6.right = &t8;
  t8.left = &t9;
  t8.right = &t10;
  t3.left = &t5;
  t3.right = &t4;
  // t1.PreOrderWalk(&t1);
  // t1.InOrderWalk(&t1);
  // t1.TreeInvert(&t1);
  // t1.PreOrderWalk(&t1);
  // t1.InOrderWalk(&t1);
  // cout << t1.compare(t1.left, t1.right);
  // cout << t1.getHeight(&t1)
  cout << t1.getDeep(&t1, 0);
  cout << t1.mindeep;
  // t1.InOrderWalk(&t1);
  // t1.PosOrderWalk(&t1);
}