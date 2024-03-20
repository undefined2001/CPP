#include <bits/stdc++.h>

#define GLOBALSPACE 10

class Node
{
public:
    std::shared_ptr<Node> left;
    std::shared_ptr<Node> right;
    int data;

    Node(int val)
    {
        this->data = val;
        this->left = NULL;
        this->right = NULL;
    }
    ~Node()
    {
    }
};

class BinarySearchTree
{
public:
    std::shared_ptr<Node> root;
    BinarySearchTree()
    {
        root = NULL;
    }
    bool isEmpty();
    std::shared_ptr<Node> successor(std::shared_ptr<Node>);
    std::shared_ptr<Node> predecessor(std::shared_ptr<Node>);
    int height(std::shared_ptr<Node> root);
    void insert(int);
    void deleteNode(int);
    int search(int);
    void printPreorder(std::shared_ptr<Node>);
    void printInorder(std::shared_ptr<Node>);
    void printPostorder(std::shared_ptr<Node>);
    void print2D(std::shared_ptr<Node>, int);
    void printBFS(std::shared_ptr<Node>);
    void levelTraverser(std::shared_ptr<Node>, int);
};

// This is Utility Block For Utility Functions

// This Function checks if a Tree is Empty or Not
bool BinarySearchTree::isEmpty()
{

    return (root == NULL) ? true : false; // 1. return if node is NULL
};

std::shared_ptr<Node> BinarySearchTree::predecessor(std::shared_ptr<Node> root)
{
    if (!root->right)
    {
        return root;
    }
    while (root)
    {
        root = root->right;
    }
    return root;
}

std::shared_ptr<Node> BinarySearchTree::successor(std::shared_ptr<Node> root)
{
    if (!root->left)
    {
        return root;
    }
    while (root)
    {
        root = root->left;
    }
    return root;
}

// This recursive function helps to traverse a level at a time
void BinarySearchTree::levelTraverser(std::shared_ptr<Node> root, int level)
{
    // It will Exit if the root is NULL
    if (root == NULL)
    {
        return;
    }
    // Here we Print the value if the level is 0
    else if (level == 0)
    {
        std::cout << root->data << (*root).data << "\n";
    }
    // in this block we call the fucntion recursively Unit or Unless our level is greater than 0
    /*for example if our level is 2 so for reaching the second level we need two iteration from root
    so we will keep reducing the level and once we reach zero that means we are at level 2
    */
    else
    {
        levelTraverser(root->left, level - 1);
        levelTraverser(root->right, level - 1);
    }
}

// This is the end of Utility Block

// This Function helps to insert a value in the BinarySearchTree
void BinarySearchTree::insert(int val)
{
    // At First we are making a newNode with the passed value
    std::shared_ptr<Node> newNode = std::make_shared<Node>(val);

    // Now checking is the tree is full empty or not
    if (isEmpty())
    {
        root = newNode;
    }
    else
    {
        /*If the Tree is Not Empty then we have to traverse so here making a temporary variable so that
        Root stay intact*/
        std::shared_ptr<Node> temp = root;

        // This loop will Continue Untill we got a NULL as a left child or right child
        while (temp != NULL)
        {
            // Checking if the value is already in the tree or not
            if (temp->data == newNode->data)
            {
                std::cout << "Duplicates Not Allowed\n";
                return;
            }
            // Checking is there any empty left child
            else if (temp->data > newNode->data && temp->left == NULL)
            {
                temp->left = newNode;
                return;
            }
            // If there is no empty left child this else if will help us to find one
            else if (temp->data > newNode->data)
            {
                temp = temp->left;
            }
            // Checking is there any empty left child
            else if (temp->data < newNode->data && temp->right == NULL)
            {
                temp->right = newNode;
                return;
            }
            // If there is no empty right child this else will help us to find one
            else
            {
                temp = temp->right;
            }
        }
    }
};

void BinarySearchTree::deleteNode(int val)
{
    std::shared_ptr<Node> currentNode = root;
    std::shared_ptr<Node> prevNode = NULL;

    while (currentNode && currentNode->data != val)
    {
        prevNode = currentNode;

        if (val > currentNode->data)
        {
            currentNode = currentNode->right;
        }
        else
        {
            currentNode = currentNode->left;
        }
    }
    if (currentNode == NULL)
    {
        return;
    }
    else if (!currentNode->right)
    {
        if (!prevNode)
        {
            root = currentNode->left;
        }
        else if (prevNode->left == currentNode)
        {
            prevNode->left = currentNode->left;
        }
        else
        {
            prevNode->right = currentNode->left;
        }
    }
    else if (!currentNode->left)
    {
        if (!prevNode)
        {
            root = currentNode->right;
        }
        else if (prevNode->left == currentNode)
        {
            prevNode->left = currentNode->right;
        }
        else
        {
            prevNode->right = currentNode->right;
        }
    }
    else
    {
        std::shared_ptr<Node> successor = this->successor(currentNode->right);
        if (!prevNode)
        {
            successor->left = root->left;
            root = successor;
        }
        else
        {
            successor->left = currentNode->left;
            if (successor->data > root->data)
            {
                prevNode->right = successor;
            }
            else
            {
                prevNode->left = successor;
            }
        }
        // std::cout << "Successor" << successor->data << std::endl;
        // std::cout << "PrevNode" << prevNode->data << std::endl;
        // std::cout << "currentNode" << currentNode->data << std::endl;
    }
    // std::cout << prevNode->data << std::endl;
    // std::cout << currentNode->data << std::endl;
}

// This function helps to find a value inside the Tree
int BinarySearchTree::search(int val)
{
    // if the tree is totally empty we will return -1
    if (root == NULL)
    {
        return -1;
    }
    /*
    If the Tree is Not Empty then we have to traverse so here making a temporary variable so that
    Root stay intact
    */
    std::shared_ptr<Node> temp = root;

    // This loop will Continue Untill we got a NULL as a left child or right child
    while (temp != NULL)
    {
        // Checking if the value Exists then return 1
        if (temp->data == val)
        {
            return 1;
        }
        // This else if helps to traverse to the right
        else if (val > temp->data)
        {
            temp = temp->right;
        }
        // This else helps to traverse to the left
        else
        {
            temp = temp->left;
        }
    }

    // If the loop ends that means value doesn't exists so return 0
    return 0;
};

int BinarySearchTree::height(std::shared_ptr<Node> root)
{
    if (root == NULL)
    {
        return -1;
    }
    int lheight = height(root->left);
    int rheight = height(root->right);
    if (lheight < rheight)
    {
        return rheight + 1;
    }
    else
    {
        return lheight + 1;
    }
};

void BinarySearchTree::printPreorder(std::shared_ptr<Node> root)
{
    if (root == NULL)
        return;
    std::cout << root->data << " ";
    printPreorder(root->left);
    printPreorder(root->right);
};
void BinarySearchTree::printInorder(std::shared_ptr<Node> root)
{
    if (root == NULL)
        return;
    printInorder(root->left);
    std::cout << root->data << " ";
    printInorder(root->right);
};
void BinarySearchTree::printPostorder(std::shared_ptr<Node> root)
{
    if (root == NULL)
        return;
    printPostorder(root->left);
    printPostorder(root->right);
    std::cout << root->data << " ";
};

void BinarySearchTree::print2D(std::shared_ptr<Node> root, int space = 5)
{
    // Checking if the tree is totally is empty or not if empty then exit
    if (root == NULL)
        return;
    // incrementing space
    space += GLOBALSPACE;

    // Traversing the right child
    print2D(root->right, space);
    std::cout << "\n";

    // Printing Empty spaces in the Console
    for (int i = GLOBALSPACE; i < space; i++)
    {
        std::cout << " ";
    }
    // Printing The value
    std::cout << root->data << "\n";

    // Traversing the left child
    print2D(root->left, space);
};

void BinarySearchTree::printBFS(std::shared_ptr<Node> root)
{
    // calculating the height
    int height = this->height(root);

    for (int i = 0; i <= height; i++)
    {
        levelTraverser(root, i);
    }
}

int main()
{

    BinarySearchTree bst;
    bst.insert(50);
    bst.insert(20);
    bst.insert(60);
    bst.insert(100);
    bst.insert(15);
    bst.insert(55);
    bst.insert(25);
    bst.insert(35);

    // bst.printPreorder(bst.root);
    // bst.printPostorder(bst.root);
    // bst.printInorder(bst.root);
    // std::cout << bst.height(bst.root) << "\n";
    // bst.printBFS(bst.root);
    std::cout << "Before Remove:\n";
    bst.print2D(bst.root);
    std::cout << std::endl;
    // bst.root = bst.root->right;
    // std::cout << bst.successor(bst.root->right)->data << std::endl;
    // std::cout << bst.predecessor(bst.root->left)->data << std::endl;
    bst.deleteNode(60);
    bst.deleteNode(20);
    std::cout << "After Remove:\n";
    bst.print2D(bst.root);

    // std::shared_ptr<Node> n1 = std::make_shared<Node>(20);
    // std::shared_ptr<Node> n2 = std::make_shared<Node>(10);
    // std::shared_ptr<Node> n3 = std::make_shared<Node>(30);
    // std::shared_ptr<Node> n4 = n3;

    // n1->left = n2;
    // n1->right = n3;
    // n2->left = n4;

    // print2D(n1);

    return 0;
}