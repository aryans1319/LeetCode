class Solution {
public:
    int maxProduct(vector<string>& words) {     // function to get the max product of two words
	int n = words.size(), ans = 0;       // n is the number of words and ans is the max product
	vector<int> mask(n);               // mask is the vector of bit masks
	for(int i = 0; i < n; i++) {      // loop to get the bit mask of each word
		for(auto& ch : words[i])     // for each character in the word          
			mask[i] |= 1 << (ch - 'a');   // hash the word
		for(int j = 0; j < i; j++) // loop to check if the word is a subset of another word
			if((mask[i] & mask[j]) == 0)    // if no common set bit is found in the hash of words[i] and words[j]
				ans = max(ans, int(size(words[i]) * size(words[j]))); // update the max product
	}    
	return ans; // return the max product
}
};