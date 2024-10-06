#include <iostream>
using namespace std;
class CircularQueue
{
private:
    int front;
    int rear;
    int arr[5];

public:
    CircularQueue()
    {
        front = -1;
        rear = -1;
        for (int i = 0; i < 5; i++)
        {
            arr[i] = 0;
        }
    }
    bool isEmpty()
    {
        if (front == -1 && rear == -1)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    bool isFull()
    {
        if ((rear + 1) % 5 == front)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    void enqueued(int a)
    {
        if (isFull())
        {
            cout << "Queue FUll" << endl;
        }
        else if (isEmpty())
        {
            rear = front = 0;
            arr[rear] = a;
        }
        else
        {
            rear = (rear + 1) % 4;
            arr[rear] = a;
        }
    }
    int dequeued()
    {
        int x;
        if (isEmpty())
        {
            cout << "Empty Queue Nothinng to Remove" << endl;
        }
        else if (front == rear)
        {
            x = arr[front];
            arr[front] = 0;
            rear = front = -1;
        }
        else
        {
            x = arr[front];
            arr[front] = 0;
            front++;
        }
        return x;
    }
    void display()
    {
        for (int i = 0; i < 5; i++)
        {
            cout << arr[i] << " ";
        }
    }
};

int main()
{
    CircularQueue one;
    one.enqueued(5);
    one.enqueued(10);
    one.enqueued(25);
    one.enqueued(30);
    one.enqueued(50);
    one.dequeued();
    one.enqueued(100);
    
    one.display();

    return 0;
}
