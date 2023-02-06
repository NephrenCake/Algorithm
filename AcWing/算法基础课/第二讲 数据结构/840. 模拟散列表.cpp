#include <iostream>
#include <unordered_set>

using namespace std;

unordered_set<int> s;
string op;
int n, x;

int main() {
    cin >> n;
    while (n--, cin >> op >> x) {
        if (op == "I") s.insert(x);
        else
            if (s.find(x) != s.end())
                cout << "Yes" << endl;
            else
                cout << "No" << endl;
    }
}
