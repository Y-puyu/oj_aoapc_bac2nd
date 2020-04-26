#include <iostream>
#include <algorithm>
#include <math.h>

using namespace std;

// 质因子分解
int divide_all(int& n, int d) {
	int x = 1;
	while (n % d == 0) { 
		n /= d; 
		x *= d; 
	}
	return x;
}

long long solve(int n) {
	if (n == 1) return 2;
	// floor向下取整，+0.5即四舍五入扩大精度
	int m = floor(sqrt(n) + 0.5);
	long long ans = 0, cnt = 0;		// cnt素数个数，ans答案最小和
	for (int i = 2; i < m; ++i) {
		if (n % i == 0) {			// 新的素因子
			++cnt;
			ans += divide_all(n, i);
		}
	}
	if (n > 1) ++cnt, ans += n;
	if (cnt <= 1) ++ans;
	return ans;
}


int main() {
	int n, tmp = 0;
	while (cin >> n and n) 
		cout << "Case " << ++tmp << ": " << solve(n) << "\n";
	return 0;
}
