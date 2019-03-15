#include <iostream>
#include <deque>
using namespace std;

int main()
{
	deque<int> d;
	int num, val;
	string str;

	cin >> num;

	for (int i=0; i<num; ++i) {
		cin >> str;

		if (str == "push_front") {
			cin >> val;
			d.push_front(val);
		} else if (str == "push_back") {
			cin >> val;
			d.push_back(val);
		} else if (str == "pop_front") {
			if (d.empty()) {
				cout << -1 << '\n';
			} else {
				cout << d.front() << '\n';
				d.pop_front();
			}
		} else if (str == "pop_back") {
			if (d.empty()) {
				cout << -1 << '\n';
			} else {
				cout << d.back() << '\n';
				d.pop_back();
			}
		} else if (str == "size") {
			 cout << d.size() << '\n';
		} else if (str == "empty") {
			if (d.empty())
				cout << 1 << '\n';
			else
				cout << 0 << '\n';
		} else if (str == "front") {
			if (d.empty())
				cout << -1 << '\n';
			else
				cout << d.front() << '\n';
		} else if (str == "back" ) {
			if (d.empty())
				cout << -1 << '\n';
			else
				cout << d.back() << '\n';
		}
	}

	return 0;
}
