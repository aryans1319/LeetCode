class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        priority_queue<int> pq;
        int sum = 0;
        for(auto i : piles){
            pq.push(i);
        }
        for(int i = 0; i < k; i++){
            int maxElement = pq.top();
            pq.pop();
            maxElement -= floor(maxElement/2);
            pq.push(maxElement);
        }
        while(!pq.empty()){
            sum += pq.top();
            pq.pop();
        }
        return sum;
    }
};