#include <iostream>
#include <string>
#include <stdio.h>
using namespace std;

int main()
{
	int array[26] = {0, };
	int max_val = 0;
	char idx;
	string str;

	cin >> str;
	
	for (int i=0; i<str.size(); ++i) {
		if (97 <= str[i] && str[i] <= 122)
			array[str[i] - 97] += 1;
		else if  (65 <= str[i] && str[i] <= 90)
			array[str[i] - 65] += 1;

	}

	for (int i=0; i<26; ++i) {
		if (max_val < array[i]) {
			max_val = array[i];
			idx = i + 65;
		} else if (array[i] == max_val) {
			idx = '?';
		}
	}

	cout << idx << '\n';
	
	return 0;
}
