
#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;
    Node *prev; //
    Node *next; // for populating next right pointers

    Node(int val)
    {
        data = val;
        left = nullptr;
        right = nullptr;
        prev = nullptr;
        next = nullptr;
    }
};


// Build BST from array
Node *insertIntoBST(Node *root, int val);
Node *buildBST(vector<int> arr)
{
    Node *root = nullptr;
    for (int val : arr)
    {
        root = insertIntoBST(root, val);
    }
    return root;
}
// Insert into BST
Node *insertIntoBST(Node *root, int val)
{
    if (root == nullptr)
    {
        return new Node(val);
    }

    if (val < root->data)
    {
        root->left = insertIntoBST(root->left, val);
    }
    else
    {
        root->right = insertIntoBST(root->right, val);
    }

    return root;
}
// Inorder Traversal
void inorderTraversal(Node *root)
{
    if (root == nullptr)
    {
        return;
    }

    inorderTraversal(root->left);
    cout << root->data << " ";
    inorderTraversal(root->right);
}
// Search in BST

bool searchBST(Node *root, int key)
{
    if (root == nullptr)
    {
        return false;
    }

    if (root->data == key)
    {
        return true;
    }
    else if (key < root->data)
    {
        return searchBST(root->left, key);
    }
    else
    {
        return searchBST(root->right, key);
    }
}

//height of a bst 
int heightBST(Node *root)
{
    if (root == nullptr)
    {
        return 0;
    }
    int leftHeight = heightBST(root->left);
    int rightHeight = heightBST(root->right);
    return max(leftHeight, rightHeight) + 1;
}
//level order traversal of bst
void levelOrderBST(Node *root)
{
    if (root == nullptr)
    {
        return;
    }

    queue<Node *> q;
    q.push(root);

    while (!q.empty())
    {
        Node *current = q.front();
        q.pop();

        cout << current->data << " ";

        if (current->left != nullptr)
        {
            q.push(current->left);
        }
        if (current->right != nullptr)
        {
            q.push(current->right);
        }
    }
}
//second largest in bst
Node* findLargest(Node* root)
{
    Node* current = root;
    while (current->right != nullptr)
    {
        current = current->right;
    }
    return current;
}
Node* findSecondLargest(Node* root)
{
    if (root == nullptr || (root->left == nullptr && root->right == nullptr))
    {
        return nullptr; // No second largest element
    }

    Node* current = root;
    Node* parent = nullptr;

    while (current->right != nullptr)
    {
        parent = current;
        current = current->right;
    }

    // Case 1: Largest node has a left subtree
    if (current->left != nullptr)
    {
        return findLargest(current->left);
    }

    // Case 2: Largest node does not have a left subtree
    return parent;
}

int getSecondLargest(Node* node)
{
    if (node == nullptr || (node->left == nullptr && node->right == nullptr))
    {
        throw runtime_error("Second largest does not exist");
    }

    Node* current = node;
    Node* parent = nullptr;

    // Go to the largest node
    while (current->right != nullptr)
    {
        parent = current;
        current = current->right;
    }

    // Case 1: largest has a left subtree
    if (current->left != nullptr)
    {
        Node* temp = current->left;
        while (temp->right != nullptr)
        {
            temp = temp->right;
        }
        return temp->data;
    }

    // Case 2: largest has no left subtree
    return parent->data;
}


int countInRange(Node* root, int start, int end)
{
    if (root == nullptr)
        return 0;

    Node* stack[1000];   // manual stack
    int top = -1;
    int count = 0;

    // push root
    stack[++top] = root;

    while (top >= 0)
    {
        Node* curr = stack[top--];

        if (curr == nullptr)
            continue;

        // Case 1: value smaller than range → go right
        if (curr->data < start)
        {
            stack[++top] = curr->right;
        }
        // Case 2: value larger than range → go left
        else if (curr->data > end)
        {
            stack[++top] = curr->left;
        }
        // Case 3: value in range
        else
        {
            count++;
            stack[++top] = curr->left;
            stack[++top] = curr->right;
        }
    }

    return count;
}


class SimpleQueue
{
private:
    Node* arr[1000];   // fixed-size queue
    int front, rear;

public:
    SimpleQueue()
    {
        front = 0;
        rear = 0;
    }

    bool empty() const
    {
        return front == rear;
    }

    void push(Node* x)
    {
        arr[rear++] = x;
    }

    Node* pop()
    {
        return arr[front++];
    }
};


void levelOrderTraversal(Node* root) 
{
    if (root == nullptr)
        return;

    SimpleQueue q;
    q.push(root);

    while (!q.empty())
    {
        Node* curr = q.pop();

        cout << "(" << curr->data << ":" << curr->data << ") ";

        if (curr->left != nullptr)
            q.push(curr->left);

        if (curr->right != nullptr)
            q.push(curr->right);
    }
}
int countInRange(Node* node, int start, int end)
{
    if (node == nullptr)
        return 0;

    // If node value is smaller than range, go right
    if (node->data < start)
        return countInRange(node->right, start, end);

    // If node value is larger than range, go left
    if (node->data > end)
        return countInRange(node->left, start, end);

    // Node is in range
    return 1
         + countInRange(node->left, start, end)
         + countInRange(node->right, start, end);
}


// Inorder Successor
Node *getInorderSuccessor(Node *node)
{
    while (node != nullptr && node->left != nullptr)
    {
        node = node->left;
    }
    return node;
}
// Delete Node in BST

Node *delNode(Node *root, int key)
{
    if (root == nullptr)
    {
        return root;
    }

    if (key < root->data)
    {
        root->left = delNode(root->left, key);
    }
    else if (key > root->data)
    {
        root->right = delNode(root->right, key);
    }
    else
    {
        // Node with only one child or no child
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
        else
        {

            // Node with two children: Get the inorder successor (smallest in the right subtree)
            Node *IS = getInorderSuccessor(root->right);
            root->data = IS->data;
            root->right = delNode(root->right, IS->data);
        }
    }

    return root;
}




// Sorted Array to Balanced BST
Node *helper_arraysort(vector<int> &arr, int start, int end)
{
    if (start > end)
    {
        return nullptr;
    }
    int mid = start + (end - start) / 2;
    Node *root = new Node(arr[mid]);
    root->left = helper_arraysort(arr, start, mid - 1);
    root->right = helper_arraysort(arr, mid + 1, end);
    return root;
}
Node *sortedArrayToBST(vector<int> &arr)
{
    return helper_arraysort(arr, 0, arr.size() - 1);
}
// Validate BST
bool helper_validbst(Node *root, Node *min, Node *max)
{
    if (root == nullptr)
    {
        return true;
    }
    if ((min != nullptr && root->data <= min->data) || (max != nullptr && root->data >= max->data))
    {
        return false;
    }
    return helper_validbst(root->left, min, root) && helper_validbst(root->right, root, max);
}
bool isValidBST(Node *root)
{
    return helper_validbst(root, nullptr, nullptr);
}
// Minimum Difference in BST
Node *prevNodeMin = nullptr;

int minDiffinBST(Node *root)
{
    if (!root)
        return INT_MAX;

    int left = minDiffinBST(root->left);

    int diff = INT_MAX;
    if (prevNodeMin)
        diff = abs(root->data - prevNodeMin->data);

    prevNodeMin = root;

    int right = minDiffinBST(root->right);

    return min(diff, min(left, right));
}

// Kth Smallest Element in BST
int kthsmallest(Node *root, int &k)
{
    if (!root)
        return -1;

    int left = kthsmallest(root->left, k);
    if (left != -1)
        return left;

    k--;   // visiting this node

    if (k == 0)
        return root->data;

    return kthsmallest(root->right, k);
}

// Lowest Common Ancestor in BST
Node *lowestCommonAncestor(Node *root, Node *p, Node *q)
{
    if (root == nullptr)
    {
        return nullptr;
    }

    if (p->data < root->data && q->data < root->data)
    {
        return lowestCommonAncestor(root->left, p, q);
    }
    else if (p->data > root->data && q->data > root->data)
    {
        return lowestCommonAncestor(root->right, p, q);
    }
    else
    {
        return root;
    }
}
// Build BST from preorder traversal
Node *helper_bstfrompreorder(vector<int> &preorder, int &index, int bound)
{
    if (index >= preorder.size() || preorder[index] > bound)
    {
        return nullptr;
    }

    int val = preorder[index++];
    Node *root = new Node(val);
    root->left = helper_bstfrompreorder(preorder, index, root->data);
    root->right = helper_bstfrompreorder(preorder, index, bound);
    return root;
}
Node *bstFromPreorder(vector<int> &preorder)
{
    int index = 0;
    return helper_bstfrompreorder(preorder, index, INT_MAX);
}
// Build BST from sorted array
Node *buildbstfromsorted(vector<int> &arr, int start, int end)
{
    if (start > end)
    {
        return nullptr;
    }
    int mid = start + (end - start) / 2;
    Node *root = new Node(arr[mid]);
    root->left = buildbstfromsorted(arr, start, mid - 1);
    root->right = buildbstfromsorted(arr, mid + 1, end);
    return root;
}
// Merge two BSTs
void inorderTraversal2(Node *root, vector<int> &arr)
{
    if (root == nullptr)
    {
        return;
    }

    inorderTraversal2(root->left, arr);
    arr.push_back(root->data);
    inorderTraversal2(root->right, arr);
}
Node *merge2bst(Node *root1, Node *root2)
{
    vector<int> arr1, arr2;
    inorderTraversal2(root1, arr1);
    inorderTraversal2(root2, arr2);
    vector<int> merged;
    int i = 0, j = 0;
    while (i < arr1.size() && j < arr2.size())
    {
        if (arr1[i] < arr2[j])
        {
            merged.push_back(arr1[i++]);
        }
        else
        {
            merged.push_back(arr2[j++]);
        }
    }
    while (i < arr1.size())
    {
        merged.push_back(arr1[i++]);
    }
    while (j < arr2.size())
    {
        merged.push_back(arr2[j++]);
    }
    return buildbstfromsorted(merged, 0, merged.size() - 1);
}
// recover BST

Node *prevNode = nullptr;
Node *firstNode = nullptr;
Node *secondNode = nullptr;
void inorderRecover(Node *root)
{
    if (root == nullptr)
    {
        return;
    }

    inorderRecover(root->left);

    if (prevNode != nullptr && root->data < prevNode->data)
    {
        if (firstNode == nullptr)
        {
            firstNode = prevNode;
        }
        secondNode = root;
    }
    prevNode = root;

    inorderRecover(root->right);
}
void recoverTree(Node *root)
{
    inorderRecover(root);
    if (firstNode != nullptr && secondNode != nullptr)
    {
        int temp = firstNode->data;
        firstNode->data = secondNode->data;
        secondNode->data = temp;
    }
}
// largest BST in BT
class Info
{
public:
    int size;
    int min;
    int max;

    Info(int sz, int mn, int mx)
    {
        size = sz;
        min = mn;
        max = mx;
    }
};

Info largestBSTinBTUtil(Node *root)
{
    if (root == nullptr)
    {
        return Info(0, INT_MAX, INT_MIN);
    }

    Info leftInfo = largestBSTinBTUtil(root->left);
    Info rightInfo = largestBSTinBTUtil(root->right);

    if (leftInfo.max < root->data && root->data < rightInfo.min)
    {
        int size = leftInfo.size + rightInfo.size + 1;
        int minVal = min(leftInfo.min, root->data);
        int maxVal = max(rightInfo.max, root->data);
        return Info(size, minVal, maxVal);
    }
    return Info(max(leftInfo.size, rightInfo.size), INT_MIN, INT_MAX);
}
int largestBSTinBT(Node *root)
{
    Info result = largestBSTinBTUtil(root);
    int maxSize = result.size;
    return maxSize;
}
// populate next right pointers in each node of BST

Node *connect(Node *root)
{
    if (root == nullptr)
    {
        return root;
    }

    queue<Node *> q;
    q.push(root);

    q.push(nullptr); // Level delimiter
    Node *prev = nullptr;
    while (!q.empty())
    {
        Node *curr = q.front();
        q.pop();

        if (curr == nullptr)
        {
            if (q.size() == 0)
            {
                break;
            }
            q.push(nullptr);
            prev = nullptr;
        }
        else
        {
            if (curr->left)
            {
                q.push(curr->left);
            }
            if (curr->right)
            {
                q.push(curr->right);
            }
            if (prev != nullptr)
            {
                prev->next = curr;
            }
            prev = curr;
        }
    }
    return root;
}
// bst iterator
class BSTiterator
{
public:
    stack<Node *> st;
    void storeLeft(Node *node)
    {
        while (node != nullptr)
        {
            st.push(node);
            node = node->left;
        }
    }
    BSTiterator(Node *root)
    {
        storeLeft(root);
    }
    bool hasNext()
    {
        return !st.empty();
    }

    int next()
    {
        Node *topNode = st.top();
        st.pop();
        if (topNode->right != nullptr)
        {
            storeLeft(topNode->right);
        }
        return topNode->data;
    }
};

// inorder predecessor and successor
Node *rightmostoinleftsubtree(Node *node)
{
    Node *ans= nullptr;
    while (node != nullptr)
    {
        ans = node;
        node = node->right;
    }
    return ans;
}
Node *leftmostinrightsubtree(Node *node)
{
    Node *ans= nullptr;
    while (node != nullptr)
    {
        ans = node;
        node = node->left;
    }
    return ans;
}
vector<int> getPresucc(Node *root, int key)
{
    Node *pre = nullptr;
    Node *succ = nullptr;
    Node *curr = root;

    while (curr != nullptr)
    {
        if (key < curr->data)
        {
            succ = curr;
            curr = curr->left;
        }
        else if (key > curr->data)
        {
            pre = curr;
            curr = curr->right;
        }
        else
        {
            if (curr->left != nullptr)
            {
                pre = rightmostoinleftsubtree(curr->left);
            }
            if (curr->right != nullptr)
            {
                succ = leftmostinrightsubtree(curr->right);
            }
            break;
        }
    }

    int preVal = (pre != nullptr) ? pre->data : -1;
    int succVal = (succ != nullptr) ? succ->data : -1;
    return {preVal, succVal};
}
int main()
{

    vector<int> values = {5, 3, 8, 1, 4, 7, 9};
    Node *bstRoot = buildBST(values);
    cout << "Inorder Traversal of BST: ";
    inorderTraversal(bstRoot);
    cout << searchBST(bstRoot, 4);
    inorderTraversal(bstRoot);
    cout << endl;
    delNode(bstRoot, 3);
    cout << "Inorder Traversal after deleting 3: ";
    inorderTraversal(bstRoot);
    cout << endl;
    vector<int> sortedValues = {1, 2, 3, 4, 5, 6, 7};
    Node *balancedBSTRoot = sortedArrayToBST(sortedValues);
    cout << "Inorder Traversal of Balanced BST: ";
    inorderTraversal(balancedBSTRoot);
    cout << endl;
    cout << "Is the tree a valid BST? " << (isValidBST(balancedBSTRoot) ? "Yes" : "No") << endl;
    cout << "Minimum difference in BST: " << minDiffinBST(bstRoot) << endl;
    int k = 3;
    cout << "3rd smallest element in BST: " << kthsmallest(bstRoot, k) << endl;
    Node *p = bstRoot->left;  // Node with value 3
    Node *q = bstRoot->right; // Node with value 8
    Node *lca = lowestCommonAncestor(bstRoot, p, q);
    if (lca)
    {
        cout << "Lowest Common Ancestor of " << p->data << " and " << q->data << " is: " << lca->data << endl;
    }

    vector<int> preorder = {8, 5, 1, 7, 10, 12};
    Node *bstFromPre = bstFromPreorder(preorder);
    cout << "Inorder Traversal of BST from Preorder: ";
    inorderTraversal(bstFromPre);
    cout << endl;
    vector<int> arr1 = {4, 2, 6, 1, 3, 5, 7};
    vector<int> arr2 = {15, 10, 20, 8, 12, 17, 25};
    Node *bst1 = buildBST(arr1);
    Node *bst2 = buildBST(arr2);
    Node *mergedBST = merge2bst(bst1, bst2);
    vector<int> mergedArr;
    inorderTraversal2(mergedBST, mergedArr);
    cout << "Inorder Traversal of Merged BST: ";
    for (int val : mergedArr)
    {
        cout << val << " ";
    }
    cout << endl;

    //
    // Node *rootRecover = buildBST({3, 1, 4, NULL, 2});
    Node *rootRecover = new Node(3);
    rootRecover->left = new Node(1);
    rootRecover->right = new Node(4);
    rootRecover->right->left = new Node(2); // swapped

    recoverTree(rootRecover);
    cout << "Inorder Traversal after recovering BST: ";
    inorderTraversal(rootRecover);
    cout << endl;
    // largest BST in BT
    Node *rootBT = new Node(10);
    rootBT->left = new Node(5);
    rootBT->right = new Node(15);
    rootBT->left->left = new Node(1);
    rootBT->left->right = new Node(8);
    rootBT->right->right = new Node(7);
    int largestBSTSize = largestBSTinBT(rootBT);
    cout << "Size of largest BST in BT: " << largestBSTSize << endl;
    // bst iterator
    BSTiterator bstIt(bstRoot);
    cout << "BST Iterator Traversal: ";
    while (bstIt.hasNext())
    {
        cout << bstIt.next() << " ";
    }
    cout << endl;
    // inorder predecessor and successor
    int key = 4;
    vector<int> presucc = getPresucc(bstRoot, key);
    cout << "Predecessor and Successor of " << key << ": ";
    cout << "Predecessor = " << presucc[0] << ", Successor = " << presucc[1] << endl;

    return 0;
}