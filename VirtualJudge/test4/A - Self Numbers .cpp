#include <iostream>
#include <vector>
using namespace std;

int calIndex(int num) {
    int res = num;
    do {
        res += num % 10;
        num /= 10;
    } while (num);
    return res;
}


int main() {
    vector<bool> mark(10000, false);
    for (int i = 1; i < 10000; ++i) {
        if (calIndex(i) < 10000)
            mark[calIndex(i)] = true;
    }
    for (int i = 1; i < 10000; ++i) {
        if (mark[i]) continue;
        cout << i << endl;
    }
}