#include <iostream>

using namespace std;

struct Node {
    int data;
    Node* next = nullptr;
};

void buildAndDestroy() {
    Node* head = new Node;
    Node* first = new Node;
    first->data=5;
    head = first;
    Node* second = new Node;
    second->data = 10;
    first->next = second;

    Node* curr = head;
    while (curr != nullptr) {
        std::cout << curr->data << "\n";
        delete curr;
        curr = curr->next;
    }

    std::cout << "Done. Last head data was: " << head->data << "\n";
}


// int sumList(const Node* head){
//     if (head == nullptr){
//         return 0;
//     }
//     int sum{};
//     while(head != nullptr){
//         sum += head->data;
//         head = head->next;
//     }
//     return sum;
// }


int main(){
    

    return 0;
}
