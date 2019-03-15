#include <iostream>
#include <stack>
using namespace std;

int main()
{
	stack<int> s;
	string op;
	int num, val;
	cin >> num;

	for (int i=0; i<num; ++i) {
		cin >> op;

		if (op == "push") {
			cin >> val;
			s.push(val);
		} else if (op == "pop") {
			if (s.empty())
				cout << "-1\n";
			else {
				cout << s.top() << '\n';
				s.pop();
			}
		} else if (op == "top") {
			if (s.empty())
				cout << "-1\n";
			else 
				cout << s.top() << '\n';
		} else if (op == "size") {
			cout << s.size() << '\n';
		} else if (op == "empty") {
			if (s.empty())
				cout << "1\n";
			else
				cout << "0\n";
		} 
	}

	return 0;
}
