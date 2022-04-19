#include <bits/stdc++.h>

using namespace std;

// https://www.acwing.com/problem/content/1522/

struct P {
    string name;
    string sex;
    string id;
    int score;
};

P ps[110];

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> ps[i].name >> ps[i].sex >> ps[i].id >> ps[i].score;

    sort(ps, ps + n, [](P& p1, P& p2) {
        if (p1.sex == p2.sex) return p1.score > p2.score;
        else return p1.sex == "F";
    });

    if (ps[0].sex == "F") cout << ps[0].name << " " << ps[0].id << endl;
    else cout << "Absent" << endl;
    if (ps[n - 1].sex == "M") cout << ps[n - 1].name << " " << ps[n - 1].id << endl;
    else cout << "Absent" << endl;
    if (ps[0].sex == "F" && ps[n - 1].sex == "M") cout << ps[0].score - ps[n - 1].score;
    else cout << "NA" << endl;
}
