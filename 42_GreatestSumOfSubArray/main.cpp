#include <iostream>
#include <vector>

using namespace std;

int FindGreatestSumOfSubArray(vector<int> array) {
    int n = array.size();
    if (n < 0)
        return 0;
    int max_value = -1;
    int bg = -1, ed = -1;
    vector<int> gssa(n+1, 0);
    int b = 1, e = 1;
    for (int i = 1; i <= n; ++i)
    {
        if (gssa[i-1] < 0)
        {
            gssa[i] = array[i-1];
            b = i;
        }
        else
        {
            gssa[i] = gssa[i-1] + array[i-1];
            ++e;
        }
        if (max_value < gssa[i])
        {
            max_value = gssa[i];
            bg = b;
            ed = e;
        }
    }
//    cout << "[" << bg - 1 << ", " << ed - 1 << ")" << endl;
    return max_value;
}

int main() {
    int n;
    cin >> n;
    vector<int> arrary(n);
    for (int i = 0; i < n; ++i)
        cin >> arrary[i];
    cout << FindGreatestSumOfSubArray(arrary) << endl;

    return 0;
}