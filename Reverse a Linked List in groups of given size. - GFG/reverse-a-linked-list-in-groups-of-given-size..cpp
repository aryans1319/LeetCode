// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


struct node
{
    int data;
    struct node* next;
    
    node(int x){
        data = x;
        next = NULL;
    }
    
};

/* Function to print linked list */
void printList(struct node *node)
{
    while (node != NULL)
    {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}


 // } Driver Code Ends
/*
  Reverse a linked list
  The input list will have at least one element  
  Return the node which points to the head of the new LinkedList
  Node is defined as 
    struct node
    {
        int data;
        struct node* next;
    
        node(int x){
            data = x;
            next = NULL;
        }
    
    }*head;
*/

class Solution
{
    public:
    struct node *reverse (struct node *head, int key)
    { 
        // Complete this method
         node* next; //1st Node next ko point kar rhi hai;
       node*prev=NULL;// 1st node ka prev NULL hota hai
       node*current=head;// Head hi current node b hai
       int count=key;// count mei humne key dal di
       while(count-- && current!=NULL)//Toh ab key ko less krte chalenge or List ko traverse krenge    
       {
           next=current->next;//So Next jo h wo 1t node k current ka next hai      
           current->next=prev;//current ka next previous hai 
           prev=current;//prev ko current p point kra diya     
           current=next;//Aur current ko next p le gye
       }
       if(head!=NULL)//Ab check krenge head ko kha tk null milega  
       {
           head->next=reverse(next,key);//Toh jo head ka next jha use null mila wha se reverse kar di
       }
       return prev; // Nhi toh prev ko return kr dega

    }
};


// { Driver Code Starts.

/* Drier program to test above function*/
int main(void)
{
    int t;
    cin>>t;
     
    while(t--)
    {
        struct node* head = NULL;
        struct node* temp = NULL;
        int n;
        cin >> n;
         
        for(int i=0 ; i<n ; i++)
        {
            int value;
            cin >> value;
            if(i == 0)
            {
                head = new node(value);
                temp = head;
            }
            else
            {
                temp->next = new node(value);
                temp = temp->next;
            }
        }
        
        int k;
        cin>>k;
        
        Solution ob;
        head = ob.reverse(head, k);
        printList(head);
    }
     
    return(0);
}

  // } Driver Code Ends