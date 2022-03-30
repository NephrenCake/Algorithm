#include <cstring>
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

// https://www.acwing.com/problem/content/118/

/**
 *      -+--
 *      ----
 *      ----
 *      -+--
 * Ŀ�꣺ȫ�����-
 * ���ͣ���������
 * 1. ֻ��һ��
 * 2. ˳���޹�
 * ������
 * 1. ö�����з��� 16λ�Ķ������� Ϊ1����ʾ��
 * 2. ���ո÷����������е���
 * 3. �жϣ����ȫ���ͼ�¼����
 * ϸ��
 * 1. ʱ�临�Ӷȣ�2^(4*4)�ַ��� * (16*7������ + 16�� + 16��¼)= 65536 * 16 * 9 = 1kw ����֧�ֱ���
 * 2. ������С
 * 3. �ֵ�����С
 */

/**
 * ��2 ��string ��������ʹ��string������memcpy()����ַ����������Ҫforѭ��cp
 */


#define x first
#define y second
#define PII pair<int, int>  // ���� ���ٴ�����

const int N = 4;

string g[N + 1], backup[N + 1];

inline int is_turned(int op, int i, int j) {
    // �����op�����£���(i, j)λ�Ƿ�Ҫ����λ���� [[1, 2, 3, 4], [5, ...], ...] ����
    return op >> (4 * i + j) & 1;
}

void turn_one(int x, int y) {
    if (g[x][y] == '+') g[x][y] = '-';
    else g[x][y] = '+';
}

void turn_all(int x, int y) {
    for (int i = 0; i < 4; i++) {
        turn_one(x, i);
        turn_one(i, y);
    }
    turn_one(x, y);
}

void str_cp(string a[], string b[]) {
    // ����Ҫ��&��str[]�������ָ�� basic_string<char> *b
    for (int i = 0; i < N; i++) {
        a[i] = b[i];
    }
}

int main() {
    // д��һ ����
    // for (auto& i : g)
    //     for (char& j : i)
    //         cin >> j;
    // д���� ����
    // for (int i = 0; i < N; i++)
    //     for (int j = 0; j < N; j++)
    //         cin >> g[i][j];
    // д���� ����
    // for (auto& i : g)
    //     cin >> i;
    // д����
    for (int i = 0; i < N; i++)
        cin >> g[i];

    // test
    // for (int i = 0; i < N; i++)
    //     cout << g[i] << endl;

    vector<PII > ans;
    for (int op = 0; op < 1 << 16; op++) {
        // ö��ÿһ�ֿ��ز���
        // ע�� ��1����16λ��������2����16λ
        vector<PII > temp;
        str_cp(backup, g);

        // 1. ���в���
        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++)
                if (is_turned(op, i, j)) {
                    temp.push_back({i, j});  // ��¼·��
                    turn_all(i, j);
                }

        // 2. �ж�
        bool has_closed = false;
        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++)
                if (g[i][j] == '+')
                    has_closed = true;
        if (!has_closed)
            if (ans.empty() || ans.size() > temp.size())
                ans = temp;

        str_cp(g, backup);
    }

    cout << ans.size() << endl;
    for (auto& an : ans)
        cout << an.x + 1 << ' ' << an.y + 1 << endl;  // ע�� �±�+1
}


/**
 * ��1 ��char[]
 */

/*
#define x first
#define y second
typedef pair<int, int> PII;  // �ȼ�

const int N = 4;
char g[N][N], backup[N][N];

inline int is_turned(int op, int i, int j) {
    // �����op�����£���(i, j)λ�Ƿ�Ҫ����λ���� [[1, 2, 3, 4], [5, ...], ...] ����
    return op >> (4 * i + j) & 1;
}

void turn_one(int x, int y) {
    if (g[x][y] == '+')
        g[x][y] = '-';
    else
        g[x][y] = '+';
}

void turn_all(int x, int y) {
    for (int i = 0; i < 4; i++) {
        turn_one(x, i);
        turn_one(i, y);
    }
    turn_one(x, y);
}

int main() {
    // д��һ
    // for (auto& i : g)
    //     for (char& j : i)
    //         cin >> j;
    // д����
    // for (int i = 0; i < N; i++)
    //     for (int j = 0; j < N; j++)
    //         cin >> g[i][j];
    // д����
    for (auto& i : g)
        cin >> i;
    // д����
    // for (int i = 0; i < N; i++)
    //     cin >> g[i];

    // test
    // for (int i = 0; i < N; i++)
    //     cout << g[i] << endl;

    vector<PII > ans;
    for (int op = 0; op < 1 << 16; op++) {
        // ö��ÿһ�ֿ��ز���
        // ע�� ��1����16λ��������2����16λ
        vector<PII > temp;
        memcpy(backup, g, sizeof g);

        // 1. ���в���
        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++)
                if (is_turned(op, i, j)) {
                    temp.push_back({i, j});  // ��¼·��
                    turn_all(i, j);
                }

        // 2. �ж�
        bool has_closed = false;
        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++)
                if (g[i][j] == '+')
                    has_closed = true;

        if (!has_closed)
            if (ans.empty() || ans.size() > temp.size())
                ans = temp;

        memcpy(g, backup, sizeof backup);
    }

    cout << ans.size() << endl;
    for (auto& an : ans)
        cout << an.x + 1 << ' ' << an.y + 1 << endl;  // ע�� �±�+1
}

*/