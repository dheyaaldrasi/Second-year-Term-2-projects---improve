#include <iostream>

using namespace std;

class SinglyLinkedList {
private:
    struct Node {
        int data;
        Node* next;
        explicit Node(int val) : data(val), next(nullptr) {}
    };

    Node* head;
    Node* tail;
    int count;

public:
    SinglyLinkedList() : head(nullptr), tail(nullptr), count(0) {}

    ~SinglyLinkedList() {
        clear();
    }

    SinglyLinkedList(const SinglyLinkedList&) = delete;
    SinglyLinkedList& operator=(const SinglyLinkedList&) = delete;
    // SinglyLinkedList* operator new(const SinglyLinkedList&) = delete;

    void pushFront(int val) {
        Node* newNode = new Node(val);
        newNode->next = head;
        head = newNode;

        if (tail == nullptr) {
            tail = newNode;
        }
        ++count;
    }

    void pushBack(int val) {
        Node* newNode = new Node(val);
        if (tail == nullptr) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
        ++count;
    }

    bool insertAt(int index, int val) {
        if (index < 0 || index > count) {
            return false;
        }
        if (index == 0) {
            pushFront(val);
            return true;
        }
        if (index == count) {
            pushBack(val);
            return true;
        }

        Node* prev = head;
        for (int i = 0; i < index - 1; ++i) {
            prev = prev->next;
        }

        Node* newNode = new Node(val);
        newNode->next = prev->next;
        prev->next = newNode;
        ++count;
        return true;
    }

    bool popFront() {
        if (head == nullptr) {
            return false;
        }

        Node* oldHead = head;
        head = head->next;
        delete oldHead;
        --count;

        if (head == nullptr) {
            tail = nullptr;
        }
        return true;
    }

    bool popBack() {
        if (head == nullptr) {
            return false;
        }

        if (head == tail) {
            delete head;
            head = tail = nullptr;
            count = 0;
            return true;
        }

        Node* prev = head;
        while (prev->next != tail) {
            prev = prev->next;
        }

        delete tail;
        tail = prev;
        tail->next = nullptr;
        --count;
        return true;
    }

    bool removeByValue(int val) {
        if (head == nullptr) {
            return false;
        }

        if (head->data == val) {
            return popFront();
        }

        Node* prev = head;
        while (prev->next != nullptr && prev->next->data != val) {
            prev = prev->next;
        }

        if (prev->next == nullptr) {
            return false;
        }

        Node* target = prev->next;
        prev->next = target->next;

        if (target == tail) {
            tail = prev;
        }

        delete target;
        --count;
        return true;
    }

    // 7. البحث الخطي (يُرجع الفهرس أو -1 إذا لم يُوجد) — O(n)
    int search(int val) const {
        const Node* curr = head;
        int index = 0;
        while (curr != nullptr) {
            if (curr->data == val) {
                return index;
            }
            curr = curr->next;
            ++index;
        }
        return -1;
    }

    // 8. التصفح والطباعة — O(n)
    void print() const {
        const Node* curr = head;
        while (curr != nullptr) {
            std::cout << curr->data << " -> ";
            curr = curr->next;
        }
        std::cout << "nullptr (size=" << count << ")\n";
    }

    // 9. تحرير جميع العقد — O(n)
    void clear() {
        while (head != nullptr) {
            Node* nextNode = head->next;
            delete head;
            head = nextNode;
        }
        tail = nullptr;
        count = 0;
    }

    int size() const { return count; }
    bool empty() const { return count == 0; }
};

int main() {
    SinglyLinkedList list;
    list.pushBack(10);
    list.pushBack(30);
    list.pushFront(5);
    list.insertAt(2, 20);   // 5 -> 10 -> 20 -> 30
    list.print();

    list.removeByValue(30); // حذف الـ tail
    list.popFront();        // حذف الـ head
    list.print();           // 10 -> 20 -> nullptr

    std::cout << "Index of 20: " << list.search(20) << "\n";
    return 0; // يُستدعى ~SinglyLinkedList() تلقائياً هنا دون أي تسريب
}
