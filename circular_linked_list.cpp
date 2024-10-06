#include <iostream>
using namespace std;
class Node
{
public:
    int data;
    int key;
    Node *next;
    Node()
    {
        data = 0;
        key = 0;
        next = NULL;
    }
    Node(int newKey, int newData)
    {
        data = newData;
        key = newKey;
        next = NULL;
    }
};

class CircularLinkedList
{
public:
    Node *head;
    CircularLinkedList()
    {
        head = NULL;
    }
    CircularLinkedList(Node *newNode)
    {
        head = newNode;
    }
    // Checking if Node already Exists
    Node *nodeExists(int newKey)
    {
        Node *temp = NULL;
        Node *ptr = head;
        if (ptr == NULL)
        {
            return temp;
        }
        else
        {
            do
            {
                if (ptr->key == newKey)
                {
                    temp = ptr;
                }
                ptr = ptr->next;
            } while (ptr != head);
            return temp;
        }
    }
    // Adding node at the end of the lsit
    void append(Node *newNode)
    {
        if (nodeExists(newNode->key) != NULL)
        {
            cout << "Node Already Exists with Key " << newNode->key << endl;
        }
        else
        {
            if (head == NULL)
            {
                head = newNode;
                newNode->next = head;
                cout << "Node apeended at the Beginning" << endl;
            }
            else
            {
                Node *ptr = head;
                while (ptr->next != head)
                {
                    ptr = ptr->next;
                }
                ptr->next = newNode;
                newNode->next = head;
                cout << "Node Appended at The End" << endl;
            }
        }
    }
    // Adding Node at the beginning of the list
    void prepend(Node *newNode)
    {
        if (nodeExists(newNode->key) != NULL)
        {
            cout << "Node Exists with Key " << newNode->key << endl;
        }
        else
        {
            if (head == NULL)
            {
                head = newNode;
                newNode->next = head;
                cout << "Node prepended at the Beginning" << endl;
            }
            else
            {
                Node *ptr = head;
                while (ptr->next != head)
                {
                    ptr = ptr->next;
                }
                ptr->next = newNode;
                newNode->next = head;
                head = newNode;
                cout << "Node Prepended" << endl;
            }
        }
    }
    // Inserting node at a position
    void insert(int newKey, Node *newNode)
    {
        Node *temp = nodeExists(newKey);
        if (temp == NULL)
        {
            cout << "No Node Exists with Key " << newKey << endl;
        }
        else
        {
            if (nodeExists(newNode->key) != NULL)
            {
                cout << "Node Already Exists With Key" << newNode->key << endl;
            }
            else
            {
                if (temp->next == head)
                {
                    temp->next = newNode;
                    newNode->next = head;
                    cout << "Node Inserted at The End" << endl;
                }
                else
                {
                    newNode->next = temp->next;
                    temp->next = newNode;
                    cout << "Inserted Node in Between" << endl;
                }
            }
        }
    }
    // Deleting Node with Key
    void deletion(int newKey)
    {
        Node *ptr = nodeExists(newKey);
        if (ptr == NULL)
        {
            cout << "No Node Exists with Key  " << newKey << endl;
        }
        else
        {
            if (ptr == head)
            {
                if (head->next == NULL)
                {
                    head = NULL;
                    cout << "Node Deleted with Key " << newKey << endl;
                }
                else
                {
                    Node *ptr = head;
                    while (ptr->next != head)
                    {
                        ptr = ptr->next;
                    }
                    ptr->next = head->next;
                    head = head->next;
                    cout << "Node Deleted with Key " << newKey << endl;
                }
            }
            else
            {
                Node *temp = NULL;
                Node *prevptr = head;
                Node *currentptr = head->next;
                while (currentptr != NULL)
                {
                    if (currentptr->key == newKey)
                    {
                        temp = currentptr;
                        currentptr = NULL;
                    }
                    else
                    {
                        prevptr = prevptr->next;
                        currentptr = currentptr->next;
                    }
                }
                prevptr->next = temp->next;
                cout << "Node Deleted with Key " << newKey << endl;
            }
        }
    }
    // Updationg Node
    void updateNode(int newKey, int newData)
    {
        Node *ptr = nodeExists(newKey);
        if (ptr != NULL)
        {
            ptr->data = newData;
            cout << "Node's Data Updated" << endl;
        }
        else
        {
            cout << "No Node exists with Key " << newKey << endl;
        }
    }

    // printing List
    void printList()
    {
        if (head == NULL)
        {
            cout << "No Node Exists in The List" << endl;
        }
        else
        {
            cout << "Nodes in the List:-" << endl;
            Node *ptr = head;
            do
            {
                {
                    cout << "(" << ptr->key << ", " << ptr->data << ")"
                         << " ";
                    ptr = ptr->next;
                }
            } while (ptr != head);
        }
    }
};

int main()
{
    Node *n1 = new Node(1, 20);
    Node *n2 = new Node(2, 40);
    Node *n3 = new Node(3, 50);
    Node *n4 = new Node(4, 80);
    Node *n5 = new Node(5, 100);
    Node *n6 = new Node(6, 200);
    CircularLinkedList c;
    c.prepend(n1);
    c.append(n2);
    c.append(n3);
    c.append(n4);
    c.updateNode(3, 99);
    c.deletion(2);
    c.insert(1, n5);
    c.insert(4, n6);
    c.printList();
}