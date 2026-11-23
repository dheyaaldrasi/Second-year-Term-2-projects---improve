#include <iostream>

using namespace std;

struct Node{
    int value = 0;
    Node* next; // pointing to the next node
};

Node* head = nullptr;

void addNode(int data){
    Node* last;
    Node* newNode = new Node; // create the node box
    newNode->value = data;
    if(head == nullptr){
        newNode->next = head; // because the head = nullptr
        head = newNode; // they both are pointers, no need for &
        // newNode->next = nullptr;
        cout << "First node created" << endl;
        return;
    }
    if(head != nullptr){
        last = head;
        while(last->next != nullptr){
            last = last->next;
        }
        last->next = newNode; // the last node points to the new node
        newNode->next = nullptr; // the new node pointes to null because it`s the last node
        cout<< "new node created at last." << endl;
    }
}

void Display(){
    if(head == nullptr){
        cout << "Linked List is empty." << endl;
        return;
    }
    if (head != nullptr){
        Node* currentNode;
        currentNode = head;
        while(currentNode != nullptr){
            cout << currentNode->value << endl;
            currentNode = currentNode->next;
        }
    }
}





int main(){
    addNode(206);
    addNode(12);
    addNode(15);
    Display();

    cout << sizeof(Node) << endl;

    return 0;
}
