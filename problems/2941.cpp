#include <iostream>
using namespace std;

int main()
{
	string str;
	int i, cnt = 0;

	cin >> str;

	for (int i=0; i<str.size(); ++i) {
		if (str[i] == 'c' && str[i+1] == '=') {
			cnt++;
			i++;
		} else if (str[i] == 'c' && str[i+1] == '-') {
			cnt++;
			i++;
		} else if (str[i] == 'd' && str[i+1] == 'z' && str[i+2] == '=') {
			cnt++;
			i += 2;
		} else if (str[i] == 'd' && str[i+1] == '-') {
			cnt++;
			i++;
		} else if (str[i] == 'l' && str[i+1] == 'j') {
			cnt++;
			i++;
		} else if (str[i] == 'n' && str[i+1] == 'j') {
			cnt++;
			i++;
		} else if (str[i] == 's' && str[i+1] == '=') {
			cnt++;
			i++;
		} else if (str[i] == 'z' && str[i+1] == '=') {
			cnt++;
			i++;
		} else {
			cnt++; 
		}
	}

	cout << cnt << '\n';

	return 0;
}
