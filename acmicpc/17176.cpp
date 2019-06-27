#include <iostream>
using namespace std;
#define MAX 53

int num[MAX];

int main()
{
	bool flag = false;
	string s, flush;
	int n, k;

	cin >> n;
	for (int i=0; i<n; ++i) {
		cin >> k;
		num[k]++;
	}

	getline(cin, flush);
	getline(cin, s);
	for (int i=0; i<s.length(); ++i) {
		if (s[i] == ' ')
			num[0]--;
		else if ('A' <= s[i] && s[i] <= 'Z')
			num[s[i]-'A'+1]--;
		else if ('a' <= s[i] && s[i] <= 'z')
			num[s[i]-'a'+27]--;
	}

	for (int i=0; i<MAX; ++i) {
		if (num[i] != 0) {
			flag = true;
			break;
		}
	}
	if (flag)
		cout << "n\n";
	else
		cout << "y\n";

	return 0;
}
