/*
[Q]
[線段數-求區間最大,最小值,和]
[dev]
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
#define elif else if
#define ifif if
/*struct*/
/*fn宣告*/
/*num*/
bool debug=0;
bool iofast=1;
bool couttree=0;
INT workmode=-1;//1==球最大, 0=球total, -1=球最小
const INT maxn=1001;//物件最大數量
INT item[maxn];
INT tree[maxn<<1];
INT nn;
/*fn定義*/
INT build_tree(INT node=0,INT l=0,INT r=nn-1){//將原始資料建立成線段數，原始數據也須保留，以便刪改
	if(l==r){
		tree[node]=item[l];
		return tree[node];
	}else{
		INT mnt=(l+r)/2;
		ifif(workmode==1) tree[node]=max(build_tree(node*2+1,l,mnt),build_tree(node*2+2,mnt+1,r));
		elif(workmode==0) tree[node]=build_tree(node*2+1,l,mnt)+build_tree(node*2+2,mnt+1,r);
		elif(workmode==-1)tree[node]=min(build_tree(node*2+1,l,mnt),build_tree(node*2+2,mnt+1,r));
		return tree[node];
	}
}
INT tree_numadd(INT ad,INT num,INT l=0,INT r=nn-1,INT node=0){//修改點資料(ad為原始資料的位置,num為修改後的數字)
	if(l<=ad && ad<=r){//若現在在區間內
		if(l==r){
			tree[node]=num;
			item[ad]=num;
			return num;
		}else{
			INT mnt=(l+r)/2;
			INT re=0;
			ifif(workmode==1) re=max(tree_numadd(ad,num,l,mnt,node*2+1),tree_numadd(ad,num,mnt+1,r,node*2+2));
			elif(workmode==0) re=(tree_numadd(ad,num,l,mnt,node*2+1)+tree_numadd(ad,num,mnt+1,r,node*2+2));
			elif(workmode==-1)re=min(tree_numadd(ad,num,l,mnt,node*2+1),tree_numadd(ad,num,mnt+1,r,node*2+2));
			tree[node]=re;
			return re;
		}
	}else{
		return tree[node];
	}
}
/*改到這*/
INT tree_find(INT fl,INT fr,INT node=0,INT l=0,INT r=nn-1){
	if(debug)cout<<"fl="<<fl<<",fr="<<fr<<",node="<<node<<",l="<<l<<",r="<<r<<endl;
	if(fl<=l && r<=fr)return tree[node];//若目前尋找的範圍(fl,fr)和框的範圍(l,r)相同
	if(fl==fr)return item[fl];//如果只要找該數值
	if(r<fl || fr<l)return 0;
	else{
		INT mnt=(l+r)/2;
		INT re=0;
		INT ll=0;
		INT rr=0;
		bool lt=fl<=mnt;
		bool rt=mnt<fr;
		if(lt){//mnt左邊
			re=ll=(tree_find(fl,fr,node*2+1,l,mnt));
		}
		if(rt){//mnt右邊
			re=rr=(tree_find(fl,fr,node*2+2,mnt+1,r));
		}
		if(lt && rt){
			ifif(workmode==1) re=max(ll,rr);
			elif(workmode==0) re=ll+rr;
			elif(workmode==-1)re=min(ll,rr);
		}
		return re;
	}
}
/*main*/
int main(){
	if(!debug && iofast){what_the_fuck;}

	/*cin 原始數據*/
	cin>>nn;
	INT q;
	cin>>q;
	for(int i=0;i<nn;i++){
		cin>>item[i];
	}
	/*write 線段數*/
	build_tree();
	/*cout*/
	if(couttree){
		for(int i=0;i<nn*2;i++){
			cout<<tree[i]<<" ";
		}
		cout<<endl;
	}

	for(INT i=0;i<q;i++){
		INT doid;
		cin>>doid;
		if(doid==1){
			/*cin 修改資料*/
			INT ad,num;
			cin>>ad>>num;
			ad--;
			/*solve 修改資料*/
			tree_numadd(ad,num);
			/*cout*/
			if(couttree){
				for(int i=0;i<nn*2;i++){
					cout<<tree[i]<<" ";
				}
				cout<<endl;
			}
		}else{
			/*cin 詢問區間和*/
			INT l,r;
			cin>>l>>r;
			l--;r--;
			/*solve+cout*/
			cout<<tree_find(l,r)<<endl;
		}
	}

	return 0;
}
/*
[I]
(資料數量 n)
(資料 tree[0]) (資料 tree[0]) ... (資料 tree[n-1])

(動作次數 q)
(動作編號 doid (假設是1) ) (修改位置 ad) (修改後數字 num)   修改
(動作編號 doid (假設是2) ) (左界 l) (右界 r)               問區間
[O]
(輸出樹(以bfs呈現))
[輸出q行，每行輸出項目如下]
[修改](輸出刪改後的樹)
[問區間](輸出區間和)*q2行
*/
/*
[I1]
8
1 2 3 4 5 6 7 8

5
2 2 3
2 4 5
2 4 6
1 8 1
2 6 8
[O1]
8 4 8 2 4 6 8 1 2 3 4 5 6 7 8
3
5
6
7 4 7 2 4 6 7 1 2 3 4 5 6 7 1
7
*/