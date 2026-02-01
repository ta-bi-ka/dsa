#include "queue.h"
#include <iostream>
using namespace std;
// Constructor implementation
ArrayQueue::ArrayQueue(int initial_capacity)
{
    // TODO: Initialize data members (data, capacity, front_idx, rear_idx)
    // TODO: Allocate memory for the array with the specified initial capacity
    capacity = initial_capacity;
    data = new int[capacity];
    front_idx = 0;
    rear_idx = 0;
}

// Destructor implementation
ArrayQueue::~ArrayQueue()
{
    // TODO: Free the dynamically allocated memory for the array
    delete[] data;
}

// Enqueue implementation (add an item to the rear of the queue)
void ArrayQueue::enqueue(int item)
{
    // TODO: Check if the array is full
    // TODO: If full, resize the array to double its current capacity
    // TODO: Add the new element to the rear of the queue

    if ((rear_idx + 1) % capacity == front_idx)
    {
        resize(capacity * 2);
    }

    data[rear_idx] = item;
    rear_idx = (rear_idx + 1) % capacity;
    return;
}

// Dequeue implementation (remove an item from the front of the queue)
int ArrayQueue::dequeue()
{
    // TODO: Check if the queue is empty, display error message if it is
    // TODO: Update front index
    // TODO: If the array is less than 25% full, resize it to half its current capacity (but not less than 2)
    // TODO: Return the dequeued element
    if (empty())
    {
        cerr << "Queue is empty. Cannot dequeue." << endl;
        return -1;
    }
    int removed = data[front_idx];
    front_idx = (front_idx + 1) % capacity;
    if (size() > 0 && size() <= capacity / 4 && capacity > 2)
    {
        if (capacity / 2 < 2)
        {
            resize(2);
        }
        else
        {
            resize(capacity / 2);
        }
    }
    return removed;
}

// Clear implementation
void ArrayQueue::clear()
{
    // TODO: Reset the queue to be empty (reset capacity, front_idx, rear_idx, data)
    delete[] data;
    capacity = 2;
    data = new int[capacity];
    front_idx = 0;
    rear_idx = 0;
}

// Size implementation
int ArrayQueue::size() const
{
    // TODO: Return the number of elements currently in the queue

    if (rear_idx >= front_idx)
    {
        return rear_idx - front_idx;
    }
    else
    {

        return (capacity - front_idx) + rear_idx;
    }
}

// Front implementation
int ArrayQueue::front() const
{
    // TODO: Check if the queue is empty, display error message if it is
    // TODO: Return the element at the front of the queue without removing it
    if (empty())
    {
        cerr << "Queue is empty. No front element." << endl;
        return -1; // or throw an exception
    }
    return data[front_idx];
}

// Back implementation (get the element at the back of the queue)
int ArrayQueue::back() const
{
    // TODO: Check if the queue is empty, display error message if it is
    // TODO: Return the element at the back of the queue without removing it
    if (empty())
    {
        cerr << "Queue is empty. No back element." << endl;
        return -1;
    }
    int lastIndex = (rear_idx - 1 + capacity) % capacity;

    return data[lastIndex];
}

// Empty implementation
bool ArrayQueue::empty() const
{
    // TODO: Return whether the queue is empty
    return size() == 0;
}

// Print implementation
string ArrayQueue::toString() const
{
    // TODO: Convert queue to a string representation in the format: <elem1, elem2, ..., elemN|
    string result = "<";
    if (empty())
    {
        result += "|";
        return result;
    }
    int i = front_idx;
    while (i != rear_idx)
    {
        result += to_string(data[i]);
        i = (i + 1) % capacity;
        if (i != rear_idx)
        {
            result += ", ";
        }
    }

    result += "|";
    return result;
}

// Resize implementation
void ArrayQueue::resize(int new_capacity)
{
    // TODO: Create a new array with the new capacity
    // TODO: Copy elements from the old array to the new array
    // TODO: Delete the old array
    // TODO: Update the data pointer and capacity
    // TODO: Update front and rear indices
    int cur_size= size();
    int *new_data = new int[new_capacity];
    for (int i = 0; i < cur_size; ++i)
    {
        new_data[i] = data[(front_idx + i) % capacity];
    }

    delete[] data;
    data = new_data;
    capacity = new_capacity;
    front_idx = 0;
    rear_idx = size();
}

int ArrayQueue::getCapacity() const
{
    // TODO: Return the current capacity of the queue
    return capacity;
}