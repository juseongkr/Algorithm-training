#include <iostream>
#include <string.h>
using namespace std;

int map[51][51];
int n, cnt, ret = 0;

void solve()
{
	for (int k=0; k<n; ++k) {
		for (int i=0; i<n; ++i) {
			for (int j=0; j<n; ++j) {
				if (i == j || i == k || k == j)
					continue;

				if (map[i][j] > map[i][k] + map[k][j])
					map[i][j] = map[i][k] + map[k][j];
			}
		}
	}
}

int main()
{
	string str;

	memset(map, 999999, sizeof(map));
	scanf("%d", &n);
	for (int i=0; i<n; ++i) {
		cin >> str;
		for (int j=0; j<str.length(); ++j) {
			if (str[j] == 'Y')
				map[i][j] = 1;
		}
	}

	solve();

	for (int i=0; i<n; ++i) {
		cnt = 0;
		for (int j=0; j<n; ++j) {
			if (i == j)
				continue;
			if (map[i][j] <= 2)
				cnt++;
		}
		ret = max(ret, cnt);
	}
	printf("%d\n", ret);

	return 0;
}
