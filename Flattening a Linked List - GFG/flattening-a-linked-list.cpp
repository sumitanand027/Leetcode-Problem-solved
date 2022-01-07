// { Driver Code Starts
#include <bits/stdc++.h>

struct Node{
	int data;
	struct Node * next;
	struct Node * bottom;
	
	Node(int x){
	    data = x;
	    next = NULL;
	    bottom = NULL;
	}
	
};

using namespace std;

void printList(Node *Node)
{
    while (Node != NULL)
    {
        printf("%d ", Node->data);
        Node = Node->bottom;
    }
}

Node* flatten (Node* root);

int main(void) {

	int t;
	cin>>t;
	while(t--){
    int n,m,flag=1,flag1=1;
    struct Node * temp=NULL;
	struct Node * head=NULL;
	struct Node * pre=NULL;
	struct Node * tempB=NULL;
	struct Node * preB=NULL;
		cin>>n;
        int work[n];
		for(int i=0;i<n;i++)
            cin>>work[i];
		for(int i=0;i<n;i++){
			m=work[i];
			--m;
			int data;
			scanf("%d",&data);
			temp = new Node(data);
			temp->next = NULL;
			temp->bottom = NULL;
			
			if(flag){
				head = temp;
				pre = temp;
				flag = 0;
				flag1 = 1;
			}
			else{
				pre->next = temp;
				pre = temp;
				flag1 = 1;
			}
			for(int j=0;j<m;j++){
				
				int temp_data;
				scanf("%d",&temp_data);
				tempB = new Node(temp_data);

				if(flag1){
					temp->bottom=tempB;
					preB=tempB;
					flag1=0;
				}
				else{
					preB->bottom=tempB;
					preB=tempB;
				}
			}
		}
		   Node *fun = head;
		   Node *fun2=head;

            Node* root = flatten(head);
            printList(root);
            cout<<endl;

	}
	return 0;
}
// } Driver Code Ends


/* Node structure  used in the program

struct Node{
	int data;
	struct Node * next;
	struct Node * bottom;
	
	Node(int x){
	    data = x;
	    next = NULL;
	    bottom = NULL;
	}
	
};
*/

/*  Function which returns the  root of 
    the flattened linked list. */
    
    Node * mergeTwoSortedLL( Node * list1, Node * list2 )
    {
        Node * l1 , *l2 , *cur;
        Node * head;
        if( !list1 )
            return list2;
        if( !list2)
            return list1;
        
        if( list1 -> data < list2 -> data )
        {
            cur = list1;
            head = list1;
            l1 = list1 -> bottom;
            l2 = list2;
        }
        else
        {
            cur = list2;
            head = list2;
            l1 = list1;
            l2 = list2 -> bottom;
        }
        
        while( l1 && l2 ) 
        {
              if( l1 -> data < l2 -> data )
              {
                  cur -> bottom = l1;
                  cur = l1; 
                  l1 = l1 -> bottom; 
              } else {
                  cur -> bottom = l2;
                  cur = l2;   
                  l2 = l2 -> bottom; 
              }
        }
        
        while( l1 ) {
            cur -> bottom = l1;
            cur = l1;
            l1 = l1 -> bottom;
        }
        while( l2 ) {
            cur -> bottom = l2;
            cur = l2;
            l2 = l2 -> bottom;
        }
        cur -> bottom = NULL;
        return head;
    }
Node *flatten(Node *root) 
{
    Node * it = root -> next;
    Node *head = root;
    while( it ) {
        head = mergeTwoSortedLL( head , it );
        it = it -> next;
    }
    return head;
}






