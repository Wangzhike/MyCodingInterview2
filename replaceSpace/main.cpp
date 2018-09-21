#include <iostream>
#include <string>
#include <cstring>

using namespace std;

void replaceSpace(char *str,int length) {
    int n_space = 0;

    int  real_len= 0;
    while (str[real_len] != '\0')
    {
        if (isspace(str[real_len]))
        {
            ++n_space;
        }
        ++real_len;
    }

    int replace_len = real_len + 2 * n_space;
    str[replace_len] = '\0';
    for (int i = real_len - 1; i >= 0; --i)
    {
        if (!isspace(str[i]))
        {
            str[--replace_len] = str[i];
        }
        else
        {
            str[--replace_len] = '0';
            str[--replace_len] = '2';
            str[--replace_len] = '%';
        }
    }
    cout << str << endl;
}

int main() {
    string str;
    getline(cin, str);
    char sz_str[str.size()*3];
    strcpy(sz_str, str.c_str());
    replaceSpace(sz_str, str.size());

    return 0;
}