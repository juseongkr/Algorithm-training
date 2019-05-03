#include <iostream>
using namespace std;

int dict[26];

int main()
{
	string s;

	while (cin >> s) {
		for (int i=0; i<s.length(); ++i)
			dict[s[i]-'a']++;
		s.clear();
	}

	int max_val = 0;
	for (int i=0; i<26; ++i)
		max_val = max(max_val, dict[i]);

	for (int i=0; i<26; ++i)
		if (dict[i] == max_val)
			cout << (char)(i+'a');

	return 0;
}
