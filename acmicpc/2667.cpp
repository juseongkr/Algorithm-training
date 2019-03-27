#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n, cnt;
int map[26][26];
int a[4] = {1, 0, -1, 0};
int b[4] = {0, -1, 0, 1};

void dfs(int x, int y)
{
	map[x][y] = 0;
	for (int i=0; i<4; ++i) {
		int next_x = x + a[i];
		int next_y = y + b[i];

		if (next_x < 0 || next_y < 0 || next_x > n || next_y > n)
			continue;

		if (map[next_x][next_y] == 1) {
			cnt++;
			dfs(next_x, next_y);
		}
	}
}

int main()
{
	vector<int> vec;
	string str;

	scanf("%d", &n);
	for (int i=0; i<n; ++i) {
		cin >> str;
		for (int j=0; j<n; ++j)
			map[i][j] = str[j] - '0';
	}

	for (int i=0; i<n; ++i) {
		for (int j=0; j<n; ++j) {
			if (map[i][j] != 0) {
				cnt = 1;
				dfs(i, j);
				vec.push_back(cnt);
			}
		}
	}
	
	sort(vec.begin(), vec.end());

	printf("%lu\n", vec.size());
	for (int i : vec)
		printf("%d\n", i);

	return 0;
}
