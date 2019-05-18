#include <iostream>
using namespace std;

int main()
{
	int ans = 0;
	string s, k;

	getline(cin, s);
	getline(cin, k);
	if (s.length() < k.length()) {
		cout << "0\n";
		return 0;
	}

	for (int i=0; i<=s.length()-k.length(); ++i) {
		int cnt = 0;
		for (int j=0; j<k.length(); ++j)
			if (s[i+j] == k[j])
				cnt++;

		if (cnt == k.length()) {
			ans++;
			i += k.length()-1;
		}
	}

	cout << ans << '\n';

	return 0;
}
