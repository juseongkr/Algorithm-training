#include <iostream>
#include <limits.h>
using namespace std;

int n, m, cnt, min_val = INT_MAX;
string board[51];
string type_a[8] = {{ "WBWBWBWB" }, { "BWBWBWBW" }, { "WBWBWBWB" }, { "BWBWBWBW" },
{ "WBWBWBWB" }, { "BWBWBWBW" }, { "WBWBWBWB" }, { "BWBWBWBW" }};
string type_b[8] = {{ "BWBWBWBW" }, { "WBWBWBWB" }, { "BWBWBWBW" }, { "WBWBWBWB" },
{ "BWBWBWBW" }, { "WBWBWBWB" }, { "BWBWBWBW" },	{ "WBWBWBWB" }};

int solve_a(int x, int y)
{
	int ret = 0;
	for (int i=x; i<x+8; ++i)
		for (int j=y; j<y+8; ++j)
			if (type_a[i-x][j-y] != board[i][j])
				ret++;
	return ret;
}

int solve_b(int x, int y)
{
	int ret = 0;
	for (int i=x; i<x+8; ++i)
		for (int j=y; j<y+8; ++j)
			if (type_b[i-x][j-y] != board[i][j])
				ret++;
	return ret;
}

int main()
{
	cin >> n >> m;
	for (int i=0; i<n; ++i)
		cin >> board[i];

	for (int i=0; i<=n-8; ++i)
		for (int j=0; j<=m-8; ++j)
			min_val = min(min_val, min(solve_a(i, j), solve_b(i, j)));

	cout << min_val << '\n';

	return 0;
}
