#include <iostream>
using namespace std;

int card[3][10];

int main()
{
	string s;

	for (int i=0; i<3; ++i) {
		cin >> s;
		int num = s[0]-'0';
		if (s[1] == 'm')
			card[0][num]++;
		else if (s[1] == 'p')
			card[1][num]++;
		else
			card[2][num]++;
	}

	int ans = 2;
	for (int i=0; i<3; ++i)
		for (int j=1; j<10; ++j)
			ans = min(ans, 3 - card[i][j]);

	for (int i=0; i<3; ++i) {
		for (int j=1; j<=7; ++j) {
			int cnt = 0;
			for (int k=0; k<3; ++k)
				if (card[i][j+k])
					cnt++;
			ans = min(ans, 3 - cnt);
		}
	}
	cout << ans << '\n';

	return 0;
}
