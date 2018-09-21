#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

#define CODE_NUM    2


#if (CODE_NUM == 1)

int parent(int i) {
    return i >> 1;
}

int left(int i) {
    return i << 1;
}

int right(int i) {
    return (i << 1) + 1;
}

void maxHeapy(vector<int> &heap, int size, int i) {
    while (i <= size)
    {
        int lc = left(i);
        int rc = right(i);
        int largest_i = i;
        if (lc <= size && heap[i] < heap[lc])
            largest_i = lc;
        if (rc <= size && heap[largest_i] < heap[rc])
            largest_i = rc;
        if (i != largest_i)
            swap(heap[i], heap[largest_i]);
        else
            break;
        i = largest_i;
    }
}

void buildHeap(vector<int> &heap) {
    int size = heap.size() - 1;
    for (int i = size / 2; i >= 1; --i)
        maxHeapy(heap, size, i);
}

void heapSort(vector<int> &heap) {
    int size = heap.size() - 1;
    while (size >= 2)
    {
        swap(heap[1], heap[size--]);
        maxHeapy(heap, size, 1);
    }

}

// 维护一个比第K+1个大的数小的最大堆，也就是k个最小的数
vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
    if (input.size() < 0 || k < 0 || k > input.size())
        return vector<int>();

    vector<int> heap(k+1);
    heap[0] = -1;
    for (int i = 0; i < k; ++i)
        heap[i+1] = input[i];
    buildHeap(heap);

    for (int i = k; i < input.size(); ++i)
    {
        if (heap[1] > input[i])
        {
            heap[1] = input[i];
            maxHeapy(heap, k, 1);
        }
    }
    heapSort(heap);
    return vector<int>(heap.begin()+1, heap.end());
}

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> input(n);
    for (int i = 0; i < n; ++i)
        cin >> input[i];
    auto leastNums = GetLeastNumbers_Solution(input, k);
    for (auto i : leastNums)
        cout << i << " ";
    cout << endl;

    return 0;
}

#elif (CODE_NUM == 2)

typedef multiset<int, greater<int>>   intSet;
typedef multiset<int, greater<int>>::iterator setIterator;

vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
    if (input.size() < 0 || k < 0 || k > input.size())
        return vector<int>();
    intSet leastNums;
    for (int i = 0; i < input.size(); ++i)
    {
        if (leastNums.size() < k)
        {
            leastNums.insert(input[i]);
        } else
        {
            setIterator bg = leastNums.begin();
            if (*bg > input[i])
            {
                leastNums.erase(bg);
                leastNums.insert(input[i]);
            }
        }
    }
    return vector<int>(leastNums.rbegin(), leastNums.rend());
}

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> input(n);
    for (int i = 0; i < n; ++i)
        cin >> input[i];
    auto leastNums = GetLeastNumbers_Solution(input, k);
    for (auto i : leastNums)
        cout << i << " ";
    cout << endl;

    return 0;
}

#endif