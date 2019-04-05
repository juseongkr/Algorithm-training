#include <iostream>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	string s, t;
	int n, idx;

	cin >> n;
	cin.ignore();
	for (int i=0; i<n; ++i) {
		getline(cin, s);
		idx = 0;
		for (int j=0; j<s.size(); ++j) {
			if (s[j] == ' ') {
				for (int k=j-1; k>=idx; k--)
					cout << s[k];
				cout << ' ';
				idx = j + 1;
			}
		}
		for (int j=s.size()-1; j>=idx; j--)
			cout << s[j];
		cout << '\n';
	}
	return 0;
}
