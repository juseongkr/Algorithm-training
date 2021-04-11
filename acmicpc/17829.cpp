#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#define MAX 1025

int n, map[MAX][MAX];

int pick(int x, int y)
{
	vector<int> vec;
	for (int i=x; i<x+2; ++i)
		for (int j=y; j<y+2; ++j)
			vec.push_back(map[i][j]);

	sort(vec.begin(), vec.end());

	return vec[2];
}

int main()
{
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);

	cin >> n;
	for (int i=0; i<n; ++i)
		for (int j=0; j<n; ++j)
			cin >> map[i][j];

	while (n) {
		for (int i=0; i<n; i+=2)
			for (int j=0; j<n; j+=2)
				map[i/2][j/2] = pick(i, j);
		n /= 2;
	}

	cout << map[0][0] << '\n';

	return 0;
}
