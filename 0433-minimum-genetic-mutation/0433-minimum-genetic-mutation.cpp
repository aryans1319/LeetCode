class Solution {
public:
    /*
        We have to keep a track of two things here, we change the 
        unmatched char (mutation) and the string formed after mutation
        must be present in the bank
        
        At each step we can change only one char of the string
        the newly formed string must be present in the bank of strings
        
    */
    
    int minMutation(string start, string end, vector<string>& bank) {
        int count = 0;
        unordered_set <string> visited;
        queue<string>q;
        q.push(start);
        visited.insert(start);
        while(!q.empty()){
            int n = q.size();
            for(int i = 0; i < n; i++){
                string node = q.front();
                q.pop();
                
                if(node == end){
                    return count;
                }
                
                for(char ch : "ACGT"){
                    for(int j = 0; j < node.size(); j++){
                        string adjacentNode = node;
                        adjacentNode[j] = ch;
                        if(!visited.count(adjacentNode) && find(bank.begin(), bank.end(), adjacentNode) != bank.end()){
                            q.push(adjacentNode);
                            visited.insert(adjacentNode);
                        }
                    }
                }
            }
            count++;
        }
        return -1;
    }
};