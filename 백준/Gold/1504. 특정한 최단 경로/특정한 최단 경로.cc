#include <stdio.h>
#include <vector>
#include <queue>
#define INF 987654321
using namespace std;

int n,e,m,s;
int a,b,c;
vector<pair<int,int> >node[805];
int value[805];
priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > >pq;

void Dijkstra(int k){
	for(int i = 1; i <= n; i++)
		value[i] = INF;
	value[k] = 0;
	pq.push(make_pair(0,k));
	while(!pq.empty()){
		int X = pq.top().first;
		int U = pq.top().second;
		pq.pop();
		for(int i = 0; i<node[U].size(); i++){
			int V = node[U][i].first;
			int W = node[U][i].second;
			if(X + W < value[V]){
				value[V] = X + W;
				pq.push(make_pair(value[V],V));
			}
		}
	}
}

int main(){	
	scanf("%d %d",&n,&e);
	for(int i=0;i<e;i++){
		scanf("%d %d %d",&a,&b,&c);
		node[a].push_back(make_pair(b,c));
		node[b].push_back(make_pair(a,c));
	}
	scanf("%d %d",&m,&s);
	long long int a1;
    long long int a2;
    long long int a3;
    long long int a4;
    long long int a5;
	Dijkstra(m);
	a1 = value[1];
	a2 = value[s];
	a3 = value[n];
	Dijkstra(s);
	a4 = value[1];
	a5 = value[n];
	long long int ans1 = a1 + a2 + a5;
	long long int ans2 = a4 + a2 + a3;
	long long int ans = ans1 < ans2 ? ans1 : ans2;
	if(ans >= INF) ans = -1;
	printf("%lld",ans);
	return 0;
}