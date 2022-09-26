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


Node* partitionAroundX(Node* head, int x){
    Node* smaller_head = NULL;
    Node* equal_head = NULL;
    Node* bigger_head = NULL;
    
    Node* smaller_tail = NULL;
    Node* equal_tail = NULL;
    Node* bigger_tail = NULL;
    
    Node*p = head;
    
    while(p){
        if (p->val==x){
            if (equal_head==NULL){
                equal_head = equal_tail = p;
            }
            else{
                equal_tail->next = p;
                equal_tail = p;
            }
        }
        else if (p->val < x){
            if (smaller_head==NULL){
                smaller_head = smaller_tail = p;
            }
            else{
                smaller_tail->next = p;
                smaller_tail = p;
            }
        }
        else{
            if (bigger_head==NULL){
                bigger_head = bigger_tail = p;
            }
            else{
                bigger_tail->next = p;
                bigger_tail = p;
            }
        }
        p = p->next;
    }
    if(bigger_tail){
        bigger_tail->next = NULL;
    }
    
    if (smaller_head==NULL){
        if(equal_head==NULL){
            return bigger_head;
        }
        else{
            equal_tail->next = bigger_head;
            return equal_head;
        }
    }

    if(equal_head==NULL){
        smaller_tail->next = bigger_head;
        return smaller_head;
    }

    smaller_tail->next = equal_head;
    equal_tail->next = bigger_head;
    return smaller_head;
}
  
int main(){

    int n = 9;
    int a[n] = {5,4,7,3,8,1,6,2,0};
    
    struct Node* head = NULL; 
    for(int i=0;i<n;i++){
        addNodeAtEnd(a[i], &head);
    }
    cout<<"Input Traversal: ";
    traverseAndPrint(head);
    int x = 5;
    head = partitionAroundX(head, x);
    
    cout<<"Input Traversal: ";
    traverseAndPrint(head);
    
    return 0;
}
