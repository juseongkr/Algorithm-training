#include <iostream>
using namespace std;

int main()
{
	int cnt = 0;
	string str;
	
	cin >> str;
	
	
	for (int i=0; i<str.size(); ++i) {
		if (str[i] == 'Q') {
			for (int j=i+1; j<str.size(); ++j) {
				if (str[j] == 'A') {
					for (int k=j+1; k<str.size(); ++k) {
						if (str[k] == 'Q')
							cnt++;
					}
				}

			}
		}
	}

	cout << cnt << '\n';
	return 0;
}
