class Solution {
public:
	bool check(vector<int> &maxiv , int len , vector<int> &vis) {
		for (int i = 0 ; i <= len ; i++) {
			if (maxiv[i] != 0 and vis[i] == 0) return false;
		}
		return true;
	}

	void add(int a , int len , vector<int> &vis) {
		for (int i = 0 ; i <= len ; i++) {
			if (((a >> i) & 1) == 1) vis[i]++;
		}
	}
	void addmaxi(int a , int len , vector<int> &maxiv) {
		for (int i = 0 ; i <= len ; i++) {
			if (((a >> i) & 1) == 1) maxiv[i]++;
		}
	}

	void clear(int a , int len , vector<int> &vis) {
		for (int i = 0 ; i <= len ; i++) {
			if (((a >> i) & 1) == 1) vis[i]--;
		}
	}
	void clearfrom(int a , int len , vector<int> &maxiv) {
		for (int i = 0 ; i <= len ; i++) {
			if (((a >> i) & 1) == 1) maxiv[i]--;
		}
	}

	bool empty(vector<int> &maxiv , int len) {
		for (int i = 0 ; i <= len ; i++) {
			if (maxiv[i] != 0) return false;
		}
		return true;
	}

	vector<int> smallestSubarrays(vector<int>& nums) {
        
        // calc maximum bits in nums
        int maxi = 0;
        for(auto x : nums) maxi = maxi|x;

		int n = nums.size() , i =0  , j= 0 , len;
		if (maxi != 0) len = log2(maxi);
		else len = 0;



		vector<int> maxiv(len + 1, 0);
		for (auto x : nums) {
			addmaxi(x, len, maxiv);
		}


		// checking visited bits
		vector<int> vis(len + 1, 0);


		//returning ans
		vector<int> ans(n, 0);

		while (i < n and j < n) {

			// maxiv is empty then all elements after is 0
			if (empty(maxiv, len)) j++;


			// checking for window
			while (!check(maxiv, len, vis) and j < n) {
				add(nums[j], len, vis);
				j++;
			}



			if (j < n and check(maxiv, len, vis)) {
				ans[i] = j - i;
				clear(nums[i], len, vis);
				clearfrom(nums[i], len, maxiv);
				i++;
			}

		}


		// remaining last elements which ended at n
		while (i < j) {
			ans[i] = j - i;
			clear(nums[i], len, vis);
			i++;
		}

		return ans;
	}
};
