class Solution {
public:
    double realProb(int n,int k,int row,int col,unordered_map<string,double>&mp){
        if(row >= n || row < 0 || col>=n || col<0){
            return 0;
        }
        
        if(k<=0){
            return 1;
        }
        
        string currentKey = to_string(k) + "_" + to_string(row) + "_"+ to_string(col);
        
        if(mp.find(currentKey)!=mp.end()){  
            return mp[currentKey];
        }
        
        double sum = 0;
        sum = realProb(n,k-1,row-2,col-1,mp)+
              realProb(n,k-1,row-2,col+1,mp)+
            realProb(n,k-1,row-1,col+2,mp)+
            realProb(n,k-1,row+1,col+2,mp)+
            realProb(n,k-1,row+2,col+1,mp)+
            realProb(n,k-1,row+2,col-1,mp)+
            realProb(n,k-1,row+1,col-2,mp)+
            realProb(n,k-1,row-1,col-2,mp);
        
        sum/=8;
        mp[currentKey] = sum;
        return  mp[currentKey];
    }
    
    double knightProbability(int n, int k, int row, int column) {
        unordered_map<string,double>mp;
        return realProb( n,k,row,column,mp);
    }
};