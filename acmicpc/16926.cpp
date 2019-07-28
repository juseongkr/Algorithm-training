#include <iostream>
#include <vector>
using namespace std;
#define MAX 301

int main()
{
	vector<vector<int>> vec;
	int a[MAX][MAX];
	int n, m, r;

	cin >> n >> m >> r;
	for (int i=0; i<n; ++i)
		for (int j=0; j<m; ++j)
			cin >> a[i][j];

	for (int k=0; k<min(n, m)/2; ++k) {
		vector<int> t;
		for (int j=k; j<m-k; ++j)
			t.push_back(a[k][j]);

		for (int i=k+1; i<n-1-k; ++i)
			t.push_back(a[i][m-1-k]);

		for (int j=m-1-k; j>k; j--)
			t.push_back(a[n-1-k][j]);

		for (int i=n-1-k; i>k; i--)
			t.push_back(a[i][k]);
		vec.push_back(t);
	}

	for (int k=0; k<min(n, m)/2; ++k) {
		int len = vec[k].size();
		int idx = r % len;
		for (int j=k; j<m-k; ++j) {
			a[k][j] = vec[k][idx];
			idx = ++idx % len;
		}

		for (int i=k+1; i<n-1-k; ++i) {
			a[i][m-1-k] = vec[k][idx];
			idx = ++idx % len;
		}

		for (int j=m-1-k; j>k; j--) {
			a[n-1-k][j] = vec[k][idx];
			idx = ++idx % len;
		}

		for (int i=n-1-k; i>k; i--) {
			a[i][k] = vec[k][idx];
			idx = ++idx % len;
		}
	}

	for (int i=0; i<n; ++i) {
		for (int j=0; j<m; ++j)
			cout << a[i][j] << " ";
		cout << '\n';
	}

	return 0;
}
