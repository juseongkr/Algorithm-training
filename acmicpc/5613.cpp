#include <iostream>
using namespace std;

int main()
{
	long long n, ret = 0;
	char op = '+';
	bool flag = true;
	while (1) {
		if (flag) {
			cin >> n;
			if (op == '+')
				ret += n;
			else if (op == '-')
				ret -= n;
			else if (op == '*')
				ret *= n;
			else
				ret /= n;
			flag = false;
		} else {
			cin >> op;
			if (op == '=')
				break;
			flag = true;
		}
	}
	cout << ret;

	return 0;
}
