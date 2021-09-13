class Solution {
public:
    int maxNumberOfBalloons(string text) {
        int freq[26]={0};
        for(auto &c:text){
            freq[c-'a']++;
        }
        char ballon[]={'b','a','l','o','n'};
        int mf=INT_MAX;
        for(char c:ballon){
            if(c=='l'|| c=='o'){
                freq[c-'a']=freq[c-'a']/2;
        }
        mf=min(freq[c-'a'],mf);
        }
        
        return mf==INT_MAX?0:mf;
    }
};
