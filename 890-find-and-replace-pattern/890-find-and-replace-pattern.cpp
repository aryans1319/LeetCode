class Solution {
public:
    vector<string> findAndReplacePattern(vector<string>& words, string p) {        
	vector<string> ans;
	for(auto& w : words) 
		if(match(w, p)) ans.push_back(w);
	return ans;
}
bool match(string& w1, string& w2) {
	unordered_map<char, char> w1_to_w2;
	for(int i = 0; i < size(w1); i++) 
		if(w1_to_w2.count(w1[i]) && w1_to_w2[w1[i]] != w2[i])  return false; 
		else w1_to_w2[w1[i]] = w2[i];
	bitset<26> visited;
	for(auto& pair : w1_to_w2) 
		if(visited[pair.second - 'a']) return false;
		else visited[pair.second - 'a'] = true;
	return true;
}
};