class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& a, int k) {
        vector<int>ans;
list<int>l;
int i=0,j=0;
while(j<a.size())
{
    if (l.empty()){
        l.push_back(a[j]);
    }
    else{
    while(l.back()<a[j] && !l.empty())
    {
        l.pop_back();
    }
    l.push_back(a[j]);
    }
    if(j-i+1<k)
    j++;

    else if(j-i+1==k)
    {
        ans.push_back(l.front());

        if(l.front()==a[i])
        {
            l.pop_front();
        }
        i++;
        j++;
    }
}
return ans;
    }
};