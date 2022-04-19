#include <bits/stdc++.h>

using namespace std;

// https://www.acwing.com/problem/content/1505/

struct Person {
    int arrive_time, play_time;
    int start_time, waiting_time;

    bool operator<(const Person &t) const {  // С�ں�����sort����
        if (start_time != t.start_time) return start_time < t.start_time;
        return arrive_time < t.arrive_time;
    }

    bool operator>(const Person &t) const {  // ���ȶ���Ҫ�ô��ں�
        return arrive_time > t.arrive_time;
    }
};

struct Table {
    int id;
    int end_time;

    bool operator>(const Table &t) const {
        if (end_time != t.end_time) return end_time > t.end_time;
        return id > t.id;  // ��š�����ʱ��С����ǰ��
    }
};

const int N = 10010, M = 110, INF = 1000000;

int n, k, m;
bool is_vip_table[M];
int table_cnt[M];
vector<Person> persons;

void assign(priority_queue<Person, vector<Person>, greater<Person>> &ps,
            priority_queue<Table, vector<Table>, greater<Table>> &ts) {
    auto p = ps.top();
    ps.pop();
    auto t = ts.top();
    ts.pop();
    p.waiting_time = round((t.end_time - p.arrive_time) / 60.0);
    p.start_time = t.end_time;
    table_cnt[t.id]++;
    persons.push_back(p);
    ts.push({t.id, t.end_time + p.play_time});
}

string get_time(int secs) {
    char str[20];
    sprintf(str, "%02d:%02d:%02d", secs / 3600, secs % 3600 / 60, secs % 60);
    return str;
}

int main() {
    cin >> n;
    priority_queue<Person, vector<Person>, greater<Person>> normal_persons;
    priority_queue<Person, vector<Person>, greater<Person>> vip_persons;
    normal_persons.push({INF});
    vip_persons.push({INF});  // ������ʱ����Ϊ�������Զ�������

    int hh, mm, ss, play_time, is_vip, tt;
    for (int i = 0; i < n; i++) {
        scanf("%d:%d:%d %d %d", &hh, &mm, &ss, &play_time, &is_vip);

        tt = hh * 3600 + mm * 60 + ss;
        play_time = min(play_time, 120) * 60;

        if (is_vip) vip_persons.push({tt, play_time});
        else normal_persons.push({tt, play_time});
    }

    priority_queue<Table, vector<Table>, greater<Table>> normal_tables;
    priority_queue<Table, vector<Table>, greater<Table>> vip_tables;
    normal_tables.push({-1, INF});
    vip_tables.push({-1, INF});  // ��������ʱ����Ϊ�������Զ����ʹ��

    cin >> k >> m;
    for (int i = 0; i < m; i++) {
        int id;
        cin >> id;
        is_vip_table[id] = true;
    }

    for (int i = 1; i <= k; i++)
        if (is_vip_table[i]) vip_tables.push({i, 8 * 3600});
        else normal_tables.push({i, 8 * 3600});

    while (normal_persons.size() > 1 || vip_persons.size() > 1) {
        auto &np = normal_persons.top();
        auto &vp = vip_persons.top();
        int arrive_time = min(np.arrive_time, vp.arrive_time);

        // ��1����� �޸ĳ� ��2�����
        // ��ͨ��������������һһ�����ѵ���ʱ�� ��ֵ�� ��������ʱ��
        while (normal_tables.top().end_time < arrive_time) {  // O(klogk)
            auto t = normal_tables.top();
            normal_tables.pop();
            t.end_time = arrive_time;
            normal_tables.push(t);
        }
        while (vip_tables.top().end_time < arrive_time) {
            auto t = vip_tables.top();
            vip_tables.pop();
            t.end_time = arrive_time;
            vip_tables.push(t);
        }

        auto nt = normal_tables.top();
        auto vt = vip_tables.top();
        int end_time = min(nt.end_time, vt.end_time);

        if (end_time >= 21 * 3600) break;

        // ��2������� vip��Ա�Ѿ����ˣ��������vip���� ����
        if (vp.arrive_time <= end_time && vt.end_time == end_time)
            assign(vip_persons, vip_tables);
            // ���������Ҫô��vip��Ա��vip������Ҫô��vip������vip��Ա
        else if (np.arrive_time < vp.arrive_time) {  // ��ͨ��Ա�ȵ�
            if (nt > vt)
                assign(normal_persons, vip_tables);  // vip�������У� ������ͨ��Ա
            else
                assign(normal_persons, normal_tables);  // ��ͨ�������У�������ͨ��Ա����Ϊ��ͨ��Ա�ȵ�
        } else {  // vip��Ա�ȵ�
            if (nt > vt)
                assign(vip_persons, vip_tables);
            else
                assign(vip_persons, normal_tables);
        }
    }

    sort(persons.begin(), persons.end());  // ���տ�ʼʱ�䣬����ʱ������
    for (auto &person : persons)
        cout << get_time(person.arrive_time) << ' ' << get_time(person.start_time) << ' ' << person.waiting_time
             << endl;

    // PATƽ̨���������һ���ո�
    cout << table_cnt[1];
    for (int i = 2; i <= k; i++)
        cout << ' ' << table_cnt[i];
}
