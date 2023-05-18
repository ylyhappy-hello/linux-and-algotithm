

class TreeNode {
 public:
  struct NodeInt {
    int x;
    TreeNode* node;
    // 重载小于号运算符
    bool operator >(const NodeInt b) const { return x > b.x; }
  };
  TreeNode* left;
  TreeNode* right;
  int weight = 0;
  int no;
  int mindeep = 999;
  TreeNode();
  TreeNode(int);
  TreeNode* WithWeight(int weight);
  void InOrderWalk(TreeNode* root);
  void PreOrderWalk(TreeNode* root);
  void PosOrderWalk(TreeNode* root);
  TreeNode* TreeInvert(TreeNode* root);
  bool compare(TreeNode* left, TreeNode* right);
  int getHeight(TreeNode* node);
  int getDeep(TreeNode* node, int d);
  void buildHuffman();
  TreeNode* buildHuffman(NodeInt lw, NodeInt rw);
};
