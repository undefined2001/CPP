#include <iostream>
#include <cstring>

template <typename T>
class Queue
{
private:
    T *m_Queue;
    int m_Front;
    int m_Rear;
    int m_Capacity;
    int m_Size;

public:
    Queue(int);
    ~Queue();
    void printQueue();
    bool isFull();
    bool isEmpty();
    void enqueue(T data);
    int getSize() const;
    T dequeue();
    T peek();
};

template <typename T>
Queue<T>::Queue(int capacity)
{
    m_Front = -1;
    m_Rear = -1;
    m_Size = 0;
    m_Capacity = capacity;
    m_Queue = new T[m_Capacity];
}

template <typename T>
Queue<T>::~Queue()
{
    delete[] m_Queue;
}

template <typename T>
bool Queue<T>::isFull()
{
    return (m_Rear + 1) % m_Capacity == m_Front ? true : false;
}

template <typename T>
bool Queue<T>::isEmpty()
{
    return (m_Front == -1 && m_Rear == -1) ? true : false;
}

template <typename T>
int Queue<T>::getSize() const
{
    return m_Size;
}

template <typename T>
void Queue<T>::enqueue(T data)
{
    if (isFull())
    {
        throw std::runtime_error("Queue OverfLow!!");
    }
    if (m_Rear == -1 && m_Front == -1)
    {
        m_Front = m_Rear = 0;
    }
    else
    {
        m_Rear = (++m_Rear) % m_Capacity;
    }
    m_Queue[m_Rear] = data;
    m_Size++;
}

template <typename T>
T Queue<T>::peek()
{
    return m_Queue[m_Front];
}

template <typename T>
T Queue<T>::dequeue()
{
    if (isEmpty())
    {
        throw std::runtime_error("Queue Underflow!!");
    }

    T rm_data = m_Queue[m_Front];

    if (m_Rear == m_Front)
    {
        m_Rear = m_Front = -1;
    }
    else
    {
        m_Front = (++m_Front) % m_Capacity;
    }

    return rm_data;
}

template <typename T>
void Queue<T>::printQueue()
{
    for (int i = 0; i < m_Capacity; i++)
    {
        std::cout << m_Queue[i] << " ";
    }
    std::cout << std::endl;
}

int main()
{
    try
    {
        Queue<std::string> q2(5);
        q2.enqueue("Hello");
        q2.enqueue("World");
        q2.enqueue("OpenAI");
        q2.enqueue("ChatGPT");
        q2.enqueue("Queue");
        q2.printQueue();
        std::cout << q2.isFull() << std::endl;
        std::cout << q2.isEmpty() << std::endl;
        std::cout << q2.getSize() << std::endl;
        std::cout << "Peek Value: " << q2.peek() << std::endl;
        std::cout << "Dequeue Value: " << q2.dequeue() << std::endl;
        std::cout << "Dequeue Value: " << q2.dequeue() << std::endl;
        std::cout << "Dequeue Value: " << q2.dequeue() << std::endl;
        std::cout << "Dequeue Value: " << q2.dequeue() << std::endl;
        std::cout << "Dequeue Value: " << q2.dequeue() << std::endl;
        std::cout << "Dequeue Value: " << q2.dequeue() << std::endl;
    }
    catch (const std::runtime_error &e)
    {
        std::cout << "Error: " << e.what() << std::endl;
    }

    return 0;
}