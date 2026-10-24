//插入排序算法 
#include <iostream>
using namespace std;

const int N=100;
int a[N];
int n;

void show(int a[],int n){
	for(int i=0;i<n;i++){
		cout<<a[i]<<" ";
	}
}

void sort(int a[],int n){
	int j;
	for(int i=1;i<=n-1;i++){
		int key=a[i];
		for(j=i-1;j>=0&&a[j]>key;j--){
			a[j+1]=a[j];
		}
		a[j+1]=key;
	}
}

int main(){
	cin>>n;
	int i;
	for(i=0;i<n;i++){
		int x;
		cin>>x;
		a[i]=x;
	}
	cout<<"未排序的数组："<<endl;
	show(a,n);
	sort(a,n);
	cout<<"排序之后的数组："<<endl;
	show(a,n);
	return 0;
}

//选择排序算法 
#include <iostream>
using namespace std;

const int N=100;
int a[N];
int n;

void show(int a[],int n){
	for(int i=0;i<n;i++){
		cout<<a[i]<<" ";
	}
	cout<<endl;
}

void sort(int a[],int n){
	for(int i=0;i<n-1;i++){
		int pos=i;
		for(int j=i+1;j<=n-1;j++){
			if(a[j]<a[pos]){
				pos=j;
			}
		}
		swap(a[i],a[pos]);
	}
}

int main(){
	cin>>n;
	for(int i=0;i<n;i++){
		int x;
		cin>>x;
		a[i]=x;
	}
	cout<<"排序之前的数组："<<endl; 
	show(a,n);
	sort(a,n);
	cout<<"排序之后的数组："<<endl;
	show(a,n);
	return 0; 
} 

//冒泡排序算法
#include <iostream>
using namespace std;

const int N=100;
int a[N];
int n;

void show(int a[],int n){
	for(int i=0;i<n;i++){
		cout<<a[i]<<" ";
	}
	cout<<endl;
}

void sort(int a[],int n){
	for(int i=0;i<n-1;i++){
		for(int j=0;j<n-1;j++){
			if(a[j]>a[j+1]){
				swap(a[j],a[j+1]);
			}
		} 
	}
} 

int main(){
	cin>>n;
	for(int i=0;i<n;i++){
		int x;
		cin>>x;
		a[i]=x;
	}
	cout<<"排序之前的数组："<<endl; 
	show(a,n);
	sort(a,n);
	cout<<"排序之后的数组："<<endl;
	show(a,n);
	return 0; 
}  

//堆排序算法
#include <iostream>
using namespace std;

const int N=100;
int a[N];
int n;

void show(int a[],int n){
	for(int i=0;i<n;i++){
		cout<<a[i]<<" ";
	}
	cout<<endl;
}

void down(int a[],int parent,int len){
	int child=parent*2+1;
	while(child<len){
		if(child+1<len&&a[child]<a[child+1]){
			child++;
		}
		if(a[parent]>a[child]){
			return;
		}
		swap(a[parent],a[child]);
		parent=child;
		child=parent*2+1;
	}
}

void heap_sort(int a[],int n){
	for(int i=(n-2)/2;i>=0;i++){
		down(a,i,n);
	}
	for(int i=n-1;i>0;i++){
		swap(a[0],a[i]);
		down(a,0,i);
	}
} 

int main(){
	cin>>n;
	for(int i=0;i<n;i++){
		int x;
		cin>>x;
		a[i]=x;
	}
	cout<<"排序之前的数组："<<endl; 
	show(a,n);
	heap_sort(a,n);
	cout<<"排序之后的数组："<<endl;
	show(a,n);
	return 0; 
}  

//快速排序算法 
#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;
 
const int N=100;
int a[N];
int n;

void show(int a[],int n){
	for(int i=0;i<n;i++){
		cout<<a[i]<<" ";
	}
	cout<<endl;
}

void quick_sort(int left,int right){
	if(left>=right){
		return;
	}
	int pos=rand()%(right-left+1)+left;
	int p=a[pos];
	int l=left-1;
	int r=right+1;
	int i=left;
	while(i<r){
		if(a[i]<p){
			swap(a[++l],a[i]);
			i++;
		}
		else if(a[i]==p){
			i++;
		}
		else if(a[i]>p){
			swap(a[i],a[--r]);
		}
	}
	quick_sort(left,l);
	quick_sort(r,right);
}

int main(){
	srand(time(0));
	cin>>n;
	for(int i=0;i<n;i++){
		int x;
		cin>>x;
		a[i]=x;
	}
	cout<<"排序之前的数组："<<endl; 
	show(a,n);
	quick_sort(0,n-1);
	cout<<"排序之后的数组："<<endl;
	show(a,n);
	return 0; 
}

//归并排序算法 
#include <iostream>
using namespace std;

const int N=100;
int a[N];
int n;
int tmp[N]; 

void show(int a[],int n){
	for(int i=0;i<n;i++){
		cout<<a[i]<<" ";
	}
	cout<<endl; 
}

void merge_sort(int left,int right){
	if(left>=right){
		return;
	} 
	int mid=(left+right)>>1;
	merge_sort(left,mid);
	merge_sort(mid+1,right);
	int cur1=left;
	int cur2=mid+1;
	int i=left;
	while(cur1<=mid&&cur2<=right){
		if(a[cur1]<=a[cur2]) tmp[i++]=a[cur1++];
		else tmp[i++]=a[cur2++];
	}
	while(cur1<=mid){
		tmp[i++]=a[cur1++];
	}
	while(cur2<=right){
		tmp[i++]=a[cur2++];
	}
	for(int j=left;j<=right;j++){
		a[j]=tmp[j];
	}
}

int main(){
	cin>>n;
	int i;
	for(i=0;i<n;i++){
		int x;
		cin>>x;
		a[i]=x;
	}
	cout<<"未排序的数组："<<endl;
	show(a,n);
	merge_sort(0,n-1);
	cout<<"排序之后的数组："<<endl;
	show(a,n);
	return 0;
}
























