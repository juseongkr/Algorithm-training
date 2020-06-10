#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#define MAX 100000

string s;
int n, m, x, y;
vector<int> X[MAX*2], Y[MAX*2];

int main()
{
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);

	cin >> n >> m;
	for (int i=0; i<n; ++i) {
		cin >> x >> y;
		x += MAX;
		y += MAX;
		X[x].push_back(y);
		Y[y].push_back(x);
	}
	cin >> s;

	for (int i=0; i<MAX*2; ++i) {
		if (X[i].size() > 0)
			sort(X[i].begin(), X[i].end());
		if (Y[i].size() > 0)
			sort(Y[i].begin(), Y[i].end());
	}

	x = y = MAX;
	for (int i=0; i<s.length(); ++i) {
		if (s[i] == 'L') {
			bool flag = false;
			for (int j=Y[y].size()-1; j>=0; j--) {
				int nx = Y[y][j];
				if (x > nx) {
					x = nx;
					flag = true;
					break;
				}
			}
			if (!flag)
				x = 0;
		} else if (s[i] == 'R') {
			bool flag = false;
			for (int j=0; j<Y[y].size(); ++j) {
				int nx = Y[y][j];
				if (x < nx) {
					x = nx;
					flag = true;
					break;
				}
			}
			if (!flag)
				x = MAX*2+1;
		} else if (s[i] == 'U') {
			bool flag = false;
			for (int j=0; j<X[x].size(); ++j) {
				int ny = X[x][j];
				if (y < ny) {
					y = ny;
					flag = true;
					break;
				}
			}
			if (!flag)
				y = MAX*2+1;
		} else {
			bool flag = false;
			for (int j=X[x].size()-1; j>=0; j--) {
				int ny = X[x][j];
				if (y > ny) {
					y = ny;
					flag = true;
					break;
				}
			}
			if (!flag)
				y = 0;
		}
	}
	cout << x - MAX << " " << y - MAX << '\n';

	return 0;
}
