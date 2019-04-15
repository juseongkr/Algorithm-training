#include <iostream>
using namespace std;

int main()
{
	string str;

	getline(cin, str);
	for (int i=0; i<str.length(); ++i) { 
		if ('a' <= str[i] && str[i] <= 'z') {
			if (str[i] > 'm')
				str[i] -= 13;
			else
				str[i] += 13;

		} else if ('A' <= str[i] && str[i] <= 'Z') {
			if (str[i] > 'M')
				str[i] -= 13;
			else
				str[i] += 13;
		}
		printf("%c", str[i]);
	}

	return 0;
}
