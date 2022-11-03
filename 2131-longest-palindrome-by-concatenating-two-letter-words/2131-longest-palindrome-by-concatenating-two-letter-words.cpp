class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        map<string,int>mp;
        for(auto i:words){
            mp[i]++;
        }
        
        int a=0;
        map<string,bool>mp1;
        for(auto i: mp){
            string x= i.first;
            string y="";
            y+=i.first[1];
            y+=i.first[0];
            
            if(x!=y){
                if(mp1[x]==false && mp1[y]==false){
                    int v = min(mp[x],mp[y]);
                    a+=(v*4);
                    mp1[x]=true;
                    mp1[y]=true;
                }
            }
        }
        
        map<string,int>mp2;
        for(auto i: words){
              string x= i;
            string y="";
            y+=i[1];
            y+=i[0];
            
            if(x==y){
                mp2[x]++;
            }
        }
        
        bool flag=false;
        
        for(auto i:mp2){
            if(mp2[i.first]%2==0){
                a+=mp2[i.first]*2;
            }
            else{
                if(flag==false){
                    a+=2;
                    flag=true;
                }
                int z=mp2[i.first]-1;
                a+=z*2;
            }
        }
        return a;
    }
};