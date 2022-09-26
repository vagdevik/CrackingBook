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

void printy(map<int, int> m){
    for (auto i : m)
    {
    cout<<i.first<<" : "<<i.second<<" - ";
    }
    cout<<"\n";
}

void removeDuplicates(Node* head){
    Node* prev = head, *curr = prev->next;
    map<int, int>dupMap;
    if(prev==NULL){
        return ;
    }
    dupMap[prev->val] = 1;
    while(curr){
        cout<<"^^\n"<<curr->val<<"\n";
        if (dupMap[curr->val]==1){
            cout<<"Found duplicate, Entered if..."<<" prev is "<<prev->val<<" curr is "<<curr->val<<"\n";
            printy(dupMap);
           Node* t = curr->next;
           prev->next = curr->next;
           traverseAndPrint(head);
           free(curr);
           curr = t;
           
        }
        else{
            cout<<"no dup, adding entry into map\n";
            dupMap[curr->val] = 1;
            printy(dupMap);
            prev = curr;
            curr = curr->next;
        }
    }
    return;
    
}

int main(){

    int n = 9;
    int a[n] = {1,4,2,3,3,1,4,2,4};
    
    struct Node* head = NULL; 
    for(int i=0;i<n;i++){
        addNodeAtEnd(a[i], &head);
    }
    cout<<"Input Traversal: ";
    traverseAndPrint(head);
    
    removeDuplicates(head);
    
    cout<< "Output traversal: ";
    traverseAndPrint(head);
    return 0;
}
