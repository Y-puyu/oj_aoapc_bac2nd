#include<iostream>
#include<cstdio>
#include<cstring>

using namespace std;
// 3e7 误写为3e8时本地竟然无法通过，不能正常打印,2e8可以，3e8报链接错误
const int MAXN = 30000000;
int cnt[MAXN + 50], sum[MAXN + 50];

void solve() {
	memset(cnt, 0, sizeof(cnt));
	for (int c = 1; c <= MAXN; ++c) {
		for (int a = c * 2; a <= MAXN; a += c) {
			int b = a - c;
			if (c == (a ^ b)) ++cnt[a];
		}
	}
	sum[0] = 0;
	for (int i = 1; i <= MAXN; ++i) sum[i] = sum[i - 1] + cnt[i];
}

int main() {
	solve();
	int T, n, tmp = 0;
	cin >> T;
	while (T--) {
		scanf("%d", &n);
		printf("Case %d: %d\n", ++tmp, sum[n]);
	}
	return 0;
}
