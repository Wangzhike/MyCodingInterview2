#include <bits/stdc++.h>

using namespace std;

int MoreThanHalfNum_Solution(vector<int> numbers) {
    if (numbers.size() < 0)
        return 0;

    pair<int, int> kv{numbers[0], 1};
    for (int i = 1; i < numbers.size(); ++i)
    {
        if (numbers[i] != kv.first)
        {
            --kv.second;
            if (kv.second == 0)
            {
                kv.first = numbers[i];
                kv.second = 1;
            }
        } else
        {
            ++kv.second;
        }
    }
    int cnt = 0;
    for (int i = 0; i < numbers.size(); ++i)
        if (numbers[i] == kv.first)
            ++cnt;
//    cout << cnt << endl;
    return (cnt * 2 <= numbers.size() ? 0 : kv.first);
}

int main() {
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; ++i)
        cin >> nums[i];
    cout << MoreThanHalfNum_Solution(nums) << endl;

    return 0;
}