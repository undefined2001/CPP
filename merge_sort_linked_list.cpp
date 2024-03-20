#include <bits/stdc++.h>

template <typename T>
class Node
{
public:
    T data;
    std::shared_ptr<Node<T>> next;
    Node(T val)
    {

        this->data = val;
        this->next = NULL;
    }
};

template <typename L>
class LinkedList
{

public:
    std::shared_ptr<Node<int>> head;
    std::shared_ptr<Node<int>> getHead()
    {
        return head;
    }
    LinkedList(L arr[], int size)
    {
        head = std::make_shared<Node<int>>(arr[0]);
        std::shared_ptr<Node<int>> tail = head;
        int i = 1;
        while (i < size)
        {
            std::shared_ptr<Node<int>> newNode = std::make_shared<Node<int>>(arr[i]);
            tail->next = newNode;
            tail = newNode;
            i++;
        }
    }
    void printList()
    {
        std::shared_ptr<Node<int>> temp = head;
        while (temp != NULL)
        {
            std::cout << temp->data << " ";
            temp = temp->next;
        }
        std::cout << std::endl;
    }
};

std::shared_ptr<Node<int>> merge(std::shared_ptr<Node<int>> left, std::shared_ptr<Node<int>> right)
{
    if (left == NULL)
    {
        return right;
    }
    if (right == NULL)
    {
        return left;
    }

    std::shared_ptr<Node<int>> ans = std::make_shared<Node<int>>(-1);
    std::shared_ptr<Node<int>> ansTail = ans;

    while (left != NULL && right != NULL)
    {
        if (left->data < right->data)
        {
            ansTail->next = left;
            ansTail = left;
            left = left->next;
        }
        else
        {
            ansTail->next = right;
            ansTail = right;
            right = right->next;
        }
    }
    while (left != NULL)
    {
        ansTail->next = left;
        ansTail = left;
        left = left->next;
    }

    while (right != NULL)
    {
        ansTail->next = right;
        ansTail = right;
        right = right->next;
    }
    return ans->next;
}

std::shared_ptr<Node<int>> findMid(std::shared_ptr<Node<int>> head)
{
    std::shared_ptr<Node<int>> slow = head;
    std::shared_ptr<Node<int>> fast = head->next;
    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

std::shared_ptr<Node<int>> mergeSort(std::shared_ptr<Node<int>> head)
{
    if (head == NULL || head->next == NULL)
    {
        return head;
    }
    std::shared_ptr<Node<int>> midNode = findMid(head);
    std::shared_ptr<Node<int>> left = head;
    std::shared_ptr<Node<int>> right = midNode->next;
    midNode->next = NULL;
    left = mergeSort(left);
    right = mergeSort(right);
    return merge(left, right);
}

int main()
{
    int arr[6] = {50, 40, 30, 20, 10, 5};
    int size = sizeof(arr) / sizeof(arr[0]);
    LinkedList<int> list(arr, size);
    std::cout << "Before Sort" << std::endl;
    std::cout << findMid(list.getHead())->data << std::endl;
    list.printList();
    list.head = mergeSort(list.getHead());
    std::cout << "After Sort" << std::endl;
    list.printList();

    return 0;
}