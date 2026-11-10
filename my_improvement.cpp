   //多项式输出算法
#include <iostream>
#include <cmath>
using namespace std;
int n;
int x;
int main(){
	cin>>n;
	for(int i=n;i>=0;i--){
	cin>>x;	
	if(x==0) continue;
	else if(x<0)	cout<<"-";
		else{
			if(i!=n) cout<<"+";
		}
	x=abs(x);
	if(x!=1||x==1&&i==0) cout<<x;
	if(i==1) cout<<"x";
		else if(i!=0&&i!=1) cout<<"x^"<<i;
	}
} 

   //蛇形方阵 
#include <iostream>
using namespace std;
const int N=10;
int a[N][N];
int n;
int cnt=1;
int dx[]={0,1,0,-1};
int dy[]={1,0,-1,0};
int pos=0;
void show(int a[][N],int n){
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cout<<a[i][j]<<"   ";
		}
		cout<<endl;
	}
}
int main(){
	cin>>n;
	int x=0;int y=0;
	while(cnt<=n*n){
		a[x][y]=cnt;
		if(cntn*n) break; 
		int nx=x+dx[pos];int ny=y+dy[pos];
		while(nx<0||nx>=n||ny<0||ny>=n||a[nx][ny]){
			pos=(pos+1)%4;
			nx=x+dx[pos];ny=y+dy[pos];		
		}
		x=nx;y=ny;
		cnt++;	
	}
	show(a,n);
	return 0;
}

   //高精度加法 
#include <iostream>
#include <string>
using namespace std;
string a,b;
const int N=100;
int la,lb,lc;
int na[N],nb[N],nc[N];
int main(){
	cin>>a>>b;
	la=a.size();lb=b.size();
	lc=max(la,lb);
	for(int i=0;i<la;i++) na[i]=a[la-1-i]-'0';
	for(int i=0;i<lb;i++) nb[i]=b[lb-1-i]-'0';
	for(int i=0;i<=lc;i++){
		nc[i]+=na[i]+nb[i];
		nc[i+1]+=nc[i]/10;
		nc[i]=nc[i]%10;
	}
	if(nc[lc]) lc++;
	for(int i=lc-1;i>=0;i--){
		cout<<nc[i];
	}
	return 0;
}

   //高精度减法
#include <iostream>
#include <string>
using namespace std;
string s1,s2,a,b;
const int N=100;
int la,lb,lc;
int na[N],nb[N],nc[N];
bool cmp(string s1,string s2){
	if(s1.size()>s2.size()) return true;
	else return false;
} 
int main(){
	cin>>s1>>s2;
	if(cmp(s1,s2)){
		a=s1;b=s2;
	}
	else{
		a=s2;b=s1;cout<<"-";
	}
	la=a.size();lb=b.size();
	for(int i=0;i<la;i++) na[i]=a[la-1-i]-'0';
	for(int i=0;i<lb;i++) nb[i]=b[lb-1-i]-'0';
	lc=max(la,lb);
	for(int i=0;i<lc;i++){
		nc[i]=na[i]-nb[i];
		if(nc[i]<0){
			na[i+1]--;
			nc[i]+=10; 
		}
	}
	int len=lc;
	while(nc[lc-1]==0&&lc>1) lc--;
	for(int i=lc-1;i>=0;i--){
		cout<<nc[i];
	}
	return 0;
}

   //高精度乘法
#include <iostream>
#include <string>
using namespace std;
const int N=100;
int a[N],b[N],c[N];
int la,lb,lc;
int main(){
	string x,y;
	cin>>x>>y; 
	la=x.size();lb=y.size();
	for(int i=0;i<la;i++) a[i]=x[la-1-i]-'0';
	for(int i=0;i<lb;i++) b[i]=y[lb-1-i]-'0';
	lc=la+lb;
	for(int i=0;i<la;i++){
		for(int j=0;j<lb;j++){
			c[i+j]+=a[i]*b[j];
		}
	}
	for(int i=0;i<lc;i++){
		c[i+1]+=c[i]/10;
		c[i]=c[i]%10;
	} 	
	while(lc>1&&c[lc-1]==0) lc--;
	for(int i=lc-1;i>=0;i--) cout<<c[i];
	return 0;
}     

   //铺地毯问题 
#include <iostream>
using namespace std;

const int N=100;
int a[N],b[N],g[N],k[N];
int n;
int x,y;
int ans=-1;

int main(){
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i]>>b[i]>>g[i]>>k[i];
	cin>>x>>y;
	for(int i=n;i>=1;i--){
		if(x>=a[i]&&y>=b[i]&&x<=a[i]+g[i]&&y<=b[i]+k[i]){
			ans=i;
			break;
		}
	}
	cout<<ans<<endl;
} 

   //子集问题 
#include <iostream>
#include <vector>
using namespace std;
const int N=20;
int n;
int a[N];
vector<int> tmp;
vector<vector<int>> vec;
int main(){
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];	
	}
	for(int st=0;st<(1<<n);st++){
		tmp.clear();
		for(int i=0;i<n;i++){
			if((st>>i&1)) tmp.push_back(a[i]);
		}
		vec.push_back(tmp);
	}
	for(auto &v:vec){
		cout<<"[";
		for(int i=0;i<v.size();i++){
			if(i!=0) cout<<",";
			cout<<v[i];
		}
		cout<<"]";
	}
	return 0;	
}

   //费解的开关
#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
using namespace std;
int a[5][5];
int t[5][5];
string s[5];
int ans=10;
int dx[]={0,0,1,0};
int dy[]={0,1,0,-1};
void press(int x,int y,int a[][5]){
	for(int i=0;i<4;i++){
		int nx=x+dx[i];
		int ny=y+dy[i];
		if(nx>=0&&nx<5&&ny>=0&&ny<5) a[nx][ny]^=1;
	}
}
int main(){
	for(int i=0;i<5;i++){
		cin>>s[i];
	}
	for(int i=0;i<5;i++){
		for(int j=0;j<5;j++){
			a[i][j]=s[i][j]-'0';
		}
	}
	int ret=0;
	for(int st=0;st<(1<<5);st++){
		ret=0;
		memcpy(t,a,sizeof(a));
		for(int i=0;i<5;i++){
			if((st>>i)&1){
				press(0,i,t);
				ret++;
			}
		}
		for(int i=1;i<5;i++){
			for(int j=0;j<5;j++){
				if(t[i-1][j]==0){
					press(i,j,t);
					ret++;
				}
			}
		}
		bool ok=true;
		for(int i=0;i<5;i++){
			if(t[4][i]==0){
				ok=false;
				break;
			}
		}
		if(ok){
			ans=min(ans,ret);
		}
	}
	if(ans>6) cout<<"-1";
	else cout<<ans;
	return 0;
}

   //一堆前缀和
#include <iostream>
using namespace std;
typedef long long LL;
const int N=1e5+10;
int n;
LL a[N],f[N];
int main(){
	ios::sync_with_t=stdio(false);
	cin.tie(nullptr);
	int m;cin>>n>>m;
	for(int i=1;i<=n;i++){
		int x;cin>>x;
		a[i]=x;
		f[i]=f[i-1]+a[i];
	}
	for(int i=1;i<=m;i++){
		int l,r;cin>>l>>r;
		cout<<f[r]-f[l-1]<<'\n';
	}
	return 0;
} 

   //最大子段和 
#include <iostream>
#include <algorithm>
using namespace std;
typedef long long LL;
const int N=1e5+10;
int f[N];
int main(){
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		int x;
		cin>>x;
		f[i]=f[i-1]+x;
	}
	int ans=-1e5+10;
	int premin=0;
	for(int i=1;i<=n;i++){
		premin=min(premin,f[i]);
		ans=max(ans,f[i]-premin);	
	}
	cout<<ans; 
	return 0;
} 

   //一维差分 （用差分数组定义创建差分数组） 
#include <iostream> 
using namespace std;
const int N=1e5+10;
typedef long long LL;
LL a[N];
LL f[N];
int n,m;
int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		int x;
		cin>>x;
		a[i]=x;
		f[i]=a[i]-a[i-1];  //
	}
	int l,r,k;
	cin>>m;
	while(m--){
		cin>>l>>r>>k;
	f[l]+=k;
	f[r+1]-=k;
	}
	for(int  ;i<=n;i++){
		a[i]=a[i-1]+f[i];
	}
	for(int i=1;i<=n;i++){
		cout<<a[i]<<" ";
	}
	return 0;
}

   //一维差分（用差分数组性质定义差分数组）
#include <iostream> 
using namespace std;
const int N=1e5+10;
typedef long long LL;
LL f[N];
int n,m;
int l,r,k;
int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		int x;
		cin>>x;
		f[i]+=x;    //
		f[i+1]-=x;	//
	}
	cin>>m;
	while(m--){
		cin>>l>>r>>k;
	f[l]+=k;
	f[r+1]-=k;
	}
	for(int i=1;i<=n;i++){
		a[i]=a[i-1]+f[i];
	}
	for(int i=1;i<=n;i++){
		cout<<a[i]<<" ";
	}
	return 0;
}

   //海底高铁 
#include <iostream> 
#include <algorithm>
using namespace std;
const int N=1e5+10;
typedef long long LL;
LL f[N];
int n,m;
int main(){
	cin>>n>>m;
	int x;
	cin>>x;
	for(int i=2;i<=m;i++){
		int y;cin>>y;
		int l=min(x,y);
		int r=max(x,y);
		f[l]++;
		f[r]--;
		x=y;
	}
	for(int i=1;i<=n;i++){
		f[i]+=f[i-1];
	}
	int a,b,c;
	LL s=0;
	for(int i=1;i<n;i++){
		cin>>a>>b>>c;
		s+=min(a*f[i],c+b*f[i]);
	}
	cout<<s;
	return 0;
}

   //唯一的雪花 （双指针） 
#include <iostream>
#include <unordered_map>
#include <algorithm>
using namespace std;
const int N=1e5+10;
int a[N];
int n;
int main(){
	int t;
	cin>>t;
	for(int i=0;i<t;i++){
		cin>>n;
		for(int i=0;i<n;i++){
			int x;
			cin>>x;
			a[i]=x;
		}
		int left=0,right=0,ret=0;
		unordered_map<int,int> mp;
		while(right<n){
			mp[a[right]]++;
			while(mp[a[right]]>1){
				mp[a[left]]--;
				left++;
			}
			ret=max(ret,right-left+1);
			right++;
		}
		cout<<"本轮的最大结果为"<<ret<<endl;
	}
	return 0;
} 

   //二分算法求前后下标 
#include <iostream>
using namespace std;
const int N=1e5+10;
typedef long long LL;
LL a[N];
int main(){
	int n;
	LL target;
	cin>>n>>target;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	LL left=1,right=n;
	while(right>left){
		LL mid=(left+right)/2;
		if(a[mid]<target){
			left=mid+1;
		}
		else right=mid;
	}
	if(a[left]!=target) return -1;
	int left_pos=left;
	left=1;right=n;
	while(right>left){
		int mid=(left+right+1)/2;
		if(a[mid]>target) right=mid-1;
		else left=mid;
	}
	int right_pos=left;
	cout<<left_pos<<" "<<right_pos<<endl;
	return 0;
}

   //二分算法 木材加工问题 
#include <iostream>
#include <algorithm>
using namespace std;
typedef long long LL;
const int N=1e5+10;
LL a[N],k,x,n;
LL calcu(LL x){
	LL ret=0;
	for(int i=0;i<n;i++){
		ret+=a[i]/x;
	}
	return ret;
}
int main(){
	cin>>n>>k;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	LL left=1;
	LL right=1e8+10;
	while(right>left){
		LL mid=(left+right+1)/2;
		if(calcu(mid)>=k) left=mid;
		else right=mid-1;
	}
	if(calcu(left)>=k){
		cout << left << endl;
	}else{
		cout << 0 << endl;
	}
	return 0;
}

   //贪心算法（找零问题）
#include <iostream>
using namespace std;
const int N=10;
int a[N];
int m,s;
int main(){
	cin>>m>>s;   //面值从大到小 
    for(int i=0;i<n;i++){
    	cin>>a[i];
	} 
	int b[N];
	for(int i=0;i<n;i++){
		b[i]=s/a[i];
		s-=a[i]*b[i];
	}
	for(int i=0;i<n;i++){
		cout<<b[i]<<" ";
	}
	return 0;
} 

   //货舱选址问题（贪心算法）
#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

const int N=100;
int a[N];
int n;
int main(){
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n);
	int pos=a/2;
	int ans=0;
	for(int i=0;i<n;i++){
		ans+=abs(a[i]-a[pos]);
	}
	cout<<ans<<endl;
	return 0;
} 

   //贪心算法计算最大子段和 
#include <iostream>
#include <algorithm>
using namespace std;
const int N=1e5+10;
typedef long long LL;
LL a[N];
int n;
int main(){
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}	
	LL sum=0;
	LL ret=-1e5;
	for(int i=0;i<n;i++){
		sum+=a[i];
		ret=max(ret,sum);
		if(sum<0){
			sum=0;
		}
	}
	cout<<ret<<endl;
	return 0;
}

   //贪心算法 哈夫曼编码 
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
typedef long long LL;
int main(){
	int n;
	cin>>n;
	priority_queue<LL,vector<int>,greater<LL>> heap;
	for(int i=0;i<n;i++){
		LL x;
		cin>>x;
		heap.push(x);
	}
	LL ret=0;
	while(heap.size()>1){
		LL x=heap.top();heap.pop();
		LL y=heap.top();heap.pop();
		ret+=x+y;
		heap.push(x+y);
	}
	cout<<ret<<endl;
	return 0;
} 

   //倍增思想（快速幂）
#include <iostream>
using namespace std;
typedef long long LL;
LL b,p,k;
int main(){
	cin>>b>>p>>k;
	int ans=1;
	while(p){
		if(p&1) ans=ans*b%k;
		b=b*b%k;
		p>>=1;
	}
	cout<<ans;
	return 0;
}

   //汉诺塔问题（递归） 
#include <iostream>
using namespace std;
int n;
char a,b,c;
void dfs(int n,char x,char y,char z){
	if(n==0) return ;
	dfs(n-1,x,z,y);
	printf("%c->%d->%c",x,n,z);
	dfs(n-1,y,x,z);
} 
int main(){
	cin>>n>>a>>b>>c;
	dfs(n,a,b,c);//把a号上的n个盘子借助b放c上 
	return 0;
}

   //逆序对（分治思想） 
#include <iostream> 
using namespace std;
typedef long long LL;
const int N=5e5+10; 
int n;
int a[N];
int tmp[N];
LL merge(int left,int right){
	if(left>=right) return 0;
	LL ret=0;
	int mid=(left+right)/2;
	ret+=merge(left,mid);
	ret+=merge(mid+1,right);
	int cur1=left,cur2=mid+1;
	int i=left;
	while(cur1<=mid&&cur2<=right){
		if(a[cur1]<=a[cur2]) tmp[i++]=a[cur1++];
		else{
			ret+=mid-cur1+1;
            tmp[i++]=a[cur2++];
		}
	}
	while(cur1 <= mid) tmp[i++]=a[cur1++];
    while(cur2 <= right) tmp[i++]=a[cur2++];
    for(int j=left;j<=right;j++) a[j]=tmp[j];
    return ret;
}
int main(){
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	cout<<merge(1,n)<<endl;
	return 0;
}

   //枚举子集 
#include <iostream>
using namespace std;
int n;
string path;
void dfs(int pos){
	if(pos>n){
		cout<<path<<endl;
		return;
	}
	path+='N';
	dfs(pos+1);
	path.pop_back();
	path+='Y';
	dfs(pos+1);
	path.pop_back();
}
int main(){
	cin>>n;
	dfs(1);
	return 0;
} 

   //组合型枚举
#include <iostream>
#include <vector>
using namespace std;
int n,m;
vector<int> path;
void dfs(int pos,int begin){
	if(pos>m){
		for(auto x:path){
			cout<<x<<" ";
		}
		cout<<endl;
		return;
	}
	for(int i=begin;i<=n;i++){
		path.push_back(i);
		dfs(pos+1,i+1);
		path.pop_back();
	}
}
int main(){
	cin>>n>>m;
	dfs(1,1);
	return 0;
} 

   //枚举全排列 
#include <iostream>
#include <vector>
using namespace std;
int n;
const int N=10;
int vis[N]={0};
vector<int> path;
void dfs(int pos){
	if(pos>n){
		for(auto x:path){
			cout<<x<<" ";
		}
		cout<<endl;
		return;
	}
	for(int i=1;i<=n;i++){
		if(vis[i]==0){//没有被传入 
			path.push_back(i);
			vis[i]=1;
			dfs(pos+1);
			path.pop_back();
			vis[i]=0; 
		}
		 
	}
}
int main(){
	cin>>n;
	dfs(1);
	return 0;
}

   //选数问题
#include <iostream>
using namespace std;
const int N=20;
int a[N]; 
int n,k;
int path=0;
int ret=0;
bool isprime(int x){
	if(x<=1) return false;
	for(int i=2;i<=x/i;i++){
		if(x%i==0) return false;
	}
	return true;
}
void dfs(int pos,int begin){
	if(pos==k){
		if(isprime(path)) ret++;
		return;
	}
	for(int i=begin;i<n;i++){
		path+=a[i];
		dfs(pos+1,i+1);
		path-=a[i];
	}
}
int main(){
	cin>>n>>k;
	for(int i=0;i<n;i++) cin>>a[i];
	dfs(0,0);
	cout<<ret;
	return 0;
} 

   //树的划分问题
#include <iostream>
using namespace std;
int n,k;
int ret=0;
int path=0;
void dfs(int pos,int begin){
	if(pos>k){
		if(path==n) ret++;
		return;
	}
	for(int i=begin;i<=n;i++){
		if(path+i*(k-pos+1)>n) break;
		path+=i;
		dfs(pos+1,i);
		path-=i;
	}
}
int main(){
	cin>>n>>k;
	dfs(1,1);
	cout<<ret;
	return 0;
} 

   //记忆化搜索 
#include <iostream>
#include <cstring>
using namespace std;
class Solution {
	private:
		int f[35];
	public:
		int dfs(int x){
			if(x==1||x==0) return x;
			if(f[x]!=-1) return f[x];
			else {
				f[x]=dfs(x-1)+dfs(x-2);
				return f[x];
			}
		}	
		int fib(int x){
			memset(f,-1,sizeof(f));
			return dfs(x);	
		}		 
};
int main(){
	Solution sol;
    int n;
    cin>>n;
    cout<<sol.fib(n)<<endl;
    return 0;
}








