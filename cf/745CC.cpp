#include <cstdio>
#include <algorithm>
#include <iostream>
#include <cstring>
#include <string>
#include <cmath>
#include <queue>
#include <vector>
#include <map>
#include <set>
#include <stack>
using namespace std;
#define INF 0x3f3f3f3f
#define N 100010
typedef long long LL;
struct node {
    int u, v, nxt;
}edge[2*N];
struct P {
    int id, num;
}p[1010];
int head[1010], tot, cnt, num;
int belong[1010], dfn[1010], low[1010], c[1010], vis[1010];
stack<int> sta;
vector<int> v1, v2;

void add(int u, int v) {
    edge[tot].v = v; edge[tot].nxt = head[u]; head[u] = tot++;
}

void tarjan(int u) {
    dfn[u] = low[u] = ++cnt;
    vis[u] = 1; sta.push(u);
    for(int i = head[u]; ~i; i = edge[i].nxt) {
        int v = edge[i].v;
        if(!dfn[v]) {
            tarjan(v);
            if(low[v] < low[u]) low[u] = low[v];
        } else if(vis[v]) {
            if(dfn[v] < low[u]) low[u] = dfn[v];
        }
    }
    if(dfn[u] == low[u]) {
        ++num;
        while(true) {
            int v = sta.top(); sta.pop();
            belong[v] = num; vis[v] = 0;
            if(v == u) break;
        }
    }
}

int main() {
    int n, m, k;
    scanf("%d%d%d", &n, &m, &k);
    for(int i = 0; i < k; i++) scanf("%d", c + i);
    memset(head, -1, sizeof(head));
    memset(vis, 0, sizeof(vis));
    tot = num = cnt = 0;
    for(int i = 0; i < m; i++) {
        int u, v;
        scanf("%d%d", &u, &v);
        add(u, v); add(v, u);
    }
    for(int i = 1; i <= n; i++)
        if(!dfn[i]) tarjan(i);
    v1.clear(); v2.clear();
    for(int i = 1; i <= num; i++) {
        for(int j = 1; j <= n; j++) {
            if(belong[j] == i) {
                p[i].num++;
            }
        }
    }
    for(int i = 0; i < k; i++)
        p[belong[c[i]]].id = 1;
    for(int i = 1; i <= num; i++) {
        if(p[i].id == 1) v1.push_back(p[i].num);
        else v2.push_back(p[i].num);
    }
    sort(v1.begin(), v1.end());
    sort(v2.begin(), v2.end());
    int sz = v1.size();
    int szz = v2.size();
    LL ans = 0;
    for(int i = 0; i < szz; i++)
        ans += v1[sz-1] * v2[i];
    for(int i = 0; i < szz; i++) {
        for(int j = i + 1; j < szz; j++) {
            ans += v2[i] * v2[j];
        }
        ans += v2[i] * (v2[i]-1) / 2;
    }

    for(int i = 0; i < sz; i++)
        ans += (v1[i]-1) * v1[i] / 2;
    ans -= m;
    printf("%I64d\n", ans);
    return 0;
}

/*
8 4 2
4 5
1 2
6 7
7 8
2 4
*/