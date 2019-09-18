#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);

	set<string> st;
	vector<pair<pair<int, int>, pair<string, string>>> vec;
	int n, k, solve, penalty;
	string univ, name;

	cin >> n >> k;
	for (int i=0; i<n; ++i) {
		cin >> univ >> name >> solve >> penalty;
		vec.push_back({{solve, -penalty}, {univ, name}});
	}
	sort(vec.begin(), vec.end());

	int i = 0;
	while (k && i < n) {
		if (!st.count(vec[n-1-i].second.first)) {
			st.insert(vec[n-1-i].second.first);
			cout << vec[n-1-i].second.second << '\n';
			k--;
		}
		i++;
	}

	return 0;
}
