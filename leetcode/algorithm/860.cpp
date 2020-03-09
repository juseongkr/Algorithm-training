class Solution {
public:
	bool lemonadeChange(vector<int>& bills) {
		int five = 0, ten = 0;
		for (auto i : bills) {
			if (i == 5) {
				five++;
			} else if (i == 10) {
				if (five == 0)
					return false;
				five--;
				ten++;
			} else {
				if (five && ten) {
					five--;
					ten--;
				} else if (five >= 3) {
					five -= 3;
				} else {
					return false;
				}
			}
		}
		return true;
	}
};
