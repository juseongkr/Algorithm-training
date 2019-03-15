#include <iostream>
using namespace std;

int main()
{
	int num, result, cnt;
	string str;

	cin >> num;

	for (int i=0; i<num; ++i) {
		cin >> str;
		result = 0;
		cnt = 0;

		for (int i=0; i<str.length(); ++i) {
			if (str[i] == 'O') {
				cnt++;
				result += cnt;
			} else {
				cnt = 0;
			}
		}
		printf("%d\n", result);
	}

	return 0;
}
