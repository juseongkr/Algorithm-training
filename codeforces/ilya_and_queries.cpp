#include <iostream>
using namespace std;

int main()
{
	int array[100000] = {0, };
	int n, l, r, cnt = 0;
	string str;

	cin >> str;

	for (int i=1; i<str.size(); ++i) {
		if (str[i] == str[i-1])
			array[i] = array[i-1] + 1;
		else
			array[i] = array[i-1];
	}

	cin >> n;
	for (int i=0; i<n; ++i) {
		cin >> l >> r;
		cout << array[r-1] - array[l-1] << '\n';
	}

	return 0;
}
