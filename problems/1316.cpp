#include <iostream>
#include <string>
using namespace std;

bool solve(string str)
{
	int flag;

	for (int i=0; i<str.length(); ++i) {
		flag = 0;
		for (int j=i+1; j<str.length(); ++j) {
			if (str[i] == str[j]) {
				if (flag == 1)
					return 0;
			} else {
				flag = 1;
			}
		}
	}
	return 1;
}

int main()
{
	int n, cnt = 0;
	string str;
	
	cin >> n;

	for (int i=0; i<n; ++i) {
		cin >> str;
		if (solve(str))
			cnt++;
	}

	cout << cnt << '\n';

	return 0;
}
