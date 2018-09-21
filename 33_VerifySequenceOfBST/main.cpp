#include <iostream>
#include <vector>

using namespace std;

bool verifySeqOfBST(vector<int> &seq, int l, int r) {
    if (r - l <= 1)
        return true;
    int rootOfLT = r - 2;
    while (seq[rootOfLT] > seq[r-1])
        --rootOfLT;
//    if (rootOfLT < l)
//        return false;
    int mostRofLT = rootOfLT - 1;
    if (mostRofLT >= l && seq[mostRofLT] > seq[r-1])
        return false;
    int mostLofRT = rootOfLT + 1;
    if (mostLofRT < r && seq[mostLofRT] < seq[r-1])
        return false;
    if (verifySeqOfBST(seq, l, rootOfLT+1) && verifySeqOfBST(seq, rootOfLT+1, r-1))
        return true;
    return false;
}

bool VerifySquenceOfBST(vector<int> sequence) {
    if (sequence.size() <= 0)
        return false;
    return verifySeqOfBST(sequence, 0, sequence.size());
}

int main() {
//    vector<int> seq;
//    int e;
//    while (cin >> e)
//    {
//        seq.push_back(e);
//    }
    vector<int> seq{5, 4, 3, 2, 1};
    if (VerifySquenceOfBST(seq))
        cout << "Yes" << endl;
    else
        cout << "No" << endl;

    return 0;
}