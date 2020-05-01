class numarray {
public:
	vector<int> psum;
	numarray(vector<int>& nums) {
		psum.resize(nums.size()+1, 0);
		for (int i=0; i<nums.size(); ++i)
			psum[i+1] = psum[i] + nums[i];
	}

	int sumrange(int i, int j) {
		return psum[j+1] - psum[i];
	}
};

/**
 * your numarray object will be instantiated and called as such:
 * numarray* obj = new numarray(nums);
 * int param_1 = obj->sumrange(i,j);
 */
