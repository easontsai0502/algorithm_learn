/*
[zj]			[Q]https://zerojudge.tw/ShowProblem?problemid=d390
[背包問題-變形]
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
#define INT LLI
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
INT t,m,total,helf;
const INT maxm=100;
const INT maxc=500;
INT c[maxm+1];
const INT dpsize=maxm*maxc/2+1;
INT dp[dpsize];
/*fn定義*/
/*main*/
int main(){
	/*IO加速*/
	if(!debug&&iofast)what_the_fuck;
	cin>>t;
	while(t--){
		/*CIN*/
		cin>>m;
		total=0;
		for(INT i=0;i<m;i++){
			cin>>c[i];
			total+=c[i];
		}
		/*solve*/
		helf=total/2;
		for(INT i=0;i<dpsize;i++){
			dp[i]=0;
		}
		for(INT i=0;i<m;i++){//物品編號
			for(INT j=helf;j>=c[i];j--){//最高容許金額
				dp[j]=max(dp[j],dp[j-c[i]]+c[i]);
			}
		}
		INT mn=dp[helf];
		INT mx=total-mn;
		cout<<mx-mn<<endl;
	}
	return 0;
}

/*
[Q]
你要來幫助處理一個關於銅幣的問題。
給你一袋銅幣（裡面最多有 100 個，面值可能有 1 分錢到 500 分錢，但單一銅幣是不可分割的）。
若要把銅幣分成 2 堆，並且使得這 2 堆銅幣的面值和盡可能接近，你必須回答這 2 堆銅幣面值和的差是多少。
[I]
輸入的第一列有一個整數
代表以下有幾組測試資料
每組測試資料 2 列
其中第一列有 1 個不為負的整數 m（m <= 100）
代表袋中銅幣的數目
接下來的一列有 m 個正整數
代表袋中各銅幣的面值
[O]
對每一組測試資料
輸出 2 堆銅幣面值和的差是多少
*/

/*
[I1]
2
3
2 3 5
4
1 2 4 6
[O1]
0
1
*/

/*think*/
/*
給你下面一數列代表金額
1,2,3,4,5
那我們可以用背包問題來設定
每個物品的重量和價值都是他的金額
而我們要尋找在helf(含helf)內可以獲取的最大價值

*/
