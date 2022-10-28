/*
[Q]https://zerojudge.tw/ShowProblem?problemid=a982
[bfs]
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
#define ULLI unsigned long long int
#define LLI long long int
#define INT int
#define UINT unsigned INT
#define PII pair<INT,INT>
#define PUIUI pair<UINT,UINT>
#define endl "\n"

/*struct*/
/*fn宣告*/
/*num*/
bool debug=false;
bool iofast=true;
INT n;
bool mp[100+1][100+1];
INT mx[]={0,1,0,-1};
INT my[]={1,0,-1,0};
INT ans[100+1][100+1];
/*fn定義*/
/*main*/
int main(){
	/*IO加速*/
	if(!debug&&iofast)cin.tie(0);cout.tie(0);ios::sync_with_stdio(false);
	/*CIN*/
	cin>>n;
	for(INT i=0;i<n;i++){
		string str;
		cin>>str;
		for(INT j=0;j<n;j++){
			if(str[j]=='.')mp[i+1][j+1]=true;
		}
	}
	/*solve*/
	deque<PII>dq;
	dq.push_back({2,2});
	ans[2][2]=1;
	PII eeend={n-1,n-1};
	while(!dq.empty()){
		PII nw=dq.front();
		if(nw==eeend)break;
		dq.pop_front();
		INT &x=nw.first;
		INT &y=nw.second;
		for(INT i=0;i<4;i++){
			INT nx=x+mx[i];
			INT ny=y+my[i];
			if(nx<=0||ny<=0||nx>n||ny>n)continue;
			if(ans[nx][ny])continue;
			if(mp[nx][ny]){
				ans[nx][ny]=ans[x][y]+1;
				dq.push_back({nx,ny});
			}
		}
	}
	if(debug){
		for(INT i=1;i<=n;i++){
			for(INT j=1;j<=n;j++){
				cout<<ans[i][j]<<",";
			}
			cout<<endl;
		}
	}
	if(ans[n-1][n-1])cout<<ans[n-1][n-1]<<endl;
	else cout<<"No solution!"<<endl;
	return 0;
}

/*
[I1]
[O1]
*/

/*think*/
/*

*/
