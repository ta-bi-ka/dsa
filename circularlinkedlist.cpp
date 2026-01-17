#include<bits\stdc++.h>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
    Node(int val)
    {
        data = val;
        next = nullptr;
    }
};
class CircularLinkedList
{
    Node *head;
    Node *tail;
public:
    CircularLinkedList()
    {
        head = tail = nullptr;
    }   
    void push_back(int val)
    {
        Node *newNode = new Node(val);
        if (!head)
        {
            head = tail = newNode;
            tail->next = head; // Making it circular
            return;
        }
        tail->next = newNode;
        tail = newNode;
        tail->next = head; // Maintaining circular nature
    }
    void pop_front()
    {
        if (!head)
        {
            cout << "List is empty" << endl;
            return;
        }
        if (head == tail) // Only one node
        {
            delete head;
            head = tail = nullptr;
            return;
        }
        Node *temp = head;
        head = head->next;
        tail->next = head; // Maintaining circular nature
        delete temp;
    }
    void display()
    {
        if (!head)
        {
            cout << "List is empty" << endl;
            return;
        }
        Node *temp = head;
        do
        {
            cout << temp->data << " ";
            temp = temp->next;
        } while (temp != head);
        cout << endl;
    
        cout << "nullptr" << endl;
            temp = temp->next;
        
    }
    
    
};  
