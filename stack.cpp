#include <iostream>
using namespace std;
class Stack
{
private:
    int top;
    int arr[5];

public:
    Stack()
    {
        top = -1;
        for (int i = 0; i < 5; i++)
        {
            arr[i] = 0;
        }
    }
    bool isEmpty()
    {
        if (top == -10)
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
        if (top == 4)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    void push(int a)
    {
        if (isFull())
        {
            cout << "Stack Overflow" << endl;
        }
        else
        {
            top++;
            arr[top] = a;
        }
    }
    int pop()
    {
        if (isEmpty())
        {
            cout << "Stack Underflow" << endl;
            return 0;
        }
        else
        {
            int popValue = arr[top];
            arr[top] = 0;
            top--;
            return popValue;
        }
    }
    int count()
    {
        return top + 1;
    }
    int peek(int x)
    {
        if (isEmpty())
        {
            cout << "Stack Empty" << endl;
            return 0;
        }
        else
        {
            return arr[x];
        }
    }
    void change(int pos, int value)
    {
        arr[pos] = value;
        cout << "Value at position " << pos << "has changed";
    }
    void display()
    {
        cout << "All the Items in Stack are " << endl;
        for (int i = 4; i >= 0; i--)
        {
            cout << arr[i] << endl;
        }
    }
};
int main()
{
    Stack s1;
    int option, position, value;
    do
    {
        cout << "1. Push" << endl;
        cout << "2. Pop" << endl;
        cout << "3. isEmpty" << endl;
        cout << "4. isFull" << endl;
        cout << "5. Peek" << endl;
        cout << "6. Count" << endl;
        cout << "7. Change" << endl;
        cout << "8. Display" << endl;
        cout << "9. Clear Screen" << endl;
        cin >> option;
        switch (option)
        {
        case 1:
            cout << "Enter an Item" << endl;
            cin >> value;
            s1.push(value);
            break;

        case 2:
            cout << "Pop Function Called - Poped Value:" << s1.pop() << endl;
            break;

        case 3:
            if (s1.isEmpty())
            {
                cout << "Stack is Empty" << endl;
            }
            else
            {
                cout << "Stack is Not Empty" << endl;
            }
            break;
        case 4:
            if (s1.isFull())
            {
                cout << "Stack is Full" << endl;
            }
            else
            {
                cout << "Stack is Not Full" << endl;
            }
            break;
        case 5:
            cout << "Enter The Index -->";
            cin >> position;
            cout << "Peek Value :" << s1.peek(position) << endl;
            break;
        case 6:
            cout << "Number Of Items: " << s1.count() << endl;
            break;
        case 7:
            cout << "Enter The Position: ";
            cin >> position;
            cout << "Enter The Value: ";
            cin >> value;
            s1.change(position, value);
            break;
        case 8:
            cout << "Items Are :" << endl;
            s1.display();
            break;
        case 9:
            system("clear");
        default:
            cout << "Enter Proper Option" << endl;
        }
    } while (option != 0);

    return 0;
}