/*
[DC(分治)]
[from]https://yuihuang.com/zj-f315/
[Q]https://zerojudge.tw/ShowProblem?problemid=f315
*/
#include <bits/stdc++.h>
using namespace std;
 
int n, a, b[100005];
long long ans;
pair <int, int> p[200005];
 
void Merge(int l, int r){
	if (l == r) return;
	int mid = (l+r)/2;
	//分治
	Merge(l, mid);
	Merge(mid+1, r);
	//solve
	vector <pair<int, int> > v;
	int p1 = l, p2 = mid+1;
	//將兩陣列進行合併
	while (p1 <= mid && p2 <= r){
		if (p[p1].first < p[p2].first){
			v.push_back(p[p1]);
			p1++;
		}
		else{
		  //計算ans
			/*
			原理
			左數設-1,右數設+1
			假設數字是n
			則先計算r左邊大於n的數量
			再計算l左邊大於n的數量
			兩者相減中間的答案
			這回合中
			左半邊的數位置一定在左邊
			然後每個數字都會被比較到
			*/
			ans += (p1-l)*p[p2].second;
			v.push_back(p[p2]);
			p2++;
		}
	}
	//上面跑完後，可能還有另一半陣列沒跑完，讓他跑完 
	while (p1 <= mid){
		v.push_back(p[p1]);
		p1++;
	}
	while (p2 <= r){
		ans += (p1-l)*p[p2].second;
		v.push_back(p[p2]);
		p2++;
	}
	//將存在vector的陣列複製到主陣列
	for (int i = 0; i < v.size(); i++){
		p[l+i] = v[i];
	}
}
 
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for (int i = 1; i <= n*2; i++){
		cin >> a;
		//確認該數值是否已存在在裡面，在裡面的話second=1
		//意即second=1，該數字在右邊
		if (b[a]) p[i] = {a, 1};
		else{
			b[a] = 1;
			p[i] = {a, -1};
		}
	}
	Merge(1, n*2);
	cout << ans << "\n";
}