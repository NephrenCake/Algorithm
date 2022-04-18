#include <bits/stdc++.h>

// https://www.acwing.com/problem/content/1480/

/**
 * tip: 也可以直接只维护最小in和最大out
 */

using namespace std;

struct P {
    string id;
    string in;
    string out;
};

P ps[20];

int main() {
    int m;
    cin >> m;
    for (int i = 0; i < m; i++) {
        string t1, t2, t3;
        cin >> t1 >> t2 >> t3;
        ps[i] = {t1, t2, t3};
    }
    sort(ps, ps + m, [](P& p1, P& p2){
        return p1.in <= p2.in;
    });
    cout << ps[0].id << " ";
    sort(ps, ps + m, [](P& p1, P& p2){
        return p1.out >= p2.out;
    });
    cout << ps[0].id;
}
