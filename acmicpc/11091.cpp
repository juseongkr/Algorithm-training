#include <iostream>
#include <vector>
using namespace std;

int main()
{
	vector<char> ans;
	int dict[26];
	int n;
	string s;

	cin >> n;
	cin.ignore();
	for (int i=0; i<n; ++i) {
		getline(cin, s);
		ans.clear();
		fill(dict, dict+26, 0);
		for (int j=0; j<s.length(); ++j) {
			if ('A' <= s[j] && s[j] <= 'Z')
				s[j] += 32;
			if ('a' <= s[j] && s[j] <= 'z')
				dict[s[j]-'a']++;
		}
		for (int j=0; j<26; ++j) {
			if (!dict[j])
				ans.push_back(j+'a');
		}
		
		if (ans.size() == 0) {
			cout << "pangram\n";
		} else {
			cout << "missing ";
			for (int j=0; j<ans.size(); ++j)
				cout << ans[j];
			cout << '\n';
		}
	}

	return 0;
}
