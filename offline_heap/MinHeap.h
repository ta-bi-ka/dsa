#ifndef MINHEAP_H
#define MINHEAP_H

#include <iostream>
#include <algorithm>
#include <fstream>
#include <stdexcept>
#include <climits>
using namespace std;

#define MAX_CAPACITY 1000 // Defines the maximum capacity of the heap

class MinHeap
{
private:
    int heap[MAX_CAPACITY]; // Array to store heap elements
    int size;               // Current number of elements in the heap

    /**
     * Sifts up the node at index i to maintain heap property.
     */
    void siftUp(int i)
    {
        /**Write your code here**/

        while (i > 0)
        {
            int parent = (i - 1) / 2;
            if (heap[i] < heap[parent])
            {
                int temp = heap[i];
                heap[i] = heap[parent];
                heap[parent] = temp;
                i = parent;
            }
            else
            {
                break;
            }
        }
    }

    /**
     * Sifts down the node at index i to maintain heap property.
     */
    void siftDown(int i)
    {
        /**Write your code here**/

        int currnt = i;
        while (true)
        {

            int left = 2 * currnt + 1;
            int right = 2 * currnt + 2;
            int smallest = currnt;

           
            if (left < size && heap[left] < heap[smallest])
            {
                smallest = left;
            }
             if (right < size && heap[right] < heap[smallest])
            {
                smallest = right;
            }
            if (smallest != currnt)
            {
                int temp = heap[currnt];
                heap[currnt] = heap[smallest];
                heap[smallest] = temp;
                currnt = smallest;
            }
            else
            {
                break;
            }
        }
    }

public:
    // Constructor initializes an empty heap
    MinHeap() : size(0) {}

    /**
     * Inserts a new element x into the heap.
     */
    void insert(int x)
    {
        /**Write your code here**/
        if (size == MAX_CAPACITY)
        {
            cout << "Heap is full. Cannot insert " << x << endl;
            return;
        }
        heap[size] = x;
        size++;
        siftUp(size - 1);
    }

    /**
     * Returns the minimum element without removing it.
     */
    int findMin()
    {
        /**Write your code here**/
        if (size == 0)
        {
            cout << "Heap i sempty" << endl;
            return -1;
        }
        return heap[0];
    }

    /**
     * Removes and returns the minimum element from the heap.
     */
    int extractMin()
    {

        /**Write your code here**/
        if (size == 0)
        {
            cout << "Heap is empty" << endl;
            return -1;
        }
        int minimum = heap[0];
        heap[0] = heap[size - 1];
        size--;
        siftDown(0);
        return minimum;
    }

    /**
     * Returns the number of elements in the heap.
     */
    int getSize()
    {
        /**Write your code here**/
        return size;
    }

    /**
     * Checks if the heap is empty.
     * Returns true if empty, false otherwise.
     */
    bool isEmpty()
    {
        /**Write your code here**/
        return size == 0;
    }

    /**
     * Decreases the value of the element at index i to newValue.
     */
    void decreaseKey(int i, int newValue)
    {
        /**Write your code here**/
        if (i < 0 || i >= size)
        {
            cout << "Invalid index" << endl;
            return;
        }
        heap[i] = newValue;
        siftUp(i);
    }

    /**
     * Deletes the element at index i.
     */
    void deleteKey(int i)
    {
        /**Write your code here**/
        if (i < 0 || i >= size)
        {
            cout << "Invalid index" << endl;
            return;
        }
        decreaseKey(i, INT_MIN);
        extractMin();
    }

    /**
     * Prints the heap's content to the output file.
     * Format: "elem1 elem2 elem3 ..." (space-separated)
     */
    void printHeap(std::ofstream &outfile)
    {
        /**Write your code here**/
        for (int i = 0; i < size; i++)
        {
            if (i > 0)
            {
                outfile << " ";
            }
            outfile << heap[i];
        }
        outfile << endl;
    }

    /**
     * Checks whether the Min Heap property is preserved.
     * Returns true if valid, false otherwise.
     */
    bool isValidMinHeap()
    {
        /**Write your code here**/

        for (int i = 0; i < size / 2; i++)
        {
            int left = 2 * i + 1;
            int right = 2 * i + 2;
            if (left < size && right < size)
            {
                if (heap[i] > heap[left] || heap[i] > heap[right])
                {
                    return false;
                }
            }
            else if (left < size)
            {
                if (heap[i] > heap[left])
                {
                    return false;
                }
            }
        }
        return true;
    }
    /**
     * Builds a heap from an unsorted array using bottom-up heapify.
     */
    void heapify(int arr[], int n)
    {
        /**Write your code here**/
        if (n > MAX_CAPACITY)
        {
            cout << "Array size exceeds maximum capacity" << endl;
            return;
        }
        size = 0;
        for (int i = 0; i < n; i++)
        {
            heap[i] = arr[i];
        }
        size = n;
        for (int i = (size / 2) - 1; i >= 0; i--)
        {
            siftDown(i);
        }
    }

    /**
     * Returns all elements in sorted (ascending) order.
     * The original heap should remain UNCHANGED after this operation.
     */
    void heapSort(std::ofstream &outfile)
    {
        /**Write your code here**/
        int orgSize = size;

        int *newtemp = new int[size];
        for (int i = 0; i < size; i++)
        {
            newtemp[i] = heap[i];
        }

        for (int i = 0; i < orgSize; i++)
        {
           
            outfile << extractMin()<< " ";
        }
        outfile << endl;
        size = orgSize;
        for (int i = 0; i < size; i++)
        {
            heap[i] = newtemp[i];
        }
        delete[] newtemp;
    }

    /**
     * Replaces the minimum element with a new value x in a single operation.
     * Returns the old minimum value.
     */
    int replaceMin(int x)
    {
        /**Write your code here**/
        if (size == 0)
        {
            cout << "Heap is empty" << endl;
            return -1;
        }
        int oldmin = findMin();
        heap[0] = x;
        siftDown(0);
        return oldmin;
    }


    ///////////////////////////////////////////////
    void mergeHeap(int otherHeap[], int otherSize)
{
    if(size + otherSize > MAX_CAPACITY)
    {
        cout << "Merge not possible: capacity exceeded" << endl;
        return;
    }

    int temp[MAX_CAPACITY];

    // Step 1: copy current heap
    for(int i = 0; i < size; i++)
    {
        temp[i] = heap[i];
    }

    // Step 2: copy other heap
    for(int i = 0; i < otherSize; i++)
    {
        temp[size + i] = otherHeap[i];
    }

    // Step 3: update size
    int newSize = size + otherSize;

    // Step 4: heapify merged array
    for(int i = 0; i < newSize; i++)
    {
        heap[i] = temp[i];
    }
    size = newSize;

    for(int i = (size/2) - 1; i >= 0; i--)
    {
        siftDown(i);
    }
}

int kthSmallest(int k)
{
    if(k <= 0 || k > size)
    {
        cout << "Invalid k" << endl;
        return -1;
    }

    // Step 1: backup heap
    int backupSize = size;
    int *backupHeap = new int[size];

    for(int i = 0; i < size; i++)
    {
        backupHeap[i] = heap[i];
    }

    // Step 2: extract k times
    int kth;
    for(int i = 0; i < k; i++)
    {
        kth = extractMin();
    }

    // Step 3: restore heap
    size = backupSize;
    for(int i = 0; i < size; i++)
    {
        heap[i] = backupHeap[i];
    }

    delete[] backupHeap;

    return kth;
}
int kthLargest(int k)
{
    if(k <= 0 || k > size)
    {
        cout << "Invalid k" << endl;
        return -1;
    }

    int newk = size - k + 1;
    return kthSmallest(newk);
}
///////////////////////////////////////
double findMedian()
{
    if(size == 0)
    {
        cout << "Heap is empty" << endl;
        return -1;
    }

    if(size % 2 == 1)
    {
        int k = (size + 1) / 2;
        return kthSmallest(k);
    }
    else
    {
        int k1 = size / 2;
        int k2 = k1 + 1;
        return (kthSmallest(k1) + kthSmallest(k2)) / 2.0;
    }
}
////////////////////////////////////////////
void deleteLessThanX(int x)
{
    while(!isEmpty() && heap[0] < x)
    {
        extractMin();
    }
}
//////////////////////////////////////////////
void replaceKey(int i, int newValue)
{
    if(i < 0 || i >= size)
    {
        cout << "Invalid index" << endl;
        return;
    }

    int oldValue = heap[i];
    heap[i] = newValue;

    if(newValue < oldValue)
    {
        siftUp(i);
    }
    else
    {
        siftDown(i);
    }
}
///////////////////////////////////////////////
void replaceKey(int i, int newValue)
{
    if(i < 0 || i >= size)
    {
        cout << "Invalid index" << endl;
        return;
    }

    int oldValue = heap[i];
    heap[i] = newValue;

    if(newValue < oldValue)
    {
        siftUp(i);
    }
    else
    {
        siftDown(i);
    }
}
////////////////////////////////////////////////
bool isIdentical(MinHeap &other)
{
    if(size != other.size)
    {
        return false;
    }

    for(int i = 0; i < size; i++)
    {
        if(heap[i] != other.heap[i])
        {
            return false;
        }
    }

    return true;
}
//////////////////////////////////////////////////////
void convertToMaxHeap()
{
    for(int i = 0; i < size; i++)
    {
        heap[i] = -heap[i];
    }

    for(int i = (size/2) - 1; i >= 0; i--)
    {
        siftDown(i);
    }
}
//////////////////////////////////////////////////////////
void printLessThanX(int x, std::ofstream &outfile)
{
    for(int i = 0; i < size; i++)
    {
        if(heap[i] < x)
        {
            outfile << heap[i] << " ";
        }
    }
    outfile << endl;
}
////////////////////////////////
int secondSmallest()
{
    if(size < 2)
    {
        cout << "Not enough elements" << endl;
        return -1;
    }

    int backupSize = size;
    int *backupHeap = new int[size];

    for(int i = 0; i < size; i++)
    {
        backupHeap[i] = heap[i];
    }

    extractMin();
    int second = extractMin();

    size = backupSize;
    for(int i = 0; i < size; i++)
    {
        heap[i] = backupHeap[i];
    }

    delete[] backupHeap;

    return second;
}
/////////////////////////////////////
void printInRange(int L, int R, std::ofstream &outfile)
{
    for(int i = 0; i < size; i++)
    {
        if(heap[i] >= L && heap[i] <= R)
        {
            outfile << heap[i] << " ";
        }
    }
    outfile << endl;
}
//////////////////////////////////////
void heapUnion(MinHeap &other)
{
    if(size + other.size > MAX_CAPACITY)
    {
        cout << "Union not possible: capacity exceeded" << endl;
        return;
    }

    // Copy elements of other heap
    for(int i = 0; i < other.size; i++)
    {
        heap[size + i] = other.heap[i];
    }

    size = size + other.size;

    // Heapify merged heap
    for(int i = (size/2) - 1; i >= 0; i--)
    {
        siftDown(i);
    }
}
/////////////////////////////////////
void heapIntersection(MinHeap &other, std::ofstream &outfile)
{
    for(int i = 0; i < size; i++)
    {
        for(int j = 0; j < other.size; j++)
        {
            if(heap[i] == other.heap[j])
            {
                outfile << heap[i] << " ";
                break;
            }
        }
    }
    outfile << endl;
}
//////////////////////////////////////
int countGreaterThanX(int x)
{
    int count = 0;

    for(int i = 0; i < size; i++)
    {
        if(heap[i] > x)
        {
            count++;
        }
    }

    return count;
}
//////////////////////////////////////
void topKSmallest(int k, std::ofstream &outfile)
{
    if(k <= 0 || k > size)
    {
        cout << "Invalid k" << endl;
        return;
    }

    int backupSize = size;
    int *backupHeap = new int[size];

    for(int i = 0; i < size; i++)
    {
        backupHeap[i] = heap[i];
    }

    for(int i = 0; i < k; i++)
    {
        outfile << extractMin() << " ";
    }
    outfile << endl;

    size = backupSize;
    for(int i = 0; i < size; i++)
    {
        heap[i] = backupHeap[i];
    }

    delete[] backupHeap;
}
/////////////////////////////////////////////
bool isArrayMinHeap(int arr[], int n)
{
    for(int i = 0; i <= (n/2) - 1; i++)
    {
        int left = 2*i + 1;
        int right = 2*i + 2;

        if(left < n && arr[i] > arr[left])
            return false;

        if(right < n && arr[i] > arr[right])
            return false;
    }
    return true;
}
///////////////////////////
int height()
{
    if(size == 0)
        return -1;

    int h = 0;
    int temp = size;

    while(temp > 1)
    {
        temp = temp / 2;
        h++;
    }
    return h;
}
/////////////////////////////////////
void printLeafNodes(std::ofstream &outfile)
{
    for(int i = size/2; i < size; i++)
    {
        outfile << heap[i] << " ";
    }
    outfile << endl;
}
};

#endif // MINHEAP_H
