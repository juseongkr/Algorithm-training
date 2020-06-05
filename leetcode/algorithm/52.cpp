class Solution {
public:
	int ans;
	vector<bool> check[3];

	void solve(int x, int n) {
		if (x == n) {
			ans++;
			return;
		}

		for (int i=0; i<n; ++i) {
			if (check[0][i] || check[1][x+i] || check[2][x+n-i])
				continue;

			check[0][i] = check[1][x+i] = check[2][x+n-i] = 1;
			solve(x+1, n);
			check[0][i] = check[1][x+i] = check[2][x+n-i] = 0;
		}
	}

	int totalNQueens(int n) {
		ans = 0;
		for (int i=0; i<3; ++i)
			check[i].resize(2*n, 0);

		solve(0, n);

		return ans;
	}
};
