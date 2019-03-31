#include <iostream>
using namespace std;

int dict[26];

int main()
{
	string str;

	cin >> str;
	for (int i=0; i<str.length(); ++i)
		dict[str[i] - 'a']++;

	for (int i=0; i<26; ++i)
		cout << dict[i] << " ";

	return 0;
}
