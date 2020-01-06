#include <iostream>
#include <cstring>
using namespace std;

int check(string str)
{
	int cnt = 0;
	for (int i=0; i<str.length()/2; ++i) {
		if (str[i] == str[str.length()-i-1])
			cnt++;
	}

	if (cnt != str.length()/2)
		return 1;
	else 
		return 0;
}

int main()
{
	string str;
	int num, cnt = 0;
	cin >> num;

	for (int i=0; i<num; ++i) {
		cin >> str;
		
		if (check(str)) {
			cout << str <<'\n';
			continue;
		} else {
			string temp;
			temp = str.substr(1, str.length()) + str[0];
			
			if (check(temp)) {
				cout << temp << '\n';
			} else {
				cout << "-1\n";
			}
		}
	}

	return 0;
}
