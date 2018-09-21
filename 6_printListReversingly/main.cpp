#include <iostream>
#include <vector>
#include <stack>

using namespace std;

struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x):
        val(x), next(nullptr) { }
};

vector<int> printListFromTailToHead(ListNode *head) {
    stack<int> reverse;
    ListNode* p = head;
    while (p)
    {
        reverse.push(p->val);
        p = p->next;
    }
    vector<int> result;
    while (!reverse.empty())
    {
        result.push_back(reverse.top());
        reverse.pop();
    }
    return result;
}

int main() {

    return 0;
}