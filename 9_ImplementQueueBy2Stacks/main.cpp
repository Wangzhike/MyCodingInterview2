#include <iostream>
#include <stack>

using namespace std;

class QueueBy2Stacks {
public:
    void push(int node) {
        stack1.push(node);
    }

    int pop() {
        if (stack2.empty())
        {
            while (!stack1.empty())
            {
                int e = stack1.top();
                stack1.pop();
                stack2.push(e);
            }
        }
        int e = stack2.top();
        stack2.pop();
        return e;
    }

private:
    stack<int> stack1;
    stack<int> stack2;
};

int main() {
    QueueBy2Stacks que;
    que.push(1);
    que.push(2);
    que.push(3);
    cout << que.pop() << endl;
    que.push(4);
    que.push(5);
    cout << que.pop() << endl;
    cout << que.pop() << endl;
    cout << que.pop() << endl;
    que.push(6);
    cout << que.pop() << endl;
    cout << que.pop() << endl;
    
    return 0;
}