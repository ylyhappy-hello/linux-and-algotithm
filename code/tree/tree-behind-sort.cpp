#include<iostream>
#include<string>
#include<stack>
#include<queue>
#include<algorithm>
using namespace std;
template<class N, class V>
class TreeNode{
  public: 
    TreeNode *LChildNode = NULL;
    TreeNode *RChildNode = NULL;
    char CoutType = 'A';
    N no;
    V value;
    void PreOrder();
    void InfixOrder();
    void PostOrder();
    void LayerOrder();
    TreeNode(TreeNode *LChildNode, TreeNode *RChildNode, N no, V value){
      this->LChildNode = LChildNode;
      this->RChildNode = RChildNode;
      this->value = value;
      this->no = no;
    }

};
template<class N, class V>
ostream & operator<<( ostream & os,const TreeNode<N, V> *tn)
{
  switch (tn->CoutType)
  {
  case 'A':
    os << "TreeNode [no=" << tn->no << ", value=" << tn->value <<  "]"; 
    os << endl;
    break;

  case 'B':
    os <<" " << tn->no << " "; 
    break;

  default:
    break;
  }
    return os;
}

template<class N, class V>
void TreeNode<N, V>::LayerOrder(){

}
template<class N, class V>
void TreeNode<N, V>::PreOrder(){
  // 传进来的必须是root节点
  cout << this;
  if (this->LChildNode != NULL){
    this->LChildNode->PreOrder();
  }
  if (this->RChildNode != NULL){
    this->RChildNode->PreOrder();
  }
}

template<class N, class V>
void TreeNode<N, V>::InfixOrder(){
  // 传进来的必须是root节点
  if (this->LChildNode != NULL){
    this->LChildNode->InfixOrder();
  }
  cout << this;
  if (this->RChildNode != NULL){
    this->RChildNode->InfixOrder();
  }
}
template<class N, class V>
void TreeNode<N, V>::PostOrder(){
  // 传进来的必须是root节点
  if (this->LChildNode != NULL){
    this->LChildNode->PostOrder();
  }
  if (this->RChildNode != NULL){
    this->RChildNode->PostOrder();
  }
  cout << this;
}
template<class N, class V>
class BinaryTree{
  public:
    TreeNode<N, V> *root;
    stack<TreeNode<N, V>*> BTstack;
    queue<TreeNode<N, V>> BTqueue;
    void PreOrder();
    void InfixOrder();
    void PostOrder();
    void LayerOrder(char);
    void PreOrderNoRec_1(char);
    void PreOrderNoRec_2(char);
    void InfixOrderNoRec(char);
   // void PreOrderSearch(V value);
    BinaryTree(TreeNode<N, V> *root){
      this->root = root;
    }
};
template<class N, class V>
void BinaryTree<N, V>::PreOrder(){
  // 传进来的必须是root节点
  if (this->root != NULL){
    this->root->PreOrder();
  }else {
    cout << "二叉树为空， 无法遍历";
  }
}

template<class N, class V>
void BinaryTree<N, V>::InfixOrder(){
  // 传进来的必须是root节点
  if (this->root != NULL){
    this->root->InfixOrder();
  }else{
    cout << "二叉树为空， 无法遍历";
  }
}
template<class N, class V>
void BinaryTree<N, V>::PostOrder(){
  // 传进来的必须是root节点
  if (this->root != NULL){
    this->root->PostOrder();
  }else{
    cout << "二叉树为空， 无法遍历";
  }
}
template<class N, class V>
void BinaryTree<N, V>::LayerOrder(char coutType){
  if (this->root == NULL){
    cout << "二叉树为空， 无法遍历";
    return;
  }
  BTqueue.push(*this->root);
  this->root->CoutType = coutType;
  cout << this->root;
  while (!BTqueue.empty()) {
    TreeNode<N, V> t = BTqueue.front();
    BTqueue.pop();
    if (t.LChildNode != NULL){
      BTqueue.push(*t.LChildNode);
      t.LChildNode->CoutType = coutType;
      cout << t.LChildNode;
    } 
    if (t.RChildNode != NULL){
      BTqueue.push(*t.RChildNode);
      t.RChildNode->CoutType = coutType;
      cout << t.RChildNode;
    }
  }
}

template<class N, class V>
void BinaryTree<N, V>::PreOrderNoRec_1(char coutType){
  if (this->root == NULL){
    cout << "二叉树为空， 无法遍历";
    return;
  }
  BTstack.push(this->root);
  while (!BTstack.empty()) {
    TreeNode<N, V> *t = BTstack.top();
    t->CoutType = coutType;
    cout << t;
    BTstack.pop();
    if (t->RChildNode != NULL){
      BTstack.push(t->RChildNode);
    }
    if (t->LChildNode != NULL){
      BTstack.push(t->LChildNode);
    } 
    if (t->LChildNode == NULL){
      while (!BTstack.empty()) {
      }
      
      BTstack.pop();
    }
  }
}

template<class N, class V>
void BinaryTree<N, V>::PreOrderNoRec_2(char coutType){
  if (this->root == NULL){
    cout << "二叉树为空， 无法遍历";
    return;
  }
  TreeNode<N, V> *t = this->root;
  while (t != NULL || !BTstack.empty()){
    t->CoutType = coutType;
    cout << t;
    if (t->RChildNode != NULL){
      BTstack.push(t->RChildNode);
    }
    t = t->LChildNode;
    if (t == NULL && !BTstack.empty()){
      t = BTstack.top();
      BTstack.pop();
    } 
  }
}


template<class N, class V>
void BinaryTree<N, V>::InfixOrderNoRec(char coutType){
  if (this->root == NULL){
    cout << "二叉树为空， 无法遍历";
    return;
  }
  TreeNode<N, V> *t = this->root;
  while (t != NULL || !BTstack.empty()){
    if (t != NULL){
      BTstack.push(t);
      t = t->LChildNode;
    } else {
      t = BTstack.top();
      t->CoutType = coutType;
      cout << t;
      BTstack.pop();
      t = t->RChildNode;
    }
  }
}

int main(){
  // 创建二叉树
  TreeNode<int, string> t1(NULL, NULL, 1, "宋江");
  BinaryTree<int, string> bt(&t1);
  TreeNode<int, string> t2(NULL, NULL, 2, "吴用");
  TreeNode<int, string> t3(NULL, NULL, 3, "卢俊义");
  TreeNode<int, string> t4(NULL, NULL, 4, "林冲");
  TreeNode<int, string> t5(NULL, NULL, 5, "hello");
  TreeNode<int, string> t6(NULL, NULL, 6, "ylyhappy");
  TreeNode<int, string> t7(NULL, NULL, 7, "yly");
  TreeNode<int, string> t8(NULL, NULL, 8, "yly");
  TreeNode<int, string> t9(NULL, NULL, 9, "yly");
  TreeNode<int, string> t10(NULL, NULL, 10, "yly");
  t1.LChildNode = &t2;
  t1.RChildNode = &t3;
  t2.RChildNode = &t7;
  t3.RChildNode = &t4;
  t3.LChildNode = &t5;
  t2.LChildNode = &t6;
  t6.LChildNode = &t8;
  t8.LChildNode = &t9;
  t8.RChildNode = &t10;
  // cout << "前序遍历结果" << endl;
  // cout << endl << "前序遍历1结果" << endl;
  // bt.PreOrderNoRec_1('B');
  // cout << endl << "前序遍历2结果" << endl;
  // bt.PreOrderNoRec_2('B');
  cout << endl << "中序遍历结果" << endl;
  bt.InfixOrderNoRec('B');
  // bt.LayerOrder('B');
  // bt.PreOrder();
  // cout << "中序遍历结果" << endl;
  // bt.InfixOrder();
  // cout << "后序遍历结果" << endl;
  // bt.PostOrder();
  return 0;
}
