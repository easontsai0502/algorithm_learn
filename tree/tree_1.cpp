/*
[Q]
[BFS]
[]
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
/*fn宣告*/
/*num*/
bool debug=false;
bool iofast=true;














const INT person=100;//人數
bool tree[person+1][person+1];//圖
/*fn定義*/
INT tree_push(INT a,INT b){//將a和b點連起來
	tree[a][b]=true;
	tree[b][a]=true;
}
INT tree_pop(INT a,INT b){//將a和b的連線砍掉
	tree[a][b]=false;
	tree[b][a]=false;
}
bool tree_check(INT a,INT b){//回傳a和b是否有線連接
	return tree[a][b]||tree[b][a];
}

bool waswalk[person+1];
void dfs(INT a,INT back=-1){//對a進行深度搜尋
	cout<<a<<" ";
	waswalk[a]=true;
	for(INT i=0;i<=person;i++){
		if(i==back)continue;//確認這條路是否走過
		if(tree_check(a,i)){//確認兩點之間有連線
			dfs(i,a);
		}
	}
	waswalk[a]=false;
}

void bfs(INT a){
	deque<INT> dq;
	dq.push_back(a);
	for(INT i=0;i<=person;i++){//初始化
		waswalk[i]=false;
	}
	while(!dq.empty()){//進行bfs
		INT now=dq.front();//提取
		dq.pop_front();//提取
		if(!waswalk){//沒走過去才走
			cout<<now<<" ";//輸出
			waswalk[now]=true;///記錄這格有被走過
			for(INT i=0;i<=person;i++){//進行廣度搜尋
				if(tree_check(a,i)){//確認兩點之間有連線
					dq.push_back(i);
				}
			}
		}
	}
	for(INT i=0;i<=person;i++){//初始化
		waswalk[i]=false;
	}
}
















/*main*/
int main(){
	/*IO加速*/
	if(!debug&&iofast)what_the_fuck;
	/*CIN*/
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
