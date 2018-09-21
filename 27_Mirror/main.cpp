#include <iostream>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x):
            val(x), left(nullptr), right(nullptr) {}
};

void Mirror(TreeNode *pRoot) {
    if (pRoot == nullptr)
        return ;
    TreeNode *ltree = pRoot->left;
    TreeNode *rtree = pRoot->right;
    pRoot->left = rtree;
    pRoot->right = ltree;
    Mirror(pRoot->left);
    Mirror(pRoot->right);
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}