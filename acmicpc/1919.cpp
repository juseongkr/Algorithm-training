#include <iostream>
using namespace std;

int dict1[26], dict2[26], ans;

int main()
{
	string a, b;

	cin >> a >> b;
	for (int i=0; i<a.length(); ++i)
		dict1[a[i]-'a']++;

	for (int i=0; i<b.length(); ++i)
		dict2[b[i]-'a']++;

	for (int i=0; i<26; ++i)
		if (dict1[i] != dict2[i])
			ans += abs(dict1[i] - dict2[i]);

	cout << ans << '\n';

	return 0;
}
