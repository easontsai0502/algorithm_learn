/*
[From]https://yuihuang.com/dp-lis/
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
		if (a[i] > v.back()){
			v.push_back(a[i]);
			L++;
			dp[i] = L;
		} else {
			auto it = lower_bound(v.begin(), v.end(), a[i]);
			*it = a[i];
			dp[i] = (int) (it - v.begin() + 1);
		}
	}
	cout << L << "\n-\n";
	vector<int> ans;
	for (int i=N-1; i>=0; i--){
		if (dp[i] == L){
			ans.push_back(a[i]);
			L--;
		}
	}
	reverse(ans.begin(), ans.end());
	for (auto i: ans){
		cout << i << '\n';
	}
	return 0;
}