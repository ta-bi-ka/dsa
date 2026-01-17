#include <bits\stdc++.h>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
    Node *prev;  // for copy with random pointer
    Node *child; // pointer to child list
    Node(int val)
    {
        data = val;
        next = nullptr;
        prev = nullptr;
    }
};

class DoublyLinkedList
{
    Node *head;
    Node *tail;

public:
    DoublyLinkedList()
    {
        head = tail = nullptr;
    }
    // Other member functions like push_front, push_back, pop_front, pop_back, etc.
    void push_front(int val)
    {
        Node *newNode = new Node(val);
        if (!head)
        {
            head = tail = newNode;
            return;
        }
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }
    void push_back(int val)
    {
        Node *newNode = new Node(val);
        if (!head)
        {
            head = tail = newNode;
            return;
        }
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
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
        if (head)
            head->prev = nullptr;
        else
            tail = nullptr; // List became empty
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
            head = tail = nullptr;
            return;
        }
        Node *temp = tail;
        tail = tail->prev;
        tail->next = nullptr;
        delete temp;
    }
    void printList()
    {
        Node *temp = head;
        while (temp)
        {
            cout << temp->data << " <-> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }
    // Additional functions like insert_at_position, search, etc. can be added similarly

    // flatten a doubly linked list with child pointers

    Node *flatten(Node *head)
    {
        if (!head)
            return nullptr;

        Node *curr = head;

        while (curr)
        {
            if (curr->child)
            {
                // Append the child list to the end of the main list
                Node *next = curr->next;
                curr->next = flatten(curr->child);

                curr->next->prev = curr;
                curr->child = nullptr;
                // Connect the next part
                while (curr->next)
                {
                    curr = curr->next;
                }

                if (next)
                {
                    curr->next = next;
                    next->prev = curr;
                }
            }
            curr = curr->next;
        }

        return head;
    }

    // swap nodes in a doubly linked list
    Node *swapPairs(Node *head)
    {
        if (!head || !head->next)
            return head;

        Node *first = head;
        Node *second = head->next;
        Node *prev = nullptr;

        while (first && second)
        {
            Node *third = second->next;
            second->next = first;
            first->next = third;
            if (prev)
            {
                prev->next = second;
            }
            else
            {
                head = second; // Update head for the first swap
            }

            prev = first;
            first = third;

            if (third)
            {
                second = third->next;
            }
            else
            {
                second = nullptr;
            }
        }
        return head;
    }
    //reverse nodes in k groups
    Node *reverseKGroup(Node *head, int k)
    {
        Node *temp=head;
        int count=0;
        while(count<k)
        {
            if(!temp)
                return head;
            temp=temp->next;
        
        }

       Node *prev=reverseKGroup(temp,k);
       temp=head;
       count=0;
         while(count<k)
         {
              Node *next=temp->next;
              temp->next=prev;
              prev=temp;
              temp=next;
              count++;
         }
         return prev;
    }
};

int main()
{
    DoublyLinkedList myList;
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

    return 0;
}