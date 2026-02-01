#ifndef LISTBST_H
#define LISTBST_H

#include "BST.hpp"
#include <iostream>
#include <stdexcept>
using namespace std;

/**
 * Binary Search Tree implementation using linked list structure
 *
 * @tparam Key - The type of keys stored in the BST
 * @tparam Value - The type of values associated with keys
 */
template <typename Key, typename Value>
class ListBST : public BST<Key, Value>
{
private:
    /**
     * Node class for the binary search tree
     */
    class Node
    {
    public:
        Key key;
        Value value;
        Node *left;
        Node *right;

        Node(Key k, Value v)
        {
            key = k;
            value = v;
            left = nullptr;
            right = nullptr;
        }
    };

    Node *root;
    size_t node_count;
    int tree_height = 0; // height of BST

    // TODO: Implement private helper functions as needed
    // Start your private helper functions here

    int computeDepth(Key key) const
    {
        Node *current = root;
        int depth = 0;

        while (current != nullptr)
        {
            if (key == current->key)
                return depth;

            if (key < current->key)
                current = current->left;
            else
                current = current->right;

            depth++;
        }
        return -1;
    }
    void updateHeightOnInsert(Key key)
    {
        int d = computeDepth(key);
        if (d != -1 && d + 1 > tree_height)
            tree_height = d + 1;
    }
    bool insertWithHeight(Key key, Value value)
    {
        bool ok = insert(key, value); // existing function
        if (ok)
            updateHeightOnInsert(key);
        return ok;
    }

    void clearNode(Node *node)
    {
        if (node == nullptr)
        {
            return;
        }
        clearNode(node->left);
        clearNode(node->right);
        delete node;
    }
    Node *MinNode(Node *node)
    {
        Node *current = node;
        while (current && current->left != nullptr)
        {
            current = current->left;
        }
        return current;
    }
    Node *delNode(Node *root, Key key)
    {

        if (key < root->key)
        {
            root->left = delNode(root->left, key);
        }
        else if (key > root->key)
        {
            root->right = delNode(root->right, key);
        }
        else
        {

            if (root->left == nullptr)
            {
                Node *temp = root->right;
                delete root;
                return temp;
            }
            else if (root->right == nullptr)
            {
                Node *temp = root->left;
                delete root;
                return temp;
            }

            Node *temp = MinNode(root->right);
            root->key = temp->key;
            root->value = temp->value;
            root->right = delNode(root->right, temp->key);
        }
        return root;
    }
    void get_keys(Node *root, Key arr[], int &index)
    {
        if (root == nullptr)
        {
            return;
        }
        get_keys(root->left, arr, index);
        arr[index++] = root->key;
        get_keys(root->right, arr, index);
    }

    Node *searchBST(Node *root, Key key) const
    {
        if (root == nullptr)
        {
            return nullptr;
        }

        if (root->key == key)
        {
            return root;
        }
        else if (key < root->key)
        {
            return searchBST(root->left, key);
        }
        else
        {
            return searchBST(root->right, key);
        }
    }
    void inorderTraversal(Node *root) const
    {
        if (root == nullptr)
            return;

        inorderTraversal(root->left);

        cout << "(" << root->key << ":" << root->value << ") ";

        inorderTraversal(root->right);
    }

    void postorderTraversal(Node *root) const
    {
        if (root == nullptr)
            return;
        postorderTraversal(root->left);
        postorderTraversal(root->right);
        cout << "(" << root->key << ":" << root->value << ") ";
    }
    void preorderTraversal(Node *root) const
    {

        if (root == nullptr)
            return;
        cout << "(" << root->key << ":" << root->value << ") ";
        preorderTraversal(root->left);
        preorderTraversal(root->right);
    }
    void defaultTraversal(Node *root) const
    {

        // BST (Default): (8:8 () (10:10))
        if (root == nullptr)
        {

            return;
        }
        cout << "(" << root->key << ":" << root->value << " ";
        if (root->left || root->right)
        {
            cout << " ";
            if (root->left)
            {
                defaultTraversal(root->left);
            }
            else
            {
                cout << "()";
            }
        }
        if (root->right)
        {
            defaultTraversal(root->right);
        }
        else
        {
            cout << "()";
        }
        cout << ")";
    }
    // End your private helper functions here

public:
    /**
     * Constructor
     */
    ListBST() : root(nullptr), node_count(0) {}

    /**
     * Destructor
     */
    ~ListBST()
    {
        // TODO: Implement destructor to free memory
        clear();
    }
    int height() const
    {
        return tree_height;
    }
    int depth(Key key) const
    {
        return computeDepth(key);
    }
    int getInorderArray(Key arr[])
    {
        int index = 0;
        get_keys(root, arr, index);
        return index; // size of inorder traversal
    }
    bool isSubsequence(Key inorder[], int n, Key list[], int m)
    {
        int i = 0, j = 0;

        while (i < n && j < m)
        {
            if (inorder[i] == list[j])
                j++;
            i++;
        }

        return (j == m);
    }
    bool isSublist(Key inorder[], int n, Key list[], int m)
    {
        if (m > n)
            return false;

        for (int i = 0; i <= n - m; i++)
        {
            int j = 0;
            while (j < m && inorder[i + j] == list[j])
                j++;

            if (j == m)
                return true;
        }
        return false;
    }
    void checkList(Key list[], int m)//we call
    {
        Key inorder[1000]; // assume enough size
        int n = getInorderArray(inorder);

        if (isSublist(inorder, n, list, m))
            cout << "Sublist\n";
        else if (isSubsequence(inorder, n, list, m))
            cout << "Subsequence\n";
        else
            cout << "No Match\n";
    }

    /**
     * Insert a key-value pair into the BST
     */
    bool insert(Key key, Value value) override
    {
        // TODO: Implement insertion logic
        if (root == nullptr)
        {
            root = new Node(key, value);
            node_count++;
            return true;
        }

        Node *current = root;
        Node *prev = root;
        while (current != nullptr)
        {

            if (key < current->key)
            {
                prev = current;
                current = current->left;
            }
            else if (key > current->key)
            {
                prev = current;
                current = current->right;
            }
            else
            {
                return false;
            }
        }
        Node *newNode = new Node(key, value);

        if (key < prev->key)
        {
            prev->left = newNode;
        }
        else
        {
            prev->right = newNode;
        }
        node_count++;
        return true;
    }

    /**
     * Remove a key-value pair from the BST
     */
    bool remove(Key key) override
    {
        // TODO: Implement removal logic
        if (root == nullptr)
        {
            return false;
        }
        if (!find(key))
        {
            return false;
        }
        root = delNode(root, key);
        node_count--;
        return true;
    }

    /**
     * Find if a key exists in the BST
     */
    bool find(Key key) const override
    {
        // TODO: Implement find logic
        Node *find = searchBST(root, key);
        if (find == nullptr)
        {
            return false;
        }
        return true;
    }

    /**
     * Find a value associated with a given key
     */
    Value get(Key key) const override
    {
        // TODO: Implement get logic
        Node *get = searchBST(root, key);
        if (get == nullptr)
        {
            throw std::runtime_error("Key not found");
        }
        return get->value;
    }

    /**
     * Update the value associated with a given key
     */
    void update(Key key, Value value) override
    {
        // TODO: Implement update logic
        Node *update = searchBST(root, key);
        if (update == nullptr)
        {
            throw std::runtime_error("Key not found");
        }
        update->value = value;
    }

    /**
     * Clear all elements from the BST
     */

    void clear() override
    {
        // TODO: Implement clear logic
        clearNode(root);
        root = nullptr;
        node_count = 0;
    }

    /**
     * Get the number of keys in the BST
     */
    size_t size() const override
    {
        size_t size = node_count;
        return size;
    }

    /**
     * Check if the BST is empty
     */
    bool empty() const override
    {
        // TODO: Implement empty check logic
        if (node_count == 0)
        {
            return true;
        }
        return false;
    }

    /**
     * Find the minimum key in the BST
     */
    Key find_min() const override
    {
        // TODO: Implement find_min logic
        if (root == nullptr)
        {
            throw std::runtime_error("BST is empty");
        }
        Node *current = root;
        Node *prev = root;
        while (current != nullptr)
        {
            prev = current;
            current = current->left;
        }
        return prev->key;
    }

    /**
     * Find the maximum key in the BST
     */
    Key find_max() const override
    {
        // TODO: Implement find_max logic
        if (root == nullptr)
        {
            throw std::runtime_error("BST is empty");
        }
        Node *current = root;
        Node *prev = root;
        while (current != nullptr)
        {
            prev = current;
            current = current->right;
        }
        return prev->key;
    }
    void get_all_keys(Key arr[])
    {
        int index = 0;
        get_keys(root, arr, index);
    }

    /**
     * Print the BST using specified traversal method
     */
    void print(char traversal_type = 'D') const override
    {
        // TODO: Implement print logic
        switch (traversal_type)
        {
        case 'I':
        case 'i':
            inorderTraversal(root);
            break;
        case 'P':
        case 'p':

            preorderTraversal(root);
            break;
        case 'O':
        case 'o':
            postorderTraversal(root);
            break;
        case 'D':
        case 'd':
            defaultTraversal(root);
            break;
        default:
            throw std::invalid_argument("Invalid traversal type");
        }
    }
};

#endif // LISTBST_H