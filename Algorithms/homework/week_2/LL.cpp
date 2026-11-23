#include <iostream>
#include <climits>

using namespace std;

class Node
{
public:
    int data;
    Node* next;

    Node(int _data)
    {
        this->data = _data;
        this->next = nullptr;
    }
};

class LinkedList
{
private:
    int length;

public:
    Node* head;
    Node* tail;

    // Constructor
    LinkedList()
    {
        this->head = this->tail = nullptr;
        this->length = 0;
    }

    // Destructor to prevent memory leaks
    ~LinkedList()
    {
        Node* current = this->head;
        while (current != nullptr)
        {
            Node* nextNode = current->next;
            delete current;
            current = nextNode;
        }
        this->head = this->tail = nullptr;
        this->length = 0;
    }

    void PrintLinkedList()
    {
        Node* iter = this->head;
        while (iter != nullptr)
        {
            cout << iter->data << " => ";
            iter = iter->next;
        }
        cout << "NULL\n";
    }

    void InsertLast(Node* newNode)
    {
        if (newNode == nullptr) return;
        newNode->next = nullptr;

        if (this->head == nullptr)
        {
            this->head = newNode;
            this->tail = newNode;
        }
        else
        {
            this->tail->next = newNode;
            this->tail = newNode;
        }
        this->length++;
    }

    void InsertAfter(Node* node, Node* newNode)
    {
        // Validation
        if (node == nullptr || newNode == nullptr) return;

        newNode->next = node->next;
        node->next = newNode;

        // Update tail if the new node is added at the end
        if (newNode->next == nullptr)
            this->tail = newNode;

        this->length++;
    }

    Node* GetPreviousNode(Node* node)
    {
        Node* iter = this->head;
        while (iter != nullptr && iter->next != node)
            iter = iter->next;
        return iter;
    }

    void InsertBefore(Node* node, Node* newNode)
    {
        // Validation
        if (node == nullptr || newNode == nullptr) return;

        if (this->head == node)
        {
            newNode->next = node;
            this->head = newNode;
        }
        else
        {
            // Find the node right before the target node
            Node* prevNode = this->GetPreviousNode(node);
            if (prevNode == nullptr)
                return;

            newNode->next = node;
            prevNode->next = newNode;
        }
        this->length++;
    }

    void DeleteNode(Node* node)
    {
        // Validation
        if (node == nullptr || this->head == nullptr)
            return;

        // Case: Only one node exists in the list
        if (this->head == this->tail && this->head == node)
        {
            this->head = nullptr;
            this->tail = nullptr;
        }
        else if (this->head == node)
        {
            this->head = node->next;
        }
        else
        {
            Node* prevNode = this->GetPreviousNode(node);
            if (prevNode == nullptr)
                return;

            // Case: Deleting the tail node, update tail pointer and clear next
            if (this->tail == node)
            {
                this->tail = prevNode;
                this->tail->next = nullptr;
            }
            else
            {
                prevNode->next = node->next;
            }
        }

        delete node;
        this->length--;
    }

    Node* FindNode(int _data)
    {
        Node* node = this->head;
        while (node != nullptr)
        {
            if (node->data == _data)
                return node;
            node = node->next;
        }
        return nullptr;
    }

    // ==========================================
    // Practice Exercises Implementation
    // ==========================================

    // 1. Find Maximum Value
    int GetMax()
    {
        if (this->head == nullptr)
        {
            cerr << "List is empty!\n";
            return INT_MIN;
        }

        int maxVal = this->head->data;
        Node* iter = this->head->next;
        while (iter != nullptr)
        {
            if (iter->data > maxVal)
                maxVal = iter->data;
            iter = iter->next;
        }
        return maxVal;
    }

    // 1. Find Minimum Value
    int GetMin()
    {
        if (this->head == nullptr)
        {
            cerr << "List is empty!\n";
            return INT_MAX;
        }

        int minVal = this->head->data;
        Node* iter = this->head->next;
        while (iter != nullptr)
        {
            if (iter->data < minVal)
                minVal = iter->data;
            iter = iter->next;
        }
        return minVal;
    }

    // 2. Delete by Value
    void DeleteByValue(int _data)
    {
        Node* targetNode = this->FindNode(_data);
        if (targetNode != nullptr)
        {
            this->DeleteNode(targetNode);
        }
    }

    // 3. Reverse the Linked List
    void Reverse()
    {
        if (this->head == nullptr || this->head == this->tail)
            return;

        Node* prev = nullptr;
        Node* curr = this->head;
        Node* next = nullptr;

        // Current head will become the new tail after reversal
        this->tail = this->head;

        while (curr != nullptr)
        {
            next = curr->next; // Save next node
            curr->next = prev; // Reverse current node's pointer
            prev = curr;       // Move prev one step forward
            curr = next;       // Move curr one step forward
        }

        // Update head to the last processed node
        this->head = prev;
    }

    // 4. Find the Middle Node (Two-Pointer Approach)
    Node* GetMiddleNode()
    {
        if (this->head == nullptr)
            return nullptr;

        Node* slow = this->head;
        Node* fast = this->head;

        while (fast != nullptr && fast->next != nullptr)
        {
            slow = slow->next;
            fast = fast->next->next;
        }

        return slow;
    }
};

int main()
{
    // Create an empty linked list
    LinkedList list;

    // Insert elements at the end
    list.InsertLast(new Node(10));
    list.InsertLast(new Node(20));
    list.InsertLast(new Node(30));

    cout << "Initial List: ";
    list.PrintLinkedList(); // Output: 10 => 20 => 30 => NULL

    // Find a specific node (e.g., node with data 20)
    Node* targetNode = list.FindNode(20);
    if (targetNode != nullptr)
    {
        // Insert a new node after the target node
        list.InsertAfter(targetNode, new Node(25));
        // Insert a new node before the target node
        list.InsertBefore(targetNode, new Node(15));
    }

    cout << "After Insertions: ";
    list.PrintLinkedList(); // Output: 10 => 15 => 20 => 25 => 30 => NULL

    // Delete a node from the list (e.g., node with data 25)
    Node* nodeToDelete = list.FindNode(25);
    if (nodeToDelete != nullptr)
    {
        list.DeleteNode(nodeToDelete);
    }

    cout << "After Deletion: ";
    list.PrintLinkedList(); // Output: 10 => 15 => 20 => 30 => NULL

    // ==========================================
    // Testing Practice Exercises
    // ==========================================
    cout << "\n--- Practice Exercises Tests ---\n";

    // 1. Test GetMax and GetMin
    cout << "Max Value: " << list.GetMax() << "\n"; // Output: 30
    cout << "Min Value: " << list.GetMin() << "\n"; // Output: 10

    // 4. Test GetMiddleNode
    list.InsertLast(new Node(40)); // List becomes: 10 => 15 => 20 => 30 => 40 => NULL
    cout << "List after adding 40: ";
    list.PrintLinkedList();

    Node* midNode = list.GetMiddleNode();
    if (midNode != nullptr)
        cout << "Middle Node: " << midNode->data << "\n"; // Output: 20

    // 2. Test DeleteByValue
    list.DeleteByValue(15);
    cout << "After DeleteByValue(15): ";
    list.PrintLinkedList(); // Output: 10 => 20 => 30 => 40 => NULL

    // 3. Test Reverse
    list.Reverse();
    cout << "After Reverse: ";
    list.PrintLinkedList(); // Output: 40 => 30 => 20 => 10 => NULL
    cout << "New Head: " << list.head->data << ", New Tail: " << list.tail->data << "\n";

    return 0;
}
