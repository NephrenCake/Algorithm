#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> PII;
const int N = 1010;
int n, m, a[N][N], r[N][4], c[N][4];
queue<int> q;

//������[i, j]��ֵΪx
//ͬʱ�жϵ�i ���Ƿ��������㣬��j ���Ƿ���������
void add(int i, int j, int x) {
    a[i][j] = x;
    //�����i ��һ���㶼û�У�������һ�����ֵ��r[i][0],����Ϊr[i][1]
    //��������i ��û�ڶ����㣬�����ڶ������ֵ��r[i][2],����Ϊr[i][3]�����Ҽ��뵽bfs��
    //������е���������ʵ�Ͳ����в���
    if (!r[i][0]) r[i][0] = x, r[i][1] = j;
    else if (!r[i][2]) r[i][2] = x, r[i][3] = j, q.push(i * 2 + 1);//���������չ����������
    //���н���ͬ�Ȳ���
    if (!c[j][0]) c[j][0] = x, c[j][1] = i;
    else if (!c[j][2]) c[j][2] = x, c[j][3] = i, q.push(j * 2);//���������չ������ż��
}

int main() {
    cin >> n >> m;
    for (int i = 0, x; i < n; i++)
        for (int j = 0; j < m; j++) {
            cin >> x;
            if (x) add(i, j, x);//��[i, j] ��ֵ x
        }

    vector<PII> ans;//frist �����[x, y]���꣬sceond�����ֵ
    while (q.size()) {
        int now = q.front() / 2, f = q.front() % 2;
        q.pop();//ȡ���кŻ����к�
        if (f) {//���������չ
            int suf = (r[now][2] - r[now][0]) / (r[now][3] - r[now][1]);//�õ��Ȳ�ֵ
            int start = r[now][0] - (r[now][1] * suf);//��õ�һ�����ֵ
            for (int i = 0; i < m; i++)
                if (!a[now][i]) {//���a[now][i]��0����a[now][i]���յȲʽ��ֵ
                    add(now, i, start + i * suf);//��ֵ
                    ans.push_back({now * 2000 + i, start + i * suf});//����[���ֵ꣬]��������
                }
        } else {//����չ������ͬ��
            int suf = (c[now][2] - c[now][0]) / (c[now][3] - c[now][1]);
            int start = c[now][0] - (c[now][1] * suf);
            for (int i = 0; i < n; i++)
                if (!a[i][now]) {
                    add(i, now, start + i * suf);
                    ans.push_back({i * 2000 + now, start + i * suf});
                }
        }
    }
    sort(ans.begin(), ans.end());//������������
    for (auto [xy, val]: ans)
        printf("%d %d %d\n", xy / 2000 + 1, xy % 2000 + 1, val);//�����
}
