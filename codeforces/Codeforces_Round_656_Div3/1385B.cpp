#include <iostream>
#include <vector>
using namespace std;
#define MAX 101

int T, n, x;
int num[MAX];

int main()
{
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);

	cin >> T;
	while (T--) {
		cin >> n;
		vector<int> ans;
		fill(num, num+MAX, 0);
		for (int i=0; i<n*2; ++i) {
			cin >> x;
			if (num[x]++ == 0) {
				ans.push_back(x);
			}
		}

		for (int i=0; i<ans.size(); ++i)
			cout << ans[i] << ' ';
		cout << '\n';
	}

	return 0;
}
