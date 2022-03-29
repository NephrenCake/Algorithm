#include <cstring>
#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;

// https://www.acwing.com/problem/content/1210/

/**
 * ��ʼ״̬������״̬�����·����ͨ��ʹ�ÿ��ѣ�������ֻ��һ��αװ�����Ż������Ψһȷ������
 * ʱ�临�Ӷ� O(n)
 */

/**
 * ��1 c++ string ʵ��
 */

string a, b;
int ans;

void turn(int x) {
    if (a[x] == '*')
        a[x] = 'o';
    else
        a[x] = '*';
}

int main() {
    cin >> a >> b;
    for (int i = 0; i < a.size(); i++) {
        if (a[i] != b[i]) {
            ans++;
            turn(i);
            turn(i + 1);
        }
    }
    cout << ans;
}

/**
 * ��2 c char[] ʵ�� ����
 */

/*
const int N = 110;

char a[N], b[N];
int n, ans;

void turn(int x) {
    if (a[x] == '*') a[x] = 'o';
    else a[x] = '*';
}

int main() {
    cin >> a >> b;
    n = strlen(a);

    for (int i = 0; i < n - 1;  i++) {
        if (a[i] != b[i]) {
            ans++;
            turn(i);
            turn(i + 1);
        }
    }

    cout << ans;
}
*/