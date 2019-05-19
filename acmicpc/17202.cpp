#include <iostream>
using namespace std;

int main()
{
	string a, b, t, ans;

	cin >> a >> b;
	for (int i=0; i<16; ++i) {
		if (i%2 == 0)
			t += a[i/2];
		else
			t += b[i/2];
	}

	ans = t;
	while (ans.size() != 2) {
		string temp;
		for (int i=0; i<ans.length()-1; ++i) {
			int r = ans[i]-'0' + ans[i+1]-'0';
			temp += (r%10)+'0';
		}
		ans = temp;
	}

	cout << ans << '\n';

	return 0;
}
