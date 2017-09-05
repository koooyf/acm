#include<bits/stdc++.h>
using namespace std;
int f[222222],c[222222];
map<int,map<int,int> > mp;
int getf(int x){
    if(f[x] == x)
        return x;
    else
        return f[x] = getf(f[x]);
}
void merge(int u,int v){
    int a = getf(u);
    int b = getf(v);
    if(a != b)
        f[b] = a;
}
int main(){
    int n,m,k;
    cin >> n >> m >> k;
    for(int i = 1;i<=n;i++){
        f[i] = i;
        scanf("%d",&c[i]);
    }
    int l,r;
    while(m--){
        scanf("%d%d",&l,&r);
        merge(l,r);
    }
    for(int i = 1;i<=n;i++){
        mp[getf(i)][c[i]]++;
    }
    int ans = 0;
    for(map<int,map<int,int> >::iterator i = mp.begin();i!=mp.end();i++){
        int sum = 0,mx = 0;
        for(map<int,int>::iterator j = i->second.begin();j!=i->second.end();j++){
            mx = max(mx,j->second);
            sum += j->second;
        }
        ans += sum-mx;
    }
    cout << ans;
    return 0;
}
