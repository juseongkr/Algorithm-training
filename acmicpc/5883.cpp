#include <iostream>
#include <set>
using namespace std;
#define MAX 1001

int num[MAX];

int main()
{
	set<int> st;
	int n;

	cin >> n;
	for (int i=0; i<n; ++i) {
		cin >> num[i];
		st.insert(num[i]);
	}

	int ans = 0;
	for (auto i : st) {
		int len = 0, prev = 0;
		for (int j=0; j<n; ++j) {
			if (i == num[j])
				continue;

			if (prev == num[j]) {
				len++;
			} else {
				ans = max(ans, len);
				prev = num[j];
				len = 1;
			}
		}
		ans = max(ans, len);
	}
	cout << ans << '\n';

	return 0;
}
