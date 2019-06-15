#include <iostream>
using namespace std;
#define MAX 1000001

int main()
{
	bool flag = false;
	int num[MAX];
	int n;

	cin >> n;
	for (int i=0; i<n; ++i)
		cin >> num[i];

	for (int i=0; i<n; ++i) {
		if (num[i] == i+1) {
			flag = true;
			break;
		}
	}

	if (flag)
		cout << "-1\n";
	else
		cout << "1000000007\n";

	return 0;
}
