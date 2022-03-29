#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

// https://www.acwing.com/problem/content/97/

/**
 * ��ۿ���
 * 1. ˳��������⣬һ������ֻ������Ӱ������й�
 * 2. ÿ���������ֻ��һ�Σ���Ϊ�����ε���û��
 * 3. ÿһ�п��صĲ�����ȫ��ǰһ�е�����״̬��Ψһȷ��
 * ϸ�ڿ���
 * 1. ���ö�ٵ�һ�еĲ�����λ���㣬������������ʮ���ƣ�
 * 2. turn(x, y) ��������
 * 3. ʱ�临�Ӷȣ���һ��32 * 25������ * Ӱ��5������ * 500�������� = 200 0000
 */

const int N = 6;  // �ַ���ĩβ��\0�������������һ�У��ڶ�ά����Ҫ6�ĳ��ȡ���Ȼ��һά����5�ĳ����ǿ��Ե�
const int dx[5] = {-1, 0, 1, 0, 0}, dy[5] = {0, 1, 0, -1, 0};  // ��������

char g[N][N], backup[N][N];
int res = 10;

void turn(int x, int y) {
    // �ı�������ӵ�ֵ
    for (int i = 0; i < 5; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx < 0 || nx > 4 || ny < 0 || ny > 4)
            continue;
        g[nx][ny] ^= 1;  // ���1�������λȡ����48->49��49->48
    }
}

void forward(int op) {
    memcpy(backup, g, sizeof g);  // ���汸��
    int step = 0;
    for (int i = 0; i < 5; i++)  // ָ����һ�еı仯
        if (op >> i & 1) {  // �����iλΪ1�������Ҫ���¿���
            step++;
            turn(0, i);
        }

    for (int i = 0; i < 4; i++)  // �鿴0~4��
        for (int j = 0; j < 5; j++)  // �鿴ÿһ�е����е�
            if (g[i][j] == '0') {
                step++;
                turn(i + 1, j);
            }  // ���ݺ������ƣ�ÿһ�������״̬��������һ��İ��Ʋ���

    bool dark = false;
    for (int i = 0; i < 5; i++)
        if (g[4][i] == '0') {
            dark = true;
            break;
        }  // ������һ���Ƿ�ȫ�����

    if (!dark)
        res = min(res, step);  // û����ĵƣ����ɹ���ȡ��Сֵ
    memcpy(g, backup, sizeof backup);  // �ñ��ݻ�ԭ�ֳ�
}

int main() {
    int n;
    cin >> n;
    while (n--) {  // ��n������������
        for (int i = 0; i < 5; i++)
            cin >> g[i];  // �������һ���ַ���

        res = 10;  // �ϴ��������6�����
        for (int op = 0; op < 32; op++)
            forward(op);  // ����ö�ٵ�һ�еĲ������ܣ�����ֻ�ǽ���ȥ���ݶ���

        if (res > 6)
            res = -1;  // �ܴ�������6����Ϊ�޽�
        cout << res << endl;
    }
}
