#include <iostream>
using namespace std;

class Node{
    public:
        int data;
        Node* next;
        Node* prev;
        Node(int d ,Node* n = NULL, Node* p = NULL):data(d) ,next(n) ,prev(p){}
};
void Print_List(Node* list){
    if(list == NULL){
        return;
    }
    cout << list->data << ' ';
    Print_List(list->next);
}
void append(Node* list , int x){
    Node* last = list;
    while(last->next != NULL){
        last = last->next;
    }
    Node* new_node = new Node(x , NULL , last);
    last->next = new_node;
}
int main(){
    Node a(5);
    for(int i = 0 ; i < 5 ; i++){
        int x;
        cin >> x;
        append(&a , x);
    }
    Print_List(&a);
    return 0;
}