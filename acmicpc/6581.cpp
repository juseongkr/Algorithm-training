#include <iostream>
using namespace std;

int main()
{
	bool newline = false;
	string s;
	int cnt = 0;

	while (cin >> s) {
		if (s == "<br>") {
			cout << '\n';
			cnt = 0;
		} else if ( s == "<hr>") {
			if (cnt == 0) {
				for (int i=0; i<80; ++i)
					cout << "-";
				cout << '\n';
			} else {
				cnt = 0;
				cout << '\n';
				for (int i=0; i<80; ++i)
					cout << "-";
				cout << '\n';
			}
		} else {
			if (cnt == 0) {
				cnt = s.length();
				cout << s;
				newline = true;
			} else if (cnt + s.length() < 80) {
				if (newline) {
					cout << " ";
					cnt++;
				}
				cnt += s.length();
				cout << s;

				if (cnt == 80) {
					cout << '\n';
					cnt = 0;
					newline = false;
				}
			} else {
				cout << '\n';
				cnt = s.length();
				newline = true;
				cout << s;
			}
		}
	}

	return 0;
}
