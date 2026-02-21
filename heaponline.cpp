#include <fstream>
#include <iostream>
#include "MaxHeap.h"
using namespace std;
int maxCandy(int arr[], int n,int customers)
{
    MaxHeap heap;
    for(int i=0;i<n;i++)
        heap.insert(arr[i]);
    int maxsell = 0;
    while(customers--)
    {
        int max = heap.extractMax();
        maxsell += max;
        max--;
        heap.insert(max);
    }
    return maxsell;
}
void processTestCases()
{
    int testCases;
    cin >> testCases;
    for (int t = 1; t <= testCases; ++t)
    {
        cout << "Test Case " << t << ":" << endl;
        int n;
        cin>>n;
        int customers;
        cin>>customers;
        int arr[n];
        for(int i=0;i<n;i++)
        {
            cin>>arr[i];
        }
        cout << maxCandy(arr,n,customers) << endl;
    }
}
int main()
{
    ifstream ipFile("input.txt");
    ofstream opFile("output.txt");
    cin.rdbuf(ipFile.rdbuf());
    cout.rdbuf(opFile.rdbuf());
    if (!ipFile.is_open() || !opFile.is_open())
    {
        cout << "Could not open input or output file" << endl;
        return 1;
    }
    processTestCases();
    ipFile.close();
    opFile.close();
    return 0;
}



//////////////////////////////////////////////////////////////////////
#include <fstream>
#include <iostream>
#include "MaxHeap.h"
using namespace std;
int maxCandy(int arr[], int n,int minutes)
{
    MaxHeap heap;
    for(int i=0;i<n;i++)
        heap.insert(arr[i]);
    int maxcandy = 0;
    while(minutes--)
    {
        int max = heap.extractMax();
        maxcandy += max;
    }
    return maxcandy;
}
void processTestCases()
{
    int testCases;
    cin >> testCases;
    for (int t = 1; t <= testCases; ++t)
    {
        cout << "Test Case " << t << ":" << endl;
        int n;
        cin>>n;
        int minutes;
        cin>>minutes;
        int arr[n];
        for(int i=0;i<n;i++)
        {
            cin>>arr[i];
        }
        cout << maxCandy(arr,n,minutes) << endl;
    }
}
int main()
{
    ifstream ipFile("input.txt");
    ofstream opFile("output.txt");
    cin.rdbuf(ipFile.rdbuf());
    cout.rdbuf(opFile.rdbuf());
    if (!ipFile.is_open() || !opFile.is_open())
    {
        cout << "Could not open input or output file" << endl;
        return 1;
    }
    processTestCases();
    ipFile.close();
    opFile.close();
    return 0;
}


///////////////////////////////////////////////////////////////////////////
#include "MaxHeap.h"
#include <iostream>
using namespace std;
void printAns(MaxHeap &heap)
{
    if (heap.isEmpty())
    {
        return;
    }
    int val = heap.extractMax();
    printAns(heap);
    cout << val << endl;
    heap.insert(val);
}
int main()
{
    int n;
    cin >> n;
    MaxHeap heap;
    for (int i = 0; i < n; i++)
    {
        int val;
        cin >> val;
        heap.insert(val);
        if(heap.getSize()<3)
        {
            cout << "-1" << endl;
        }
        else
        {
            int largest = heap.extractMax();
            int secondLargest = heap.extractMax();
            int thirdLargest = heap.findMax();
            cout << largest * secondLargest * thirdLargest << endl;
            heap.insert(secondLargest);
            heap.insert(largest);
        }
    }
    return 0;
}