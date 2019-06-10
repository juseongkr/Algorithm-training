#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> vec, ans;
int n, check[10];
string s;

void dfs()
{
	if (vec.size() == n) {
		string r;
		for (int i=0; i<n; ++i)
			r += vec[i]+'0';
		ans.push_back(atoi(r.c_str()));
	}

	for (int i=0; i<10; ++i) {
		if (check[i] != 0) {
			check[i]--;
			vec.push_back(i);
			dfs();
			vec.pop_back();
			check[i]++;
		}
	}
}

int main()
{
	cin >> s;
	n = s.length();
	for (int i=0; i<n; ++i)
		check[s[i]-'0']++;

	dfs();

	sort(ans.begin(), ans.end());

	for (int i=0; i<ans.size(); ++i) {
		if (atoi(s.c_str()) < ans[i]) {
			cout << ans[i] << '\n';
			return 0;
		}
	}
	cout << "0\n";

	return 0;
}
