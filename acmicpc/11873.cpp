#include <iostream>
#include <stack>
using namespace std;
#define MAX 1001

int n, m;
int mat[MAX][MAX];
int arr[MAX];

int histogram()
{
	stack<int> st;
	int ret = 0;
	for (int i=0; i<=m; ++i) {
		while (!st.empty()) {
			int t = st.top();
			if (arr[t] < arr[i])
				break;
			st.pop();

			int w = i;
			if (!st.empty())
				w = i - st.top() - 1;

			ret = max(ret, arr[t] * w);
		}
		st.push(i);
	}
	return ret;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	while (1) {
		cin >> n >> m;
		if (n == 0 && m == 0)
			break;
		for (int i=0; i<n; ++i)
			for (int j=0; j<m; ++j)
				cin >> mat[i][j];

		int ans = 0;
		fill(arr, arr+MAX, 0);
		for (int i=0; i<n; ++i) {
			for (int j=0; j<m; ++j) {
				if (mat[i][j])
					arr[j]++;
				else
					arr[j] = 0;
			}
			int ret = histogram();
			ans = max(ans, ret);
		}
		cout << ans << '\n';
	}

	return 0;
}
