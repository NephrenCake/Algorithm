#include <iostream>
#include <vector>

using namespace std;

#define v first
#define w second
typedef pair<int, int> PII;

const int N = 70, M = 32010;
int m, n, f[N][M];
PII fa[N];
vector<PII> son[N];

int main() {
    cin >> m >> n;
    for (int i = 1; i <= n; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        if (!c) fa[i] = {a, a * b};
        else son[c].push_back({a, a * b});
    }

    for (int i = 1; i <= n; i++) {  // ǰi����Ʒ
        if (fa[i].v) {  // �����i����Ʒ������
            // 01�������ȴ�������ʼ��
            for (int j = fa[i].v; j <= m; j++)
                f[i][j] = max(f[i][j], f[i - 1][j - fa[i].v] + fa[i].w);

            // ��Ϊpush_back���±��Ǵ�0��ʼ�ģ�������ʱ��Ҫע��
            // �ⲿ���жϵ��ǣ����뵱ǰ��������������������ĸ�����01�����ķ�ʽȥ˼�����
            // ���ҵ�ǰ��f[i][j]һ�����Ѿ����뵱ǰ���������
            for (int k = 0; k < son[i].size(); k++)
                for (int j = m; j >= son[i][k].v; j--)
                    // �Ź������Ժ󣬲��ܷŸ�����fΪ0�Ĳ���˵���ⲿ�ַŲ�����ǰ������
                    if (f[i][j - son[i][k].v] > 0)
                        f[i][j] = max(f[i][j], f[i][j - son[i][k].v] + son[i][k].w);
        }
        // ��Ϊ�����͸���Ҫ��ͬ�жϣ��������ۺϿ���֮ǰ���޷��жϺ�ǰһ�������ĸ�����
        // ע��i��������ʱ��ҲҪ��״̬������ȥ
        for (int j = 0; j <= m; j++)
            f[i][j] = max(f[i][j], f[i - 1][j]);
    }

    cout << f[n][m] << endl;
}
