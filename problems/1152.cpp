#include <iostream>
using namespace std;

int main()
{
	string str;
	int cnt = 1;

	getline(cin, str);

	if (str[0] == ' ')
		cnt--;
	if (str[str.length()-1] == ' ')
		cnt--;

	for (int i=0; i<str.length(); ++i) {
		if (str[i] == ' ')
			cnt++;
	}

	printf("%d\n", cnt);

	return 0;
}
