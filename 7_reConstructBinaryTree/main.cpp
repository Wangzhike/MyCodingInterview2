#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <exception>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x):
        val(x), left(nullptr), right(nullptr) { }
};

typedef vector<int>::iterator vec_iter_t;

TreeNode* reConstructCore(vec_iter_t pre_begin, vec_iter_t pre_end,
                            vec_iter_t vin_begin, vec_iter_t vin_end) {
    int val_root = *pre_begin;
    TreeNode *root = new TreeNode(val_root);

    // 单个节点，直接返回根节点
    if (pre_end - pre_begin == 1 )
    {
        if (vin_end - vin_begin == 1 && *pre_begin == *vin_begin)
        {
            return root;
        } else
        {
            throw runtime_error("Invalid input");
        }
    }

    auto it_root_vin = find(vin_begin, vin_end, val_root);

    if (it_root_vin == vin_end)
    {
        throw runtime_error("Invalid input");
    }

    int length_left = it_root_vin - vin_begin;
    // 左子树不为空
    if (length_left > 0)
    {
        root->left = reConstructCore(pre_begin + 1, pre_begin + 1 + length_left,
                                    vin_begin, it_root_vin);
    }
    // 右子树不为空
    if (length_left < vin_end - vin_begin - 1)
    {
        root->right = reConstructCore(pre_begin + 1 + length_left, pre_end,
                                        it_root_vin + 1, vin_end);
    }

    return root;
}

TreeNode* reConstructBinaryTree(vector<int> pre,vector<int> vin) {
    if (pre.empty() || vin.empty())
    {
        return nullptr;
    }

    return reConstructCore(pre.begin(), pre.end(),
                            vin.begin(), vin.end());

}

void print_tree(TreeNode *root)
{
    queue<TreeNode*> que;
    TreeNode *p = root;
    while (p)
    {
        cout << p->val << " ";
        if (p->left)
        {
            que.push(p->left);
        }
        if (p->right)
        {
            que.push(p->right);
        }
        p = que.front();
        que.pop();
    }
    cout << endl;
}

int main() {
    vector<int> pre{1, 2, 4, 7, 3, 5, 6, 8};
    vector<int> vin{4, 7, 2, 1, 5, 3, 8, 6};
    TreeNode* root = reConstructBinaryTree(pre, vin);
    print_tree(root);
    return 0;
}