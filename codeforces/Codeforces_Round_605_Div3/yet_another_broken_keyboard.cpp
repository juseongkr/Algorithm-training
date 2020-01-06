#include <iostream>
#include <set>
using namespace std;
#define MAX 200001

string s;
char t;
long long n, k, cnt, ans;
set<char> st;

int main()
{
	cin >> n >> k >> s;
	for (int i=0; i<k; ++i) {
		cin >> t;
		st.insert(t);
	}

	for (int i=0; i<n; ++i) {
		if (st.count(s[i])) {
			cnt++;
		} else {
			ans += cnt * (cnt+1) / 2;
			cnt = 0;
		}
	}
	ans += cnt * (cnt+1) / 2;
	cout << ans << '\n';

	return 0;
}
