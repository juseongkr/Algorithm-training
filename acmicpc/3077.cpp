#include <iostream>
#include <map>
using namespace std;

int main()
{
	map<string, int> dict;
	int ans[2501];
	int n, cnt = 0;
	string s;

	cin >> n;
	for (int i=0; i<n; ++i) {
		cin >> s;
		dict.insert({s, i});
	}

	for (int i=0; i<n; ++i) {
		cin >> s;
		ans[i] = dict[s];
	}

	for (int i=0; i<n; ++i)
		for (int j=i+1; j<n; ++j)
			if (ans[i] < ans[j])
				cnt++;

	cout << cnt << "/" << (n*n-n)/2 << '\n';

	return 0;
}
