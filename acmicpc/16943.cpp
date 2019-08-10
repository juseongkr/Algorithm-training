#include <iostream>
#include <algorithm>
using namespace std;

int b, ans;

int main()
{
	string a;

	cin >> a >> b;
	sort(a.begin(), a.end());
	do {
		int c = stoi(a.c_str());
		if (a[0] != '0' && c < b)
			ans = max(ans, c);
	} while (next_permutation(a.begin(), a.end()));

	if (ans)
		cout << ans << '\n';
	else
		cout << "-1\n";

	return 0;
}
