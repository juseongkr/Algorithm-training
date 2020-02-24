#include <iostream>
#include <algorithm>
#include <set>
using namespace std;
#define MAX 101
 
int T, n;
int num[MAX], visit[MAX*2], ans[MAX*2];
 
int main()
{
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);
 
	cin >> T;
	while (T--) {
		cin >> n;
		set<int> st;
		fill(visit, visit+MAX, 0);
		for (int i=1; i<=n; ++i) {
			cin >> num[i];
			visit[num[i]] = 1;
		}

		for (int i=1; i<=2*n; ++i)
			if (!visit[i])
				st.insert(i);

		bool flag = false;
		for (int i=1; i<=n; ++i) {
			auto it = st.lower_bound(num[i]);
			if (it == st.end()) {
				cout << "-1\n";
				flag = true;
				break;
			}
			ans[i*2-1] = num[i];
			ans[i*2] = *it;
			st.erase(it);
		}

		if (!flag) {
			for (int i=1; i<=2*n; ++i)
				cout << ans[i] << " ";
			cout << '\n';
		}
	}
 
	return 0;
}
