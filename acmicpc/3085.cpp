#include <iostream>
using namespace std;
#define MAX 51

string map[MAX];
int n, ans;

void check()
{
	for (int i=0; i<n; ++i) {
		int cnt = 1;
		for (int j=0; j<n; ++j) {
			if (map[i][j] == map[i][j+1]) {
				cnt++;
			} else {
				ans = max(ans, cnt);
				cnt = 1;
			}
		}
	}
	for (int j=0; j<n; ++j) {
		int cnt = 1;
		for (int i=0; i<n; ++i) {
			if (map[i][j] == map[i+1][j]) {
				cnt++;
			} else {
				ans = max(ans, cnt);
				cnt = 1;
			}
		}
	}
}

int main()
{
	cin >> n;
	for (int i=0; i<n; ++i)
		cin >> map[i];

	for (int i=0; i<n; ++i) {
		for (int j=0; j<n-1; ++j) {
			swap(map[i][j], map[i][j+1]);
			check();
			swap(map[i][j], map[i][j+1]);
		}
	}

	for (int j=0; j<n; ++j) {
		for (int i=0; i<n-1; ++i) {
			swap(map[i][j], map[i+1][j]);
			check();
			swap(map[i][j], map[i+1][j]);
		}
	}

	cout << ans << '\n';

	return 0;
}
