/*
[Q]https://zerojudge.tw/ShowProblem?problemid=d908
[AC]
[額這一題是在找最長路徑]
[要改最短就把line40改min即可]
[這個方法沒有很好，僅供參考]
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

/*using namespace*/
using namespace std;

/*define type*/
#define ULLI unsigned long long int
#define LLI long long int
#define INT int
#define UINT unsigned INT
#define PII pair<INT,INT>
#define PUIUI pair<UINT,UINT>

/*struct*/

/*fn宣告*/

/*num*/
vector<PII> tre[27];
INT ans=0;
/*fn定義*/
INT dfs(INT p,INT g){
	ans=max(ans,g);
	for(auto i:(tre[p])){
		dfs(i.first,g+i.second);
	}
	return 0;
}
/*main*/
int main(){
	{/*IO加速*/
		cin.tie(0);
		cout.tie(0);
		ios::sync_with_stdio(false);
	}
	/*CIN*/
	char c;
	cin>>c;
	INT st=c-'A';
	INT n;
	cin>>n;
	for(INT i=0;i<n;i++){
		char a,b;
		INT g;
		cin>>a>>b>>g;
		INT ia=a-'A',ib=b-'A';
		tre[ia].push_back({ib,g});
	}
	/*solve*/
	dfs(st,0);
	cout<<ans<<"\n";
	return 0;
}

/*
[I1]
B
6
A B 7
A C 1
B D 3
B E 5
C F 2
D F 4
[O1]
7
[I2]
A
7
A B 4
A C 2
A D 3
B E 7
B G 1
B H 6
C E 5
[O2]
11
*/

/*think*/
/*

*/