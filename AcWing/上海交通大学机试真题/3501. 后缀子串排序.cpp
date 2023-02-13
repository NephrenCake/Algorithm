#include <iostream>
#include <queue>

using namespace std;

priority_queue<string, vector<string>, greater<>> h;

int main() {
    string s;
    cin >> s;
    for (int i = 0; i < s.size(); i++)
        h.push(s.substr(i, s.size() - i));
    while (h.size()) {
        cout << h.top() << endl;
        h.pop();
    }
}
