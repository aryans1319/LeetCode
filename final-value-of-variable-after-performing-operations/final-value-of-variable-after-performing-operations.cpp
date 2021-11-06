class Solution {
public:
    int finalValueAfterOperations(vector<string>& operations) {
        int sum=0;
        for(int i=0;i<operations.size();i++){
            if(operations[i]=="--X" || operations[i]=="X--"){
                sum+=(-1);
            }
            else{
                sum+=1;
            }
        }
        return sum;
    }
};