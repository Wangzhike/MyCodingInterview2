#include <iostream>


using namespace std;

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x):
            val(x), left(nullptr), right(nullptr) { }
};

bool isBalanced(TreeNode *root, int &height) {
    if (root == nullptr)
    {
        height = 0;
        return true;
    }
    int lh, rh;
    if (isBalanced(root->left, lh) && isBalanced(root->right, rh))
    {
        height = max(lh, rh) + 1;
        int diff = lh - rh;
        if (diff >= -1 && diff <= 1)
            return true;
    }
    return false;
}

bool IsBalanced_Solution(TreeNode* pRoot) {
    int height;
    return isBalanced(pRoot, height);
}


int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}