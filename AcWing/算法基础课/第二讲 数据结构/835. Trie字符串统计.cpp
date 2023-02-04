#include <iostream>

using namespace std;

const int N = 100010;
int son[N][26], cnt[N], idx;

void insert(string str) {
    int p = 0;  // ����ָ�룬ָ��ǰ�ڵ�
    for (int i = 0; i < str.size(); i++) {
        int u = str[i] - 'a'; // ����ĸת��Ϊ����
        if (!son[p][u]) son[p][u] = ++idx;   // �ýڵ㲻���ڣ������ڵ�
        p = son[p][u];  // ʹ��pָ�롱ָ����һ���ڵ�
    }
    cnt[p]++;  // ����ʱ�ı�ǣ�Ҳ�Ǽ�¼�Դ˽ڵ�������ַ�������
}

int query(string str) {
    int p = 0;
    for (int i = 0; i < str.size(); i++) {
        int u = str[i] - 'a';
        if (!son[p][u]) return 0;  // �ýڵ㲻���ڣ������ַ���������
        p = son[p][u];
    }
    return cnt[p];  // �����ַ������ֵĴ���
}

int main() {
    int m;
    string str, op;
    cin >> m;
    while (m--) {
        cin >> op >> str;
        if (op == "I") insert(str);
        else cout << query(str) << endl;
    }
}
