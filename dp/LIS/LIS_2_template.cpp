/*
[tioj]			[Q]https://tioj.ck.tp.edu.tw/problems/ [ID]
[zj]				[Q]https://zerojudge.tw/ShowProblem?problemid= [ID]
[cses]			[Q]https://cses.fi/problemset/task/ [ID]
[AtCoder]		[Q]https://atcoder.jp/contests/ [ID] /tasks/ [ID] _ [PID]
[maybe TLE]
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
/*num*/
bool debug=0;
bool iofast=true;

PII mv[]={{0,1},{1,0},{0,-1},{-1,0}};
INT mx[]={0,1,0,-1};
INT my[]={1,0,-1,0};
INT mod=988244353;
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
INT INT_IN(){
	INT a;
	cin>>a;
	return a;
}

template<typename TPE>TPE reader(){
	TPE a;
	cin>>a;
	return a;
}

template<typename TPE>bool vser(TPE a,TPE b){
	return a<b;
}

template<typename TPE,typename Fn>auto LIS(TPE a,Fn fn){
	INT N=(int)a.size();
	INT dp[N+1];dp[0]=1;
	TPE vec;vec.push_back(a[0]);
	INT L=1;
	for(INT i=1;i<N;i++){
		if(fn(vec.back(),a[i])){
			vec.push_back(a[i]);
			L++;
			dp[i]=L;
		}
		else{
			auto it=lower_bound(vec.begin(),vec.end(),a[i]);
			while(!( fn (*(it-1),a[i]) )){
				//接下來要把it調換掉，所以檢查vec 0~(it-1)的陣列加入a[i]是否合法
				it--;
			}
			*it=a[i];
			dp[i]=(int)(it-vec.begin()+1);
		}
	}
	TPE re;
	INT mx=L;
	for(INT i=N-1;i>=0;i--){
		if(dp[i]==L){
			re.push_back(a[i]);
			L--;
		}
	}
	reverse(re.begin(),re.end());
	pair<INT,TPE> rere={mx,re};
	return rere;
}

/*main*/
int main(){
	if(!debug&&iofast){what_the_fuck;}
	/*CIN*/
	vector<INT> vec;
	INT n;
	while(n=reader<INT>())vec.push_back(n);
	/*solve*/
	auto ans=LIS(vec,vser<INT>);
	cout<<ans.FIR<<endl;
	cout<<"-"<<endl;
	for(INT i:ans.SEC){
		cout<<i<<endl;
	}
	return 0;
}

/*
[I1]
[O1]
*/

/*think*/
/*

*/
