#include <iostream>
using namespace std;

int main()
{
	string n;
	while (cin >> n && n != "0") {
		int ans = atoi(n.c_str());
		cout << ans << " ";
		while (ans >= 10) {
			int ret = 1;
			for (int i=0; i<n.length(); ++i)
				ret *= n[i]-'0';
			ans = ret;
			n = to_string(ans);
			cout << ans << " ";
		}
		cout << '\n';
	}
	return 0;
}
