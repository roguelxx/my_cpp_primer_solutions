//
// Created by lxx on 2021/8/19.
//

#include <string>

using namespace std;

class TreeNode {
 public:
  TreeNode() = default;
  TreeNode(const string &s, const int &i) : value(s), count(i) {}
  TreeNode(const TreeNode &ori);
  TreeNode &operator=(const TreeNode &rhs);

  void copyTree(TreeNode *, const TreeNode *);
  ~TreeNode() {
    delete left;
    delete right;
  }
 private:
  string value;
  int count;
  TreeNode *left;
  TreeNode *right;
};

/* copy constructor with helper function
void TreeNode::copyTree(TreeNode *lhs, const TreeNode *rhs) {
  lhs->value = rhs->value;
  lhs->count = rhs->count;
  if (rhs->left) {
    lhs->left = new TreeNode;
    copyTree(lhs->left, rhs->left);
  } else {
    lhs->left = nullptr;
  }
  if (rhs->right) {
    lhs->right = new TreeNode;
    copyTree(lhs->right, rhs->right);
  } else {
    lhs->right = nullptr;
  }
}

TreeNode::TreeNode(const TreeNode &ori) {
  copyTree(this, &ori);
}
*/

/* wrong implementation, lhs.left will be dangling pointer *
TreeNode &TreeNode::operator=(const TreeNode &rhs) {
  value = rhs.value;
  count = rhs.count;
  if(rhs.left){
    left = new TreeNode(*rhs.left);
  } else {
    left = nullptr;
  }
  if (rhs.right) {
    right = new TreeNode(*rhs.right);
  } else {
    right = nullptr;
  }
  return *this;
}
 */

// copy constructor without helper function, ori must NOT be nullptr
TreeNode::TreeNode(const TreeNode &ori) : value(ori.value), count(ori.count), left(nullptr), right(nullptr) {
  if (ori.left) {
    left = new TreeNode(*ori.left);
  }
  if (ori.right) {
    right = new TreeNode(*ori.right);
  }
}

TreeNode &TreeNode::operator=(const TreeNode &rhs) {
  value = rhs.value;
  count = rhs.count;
  TreeNode *tmp = nullptr;
  if (rhs.left) {
    tmp = new TreeNode(*rhs.left);
  }
  delete left;
  left = tmp;
  tmp = nullptr;
  if (rhs.right) {
    tmp = new TreeNode(*rhs.right);
  }
  delete right;
  right = tmp;
  return *this;
}

class BinStrTree {
 public:
  BinStrTree() = default;
  BinStrTree(const TreeNode &tree = TreeNode()) : root(new TreeNode(tree)), use(new size_t(1)) {}
  BinStrTree(const BinStrTree &);
  BinStrTree & operator=(const BinStrTree &);
  ~BinStrTree();
 private:
  TreeNode *root;
  size_t *use;
};

// pointerlike version
BinStrTree::BinStrTree(const BinStrTree &ori) {
  root = new TreeNode(*ori.root);
  use = ori.use;
  ++*use;
}

BinStrTree & BinStrTree::operator=(const BinStrTree &rhs) {
  ++*rhs.use;
  if (--*use == 0) {
    delete root;
    delete use;
  }
  use = rhs.use;
  root = rhs.root;
  return *this;
}

BinStrTree::~BinStrTree() {
  if (--*use == 0) {
    delete root;
    delete use;
  }
}

int main() {
  return 0;
}
