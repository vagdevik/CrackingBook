#include<stdio.h>
#include<bits/stdc++.h>
#include <vector>
#include <map>
using namespace std;

struct Node{
    int val;
    struct Node* next;
    
    Node() {}
    Node(int val): val(val) {}

} ;

void addNodeAtEnd(int val, Node** head){
    Node* p = new Node(val);
    p->val = val;
    p->next = NULL;
    if( *head==NULL){
        *head = p;
    }
    else{
        Node* r = *head;
        while(r->next!=NULL){
            r = r->next;
        }
        r->next = p;
    }
}

void traverseAndPrint(Node *head){
    Node *p = head;
    while(p!=NULL){
        cout<<p->val<<" ";
        p = p->next;
    }
    cout<<"\n";
}

int getkthToLast(Node* head, int k){
    Node *slow = head;
    Node* fast = slow;
    int count = k;
    if(k==0){
        count = 1;
    }
    while(count--){
        fast = fast->next;
    }
    while(fast){
        slow = slow->next;
        fast = fast->next;
    }

    return slow->val;
}

int main(){

    int n = 9;
    int a[n] = {1,4,2,3,3,1,6,2,4};
    
    struct Node* head = NULL; 
    for(int i=0;i<n;i++){
        addNodeAtEnd(a[i], &head);
    }
    cout<<"Input Traversal: ";
    traverseAndPrint(head);
    int k = 0;
    int kthtoLast = getkthToLast(head, k);
    
    cout<<"kth element from last: "<< kthtoLast<<"\n";
    return 0;
}
