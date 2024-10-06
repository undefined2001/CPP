#include <bits/stdc++.h>
#define None NULL
template <typename K, typename V>
struct Pair
{
    K key;
    V value;
};
typedef Pair<int, std::string> KeyValue;

struct Node
{
    KeyValue data;
    Node *next;
};

class Map
{
public:
    Node *head;
    Map()
    {
        head = None;
    }

    void insert(int k, std::string v)
    {
        Node *newNode = new Node();
        newNode->data.key = k;
        newNode->data.value = v;
        newNode->next = head;
        head = newNode;
    }

    void printMap()
    {
        Node *temp = head;
        std::cout << "(Key, Value)" << std::endl;
        while (temp)
        {
            std::cout << "(" << temp->data.key << ", " << temp->data.value << ")" << std::endl;
            temp = temp->next;
        }
    }
    Node *search(int k)
    {
        Node *temp = head;
        while (temp)
        {
            if (temp->data.key == k)
            {
                return temp;
            }
            temp = temp->next;
        }
        return None;
    }
};

int main()
{

    Map m;
    int val;
    while (true)
    {
        std::cout << "1. Insert in Map. " << std::endl;
        std::cout << "2. Search by Key. " << std::endl;
        std::cout << "3. Print Map. " << std::endl;
        std::cout << "4. Clear Screen. " << std::endl;
        std::cout << "Choose Your Option: ";
        std::cin >> val;
        if (val == 1)
        {
            int k;
            std::string v;
            std::cin >> k >> v;
            m.insert(k, v);
        }
        else if (val == 2)
        {
            int k;
            std::cin >> k;
            Node *res = m.search(k);
            if (res)
            {
                std::cout << "(" << res->data.key << ", " << res->data.value << ")" << std::endl;
            }
            else
            {
                std::cout << "No Value Found." << std::endl;
            }
        }
        else if (val == 3)
        {
            m.printMap();
        }
        else if (val == 4)
        {
            system("clear");
        }
        else
        {
            break;
        }
    }
    return 0;
}
