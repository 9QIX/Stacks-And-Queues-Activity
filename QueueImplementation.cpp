// Queue Implementation
#include <iostream>
#include <cstdlib>
using namespace std;
// the default capacity of the queue
#define SIZE 1000

// class to store queue
class Queue {
    int *arr, capacity, front, rear, count;

public:
    explicit Queue(int size = SIZE);
    int dequeue();
    void enqueue(int item);
    int peek();
    [[nodiscard]] int size() const;
    [[nodiscard]] bool isEmpty() const;
    [[nodiscard]] bool isFull() const;
};

// constructor to initialize a queue
Queue::Queue(int size) {
    arr = new int[size];
    capacity = size;
    front = 0;
    rear = -1;
    count = 0;
}

// utility function to dequeue the front element
int Queue::dequeue() {
    // check for queue underflow
    if (isEmpty()) {
        cout << "Queue Underflow";
        exit(EXIT_FAILURE);
    }

    int x = arr[front];
    cout << "Dequeued " << x << endl;

    front = (front + 1) % capacity;
    count--;

    return x;
}

// utility function to add an item to the queue
void Queue::enqueue(int item){
    // check for queue overflow
    if (isFull()) {
        cout << "Queue Overflow";
        exit(EXIT_FAILURE);
    }

    cout << "Queued " << item << endl;

    rear = (rear + 1) % capacity;
    arr[rear] = item;
    count++;
}

// utility function to return the front element of the queue
int Queue::peek(){
    if (isEmpty()){
        cout << "Queue Underflow";
        exit(EXIT_FAILURE);
    }
    return arr[front];
}

// utility function to return the size of the queue
int Queue::size() const {
    return count;
}

// utility function to check if the queue is empty or not
bool Queue::isEmpty() const {
    return (size() == 0);
}

// utility function to check if the queue is full or not
bool Queue::isFull() const {
    return (size() == capacity);
}

// driver program
int main() {
    // qd
    Queue q(5);
    cout << "Queuing\n";
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.enqueue(4);
    q.enqueue(5);
    // display front element and q size
    cout << "The front element is " << q.peek() << " and the queue size is " << q.size() << endl << endl;
    // dqd
    cout << "Dequeuing\n";
    q.dequeue();
    q.dequeue();
    q.dequeue();
    q.dequeue();
    q.dequeue();
    // q empty or not
    if (q.isEmpty()) {
        cout << "The queue is empty\n";
    }
    else {
        cout << "The queue is not empty\n";
    }

    return 0;
}