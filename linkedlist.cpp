#include <bits\stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node *random; // for copy with random pointer
    Node(int val)
    {
        data = val;
        next = nullptr;
        random = nullptr;
    }
};

class List
{
    Node *tail;
    Node *head;

public:
    List()
    {
        head = tail = NULL;
    }
    void push_front(int val)
    {
        Node *newNode = new Node(val); // dynamic allocation
        // Node newNode(val);//static allocation
        if (!head)
        {
            head = tail = newNode;
            return;
        }
        else
        {
            newNode->next = head; //(*newNode).next=head
            head = newNode;
        }
    }

    void printList()
    {
        Node *temp = head;
        while (temp)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }

    void push_back(int val)
    {
        Node *newNode = new Node(val);
        if (!head)
        {
            head = tail = newNode;
            return;
        }
        else
        {
            tail->next = newNode;
            tail = newNode;
        }
    }

    void pop_front()
    {
        if (!head)

        {

            cout << "List is empty" << endl;
            return;
        }

        Node *temp = head;
        head = head->next;
        delete temp;
    }

    void pop_back()
    {
        if (!head)
        {
            cout << "List is empty" << endl;
            return;
        }
        if (head == tail)
        {
            delete head;
            head = tail = NULL;
            return;
        }
        Node *temp = head;
        while (temp->next != tail)
        {
            temp = temp->next;
        }
        delete tail;
        tail = temp;
        tail->next = NULL;
    }

    // insert at position
    void insert_at_position(int val, int pos)
    {

        if (!head || pos < 0)
        {
            cout << "List is empty or invalid position" << endl;
            return;
        }
        if (pos == 0)
        {
            push_front(val);
            return;
        }
        Node *newNode = new Node(val);
        Node *temp = head;
        for (int i = 0; i < pos - 1; i++)
        {
            if (temp == NULL)
            {
                cout << "Position out of bounds" << endl;
                delete newNode;
                return;
            }
            temp = temp->next;
        }
        newNode->next = temp->next;
        temp->next = newNode;
        if (newNode->next == NULL)
        {
            tail = newNode;
        }
    }
    // search
    int search(int key)
    {
        Node *temp = head;
        int pos = 0;
        while (temp)
        {
            if (temp->data == key)
            {
                return pos;
            }
            temp = temp->next;
            pos++;
        }
        return -1; // not found
    }
    // reverse
    Node *reverse(Node *head)
    {
        Node *prev = NULL;
        Node *current = head;
        Node *next = NULL;
        // tail = head; // new tail will be the old head
        while (current != NULL)
        {
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }
        return prev;
    }

    // middle element
    Node *middle_element(Node *head)
    {
        Node *slow = head;
        Node *fast = head;
        while (fast != NULL && fast->next != NULL)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }

    // getter for head
    Node *getHead()
    {
        return head;
    }

    // detect and remove cycle in linked list
    bool has_cycle()
    {
        Node *slow = head;
        Node *fast = head;

        while (fast != NULL && fast->next != NULL)
        {
            slow = slow->next;
            fast = fast->next->next;

            if (slow == fast)
            {
                return true;
            }
        }
        return false;
    }
    Node *detectCycle(Node *head)
    {
        Node *slow = head;
        Node *fast = head;
        bool cycle_found = false;

        while (fast != NULL && fast->next != NULL)
        {
            slow = slow->next;
            fast = fast->next->next;

            if (slow == fast)
            {
                cycle_found = true;
                break; // cycle detected
            }
        }

        if (cycle_found)
        {
            slow = head;
            while (slow != fast)
            {
                slow = slow->next;
                fast = fast->next;
            }
            return slow; // starting node of cycle
        }
        return NULL; // no cycle
    }

    void detect_and_remove_cycle()
    {
        Node *slow = head;
        Node *fast = head;
        bool cycle_found = false;

        while (fast != NULL && fast->next != NULL)
        {
            slow = slow->next;
            fast = fast->next->next;

            if (slow == fast)
            {
                cycle_found = true;
                break;
            }
        }

        if (cycle_found)
        {
            slow = head;
            Node *prev = nullptr;

            while (slow != fast)
            {
                prev = fast;
                slow = slow->next;
                fast = fast->next;
            }

            // Remove cycle
            prev->next = NULL;
        }
    }

    // merge two sorted linked lists
    Node *merge_sorted_lists(Node *l1, Node *l2)
    {
        if (!l1)
            return l2;
        if (!l2)
            return l1;

        if (l1->data <= l2->data)
        {
            l1->next = merge_sorted_lists(l1->next, l2);
            return l1;
        }
        else
        {
            l2->next = merge_sorted_lists(l1, l2->next);
            return l2;
        }
    }
    // copy list with random pointer
    //...

    Node *copy_list_with_random_pointer(Node *head)
    {
        if (!head)
            return nullptr;

        unordered_map<Node *, Node *> m;
        Node *newHead = new Node(head->data);
        Node *oldTemp = head->next;
        Node *newTemp = newHead;

        m[head] = newHead;
        // First pass: create copies of nodes and store in map
        while (oldTemp)
        {
            Node *copyNode = new Node(oldTemp->data);
            m[oldTemp] = copyNode;
            newTemp->next = copyNode;
            newTemp = newTemp->next;
            oldTemp = oldTemp->next;
        }

        oldTemp = head;
        newTemp = newHead;
        // Second pass: assign random pointers
        while (oldTemp)
        {

     newTemp->random = m[oldTemp->random];

            oldTemp = oldTemp->next;
            newTemp = newTemp->next;
        }

        return newHead;
    }
};
int main()
{
    List myList;
    myList.push_front(10);
    myList.push_front(20);
    myList.push_front(30);
    myList.printList();

    myList.push_back(5);
    myList.push_back(1);
    myList.printList();
    myList.pop_front();
    myList.printList();
    myList.pop_back();
    myList.printList();
    myList.insert_at_position(15, 2);
    myList.printList();

    myList.insert_at_position(25, 0);
    myList.printList();

    cout << "Position of 15: " << myList.search(15) << endl;
    cout << "Position of 100: " << myList.search(100) << endl;
    // Reverse the list
    // find head
    Node *head = myList.getHead();
    myList.reverse(head);
    myList.printList();
    // Find middle element
    Node *middle = myList.middle_element(head);

    if (middle)
        cout << "Middle element: " << middle->data << endl;
    else
        cout << "List is empty" << endl;

    // detect cycle
    if (myList.has_cycle())
        cout << "Cycle detected" << endl;
    else
        cout << "No cycle detected" << endl;

    return 0;
}
