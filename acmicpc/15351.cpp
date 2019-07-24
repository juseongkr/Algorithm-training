#include <iostream>
using namespace std;

int main()
{
	string flush;
	int n;

	cin >> n;
	getline(cin, flush);
	for (int k=0; k<n; ++k) {
		string s;
		getline(cin, s);

		int ans = 0;
		for (int i=0; i<s.length(); ++i)
			if (s[i] != ' ')
				ans += s[i]-'A'+1;

		if (ans == 100)
			cout << "PERFECT LIFE\n";
		else
			cout << ans << '\n';
	}

	return 0;
}
