#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	string str;
	int sum = 0, temp = 0;
	int num[10] = {0, };

	cin >> str;
	for (int i=0; i<str.size(); ++i)
		num[str[i]-'0']++;

	for (int i=0; i<10; ++i) {
		if (i == 6 || i == 9)
			temp += num[i];
		else
			sum = max(sum, num[i]);
	}
	
	if (sum < ceil((double)temp/2))
		cout << ceil((double)temp/2) << '\n';
	else
		cout << sum << '\n';

	return 0;
}
