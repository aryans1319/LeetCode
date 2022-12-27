class Solution 
{
public:
    //for sorting pairs which has less difference b/w capacity and rocks
    static bool compare(vector<int> &a, vector<int> &b) 
    {
        return (a[1]-a[0] < b[1]-b[0]);
    }

    int maximumBags(vector<int>& cap, vector<int>& rocks, int addrocks) 
    {
        int n=cap.size();
        vector<vector<int>> bags; 

        //storing rocks and capacity in 2d vector
        for(int i=0; i<n; i++)
            bags.push_back({rocks[i], cap[i]});

        //sort bags based on less difference between capacity and rocks
        sort(bags.begin(), bags.end(), compare);

        //count maximum number of bags having full capacity
        int cnt=0;
        for(auto &it:bags) 
        {
            if((it[1]-it[0]) <= addrocks) addrocks -= (it[1]-it[0]);       
            else break;
            cnt++;
        }
        return cnt;
    }
};