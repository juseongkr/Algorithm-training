#include <iostream>
using namespace std;
#define MAX 10001

char x;
string s;
int n, m, o;
int dict[MAX];

int main()
{
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);

	cin >> n >> m;
	for (int i=0; i<n; ++i) {
		cin >> s;
		for (int j=0; j<s.length(); ++j)
			dict[i] |= (1 << s[j]-'a');
	}

	int know = (1 << 26)-1;
	while (m--) {
		cin >> o >> x;
		if (o == 1)
			know &= ~(1 << x-'a');
		else
			know |= (1 << x-'a');

		int cnt = 0;
		for (int i=0; i<n; ++i)
			if ((dict[i] & know) == dict[i])
				cnt++;

		cout << cnt << '\n';
	}

	return 0;
}
