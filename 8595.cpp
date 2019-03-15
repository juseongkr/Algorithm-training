#include <iostream>
#include <cmath>
using namespace std;

long long to_number(string str)
{
	long long ret = 0;

	for (int i=0; i<str.length(); ++i)
		ret += (str[str.length() - i - 1] - '0') * pow(10, i);

	return ret;
}

int main()
{
	long long len, result = 0;
	string str, temp;

	scanf("%lld", &len);
	cin >> str;

	for (int i=0; i<len; ++i) {
		if (str[i] >= 48 && str[i] <= 57) {
			temp += str[i];
		} else {
			result += to_number(temp);
			temp.clear();
		}
	}

	result += to_number(temp);
	cout << result << '\n';

	return 0;
}
