#include <iostream>
#include <vector>

using namespace std;

int minIndexInOrder(vector<int> rotateArray, int l ,int r) {
    int minIndex = l;
    for (int i = l + 1; i < r; ++i)
    {
        if (rotateArray[minIndex] > rotateArray[i])
        {
            minIndex = i;
        }
    }
    return minIndex;
}

int minNumberInRotateArray(vector<int> rotateArray) {
    int l = 0, r = rotateArray.size();
    int m = 1;
    while (rotateArray[l] >= rotateArray[r-1]) {
        if (r - l == 2) {
            m = r - 1;
            break;
        }
        m = (l + r) / 2;

        // 如果l, r, m指向的数字相等，则只能顺序查找
        if (rotateArray[l] == rotateArray[r - 1]
            && rotateArray[l] == rotateArray[m])
        {
            m = minIndexInOrder(rotateArray, l, r);
            break;
        }

        // 位于左端的递增子数组
        if (rotateArray[m] >= rotateArray[l])
        {
            l = m;
        }
        // 位于右端的递增子数组
        if (rotateArray[m] <= rotateArray[r-1])
        {
            r = m + 1;
        }
    }
    return rotateArray[m];
}

int main() {
    int n;
    cin >> n;
    vector<int> rotateArray(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> rotateArray[i];
    }
    cout << minNumberInRotateArray(rotateArray) << endl;

    return 0;
}