#include <iostream>
using namespace std;

//1. 도착 전 계단 밟은 경우 (도착 전전 계단 못 밟음, 도착 전전전 계단 필수) : n + n-1 + n-3
//2. 도착 전전 계단 밟은 경우 : n + n-2

int stair[301], dp[301];

int Max(int a, int b) {
	if (a > b) {
		return a;
	}
	else {
		return b;
	}
}

void getScore(int s){

	dp[0] = stair[0]; //dp[0] 1칸
	dp[1] = Max(stair[0] + stair[1], stair[1]); //dp[1] 1 + 2칸 혹은 그냥 2칸인데? 1 + 2칸이 당연히 큼 : Max 안 쓰면 값 다른데 왜?
	dp[2] = Max(stair[0] + stair[2], stair[1] + stair[2]); //dp[2] 1 + 3칸 혹은 2 + 3칸

	for (int i = 3; i < s; i++) {
		dp[i] = Max(dp[i - 2] + stair[i], stair[i - 1] + stair[i] + dp[i - 3]);
	}

	cout << dp[s - 1];
}

int main(){
	int s;
	cin >> s;

	for (int i = 0; i < s; i++) {
		cin >> stair[i];
	}

	getScore(s);

	return 0;
}