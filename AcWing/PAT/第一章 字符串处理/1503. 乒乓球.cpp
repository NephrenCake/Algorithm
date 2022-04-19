#include <bits/stdc++.h>

using namespace std;

// https://www.acwing.com/problem/content/1505/

struct Person {
    int arrive_time, play_time;
    int start_time, waiting_time;

    bool operator<(const Person &t) const {  // 小于号用于sort排序
        if (start_time != t.start_time) return start_time < t.start_time;
        return arrive_time < t.arrive_time;
    }

    bool operator>(const Person &t) const {  // 优先队列要用大于号
        return arrive_time > t.arrive_time;
    }
};

struct Table {
    int id;
    int end_time;

    bool operator>(const Table &t) const {
        if (end_time != t.end_time) return end_time > t.end_time;
        return id > t.id;  // 序号、结束时间小的在前面
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
    vip_persons.push({INF});  // 将到达时间设为正无穷，永远不会服务

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
    vip_tables.push({-1, INF});  // 将到结束时间设为正无穷，永远不会使用

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

        // 第1种情况 修改成 第2种情况
        // 普通球桌结束，把下一一对球友到达时间 赋值给 球桌结束时间
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

        // 第2种情况， vip球员已经到了，空余的是vip球桌 安排
        if (vp.arrive_time <= end_time && vt.end_time == end_time)
            assign(vip_persons, vip_tables);
            // 正常情况，要么有vip球员无vip球桌，要么有vip球桌无vip球员
        else if (np.arrive_time < vp.arrive_time) {  // 普通球员先到
            if (nt > vt)
                assign(normal_persons, vip_tables);  // vip球桌空闲， 安排普通球员
            else
                assign(normal_persons, normal_tables);  // 普通球桌空闲，安排普通球员，因为普通球员先到
        } else {  // vip球员先到
            if (nt > vt)
                assign(vip_persons, vip_tables);
            else
                assign(vip_persons, normal_tables);
        }
    }

    sort(persons.begin(), persons.end());  // 按照开始时间，到达时间排序
    for (auto &person : persons)
        cout << get_time(person.arrive_time) << ' ' << get_time(person.start_time) << ' ' << person.waiting_time
             << endl;

    // PAT平台不能有最后一个空格
    cout << table_cnt[1];
    for (int i = 2; i <= k; i++)
        cout << ' ' << table_cnt[i];
}
