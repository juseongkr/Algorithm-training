#include <iostream>
using namespace std;
#define MAX 51

int cal[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int leap(int y) { return (y%4 == 0) - (y%100 == 0) + (y%400 == 0); }

int main()
{
	int area[MAX];
	string s;
	int n;

	cin >> s >> n;
	for (int i=0; i<n; ++i)
		cin >> area[i];

	int A = stoi(s.substr(0, 6));

	bool flag = false;
	for (int i=0; i<n; ++i)
		if (area[i] == A)
			flag = true;

	if (!flag) {
		cout << "I\n";
		return 0;
	}

	int year = stoi(s.substr(6, 4));
	if (year < 1900 || year > 2011) {
		cout << "I\n";
		return 0;
	}

	int month = stoi(s.substr(10, 2));
	if (month < 1 || month > 12) {
		cout << "I\n";
		return 0;
	}

	int day = stoi(s.substr(12, 2));
	if (day < 1) {
		cout << "I\n";
		return 0;
	}

	if (leap(year) && month == 2) {
		if (day > 29) {
			cout << "I\n";
			return 0;
		}
	} else {
		if (day > cal[month]) {
			cout << "I\n";
			return 0;
		}
	}

	int order = stoi(s.substr(14, 3));
	if (order == 0) {
		cout << "I\n";
		return 0;
	}

	string c = s.substr(17, 1);
	int check;
	if (c == "X")
		check = 10;
	else
		check = stoi(c);

	for (int i=0; i<17; ++i) {
		check += (s[i]-'0') * (1 << (17-i));
		check %= 11;
	}

	if (check != 1) {
		cout << "I\n";
		return 0;
	} else {
		if (order % 2 == 1)
			cout << "M\n";
		else
			cout << "F\n";
	}

	return 0;
}
