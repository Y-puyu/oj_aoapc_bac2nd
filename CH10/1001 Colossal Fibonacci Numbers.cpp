#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int MAXN = 1e3 + 50;
#define ULL unsigned long long

int f[MAXN][MAXN * 7], F[MAXN];

int pow_mod(ULL a, ULL b, int n) {
	if (b == 0) return 1;
	int x = pow_mod(a, b / 2, n);
	int res = (ULL)x * x % n;
	if (b % 2 == 1) res = res * a % n;
	return res;
}

int solve(ULL a, ULL b, int n) {
	if (a == 0 or n == 1) return 0;
	int x = pow_mod(a % F[n], b, F[n]);
	return f[n][x];
}

int main() {
	// memset(f, 0, sizeof(f));
	// memset(F, 0, sizeof(F));
	for (int n = 2; n <= 1000; ++n) {
		f[n][0] = 0, f[n][1] = 1;
		for (int i = 2; ; ++i) {
			f[n][i] = (f[n][i - 1] + f[n][i - 2]) % n;
			if (f[n][i - 1] == 0 and f[n][i] == 1) {
				F[n] = i - 1;
				break;
			}
		}
	}

	int t;
	scanf("%d", &t);
	ULL a, b;
	int n, res;

	while (t--) {
	    cin >> a >> b >> n;
	    cout << solve(a, b, n) << "\n";
	}
	/*
	// 一开始采用c语言形式输出未包含using namespace std;本地能过但是过不去oj，不知什么情况...
	// 靠，找到原因了，这个I64u在OJ上不支持，貌似只能支持llu，无语了...
	while (t--) {
		scanf("%llu%I64u%d", &a, &b, &n);
		res = solve(a, b, n);
		printf("%d\n", res);
	}
	*/
	return 0;
}
