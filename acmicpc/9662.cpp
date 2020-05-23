#include <iostream>
#include <vector>
#include <map>
using namespace std;
#define MAX 22

int m, k, t;
vector<int> mv, vec;
map<int, int> last;

int main()
{
	cin >> m >> k;
	for (int i=0; i<k; ++i) {
		cin >> t;
		mv.push_back(t);
	}

	int bit = (1 << MAX)-1;
	int ans = -1;
	for (int i=0; i<=m; ++i) {
		ans++;
		bit <<= 1;
		for (int j=0; j<mv.size(); ++j) {
			if ((bit & (1 << mv[j])) == 0) {
				bit++;
				ans--;
				break;
			}
		}

		bit &= (1 << MAX)-1;
		if (last.count(bit)) {
			int len = i - last[bit];
			int cnt = (m-i) / len;
			i += cnt * len;
			ans += cnt * (ans - vec[last[bit]]);
		}

		last[bit] = i;
		vec.push_back(ans);
	}
	cout << ans << '\n';

	return 0;
}
