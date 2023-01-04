/*
[tioj]			[Q]https://tioj.ck.tp.edu.tw/problems/ [ID]
[zj]				[Q]https://zerojudge.tw/ShowProblem?problemid= [ID]
[cses]			[Q]https://cses.fi/problemset/task/ [ID]
[AtCoder]		[Q]https://atcoder.jp/contests/ [ID] /tasks/ [ID] _ [PID]
[]
*/

/*include*/
#pragma GCC optimize("Ofast")
#pragma GCC optimize("O2")
#pragma GCC optimize("O1")
#pragma GCC optimize("O3")
#include<iostream>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<string>
#include<sstream>
#include<vector>
#include<queue>
#include<deque>
#include<map>
#include<set>
#include<cstring>
#include<iomanip>

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
#define endl "\n"
#define DBG if(debug)
#define FIR first
#define SEC second
#define elif else if
#define wassomething() empty()==false
#define REre return re
#define P(n,m) pair<n,m>
/*struct宣告*/
struct mat;
/*fn宣告*/
template<typename TPE>TPE tt(INT a,INT b){
	return a+b;
}
/*num*/
bool debug=0;
bool iofast=true;

PII mv[]={{0,1},{1,0},{0,-1},{-1,0}};
INT mx[]={0,1,0,-1};
INT my[]={1,0,-1,0};
INT mod=988244353;
/*struct定義*/
template<typename TPE>struct seg_tree{
	INT sz=0;
	vector<TPE> vec;
	vector<TPE> tree;
	INT push_back(TPE n){
		vec.push_back(n);
		sz++;
		return sz;
	}
	INT size(){
		return sz;
	}
	template<typename FnTPE>TPE build(FnTPE fn){
		tree.resize(sz<<1+1);
		return builder(fn=fn);
	}
	template<typename FnTPE>TPE builder(INT l=0,INT r=sz-1,INT nw=0,FnTPE fn){
		if(l==r){
			tree[nw]=vec[l];
		}
		else{
			INT mnt=(l+r)/2;
			TPE tl=builder(l,mnt,nw*2+1,fn);
			TPE tr=builder(mnt+1,r,nw*2+2,fn);
			tree[nw]=fn(tl,tr);
		}
		return tree[nw];
	}
};
/*fn定義*/

template<typename TPE>TPE reader(){
	TPE a;
	cin>>a;
	return a;
}

/*main*/
int main(){
	if(!debug&&iofast){what_the_fuck;}
	/*CIN*/
	INT n=reader<INT>();
	cout<<n;
	/*solve*/
	return 0;
}

/*
[I1]
[O1]
*/

/*think*/
/*

*/
