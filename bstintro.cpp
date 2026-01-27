#include <bits\stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};

static int idx = 0;
Node *buildBST(vector<int> preorder)
{
    idx++;
    if (preorder[idx] == -1)

        return NULL;
    ;
    int val = preorder[idx];
    Node *root = new Node(val);
    root->left = buildBST(preorder);
    root->right = buildBST(preorder);
    return root;
}

void preorderPrint(Node *root)
{
    if (root == NULL)
        return;
    cout << root->data << " ";
    preorderPrint(root->left);
    preorderPrint(root->right);
}

void inorderPrint(Node *root)
{
    if (root == NULL)
        return;
    inorderPrint(root->left);
    cout << root->data << " ";
    inorderPrint(root->right);
}
void postorderPrint(Node *root)
{
    if (root == NULL)
        return;
    postorderPrint(root->left);
    postorderPrint(root->right);
    cout << root->data << " ";
}
void levelOrderPrint(Node *root)
{

    queue<Node *> q;
    q.push(root);

    while (q.size() > 0)
    {
        Node *curr = q.front();
        q.pop();
        if (curr == NULL)
        {
            if (!q.empty())
            {
                cout << endl;
                q.push(NULL);
                continue;
            }
            else
                break;
        }

        cout << curr->data << " ";
        if (curr->left != NULL)
            q.push(curr->left);
        if (curr->right != NULL)
            q.push(curr->right);
    }

    cout << endl;
}
int height(Node *root)
{
    if (root == NULL)
        return 0;
    int leftHeight = height(root->left);
    int rightHeight = height(root->right);
    return max(leftHeight, rightHeight) + 1;
}
int countNodes(Node *root)
{
    if (root == NULL)
        return 0;
    return countNodes(root->left) + countNodes(root->right) + 1;
}
int sumNodes(Node *root)
{
    if (root == NULL)
        return 0;
    return sumNodes(root->left) + sumNodes(root->right) + root->data;
}
bool issametree(Node *p, Node *q)
{
    if (p == NULL || q == NULL)
        return p == q;
    ;
    bool isleftsame = issametree(p->left, q->left);
    bool isrightsame = issametree(p->right, q->right);
    return (p->data == q->data) && isleftsame && isrightsame;
}
bool issubtree(Node *root, Node *subroot)
{
    if (root == NULL || subroot == NULL)
    {
        return root == subroot;
    }
    if (root->data == subroot->data && issametree(root, subroot))
    {
        return true;
    }
    return issubtree(root->left, subroot) || issubtree(root->right, subroot);
}
int diameter(Node *root)
{
    if (root == NULL)
    {

        return 0;
    }

    int ld = diameter(root->left);
    int rd = diameter(root->right);
    int currdiameter = height(root->left) + height(root->right);
    return max(currdiameter, max(ld, rd));
}
/*
int heightdiameter(Node *root)
{
int ans = 0;
    if (root == NULL)
    {
        return 0;
    }
    int lh = heightdiameter(root->left);
    int rh = heightdiameter(root->right);
    ans = max(ans, lh + rh);
    return max(lh, rh) + 1;
}
    int diameter(Node *root)
{
    int height = 0;
    return heightdiameter(root, height);
}



*/

void topview(Node *root)
{
    queue<pair<Node *, int>> q;
    map<int, int> m;
    q.push({root, 0});
    while (!q.empty())
    {
        Node *curr = q.front().first;
        int hd = q.front().second;
        q.pop();
        cout << curr->data << " ";
        if (curr->left)
        {
            q.push({curr->left, hd - 1});
        }
        if (curr->right)
        {
            q.push({curr->right, hd + 1});
        }
    }
}
void kthlevel(Node *root, int k)
{
    if (root == NULL)
    {
        return;
    }
    if (k == 1)
    {
        cout << root->data << " ";
        return;
    }
    kthlevel(root->left, k - 1);
    kthlevel(root->right, k - 1);
}
Node *lca(Node *root, Node *n1, Node *n2)
{
    if (root == NULL)
    {
        return NULL;
    }

    if (root->data == n1->data || root->data == n2->data)
    {
        return root;
    }
    Node *leftlca = lca(root->left, n1, n2);
    Node *rightlca = lca(root->right, n1, n2);
    if (leftlca && rightlca)
    {
        return root;
    }
    if (leftlca != NULL)
    {
        return leftlca;
    }
    return rightlca;
}
int search(vector<int> &inorder, int instart, int inend, int curr)
{
    for (int i = instart; i <= inend; i++)
    {
        if (inorder[i] == curr)
        {
            return i;
        }
    }
    return -1;
}

Node *buildtreehelper(vector<int> &inorder, vector<int> &preorder, int &preidx, int instart, int inend)
{

    if (instart > inend)
    {
        return NULL;
    }
    Node *root = new Node(preorder[preidx++]);

    int inIdx = search(inorder, instart, inend, preorder[preidx]);

    root->left = buildtreehelper(inorder, preorder, preidx, instart, inIdx - 1);
    root->right = buildtreehelper(inorder, preorder, preidx, inIdx + 1, inend);
    return root;
}
Node *buildtree(vector<int> inorder, vector<int> preorder)
{
    int preidx = 0;
    return buildtreehelper(inorder, preorder, preidx, 0, inorder.size() - 1);
}

int sumtree(Node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    int leftsum = sumtree(root->left);
    int rightsum = sumtree(root->right);
    root->data += leftsum + rightsum;
    return root->data;
}

void allpaths(Node *root, string path, vector<string> &ans)
{
    if (root->left == NULL && root->right == NULL)
    {
        ans.push_back(path);
        return;
    }
    if (root->left)
    {
        allpaths(root->left, path + "->" + to_string(root->left->data), ans);
    }
    if (root->right)
    {
        allpaths(root->right, path + "->" + to_string(root->right->data), ans);
    }
}
vector<string> binaryTreePaths(Node *root)
{
    vector<string> ans;
    if (root == NULL)
    {
        return ans;
    }
    string path = to_string(root->data);
    allpaths(root, path, ans);
    return ans;
}
int widthoftree(Node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    queue<pair<Node *, unsigned long long>> q;
    q.push({root, 0});
    int maxwidth = 0;
    while (!q.empty())
    {
        int curlevelsize = q.size();
        unsigned long long stidx = q.front().second;
        unsigned long long endidx = q.back().second;
        maxwidth = max(maxwidth, (int)(endidx - stidx + 1));
        for (int i = 0; i < curlevelsize; i++)
        {
            auto curr = q.front();
            unsigned long long idx = curr.second;
            q.pop();
            if (curr.first->left)
            {
                q.push({curr.first->left, 2 * idx + 1});
            }
            if (curr.first->right)
            {
                q.push({curr.first->right, 2 * idx + 2});
            }
        }
    }
    return maxwidth;
}
int main()
{
    vector<int> preorder = {10, 5, 1, -1, -1, 7, -1, -1, 40, -1, 50, -1, -1};
    Node *root = buildBST(preorder);
    cout << root->data << endl;
    preorderPrint(root);
    inorderPrint(root);
    postorderPrint(root);
    levelOrderPrint(root);
    cout << "Height of tree: " << height(root) << endl;
    cout << "Number of nodes: " << countNodes(root) << endl;
    cout << "Sum of nodes: " << sumNodes(root) << endl;
    int height = 0;
    cout << "Diameter of tree: " << diameter(root) << endl;
    return 0;
}