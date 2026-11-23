#include <iostream>

using namespace std;

class SinglyLinkedList {
private:
    struct Node {
        int data;
        Node* next;
        explicit Node(int val, Node* nextNode = nullptr)
            : data(val), next(nextNode) {}
    };

    Node* head;
    Node* tail;
    int count;


    Node* getMiddle(Node* start) const {
        Node* slow = start;
        Node* fast = start->next;
        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }

    Node* mergeSorted(Node* left, Node* right) {
        Node dummy(0);
        Node* curr = &dummy;

        while (left != nullptr && right != nullptr) {
            if (left->data <= right->data) {
                curr->next = left;
                left = left->next;
            } else {
                curr->next = right;
                right = right->next;
            }
            curr = curr->next;
        }
        curr->next = (left != nullptr) ? left : right;
        return dummy.next;
    }

    Node* mergeSort(Node* start) {
        if (start == nullptr || start->next == nullptr) {
            return start;
        }

        Node* mid = getMiddle(start);
        Node* rightHalf = mid->next;
        mid->next = nullptr;

        Node* sortedLeft = mergeSort(start);
        Node* sortedRight = mergeSort(rightHalf);
        return mergeSorted(sortedLeft, sortedRight);
    }

public:
    SinglyLinkedList() : head(nullptr), tail(nullptr), count(0) {}

    ~SinglyLinkedList() {
        clear();
    }

    SinglyLinkedList(const SinglyLinkedList&) = delete;
    SinglyLinkedList& operator=(const SinglyLinkedList&) = delete;


    void pushFront(int val) {
        head = new Node(val, head);
        if (tail == nullptr) {
            tail = head;
        }
        ++count;
    }

    void pushBack(int val) {
        if (head == nullptr) {
            head = tail = new Node(val);
        } else {
            tail->next = new Node(val);
            tail = tail->next;
        }
        ++count;
    }

    bool insertAt(int index, int val) {
        if (index < 0 || index > count) return false;
        if (index == 0) { pushFront(val); return true; }
        if (index == count) { pushBack(val); return true; }

        Node* curr = head;
        for (int i = 0; i < index - 1; ++i) {
            curr = curr->next;
        }

        curr->next = new Node(val, curr->next);
        ++count;
        return true;
    }


bool popFront() {
        if (head == nullptr) return false;

        Node* old = head;
        head = head->next;
        delete old;

        if (head == nullptr) {
            tail = nullptr;
        }
        --count;
        return true;
    }

    bool popBack() {
        if (head == nullptr) return false;

        if (head == tail) {
            delete head;
            head = tail = nullptr;
            count = 0;
            return true;
        }

        Node* curr = head;
        while (curr->next != tail) {
            curr = curr->next;
        }

        delete tail;
        tail = curr;
        tail->next = nullptr;
        --count;
        return true;
    }

    bool popAt(int index) {
        if (index < 0 || index >= count) return false;
        if (index == 0) return popFront();
        if (index == count - 1) return popBack();

        Node* curr = head;
        for (int i = 0; i < index - 1; ++i) {
            curr = curr->next;
        }

        Node* old = curr->next;
        curr->next = old->next;
        delete old;
        --count;
        return true;
    }

    bool removeByValue(int val) {
        if (head == nullptr) return false;
        if (head->data == val) return popFront();

        Node* curr = head;
        while (curr->next != nullptr && curr->next->data != val) {
            curr = curr->next;
        }
        if (curr->next == nullptr) return false;

        if (curr->next == tail) {
            delete tail;
            tail = curr;
            tail->next = nullptr;
        } else {
            Node* old = curr->next;
            curr->next = old->next;
            delete old;
        }
        --count;
        return true;
    }


    void sort() {
        if (count <= 1) return;

        head = mergeSort(head);

        tail = head;
        while (tail->next != nullptr) {
            tail = tail->next;
        }
    }

    void clear() {
        while (head != nullptr) {
            popFront();
        }
        tail = nullptr;
        count = 0;
    }

    void print() const {
        const Node* curr = head;
        while (curr != nullptr) {
            cout << curr->data << " -> ";
            curr = curr->next;
        }
        cout << "nullptr (size=" << count << ")\n";
    }
};

class DoublyLinkedList {
private:
    struct Node {
        int data;
        Node* prev;
        Node* next;
        explicit Node(int val, Node* prevNode = nullptr, Node* nextNode = nullptr)
            : data(val), prev(prevNode), next(nextNode) {}
    };

    Node* head;
    Node* tail;
    int count;

    Node* getNodeAt(int index) const {
        Node* curr = nullptr;
        if (index <= count / 2) {
            curr = head;
            for (int i = 0; i < index; ++i) {
                curr = curr->next;
            }
        } else {
            curr = tail;
            for (int i = count - 1; i > index; --i) {
                curr = curr->prev;
            }
        }
        return curr;
    }

public:
    DoublyLinkedList() : head(nullptr), tail(nullptr), count(0) {}

    ~DoublyLinkedList() {
        clear();
    }

    DoublyLinkedList(const DoublyLinkedList&) = delete;
    DoublyLinkedList& operator=(const DoublyLinkedList&) = delete;


    void pushFront(int val) {
        if (head == nullptr) {
            head = tail = new Node(val);
        } else {
            head->prev = new Node(val, nullptr, head);
            head = head->prev;
        }
        ++count;
    }

    void pushBack(int val) {
        if (tail == nullptr) {
            head = tail = new Node(val);
        } else {
            tail->next = new Node(val, tail, nullptr);
            tail = tail->next;
        }
        ++count;
    }

    bool insertAt(int index, int val) {
        if (index < 0 || index > count) return false;
        if (index == 0) { pushFront(val); return true; }
        if (index == count) { pushBack(val); return true; }

        Node* curr = getNodeAt(index);

        curr->prev->next = new Node(val, curr->prev, curr);
        curr->prev = curr->prev->next;
        ++count;
        return true;
    }


    bool popFront() {
        if (head == nullptr) return false;

        if (head == tail) {
            delete head;
            head = tail = nullptr;
        } else {
            head = head->next;
            delete head->prev;
            head->prev = nullptr;
        }
        --count;
        return true;
    }

    bool popBack() {
        if (tail == nullptr) return false;

        if (head == tail) {
            delete tail;
            head = tail = nullptr;
        } else {
            tail = tail->prev;
            delete tail->next;
            tail->next = nullptr;
        }
        --count;
        return true;
    }

    bool popAt(int index) {
        if (index < 0 || index >= count) return false;
        if (index == 0) return popFront();
        if (index == count - 1) return popBack();

        Node* curr = getNodeAt(index);

        curr->prev->next = curr->next;
        curr->next->prev = curr->prev;
        delete curr;
        --count;
        return true;
    }

    bool removeByValue(int val) {
        Node* curr = head;
        while (curr != nullptr && curr->data != val) {
            curr = curr->next;
        }
        if (curr == nullptr) return false;
        if (curr == head) return popFront();
        if (curr == tail) return popBack();

        curr->prev->next = curr->next;
        curr->next->prev = curr->prev;
        delete curr;
        --count;
        return true;
    }

    void clear() {
        while (head != nullptr) {
            popFront();
        }
    }

    void printForward() const {
        const Node* curr = head;
        cout << "Forward:  nullptr <- ";
        while (curr != nullptr) {
            cout << curr->data << (curr->next ? " <-> " : " -> ");
            curr = curr->next;
        }
        cout << "nullptr (size=" << count << ")\n";
    }

    void printBackward() const {
        const Node* curr = tail;
        cout << "Backward: nullptr <- ";
        while (curr != nullptr) {
            cout << curr->data << (curr->prev ? " <-> " : " -> ");
            curr = curr->prev;
        }
        cout << "nullptr\n";
    }
};

int main() {
    cout << "=== 1. Singly Linked List (Direct + Merge Sort) ===\n";
    SinglyLinkedList sll;
    sll.pushBack(40);
    sll.pushFront(10);
    sll.pushBack(20);
    sll.insertAt(1, 50); // 10 -> 50 -> 40 -> 20
    sll.insertAt(4, 30); // 10 -> 50 -> 40 -> 20 -> 30
    cout << "Before sort: ";
    sll.print();

    sll.sort();
    cout << "After sort:  ";
    sll.print();         // 10 -> 20 -> 30 -> 40 -> 50

    sll.popFront();      // حذف 10
    sll.popBack();       // حذف 50
    sll.popAt(1);        // حذف 30
    sll.removeByValue(40);
    cout << "After deletions: ";
    sll.print();         // 20 -> nullptr

    cout << "\n=== 2. Doubly Linked List (Direct + prev Navigation) ===\n";
    DoublyLinkedList dll;
    dll.pushBack(10);
    dll.pushBack(30);
    dll.pushBack(50);
    dll.pushFront(5);
    dll.insertAt(2, 20); // 5 <-> 10 <-> 20 <-> 30 <-> 50
    dll.insertAt(4, 40); // 5 <-> 10 <-> 20 <-> 30 <-> 40 <-> 50
    dll.printForward();
    dll.printBackward();

    dll.popFront();      // حذف 5
    dll.popBack();       // حذف 50
    dll.popAt(2);        // حذف 30 (يصل إليها عبر tail->prev مباشرة)
    cout << "After deletions:\n";
    dll.printForward();  // 10 <-> 20 <-> 40
    dll.printBackward(); // 40 <-> 20 <-> 10

    return 0;
}
