#include <iostream>
#include <memory>
#include <variant>

template<typename... Ts>
class Node {
public:
    std::variant<Ts...> data;
    std::shared_ptr<Node<Ts...>> next;

    Node(const std::variant<Ts...>& value) : data(value), next(nullptr) {}
};

template<typename... Ts>
class LinkedList {
private:
    std::shared_ptr<Node<Ts...>> head;

public:
    LinkedList() : head(nullptr) {}

    template<typename T>
    void insert(const T& value) {
        std::shared_ptr<Node<Ts...>> newNode = std::make_shared<Node<Ts...>>(value);
        if (head == nullptr) {
            head = newNode;
        } else {
            std::shared_ptr<Node<Ts...>> temp = head;
            while (temp->next != nullptr) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }

    void display() {
        std::shared_ptr<Node<Ts...>> temp = head;
        while (temp != nullptr) {
            std::visit([](const auto& value) { std::cout << value << " "; }, temp->data);
            temp = temp->next;
        }
        std::cout << std::endl;
    }
};

int main() {
    LinkedList<int, std::string> list;
    list.insert(10);
    list.insert("Hello");
    list.insert(20);
    list.display();

    return 0;
}
