#include <iostream>
/**
 * @brief this code is for to show about struct this code makes a linked list with struct
 * @brief struct is a user defined data type which works like class but it doesn't have
 * @brief security like class and don't have methods like class
 */

struct Node
{
    int data;
    Node *next;
};

Node *make_list(int arr[], int size)
{
    Node *head = new Node();
    Node *temp = head;
    head->data = arr[0];
    for (int i = 1; i < size; i++)
    {
        Node *newNode = new Node();
        newNode->data = arr[i];
        newNode->next = nullptr;
        temp->next = newNode;
        temp = newNode;
    }
    return head;
}

void append(Node *head, int value)
{
    Node *temp = head;
    while (temp->next != nullptr)
    {
        temp = temp->next;
    }
    Node *newNode = new Node();
    newNode->data = value;
    newNode->next = nullptr;
    temp->next = newNode;
}

void print_list(Node *head, int size)
{
    Node *temp = head;
    while (temp != nullptr)
    {
        std::cout << temp->data << " ";
        temp = temp->next;
    }
    std::cout << std::endl;
}

int main()
{
    int arr[] = {10, 20, 30, 40, 50};
    int size = sizeof(arr) / sizeof(arr[0]);
    Node *head = make_list(arr, size);
    append(head, 100);
    print_list(head, size);

    return 0;
}