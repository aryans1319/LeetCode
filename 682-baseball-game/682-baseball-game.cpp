class Solution {
public:
    int calPoints(vector<string>& ops) {
         stack<int> bhai_yeh_stack;
        int helper_one;
        int helper_two;
        int apna_javab = 0;
        
        for(auto value : ops)
        {
            if(value=="C")
            {
                bhai_yeh_stack.pop();
            }
            else if(value=="D")
            {
                bhai_yeh_stack.push(bhai_yeh_stack.top()*2);
            }
            else if(value=="+")
            {
                helper_one = bhai_yeh_stack.top();
                bhai_yeh_stack.pop();
                helper_two = helper_one + bhai_yeh_stack.top();
                bhai_yeh_stack.push(helper_one);
                bhai_yeh_stack.push(helper_two);
            }
            else
            {
                bhai_yeh_stack.push(stoi(value));
            }
        }
        
        while(!bhai_yeh_stack.empty())
        {
            apna_javab+=bhai_yeh_stack.top();
            bhai_yeh_stack.pop();
        }
        
        return apna_javab;
    }
};