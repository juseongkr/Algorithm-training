#include <iostream>
#include <vector>
using namespace std;
#define MAX 20

int T, n;
int map[MAX][MAX];

int main()
{
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);

	cin >> T;
	while (T--) {
		cin >> n;
		for (int i=0; i<n; ++i)
			for (int j=0; j<n; ++j)
				cin >> map[i][j];

		vector<bool> visit((1 << n), 0);
		visit[(1 << n)-1] = 1;
		for (int k=(1 << n)-1; k>0; k--) {
			if (!visit[k])
				continue;
			for (int i=0; i<n; ++i) {
				if (k & (1 << i)) {
					int sum = 0;
					for (int j=0; j<n; ++j)
						if (k & (1 << j))
							sum += map[i][j];
					if (sum > 0)
						visit[k & ~(1 << i)] = 1;
				}
			}
		}

		vector<int> vec;
		for (int i=0; i<n; ++i)
			if (visit[(1 << i)])
				vec.push_back(i+1);

		if (vec.size()) {
			for (int i=0; i<vec.size(); ++i)
				cout << vec[i] << " ";
			cout << '\n';
		} else {
			cout << "0\n";
		}
	}

	return 0;
}
