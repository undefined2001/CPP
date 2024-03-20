#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node(int data)
    {
        this->data = data;
        next = NULL;
    }
};

class LinkedList
{
public:
    Node *head;
    LinkedList(int arr[], int size)
    {
        head = new Node(arr[0]);
        Node *tail = head;
        int i = 1;
        while (i < size)
        {
            Node *newNode = new Node(arr[i]);
            tail->next = newNode;
            tail = newNode;
            i++;
        }
    }

    int countNode()
    {
        Node *temp = head;
        int length = 0;
        while (temp != NULL)
        {
            length++;
            temp = temp->next;
        }
        return length;
    }


    Node *nodeAt(int index)
    {
        Node *temp = head;
        int i = 0;
        while (i < index)
        {
            temp = temp->next;
            i++;
        }
        return temp;
    }

    void print()
    {
        Node *temp = head;
        while (temp != NULL)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    void insertAt(int data, int index)
    {
        Node *newNode = new Node(data);
        if (index == 0)
        {
            newNode->next = head;
            head = newNode;
        }
        else
        {
            Node *prevNode = nodeAt(index - 1);
            Node *nextNode = prevNode->next;
            prevNode->next = newNode;
            newNode->next = nextNode;
        }
    }

    void removeNodeAt(int index)
    {
        if (index == 0)
        {
            head = head->next;
        }
        else
        {
            Node *prevNode = nodeAt(index - 1);
            Node *nextNode = prevNode->next->next;
            prevNode->next = nextNode;
        }
    }
};

int main()
{
    int arr[] = {1, 4, 5, 100, 8, 60};
    int length = sizeof(arr) / sizeof(arr[0]);
    LinkedList mylist(arr, length);
    // cout<<"Before Remove:"<<endl;
    cout<<"Length: "<<mylist.countNode()<<endl;
    mylist.print();

    // cout<<"After Remove:"<<endl;
    // mylist.removeNodeAt(5);
    mylist.insertAt(200, 6);
    cout<<"After insertion Length: "<<mylist.countNode()<<endl;
    mylist.print();
    // cout<<"Data: "<<mylist.nodeAt(2)->data<<endl;
    return 0;
}