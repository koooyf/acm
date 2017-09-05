
#include<iostream>  
#include<stdio.h>  
#include<algorithm>  
#include<cmath>  
#include<stdlib.h>  
#include <string.h>  
#include<queue>  
#include<set>  
#include<map>  
#include<stack>  
#include<time.h>  
using namespace std;  
#define MAX_N 1000005  
#define inf 0x3f3f3f3f  
#define LL long long  
#define ull unsigned long long  
const LL INF = 9e18;  
const int mod = 100000000;  
typedef pair<LL, LL>P;  
  
int S[MAX_N];  
int par[MAX_N];  
vector<int>G[MAX_N];  
int val[MAX_N];  
int n, sum;  
int root;  
int ans, ans1, ans2;  
bool vis[MAX_N];  
int dfs(int u)  
{  
    int tmp = 0;  
    for(int i=0; i<G[u].size(); i++) {  
        S[u] += dfs(G[u][i]);  
    }  
    S[u] += val[u];  
    return S[u];  
}  
void dfs3(int u)  
{  
    vis[u] = true;  
    for(int i=0; i<G[u].size();i++)  
        dfs3(G[u][i]);  
}  
bool dfs2(int u)  
{  
    for(int i=0; i<G[u].size(); i++)  
        if(dfs2(G[u][i]))  
            return true;  
    if(S[u] == sum/3 && u!=root && !vis[u]) {  
        ans = u;  
        int fa = par[u];  
        //祖先节点节点sum/3  
        while(fa) {  
            S[fa] -= S[u];  
            fa = par[fa];  
        }  
        //标记子树  
        dfs3(u);  
        return true;  
    }  
    return false;  
}  
int main()  
{  
    cin >> n;  
    sum = 0;  
    for(int i=1; i<=n; i++) {  
        int fa;  
        scanf("%d%d",&fa,&val[i]);  
        par[i] = fa;  
        G[fa].push_back(i);  
        sum += val[i];  
        if(!fa)  
            root = i;  
    }  
    if(sum % 3) {  
        printf("-1\n");  
        return 0;  
    }  
    dfs(root);  
    ans1 = ans2 = 0;  
    memset(vis, false, sizeof(vis));  
    if(dfs2(root))  
        ans1 = ans;  
    if(dfs2(root))  
        ans2 = ans;  
    if(ans1 && ans2) {  
        printf("%d %d\n",ans1, ans2);  
        return 0;  
    }  
    printf("-1\n");  
}  
