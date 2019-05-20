#include <iostream>
#include <map>
using namespace std;

int main()
{
	map<string, bool> dict;
	int n, m, ans = 0;
	string s;

	cin >> n >> m;
	for (int i=0; i<n; ++i) {
		cin >> s;
		dict[s] = true;
	}

	for (int i=0; i<m; ++i) {
		cin >> s;
		if (dict[s])
			ans++;
	}
	
	cout << ans << '\n';	

	return 0;
}
