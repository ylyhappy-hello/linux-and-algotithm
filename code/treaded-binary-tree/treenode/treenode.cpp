#include <algorithm>
#include <iostream>
#include <stack>
#include <vector>
using std::cout;
using std::endl;
using std::stack;
using std::vector;

#include "treenode.h"

TreeNode::TreeNode() {
  this->left = nullptr;
  this->right = nullptr;
}

TreeNode::TreeNode(int no) {
  this->left = nullptr;
  this->right = nullptr;
  this->no = no;
}

void TreeNode::InOrderWalk(TreeNode* root) {
  vector<int> res;
  stack<TreeNode*> st;
  TreeNode* t = root;
  while (t != NULL || !st.empty()) {
    if (t != NULL) {
      st.push(t);
      t = t->left;
    } else {
      t = st.top();
      st.pop();
      res.push_back(t->no);
      t = t->right;
    }
  }

  cout << "中序遍历结果：" << endl;
  for (auto x : res) {
    cout << x << " ";
  }
  cout << endl;
}

void TreeNode::PreOrderWalk(TreeNode* root) {
  vector<int> res;
  stack<TreeNode*> st;
  TreeNode* t = root;
  st.push(t);
  while (!st.empty()) {
    t = st.top();
    st.pop();
    if (t != NULL) {
      res.push_back(t->no);
    }
    if (t->right != NULL) {
      st.push(t->right);
    }
    if (t->left != NULL) {
      st.push(t->left);
    }
  }
  cout << "前序遍历结果：" << endl;
  for (auto x : res) {
    cout << x << " ";
  }
  cout << endl;
}

void TreeNode::PosOrderWalk(TreeNode* root) {
  vector<int> res;
  stack<TreeNode*> st;
  TreeNode* t = root;
  st.push(t);
  while (!st.empty()) {
    t = st.top();
    st.pop();
    if (t != NULL) {
      res.push_back(t->no);
    }
    if (t->left != NULL) {
      st.push(t->left);
    }
    if (t->right != NULL) {
      st.push(t->right);
    }
  }
  cout << "后序遍历结果：" << endl;
  std::reverse(res.begin(), res.end());
  for (auto x : res) {
    cout << x << " ";
  }
  cout << endl;
}

TreeNode* TreeNode::TreeInvert(TreeNode* root) {
  if (root == NULL) {
    return root;
  }
  std::swap(root->left, root->right);
  TreeInvert(root->left);
  TreeInvert(root->right);
  return NULL;  //  c++ compile 警告， 类似java不是所有的代码路径都返回值,
                //  所以加上这个
}

bool TreeNode::compare(TreeNode* left, TreeNode* right) {
  if (left == NULL && right != NULL)
    return false;
  else if (left == NULL && right != NULL)
    return false;
  else if (left != NULL && right == NULL)
    return false;
  else if (left == NULL && right == NULL)
    return true;
  else if (left->no != right->no)
    return false;
  bool outside = compare(left->left, right->right);
  bool inside = compare(left->right, right->left);
  bool result = outside && inside;
  return result;
}
int TreeNode::getHeight(TreeNode* node) {
  if (node == NULL)
    return 0;
  int lh = getHeight(node->left);
  int rh = getHeight(node->right);
  return std::max(lh, rh) + 1;
}
int TreeNode::getDeep(TreeNode* node, int d) {
  if (node == NULL)
    return d;
  if (node->left == NULL && node->right == NULL){
    mindeep = std::min(mindeep, d);
  }
  cout << node->no << "\t" << d << endl;
  getDeep(node->left, d + 1);
  getDeep(node->right, d + 1);
  return 0;
}