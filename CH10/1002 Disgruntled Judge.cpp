#include <iostream>

using namespace std;

const int MAXN = 100 * 2 + 50;
const int MOD = 10001;
int t, arr[MAXN];

int main() {
	while (cin >> t) {
		for (int i = 1; i <= t * 2 - 1; i += 2) cin >> arr[i];
		
		for (int a = 0; a < MOD; ++a) {
			for (int b = 0; b < MOD; ++b) {
				bool flag = true;
				for (int i = 2; i <= t * 2; i += 2) {
					arr[i] = (a * arr[i - 1] + b) % MOD;
					if (i + 1 <= t * 2 and arr[i + 1] != ((a * arr[i] + b) % MOD)) { 
						flag = false; 
						break; 
					}
				}
				if (flag) {
					for (int i = 2; i <= t * 2; i += 2)
						cout << arr[i] << endl;
					return 0;
				}
			}
		}
	}
	return 0;
}

