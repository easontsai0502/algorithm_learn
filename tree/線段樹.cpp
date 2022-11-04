/*
[Q]
[線段數]
*/

/*include*/
#pragma GCC optimize("Ofast")
#pragma GCC optimize("O2")
#pragma GCC optimize("O1")
#pragma GCC optimize("O3")
#include<iostream>
#include<algorithm>
#include<cmath>
#include<string>
#include<sstream>
#include<vector>
#include<queue>
#include<deque>
#include<map>
#include<set>

/*using namespace*/
using namespace std;

/*define type*/
#define what_the_fuck cin.tie(0);cout.tie(0);ios::sync_with_stdio(false)
#define ULLI unsigned long long int
#define LLI long long int
#define INT LLI
#define UINT unsigned INT
#define PII pair<INT,INT>
#define PUIUI pair<UINT,UINT>
/*struct*/
/*fn宣告*/
/*num*/
bool debug=false;
bool iofast=true;
const INT maxn=1000;//物件最大數量
INT item[maxn];
INT tree[maxn];
INT nn;
/*fn定義*/
INT build_tree(INT node=0,INT l=0,INT r=nn-1){//將原始資料建立成線段數，原始數據也須保留，以便刪改
	if(l==r){
		tree[node]=item[l];
		return tree[node];
	}else{
		INT mnt=(l+r)/2;
		tree[node]=build_tree(node*2+1,l,mnt)+build_tree(node*2+2,mnt+1,r);
		return tree[node];
	}
}
void tree_numadd(INT ad,INT num,INT l=0,INT r=nn-1,INT node=0){//修改點資料(ad為原始資料的位置,num為修改後的數字)
	if(l<=ad && ad<=r){
		tree[node]-=item[ad];
		tree[node]+=num;
		if(l!=r){
		INT mnt=(l+r)/2;
		
		tree_numadd(ad,num,l,mnt,node*2+1);
		tree_numadd(ad,num,mnt+1,r,node*2+2);
		}
		item[ad]=num;
	}
}
/*main*/
int main(){
	if(!debug && iofast){what_the_fuck;}
	/*cin 原始數據*/
	cin>>nn;
	for(int i=0;i<nn;i++){
		cin>>item[i];
	}
	/*write 線段數*/
	build_tree();
	for(int i=0;i<14;i++){
		cout<<tree[i]<<" ";
	}
	cout<<endl;


	/*cin修改*/
	INT q;
	cin>>q;
	for(INT i=0;i<q;i++){
		INT ad,num;
		cin>>ad>>num;
		ad--;
		tree_numadd(ad,num);
	}
	/*solve 修改資料*/
	for(int i=0;i<14;i++){
		cout<<tree[i]<<" ";
	}
	return 0;
}
/*
[I]
(資料數量 n)
(資料 1) (資料 2) ... (資料 n)

(刪改次數 q)
(資料 id (1-n)) (修改後資料)
...q個
*/