#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int N = 1010;
string str;
pair<char, string> a[N];

int main() {
    cin >> str;
    for (int i = 0; i < str.size(); i++)
        a[i] = {str[i], str.substr(i, str.size())};

    sort(a, a + str.size());

    for (int i = 0; i < str.size(); i++)
        cout << a[i].second << endl;
}
