#include<cstdio>
#include<cstring>
#include<vector>
#include<cmath>
#include<algorithm>
using namespace std;
struct People{
	int d;
	int v;
	int id;
	int left;
	int right;
};
struct Edge{
	double time;
	int id;
	int left;
	bool operator< (const Edge &a) const
	{
		return time>a.time;
	}
};
int aabs(int x)
{
	if(x>=0)
		return x;
	else
		return -x;
}
/*struct cmp{
	bool operator () (const Edge& a,const Edge& b) const
	{
		return a.time>b.time;
	}
};*/
vector<Edge>e;
vector<People>p;
int main()
{
	int t,n,len;
	scanf("%d",&t);
	while(t--)
	{
		int d,v;
		scanf("%d%d",&n,&len);
		for(int i=0;i<n;i++)
		{
			scanf("%d",&d);
			p.push_back((People){d,0,i,i-1,i+1});
		}
		p[0].left=n;
		p[n-1].right=0;
		for(int i=0;i<n;i++)
		{
			scanf("%d",&v);
			p[i].v=v;
		}
		//sort(p.begin(),p.end());
		for(int i=0;i<n;i++)
		{
			e.push_back((Edge){0,i,p[i].left});
			double vv,llen;
			if(p[p[i].left].v>=0&&p[i].v>=0)
			{
				if(p[p[i].left].v>p[i].v)
				{
					vv=p[p[i].left].v-p[i].v;
					llen=(len+p[i].d-p[p[i].left].d)%len;
					e[i].time=llen/vv;
				}
				else if(p[p[i].left].v<p[i].v)
				{
					vv=p[i].v-p[p[i].left].v;
					llen=(len+p[p[i].left].d-p[i].d)%len;
					e[i].time=llen/vv;
				}
			}
			else if(p[p[i].left].v<=0&&p[i].v<=0)
			{
				if(p[p[i].left].v<p[i].v)
				{
					vv=aabs(p[p[i].left].v-p[i].v);
					llen=(len+p[p[i].left].d-p[i].d)%len;
					e[i].time=llen/vv;
				}
				else if(p[p[i].left].v>p[i].v)
				{
					vv=aabs(p[p[i].left].v-p[i].v);
					llen=(len+p[i].d-p[p[i].left].d)%len;
					e[i].time=llen/vv;
				}
			}
			else if(p[p[i].left].v>0&&p[i].v<0)
			{
				vv=aabs(p[p[i].left].v-p[i].v);
				llen=(len+p[i].d-p[p[i].left].d)%len;
				e[i].time=llen/vv;
			}
			else if(p[p[i].left].v<0&&p[i].v>0)
			{
				vv=aabs(p[p[i].left].v-p[i].v);
				llen=(len+p[p[i].left].d-p[i].d)%len;
				e[i].time=llen/vv;
			}
		}
		make_heap(e.begin(),e.end());
		int k=n;
		while(k>2)
		{
			Edge edge=e[0];
			pop_heap(e.begin(),e.end());
			double vv,llen;
			int ll,rr;
			p[p[edge.id].left].right=p[edge.id].right;
			p[p[edge.id].right].left=p[edge.id].left;
			int ss;
			if(p[edge.id].id>p[edge.left].id)
			{
				ss=edge.left;
			}
			else
				ss=edge.id;
			e.pop_back();
			ll=p[ss].left,rr=p[ss].right;
			e[ss].left=p[ss].left;
			e[ss].id=p[ss].id;
			vv=aabs(p[ll].v-p[rr].v);
		    if(p[ll].v>=0&&p[rr].v>=0)
			{
				if(p[ll].v>p[rr].v)
					llen=(len+p[rr].d-p[ll].d)%len;
				else
					llen=(len+p[ll].d-p[rr].d)%len;
			}
			else if(p[ll].v<=0&&p[rr].v<=0)
			{
				if(p[ll].v<p[rr].v)
				{
					llen=(len+p[ll].d-p[rr].d)%len;
				}
				else
					llen=(len+p[rr].d-p[ll].d)%len;
			}
			else if(p[ll].v>0&&p[rr].v<0)
			{
				llen=(len+p[rr].d-p[ll].d)%len;	
			}
			else if(p[ll].v<0&&p[rr].v>0)
				llen=(len+p[ll].d-p[rr].d)%len;
			e[p[ss].right].time=llen/vv;
			push_heap(e.begin(),e.end());
			k--;
		}
		printf("%lf",e[0].time);
	}
	return 0;
}
