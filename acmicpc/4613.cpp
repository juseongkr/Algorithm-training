#include <iostream>
using namespace std;

int main()
{
	while (1) {
		string s;
		getline(cin, s);
		if (s == "#")
			break;
		int sum = 0;
		for (int i=0; i<s.length(); ++i)
			if ('A' <= s[i] && s[i] <= 'Z')
				sum += (s[i]-'A'+1) * (i+1);

		cout << sum << '\n';
	}

	return 0;
}
