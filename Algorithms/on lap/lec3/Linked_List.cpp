#include <iostream>

using namespace std;

struct Node{
    int data;
    Node* next;

    Node (int value){
        data = value;
        next = nullptr;
    }
};

int main(){
    Node* first = new Node(10); // A
    Node* second = new Node(20); // B
    Node* third = new Node(30); // C

    Node* head = first;
    first->next=second;
    second->next=third;
    third->next=nullptr;

    Node* four = new Node(40);
    four->next = head->next;
    head->next=four;

    return 0;
}
