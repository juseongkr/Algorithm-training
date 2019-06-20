#include <iostream>
using namespace std;

const int key[26] = {2, 22, 222, 3, 33, 333, 4, 44, 444, 5, 55, 555, 6, 66, 666, 7, 77, 777, 7777, 8, 88, 888, 9, 99, 999, 9999};

int main()
{
	int num[10], t;
	string s;

	for (int i=1; i<10; ++i) {
		cin >> t;
		num[t] = i;
	}

	cin >> s;
	int last = 0;
	for (int i=0; i<s.length(); ++i) {
		int n = key[s[i]-'a'];
		if (last == n%10)
			cout << '#';

		while (n) {
			last = n%10;
			cout << num[n%10];
			n /= 10;
		}
	}

	return 0;
}
