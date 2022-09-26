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

int sumLists(Node* list1, Node* list2){
    Node* p1 = list1;
    Node* p2 = list2;
    int sum = 0, count = 0, carry = 0;
    while(p1!=NULL && p2!=NULL){
        int digit = (p1->val + p2->val+ carry)%10;
        carry = (p1->val + p2->val+ carry)/10;
        sum = sum + digit*pow(10, count);
        // cout<< p1->val<< " "<<p2->val<<" "<<pow(10, count)<<" "<< sum<<"\n";
        p1 = p1->next;
        p2 = p2->next;
        count++;
    }
    while(p1){
        int digit = (p1->val + carry)%10;
        carry = (p1->val + carry)/10;
        sum = sum + digit*pow(10, count);
        // cout<< p1->val<< " "<<pow(10, count)<<" "<< sum<<"\n";
        p1 = p1->next;
        count++;
    }
    while(p2){
        int digit = (p2->val+ carry)%10;
        carry = (p2->val+ carry)/10;
        sum = sum + digit*pow(10, count);
        // cout<< p2->val<<" "<<pow(10, count)<<" "<< sum<<"\n";
        p2 = p2->next;
        count++;
    }
    sum = sum + carry*pow(10, count);
    return sum;
}

  
/*  
(7->1->6) + (5->9->2) => 617+295 = 912
*/

int main(){

    int n = 9;
    struct Node* list1 = NULL; 
    struct Node* list2 = NULL;
    // // Testcase 1:
    // int a[n] = {7,1,6};
    // int b[n] = {5,9,2};
    // for(int i=0;i<3;i++){
    //     addNodeAtEnd(a[i], &list1);
    //     addNodeAtEnd(b[i], &list2);
    // }
    
    // // Testcase 2:
    // int a[n] = {7,1,6};
    // int b[n] = {8,2};
    // for(int i=0;i<3;i++){
    //     addNodeAtEnd(a[i], &list1);
    // }
    // for(int i=0;i<2;i++){
    //     addNodeAtEnd(b[i], &list2);
    // }
    
    // // Testcase 3:
    // int a[n] = {8,2};
    // int b[n] = {7,1,6};
    // for(int i=0;i<2;i++){
    //     addNodeAtEnd(a[i], &list1);
    // }
    // for(int i=0;i<3;i++){
    //     addNodeAtEnd(b[i], &list2);
    // }
    
    // // Testcase 4:
    int a[n] = {1,9,9};
    int b[n] = {2,1,2};
    for(int i=0;i<3;i++){
        addNodeAtEnd(a[i], &list1);
    }
    for(int i=0;i<3;i++){
        addNodeAtEnd(b[i], &list2);
    }
    

    int sum = sumLists(list1, list2);
    
    cout<< "Sum is: "<< sum<<"\n";
    
    return 0;
}
