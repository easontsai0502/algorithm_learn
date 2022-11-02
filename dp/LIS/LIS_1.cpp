/*
[From]https://yuihuang.com/dp-lis/
[LIS]
[最長遞增子序列]
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
 
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	//cin
	int num;
	vector<int> a;
	while (cin >> num){
		a.push_back(num);
	}
	//solve
	int N = (int) a.size();//計算DP大小
	int dp[N+1];//建立dp
	vector<int> v;//已走訪過的數字
	dp[0] = 1;//dp初始化
	v.push_back(a[0]);//v初始化

	int L = 1; //LIS length
	//L為長度
	for (int i=1; i<N; i++){
		if (a[i] > v.back()){//如果現在這個大於v最頂端的
			v.push_back(a[i]);//先將自己推進v
			L++;//長度增加
			dp[i] = L;
		} else {
			auto it = lower_bound(v.begin(), v.end(), a[i]);//尋找v裡面最第一個大於等於她的數
			*it = a[i];//將此數換成更小的數(自己)
			dp[i] = (int) (it - v.begin() + 1);//計算長度，因為此vector是遞增子序列，直接量他的size就可以了
			//假如他是3
			//陣列是1,2,5,10
			//尋找到5
			//將4替換成3
			//為甚麼要將5換成3
			/*
			這代表說後面的數 例如6
			不刪除5的話會得到這個結果
			1,2,5,3,6
			有看到嗎
			因為3比5晚進去
			但為了讓整個數列是遞增狀態
			所以必須將5拿掉
			換成3

			那如果不換ㄋ
			因為現在
			1,2,3
			你只需要拿4
			就可以拿到大小為4的遞增子序列了
			1,2,3,4
			. .   . .
			不需要大於5
			所以把5踢掉換成3
			窩希望大家看ㄉ懂
			*/
		}
	}
	cout << L << "\n-\n";
	//尋找順序
	vector<int> ans;
	for (int i=N-1; i>=0; i--){//由後往前
		if (dp[i] == L){
			ans.push_back(a[i]);//找到的話就把元素塞進ans
			L--;
		}
	}
	reverse(ans.begin(), ans.end());//ans反向
	//輸出順序
	for (auto i: ans){
		cout << i << '\n';
	}
	return 0;
}