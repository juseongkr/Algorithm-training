#include <iostream>
#include <stack>
using namespace std;
#define MAX 500001

int main()
{
	int n;
	int num[MAX];
	stack<pair<int, int>> st;

	cin >> n;
	for (int i=0; i<n; ++i)
		cin >> num[i];

	long long ans = 0;
	for (int i=0; i<n; ++i) {
		int cnt = 1;
		while (!st.empty()) {
			auto [cur, man] = st.top();
			if (cur < num[i]) {
				ans += man;
				st.pop();
			} else if (cur == num[i]) {
				ans += man;
				cnt += man;
				st.pop();
			} else {
				break;
			}
		}
		if (!st.empty())
			ans++;
		st.push({num[i], cnt});
	}
	cout << ans << '\n';

	return 0;
}
