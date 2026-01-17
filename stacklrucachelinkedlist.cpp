#include<bits\stdc++.h>
using namespace std;


class LRUCache {
    
public:
  class Node {
    public:
        int key;
        int value;
        Node* prev;
        Node* next;
        Node(int k, int v) : key(k), value(v), prev(nullptr), next(nullptr) {}
    };

    Node* head=new Node(-1,-1); 
    Node* tail=new Node(-1,-1);
   unordered_map<int, Node*> cache;
   int limit;
 void addNode(Node* node) {
       Node* oldNext = head->next;
        head->next = node;
        node->prev = head;
        node->next = oldNext;
        oldNext->prev = node;
    }
    void delNode(Node* node) {
        Node* prevNode = node->prev;
        Node* nextNode = node->next;
        prevNode->next = nextNode;
        nextNode->prev = prevNode;
    }
    LRUCache(int cap) {
        limit = cap;
        head->next = tail;
        tail->prev = head;

    }
    int get(int key) {
        if (cache.find(key) != cache.end()) {
            Node* node = cache[key];
            int val = node->value;
            cache.erase(key);
            delNode(node);
            addNode(node);
            cache[key] = node;
            return val;
        }
        return -1;
    
    }
    void put(int key, int value) {

    // If key exists: delete old node
    if (cache.find(key) != cache.end()) {
        Node* existingNode = cache[key];
        delNode(existingNode);
        cache.erase(key);
    }

    // If capacity full: remove LRU node (tail->prev)
    if (cache.size() == limit) {
        Node* lru = tail->prev;
        cache.erase(lru->key);
        delNode(lru);
    }

    // Add new node at front
    Node* newNode = new Node(key, value);
    addNode(newNode);
    cache[key] = newNode;
}

};
