#include <iostream>
using namespace std;

int main()
{
	int t, B, C, M, W;

	cin >> t;
	while (t--) {
		string a, b, ans;
		bool flag = false;
		B = C = M = W = 0;
		cin >> a >> b;
		for (int i=0; i<b.length(); ++i) {
			if (b[i] == 'B')
				B+=2;
			else if (b[i] == 'C')
				C+=1;
			else if (b[i] == 'M')
				M+=4;
			else if (b[i] == 'W')
				W+=3;
		}
		cout << a << ": ";
		if (B > C && B > M && B > W)
			ans = "Bobcat";
		else if (C > B && C > M && C > W)
			ans = "Coyote";
		else if (M > B && M > C && M > W)
			ans = "Mountain Lion";
		else if (W > B && W > C && W > M)
			ans = "Wolf";
		else
			flag = true;

		if (flag)
			cout << "There is no dominant species" << '\n';
		else
			cout << "The " << ans << " is the dominant species" << '\n';
	}

	return 0;
}
