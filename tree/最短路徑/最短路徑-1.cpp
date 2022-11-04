/*
[zj]		[Q]https://zerojudge.tw/ShowProblem?problemid=c128
[AC]
[最短路徑]
這一題是在找
找出一條路
再找出這條路經過的數的最小值
盡可能讓這個值最大
該值即為所求
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
string s1,s2;
INT n,r;
INT id=1;
map<string,INT>stint;
const INT maxn=200;
INT mp[maxn+1][maxn+1];
INT season=0;
INT num1,num2;
INT h;
/*fn定義*/
INT find(string str){
	if(stint[str]==0){
		stint[str]=id;
		id++;
		return stint[str];
	}else return stint[str];
}
/*main*/
int main(){
	/*IO加速*/
	if(!debug&&iofast)what_the_fuck;
	while(cin>>n>>r){
		if(n==0&&r==0)break;
		/*re:0*/
		season++;
		stint.clear();
		s1.clear();
		s2.clear();
		id=1;
		num1=0;
		num2=0;
		h=0;
		for(INT i=0;i<=n;i++){
			for(INT j=0;j<=n;j++){
				mp[i][j]=-1;
			}
		}
		/*CIN*/
		for(INT i=0;i<r;i++){
			cin>>s1>>s2>>h;
			num1=find(s1);
			num2=find(s2);
			mp[num1][num2]=h;
			mp[num2][num1]=h;
		}
		cin>>s1>>s2;
		num1=find(s1);
		num2=find(s2);
		/*solve*/
		for(INT i=1;i<=n;i++){//中繼站
			for(INT j=1;j<=n;j++){//起點(或終點)
				for(INT k=j+1;k<=n;k++){//終點(或起點)
					INT tosen=min(mp[j][i],mp[i][k]);//j=>i=>k
					mp[j][k]=max(mp[j][k],tosen);//j=>k或者上面的，看哪個載重量比較大
					mp[k][j]=mp[j][k];
				}
			}
		}
		cout<<"Scenario #"<<season<<endl;
		cout<<mp[num1][num2]<<" tons"<<endl<<endl;
	}
	return 0;
}

/*
[I1]
(城市數量 0結束) (邊數m 0結束)
m行
(城市名str) (城市名str) (最大承受重量) 連結兩點，兩點之間最多只能在重多少公斤
...
(城市名str) (城市名str)
下一組側資
[O1]
兩城市之間最大可承受多少重量
*/

/*think*/
/*
try to use this way
https://yuihuang.com/zj-c128/
*/
