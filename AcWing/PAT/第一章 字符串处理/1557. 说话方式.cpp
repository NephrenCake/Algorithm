#include <bits/stdc++.h>

using namespace std;

// https://www.acwing.com/problem/content/1559/

string str, word;
map<string, int> cnt;
int max_;

void update() {
    // cout << "recording   " << word << endl;
    cnt[word]++;
    max_ = max(max_, cnt[word]);
    word = "";
}

int main() {
    getline(cin, str);
    for (auto& c: str) {
        if (c >= 'a' && c <= 'z' || c >= '0' && c <= '9') word += c;
        else if (c >= 'A' && c <= 'Z') word += char(c - ('A' - 'a'));
        else if (!word.empty()) update();
    }
    if (!word.empty()) update();

    for (auto& i: cnt)
        if (i.second == max_) {
            cout << i.first << " " << i.second;
            break;
        }
}
