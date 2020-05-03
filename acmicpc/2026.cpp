#include <iostream>
#include <vector>
using namespace std;
#define MAX 901

bool ans;
int k, n, f, x, y;
bool map[MAX][MAX];
vector<int> vec;

void solve(int cur)
{
	if (vec.size() == k) {
		for (int i=0; i<vec.size(); ++i)
			cout << vec[i] << '\n';
		ans = true;
		return;
	}

	for (int i=cur+1; i<=n; ++i) {
		if (map[i][cur]) {
			bool flag = true;
			for (int j=0; j<vec.size(); ++j)
				if (!map[i][vec[j]])
					flag = false;
			if (!flag)
				continue;
			vec.push_back(i);
			solve(i);
			if (ans)
				return;
			vec.pop_back();
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);

	cin >> k >> n >> f;
	for (int i=0; i<f; ++i) {
		cin >> x >> y;
		map[x][y] = map[y][x] = 1;
	}

	for (int i=1; i<=n; ++i) {
		vec.push_back(i);
		solve(i);
		if (ans)
			break;
		vec.pop_back();
	}

	if (!ans)
		cout << "-1\n";

	return 0;
}
