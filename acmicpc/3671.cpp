#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <cmath>
using namespace std;
#define MAX 10000001

int t;
string s;
set<int> st;
bool check[MAX], prime[MAX];

int main()
{
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);

	fill(check+2, check+MAX, true);
	for (int i=2; i<=MAX; ++i) {
		if (check[i])
			prime[i] = true;
		for (int j=i; j<=MAX; j+=i)
			check[j] = false;
	}

	cin >> t;
	while (t--) {
		cin >> s;
		sort(s.begin(), s.end());
		do {
			int num = 0;
			for (int i=0; i<s.length(); ++i) {
				num = num * 10 + s[i]-'0';
				if (prime[num])
					st.insert(num);
			}
		} while (next_permutation(s.begin(), s.end()));

		cout << st.size() << '\n';
		st.clear();
	}

	return 0;
}
