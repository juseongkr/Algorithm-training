#include <iostream>
#include <vector>
using namespace std;
#define MAX 101

int n, l, ans;
int map[MAX][MAX];
bool c[MAX];
vector<int> v;

bool check()
{
	fill(c, c+MAX, false);
	for (int i=1; i<n; ++i) {
		if (v[i-1] != v[i]) {
			if (abs(v[i-1] - v[i]) != 1)
				return false;

			if (v[i-1] < v[i]) {
				for (int j=1; j<=l; ++j) {
					if (i-j < 0 || v[i-1] != v[i-j] || c[i-j])
						return false;
					c[i-j] = true;
				}

			} else {
				for (int j=0; j<l; ++j) {
					if (i+j >= n || v[i] != v[i+j] || c[i+j])
						return false;
					c[i+j] = true;
				}
			}
		}
	}
	return true;
}

int main()
{
	cin >> n >> l;
	for (int i=0; i<n; ++i)
		for (int j=0; j<n; ++j)
			cin >> map[i][j];

	for (int i=0; i<n; ++i) {
		for (int j=0; j<n; ++j)
			v.push_back(map[i][j]);

		if (check())
			ans++;
		v.clear();
	}

	for (int j=0; j<n; ++j) {
		for (int i=0; i<n; ++i)
			v.push_back(map[i][j]);

		if (check())
			ans++;
		v.clear();
	}
	cout << ans << '\n';

	return 0;
}
