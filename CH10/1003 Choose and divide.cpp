#include <iostream>
#include <algorithm>
#include <math.h>
#include <string.h>

using namespace std;

const int MAXN = 1e5 + 50;
int arr[MAXN][6], prime[MAXN];

void init_prime() {
	for (int i = 2; i < MAXN; ++i) {
		if (!prime[i]) {
			prime[++prime[0]] = i;
		}
		for (int j = 1; j <= prime[0]; ++j) {
			if (i * prime[j] > MAXN) break;
			prime[i * prime[j]] = 1;
			if (i % prime[j] == 0) break;
		}
	}
	return;
}

int main() {
	init_prime();
	int p, q, r, s;
	while (cin >> p >> q >> r >> s) {
		// 全局变量一定得在多输入内进行初始化
		memset(arr, 0, sizeof(arr));
		arr[0][0] = p, arr[0][1] = s, arr[0][2] = r - s;
		arr[0][3] = r, arr[0][4] = q, arr[0][5] = p - q;
		for (int len = 0; len < 6; ++len) {
			int n = arr[0][len];
			for (int i = 1; i <= prime[0] and prime[i] <= n; ++i) {
				int cnt = 0, num = n;
				while (num) {
					cnt += num / prime[i];
					num /= prime[i];
				}
				arr[prime[i]][len] = cnt;
			}
		}
		for (int j = 2; j < MAXN; ++j) {
			arr[j][0] = arr[j][0] + arr[j][1] + arr[j][2] - arr[j][3] - arr[j][4] - arr[j][5];
		}
		double ans = 1.0;
		for (int j = 2; j < MAXN; ++j) ans *= pow(j, arr[j][0]);
		printf("%.5lf\n", ans);
	}
	return 0;
}
