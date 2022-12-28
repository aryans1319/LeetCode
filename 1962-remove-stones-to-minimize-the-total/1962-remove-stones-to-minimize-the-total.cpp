class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        /*
            The problem given is to find the minimum possible
            sum after performing K number of operations on a particular
            element given in the array
            
            the operation - remove floor(a[i]/2) from any given a[i]
            
            By observation we can say
                - To get minimum sum we need to reduce the maximum element
                - To get max element in every iteration
                - We can use some data structure to get max element in every 
                  iteration hence we get an idea of using max heap
            
            We can do at max K operations so we iterate for K times and
            in every iteration take top element (max element) and reduce it
            by element/2 and repush into the queue
            
            After K iteration return sum of all elements of the priority queue thus
            we would get the minimum sum
            
            Time Complexity : O(n) for creating priority queue
                              O(k) for running upto K iterations, 
                                   insertion and deletion in pq takes O(logn) time
                                  
                                   So, traversing and deleting simultaneously takes
                                   O(nlogn)
                                   
                                   total = O((n + k) logn)
        */
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