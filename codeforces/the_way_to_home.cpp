#include <iostream>
using namespace std;

int main()
{
	string str;
	int n, d, s, cnt = 0, i = 0;
	cin >> n >> d >> str;

	while (n > 1) {
		s = 0;
		for (int j=1; j<=d; ++j) {
			if (str[i+j] == '1')
				s = j;
		}
		if (s == 0) {
			cout << "-1\n";
			return 0;
		}
		i += s;
		n -= s;
		cnt++;
	}

	cout << cnt << '\n';

	return 0;
}
