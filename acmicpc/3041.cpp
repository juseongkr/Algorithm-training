#include <iostream>
using namespace std;

int main()
{
	int ans = 0;
	string s[4];

	for (int i=0; i<4; ++i)
		cin >> s[i];

	for (int i=0; i<4; ++i)
		for (int j=0; j<4; ++j)
			if (s[i][j] != '.')
				ans += abs((s[i][j]-'A')/4-i) + abs((s[i][j]-'A')%4-j);

	cout << ans << '\n';

	return 0;
}
