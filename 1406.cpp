#include <iostream>
#include <list>
#include <string>
using namespace std;

int main()
{
	string str;
	int num;
	
	cin >> str >> num;

	list<char> li(str.begin(), str.end());
	auto pos = li.end();

	for (int i=0; i<num; ++i) {
		char op;
		cin >> op;

		if (op == 'L') {
			if (pos != li.begin())
				pos--;

		} else if (op == 'D') {
			if (pos != li.end())
				pos++;

		} else if (op == 'B') {
			if (pos != li.begin()) {
				auto t = pos;
				--pos;
				li.erase(pos);
				pos = t;
			}
		} else if (op == 'P') {
			char c;
			cin >> c;
			li.insert(pos, c);
		}
	}

	for (char i : li)
		cout << i;

	return 0;
}
