/*
[cses]	[Q]https://cses.fi/problemset/task/1131
[AC]
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
#define INT int
#define UINT unsigned INT
#define PII pair<INT,INT>
#define PUIUI pair<UINT,UINT>
#define endl "\n"
#define wassomething() empty()==false

/*struct*/
struct super_pair{
	INT x1=0;
	INT x2=0;
	INT x3=0;
	INT x4=0;
	INT x5=0;
};
/*fn宣告*/
/*num*/
bool debug=false;
bool iofast=true;
vector<INT> tree[INT(2e5)];
INT mx=0;
INT p=0;
/*fn定義*/
INT dfs(INT now,INT from,INT ans=0){
	if(mx<ans){
		mx=ans;
		p=now;
	}
	for(INT i:tree[now]){
		if(i==from)continue;
		dfs(i,now,ans+1);
	}
	return p;
}
/*main*/
int main(){
	/*IO加速*/
	if(!debug&&iofast)what_the_fuck;
	/*CIN*/
	INT n;
	cin>>n;
	for(INT i=0;i<n-1;i++){
		INT a,b;
		cin>>a>>b;
		a--;
		b--;
		tree[a].push_back(b);
		tree[b].push_back(a);
	}
	/*solve*/
	dfs(dfs(0,-1),-1);
	cout<<mx<<endl;
	return 0;
}

/*
[I1]
[O1]
*/

/*think*/
/*

*/
