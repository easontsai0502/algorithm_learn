/*
[Q]https://cses.fi/problemset/task/1722/
[AC]
[矩陣快速冪]
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
/*struct宣告*/
struct mat;
/*fn宣告*/
/*num*/
bool debug=1;
bool iofast=true;
INT n,m,q;
const INT mxnm=1e6;
map<PII,INT>mp;

deque<pair<PII,INT>>dol;
map<PII,bool>waswalk;
//INT mp[mxnm+5][mxnm+5];
PII mv[]={{0,1},{1,0},{0,-1},{-1,0}};
INT mx[]={0,1,0,-1};
INT my[]={1,0,-1,0};
INT mod=1e9+7;
/*struct定義*/
struct mat{
	INT a[2][2];
	mat(){
		memset(a,0,sizeof(a));
	}
	mat operator*(const mat &b)const{
		mat re;
		for(INT i=0;i<2;i++){
			for(INT j=0;j<2;j++){
				for(INT k=0;k<2;k++){
					re.a[i][j]=(re.a[i][j]+a[i][k]*b.a[k][j])%mod;
				}
			}
		}
		return re;
	}
};
/*fn定義*/
PII padd(PII a,PII b){
	return {a.FIR+b.FIR,a.SEC+b.SEC};
}
map<INT,mat> ansl;
void solve(INT n){
	if(n==0){
		return;
	}
	if(n==1){
		ansl[1].a[0][1]=1;
		ansl[1].a[1][0]=1;
		ansl[1].a[1][1]=1;
	}
	else{
		solve(n/2);
		ansl[n]=ansl[n/2]*ansl[n/2];
		if(n%2){
			ansl[n]=ansl[1]*ansl[n];
		}
	}
}
/*main*/
int main(){
	if(!debug&&iofast){what_the_fuck;}
	/*CIN*/
	INT n;
	cin>>n;
	/*solve*/
	mat fir;
	fir.a[0][0]=0;
	fir.a[0][1]=1;
	solve(n);
	cout<<ansl[n].a[0][1]<<endl;
	return 0;
}

/*
[I1]
[O1]
*/

/*think*/
/*

*/
