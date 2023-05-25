class TreeNode {
 public:
  TreeNode* left;
  TreeNode* right;
  int no;
  int d;
  int x;
  int y;
  int mindeep = 999;
  TreeNode();
  TreeNode(int no);
  void InOrderWalk(TreeNode* root);
  void PreOrderWalk(TreeNode* root);
  void PosOrderWalk(TreeNode* root);
  TreeNode* TreeInvert(TreeNode* root);
  bool compare(TreeNode* left, TreeNode* right);
  int getHeight(TreeNode* node);
  int getDeep(TreeNode* node, int d);
  void Print(TreeNode* node);
};