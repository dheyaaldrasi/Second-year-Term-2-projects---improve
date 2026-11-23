#include <iostream>

using namespace std;

struct Node{
    int data;
    Node* next;

    explicit Node(int value){
        data = value;
        next = nullptr;
    }
};

int main(){
    Node* first = new Node(10);
    Node* second = new Node(20);
    Node* third = new Node(30);

    Node* head = first;
    first->next = second;
    second->next = third;

    cout << third->next << endl;
    cout << sizeof(Node)  << " /bytes" << endl;
    cout << sizeof(int)  << " /bytes" << endl;

    return 0;
}
