#include <iostream>
using namespace std;
#define MAX 101

int T, n;
int x[101];
string s[101];

int main()
{
	cin >> T;
	while(T--) {
		cin >> n;
		int mx = 0;
		for (int i=0; i<n; ++i)
			cin >> x[i];

		string p;
		for (int i=0; i<51; ++i)
			p += 'a';

		s[0] = p;
		for (int i=0; i<n+1; ++i) {
			string k;
			for (int j=0; j<s[i].length(); ++j) {
				if (j == x[i]) {
					k += (s[i][j]+1-'a') % 26 +'a';

				} else {
					k += s[i][j];
				}
			}
			s[i+1] = k;
		}

		for (int i=0; i<n+1; ++i)
			cout << s[i] << '\n';
	}

	return 0;
}
