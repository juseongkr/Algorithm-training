#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int n;
	vector<string> ans;
	string s;

	cin >> n >> s;
	int z = 0, o = 0;
	for (int i=0; i<s.length(); ++i) {
		if (s[i] == '0')
			z++;
		else
			o++;
	}
	if (z != o) {
		cout << "1\n" << s << '\n';
		return 0;
	}

	for (int i=0; i<s.length(); ++i) {
		string a, b;
		z = 0, o = 0;
		for (int j=0; j<i; ++j) {
			a += s[j];
			if (s[j] == '0')
				z++;
			else
				o++;
		}
		if (z == o)
			continue;

		z = 0, o = 0;
		for (int j=i; j<s.length(); ++j) {
			b += s[j];
			if (s[j] == '0')
				z++;
			else
				o++;
		}
		if (z == o)
			continue;

		ans.push_back(a);
		ans.push_back(b);
		break;
	}

	cout << ans.size() << '\n';
	for (int i=0; i<ans.size(); ++i)
		cout << ans[i] << " ";

	return 0;
}
