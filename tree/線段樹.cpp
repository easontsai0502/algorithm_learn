/*
[Q]
[線段數]
[err]
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
INT tree_find(INT fl,INT fr,INT node=0,INT l=0,INT r=nn-1){
	if(debug)cout<<"fl="<<fl<<",fr="<<fr<<",node="<<node<<",l="<<l<<",r="<<r<<endl;
	if(fl<=l && r<=fr)return tree[node];//若目前尋找的範圍(fl,fr)和框的範圍(l,r)相同
	if(fl==fr)return item[fl];//如果只要找該數值
	else{
		INT mnt=(l+r)/2;
		INT re=0;
		if(fl<=mnt){//mnt左邊
			re+=tree_find(fl,fr,node*2+1,l,mnt);
		}
		if(mnt<fr){//mnt右邊
			re+=tree_find(fl,fr,node*2+2,mnt+1,r);
		}
		return re;
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
	/*cout*/
	for(int i=0;i<14;i++){
		cout<<tree[i]<<" ";
	}
	cout<<endl;

	/*cin 修改資料*/
	INT q;
	cin>>q;
	for(INT i=0;i<q;i++){
		INT ad,num;
		cin>>ad>>num;
		ad--;
		/*solve 修改資料*/
		tree_numadd(ad,num);
		/*cout*/
		for(int i=0;i<14;i++){
			cout<<tree[i]<<" ";
		}
	}

	/*cin 詢問區間和*/
	INT q2;
	cin>>q2;
	while(q2--){
		INT l,r;
		cin>>l>>r;
		l--;r--;
		/*solve+cout*/
		cout<<tree_find(l,r)<<endl;
	}
	return 0;
}
/*
[I]
(資料數量 n)
(資料 tree[0]) (資料 tree[0]) ... (資料 tree[n-1])

(修改次數 q)
(資料 ad (input 1-n)) (修改後資料 num)
...q個

(詢問區間和 q2)
(左 l) (右 r)
[O]
(輸出樹(以bfs呈現))
(輸出刪改後的樹)*q行
(輸出區間和)*q2行
*/