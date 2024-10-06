#include <iostream>
using namespace std;
class Node
{
public:
    int key;
    int data;
    Node *next;
    Node *previous;
    Node()
    {
        key = 0;
        data = 0;
        next = NULL;
        previous = NULL;
    }
    Node(int newKey, int newData)
    {
        key = newKey;
        data = newData;
        next = NULL;
        previous = NULL;
    }
};

class DoublyLinkedList
{
public:
    Node *head;
    DoublyLinkedList()
    {
        head = NULL;
    }
    DoublyLinkedList(Node *node)
    {
        head = node;
    }
    // Checking if Node exists or not
    Node *nodeExists(int newKey)
    {
        Node *temp = NULL;
        Node *ptr = head;
        while (ptr != NULL)
        {
            if (ptr->key == newKey)
            {
                temp = ptr;
            }
            ptr = ptr->next;
        }
        return temp;
    }
    // Adding Node at the end of the List
    void append(Node *newNode)
    {
        if (nodeExists(newNode->key) != NULL)
        {
            cout << "Node Exists With Key " << newNode->key << endl;
        }
        else if (head == NULL)
        {
            head = newNode;
            cout << "Node Appended as Head" << endl;
        }
        else
        {
            Node *ptr = head;
            while (ptr->next != NULL)
            {
                ptr = ptr->next;
            }
            ptr->next = newNode;
            newNode->previous = ptr;
            cout << "Node Appended" << endl;
        }
    }
    // Adding node at the beginning of the list
    void prepend(Node *newNode)
    {
        if (nodeExists(newNode->key) != NULL)
        {
            cout << "Node Exists With Key " << newNode->key << endl;
        }
        else if (head == NULL)
        {
            head = newNode;
            cout << "Node Prepended as Head" << endl;
        }
        else
        {
            newNode->next = head;
            head->previous = newNode;
            head = newNode;
            cout << "Prepend Successfully" << endl;
        }
    }
    // Insert node after particular position
    void insert(int newKey, Node *newNode)
    {
        Node *ptr = nodeExists(newKey);
        if (ptr == NULL)
        {
            cout << "No Node Exists with this key " << newKey << endl;
        }
        else if (nodeExists(newNode->key) != NULL)
        {
            cout << "Node Already Exists With Key " << newNode->key << endl;
        }
        else
        {
            Node *nextNode = ptr->next;
            if (nextNode == NULL)
            {
                nextNode = newNode;
                newNode->previous = ptr;
                cout << "Node Inserted at The End" << endl;
            }
            else
            {
                nextNode->previous = newNode;
                newNode->next = nextNode;
                ptr->next = newNode;
                newNode->previous = ptr;
            }
        }
    }
    // Deleting Node By Key
    void deletion(int newKey)
    {
        Node *ptr = nodeExists(newKey);
        if (ptr == NULL)
        {
            cout << "No Node Exists with Key " << newKey << endl;
        }
        else
        {
            if (head->key == newKey)
            {
                head = head->next;
                cout << "Node Unlinked With Key " << newKey << endl;
            }
            else
            {
                Node *prevNode = ptr->previous;
                Node *nextNode = ptr->next;
                // Deleting Node at The End
                if (nextNode == NULL)
                {
                    prevNode->next = NULL;
                    cout << "Node Deleted at The End with Key:-" << newKey << endl;
                }
                // Deleting in Between
                else
                {
                    prevNode->next = nextNode;
                    nextNode->previous = prevNode;
                    cout << "Node Deleted in Between with Key:-" << newKey << endl;
                }
            }
        }
    }
    void updateNode(int newKey, int newData)
    {
        Node *ptr = nodeExists(newKey);
        if (ptr != NULL)
        {
            ptr->data = newData;
            cout << "Data Updted" << endl;
        }
        else
        {
            cout << "No Node Exists with Key " << newKey << endl;
        }
    }
    void printList()
    {
        if (head == NULL)
        {
            cout << "No Node in The List" << endl;
        }
        else
        {
            Node *temp = head;
            cout << "Key and Values in The List" << endl;
            while (temp != NULL)
            {
                cout << "(" << temp->key << ", " << temp->data << ")" << endl;
                temp = temp->next;
            }
        }
    }
};

int main()
{
    Node *n1 = new Node(1, 20);
    Node *n2 = new Node(2, 40);
    Node *n3 = new Node(3, 60);
    DoublyLinkedList d;
    d.append(n1);
    d.append(n2);
    d.append(n3);
    d.deletion(2);
    d.updateNode(3, 100);
    d.printList();
    return 0;
}
