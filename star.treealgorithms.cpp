//链式前向星
#include <iostream>
using namespace std;

const int N=1e5+10;
int h[N],e[N*2],ne[N*2],id,n;
bool st[N];//用于判断该点是否遍历 

void add(int a,int b){
	id++;
	e[id]=b;
	ne[id]=h[a];
	h[a]=id;
}

//深度优先遍历 
void dfs(int u){
	cout<<u<<" ";
	st[u]=true;
	
	for(int i=h[u];i;i=ne[u]){
		int v=e[i];
		if(!st[v]){
			dfs(v);
		}
	}
} 

//宽度优先遍历
void bfs(){
	queue<int> q;
	q.push(1);
	st[1]=true;
	while(q.sizeof()){
		int u=q.front();
		q.pop();
		cout<<u<<" ";
		for(int i=h[u];i;i=ne[u]){
			int v=ne[i];
			if(!st[v]){
				st[v]=true;
				q.push(v);//链式前向星
#include <iostream>
using namespace std;
const int N=1e5+10;
int h[N],e[N*2],ne[N*2],id,n;
void add(int a,int b){
	id++;
	e[id]=b;
	ne[id]=h[a];
	h[a]=id;
}
int main(){
	cin>>n;
	for(inti=1;i<n;i++){
		int a,b;
		cin>>a>>b;
		add(a,b);
		add(b,a);
	}
	return 0;
}
			}
		} 
	}
} 

int main(){
	cin>>n;
	for(inti=1;i<n;i++){
		int a,b;
		cin>>a>>b;
		add(a,b);
		add(b,a);
	}
	return 0;
}
