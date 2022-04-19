#include <bits/stdc++.h>

using namespace std;

// https://www.acwing.com/problem/content/1479/

string itoe[] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};

int main() {
    string str;
    cin >> str;
    int res = 0;
    for (auto i: str)
        res += i - '0';

    string out = to_string(res);
    for (int i = 0; i < out.size(); i ++) {
        cout << itoe[out[i] - '0'];
        if (i != out.size() - 1)
            cout << " ";
    }
}
