#include <iostream>
#include <optional>

class Node
{
public:
    int data;
    std::optional<Node *> next;

    Node(int d) : data(d), next(nullptr) {}
};

class LinkedList
{
public:
    std::optional<Node *> head;
    std::optional<Node *> tail;

    LinkedList() = default;

    LinkedList(Node *h);

    void print() const;
    void append(int data);
    Node *&getHead();
};

LinkedList::LinkedList(Node *h) : head(h), tail(h) {}

Node *&LinkedList::getHead()
{
    return head.value();
}

void LinkedList::print() const
{
    Node *current = head.value_or(nullptr);
    while (current != nullptr)
    {
        std::cout << current->data << " -> ";
        current = current->next.value();
    }
    std::cout << "None" << std::endl;
}

void LinkedList::append(int data)
{
    Node *new_node = new Node(data);

    if (!head.has_value())
    {
        head = new_node;
        tail = new_node;
    }
    else
    {
        tail.value()->next = new_node;
        tail = new_node;
    }
}



int main()
{
    LinkedList list;

    list.append(10);
    list.append(20);
    list.append(30);

    list.print(); // Output: 10 -> 20 -> 30 -> None
    std::cout << list.getHead() << std::endl;
    std::cout << list.head.value() << std::endl;
    greet();

    return 0;
}
