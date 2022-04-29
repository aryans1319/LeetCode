// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


 // } Driver Code Ends
//User function template for C++

/* 
From observations, we can see the length/no of words in pattern 
doesn't change

Therefore we can observe it as a problem with fixed size window
(which is the length of pat), now we can apply the similar logic here.

We have window size we have string and if we see carefully we just
need to find the number of substrings of same size of pat

Approach: 

Let's take this example 
txt = aabaabaa
pat = aaba

We need to find occurences of anagrams of 
"aaba" in the given string, what we can do is we can
use a map to store the count of every char of pat

a -> 3
b -> 1

Now we will traverse the txt string and if we find similar
char present in txt as well as in map we decrement the count of 
every char occured, as soon as both a and b will hit 0 , we get a
anagram but this approach is not so efficient as we have to traverse 
map multiple times

Now how to optimise it ?

Store the count of distinct letters in pat,which is
definitely size of map ( 2(distinct) in this case (a,b) )

this helps to avoid traversing the map multiple times

Count = 2;

Now whenever any char count in map hits 0,we decrement 
the count of distinct char, for eg a->3, b->1

if a==0 || b==0 we decrement count--

if count = 0, that means we got anagram as we wanted it to be
so increment anagram count

if count != 0 think of a case aacb, a->3 decreased to 1
b->1 decreased to 0, c not present so avoid it but we can
see count of a->1 so we won't decrement the count of distinct
char(which we do when every char in map has a zero count), 
in this case we didn't get an anagram 


Now how to slide the window ?
This is an important part

a a b a a b a a

i     j         1st window
  i     j
2nd window we need to remove calculations of 
prev window, think what we did prev when we 
find occurences of pat in string we decremented the count
just do the reverse to remove prev window calculations

if a is occurring again increment count of a, back to 1 in map
as well as increase count of total distinct char(map size) as 
we have a in map (non zero)

*/
class Solution{
public:
	int search(string pat, string txt) {
	    int ans=0;
	    int i=0,j=0;
	    int k = pat.size();
	    unordered_map<char,int> mp;
	    
	    for(int i=0;i<k;i++){
	        mp[pat[i]]++;
	    }
	    int count = mp.size();
	    
	    while(j< txt.size()){
	        if(mp.find(txt[j])!=mp.end()){
	        mp[txt[j]]--;
	        
	        if(mp[txt[j]]==0)
	        count--;
	    }
	    
	     if(j-i+1<k){
	        j++;
	    }
	    else if(j-i+1 == k){
	        if(count==0)
	        ans++;
	        if(mp.find(txt[i])!=mp.end()){
	            mp[txt[i]]++;
	            
	            if(mp[txt[i]]==1)
	            count++;
	        }
	        
	        i++;
	        j++;
	    }
	    }
	    return ans;
	}

};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string pat, txt;
        cin >> txt >> pat;
        Solution ob;
        auto ans = ob.search(pat, txt);
        cout << ans << "\n";
    }
    return 0;
}  // } Driver Code Ends