/*
[Q]https://atcoder.jp/contests/dp/tasks/dp_f
[LCS]
[最長共用子序列]
[AC]
*/

/*include*/
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
#include<stack>
#include<cstring>
#include<unordered_map>

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
string s,t;
INT dp[3001][3001];
bool debug=false;
/*fn定義*/
template<typename TPE>auto LCS(TPE a,TPE b){
	INT dp[a.size()+1][b.size()+1];
	memset(dp,0,sizeof(dp));
	INT as=a.size();
	INT bs=b.size();
	for(INT i=1;i<=as;i++){
		for(INT j=1;j<=bs;j++){
			if(a[i-1]==b[j-1]){
				dp[i][j]=dp[i-1][j-1]+1;
			}else{
				dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
			}
		}
	}
	//get 子序列
	TPE re;
	re.clear();
	INT i=as,j=bs;
	while(i && j){
		if(a[i-1]==b[j-1]){
			re.push_back(a[i-1]);
			i--;
			j--;
		}else{
			if(dp[i-1][j]>=dp[i][j-1]){
				i--;
			}else j--;
		}
	}
	reverse(re.begin(),re.end());
	return re;
}
/*main*/
int main(){
	/*IO加速*/
	if(!debug){cin.tie(0);cout.tie(0);ios::sync_with_stdio(false);}
	/*CIN*/
	cin>>s>>t;
	/*solve*/
	cout<<LCS(s,t)<<endl;
	return 0;
}

/*
[I1]
[O1]
*/

/*think*/
/*

*/
