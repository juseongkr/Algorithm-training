#include <iostream>
using namespace std;
#define MAX 1001

int T;
string s;

int main()
{
	cin >> T;
	while (T--) {
		cin >> s;
		int R = 0, S = 0, P = 0;
		for (int i=0; i<s.length(); ++i) {
			if (s[i] == 'R')
				R++;
			else if (s[i] == 'S')
				S++;
			else
				P++;
		}

		string ans;
		if (R >= P && R >= S) {
			for (int i=0; i<s.length(); ++i)
				ans += 'P';

		} else if (P >= S) {
			for (int i=0; i<s.length(); ++i)
				ans += 'S';

		} else {
			for (int i=0; i<s.length(); ++i)
				ans += 'R';
		}
		cout << ans << '\n';
	}

	return 0;
}
