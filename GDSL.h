#include <iostream>


template <typename T>
struct Node {
    T data;
    Node<T>* prev;
    Node<T>* next;
};

template <typename T>
using PNODE = Node<T>*;

template <typename T>
using PPNODE = Node<T>**;

template <typename T>
class SinglyLL {
private:
    PNODE<T> head;

public:
    SinglyLL();
    void insertFirst(T value);
    void insertLast(T value);
    void insertAtPosition(T value, int position);
    void removeFirst();
    void removeLast();
    void removeAtPosition(int position);
    void display();
    int count();
};

template <typename T>
SinglyLL<T>::SinglyLL() : head(nullptr) {}

template <typename T>
void SinglyLL<T>::insertFirst(T value) {
    PNODE<T> newNode = new Node<T>;
    newNode->data = value;
    newNode->next = head;
    head = newNode;
}

template <typename T>
void SinglyLL<T>::insertLast(T value) {
    PNODE<T> newNode = new Node<T>;
    newNode->data = value;
    newNode->next = nullptr;

    if (head == nullptr) {
        head = newNode;
    } else {
        PNODE<T> current = head;
        while (current->next != nullptr) {
            current = current->next;
        }
        current->next = newNode;
    }
}

template <typename T>
void SinglyLL<T>::insertAtPosition(T value, int position) {
    if (position < 0)
        throw std::out_of_range("Invalid position!");

    if (position == 0) {
        insertFirst(value);
        return;
    }

    PNODE<T> newNode = new Node<T>;
    newNode->data = value;

    PNODE<T> current = head;
    for (int i = 1; i < position; i++) {
        if (current == nullptr)
            throw std::out_of_range("Invalid position!");
        current = current->next;
    }

    newNode->next = current->next;
    current->next = newNode;
}

template <typename T>
void SinglyLL<T>::removeFirst() {
    if (head == nullptr)
        return;

    PNODE<T> temp = head;
    head = head->next;
    delete temp;
}

template <typename T>
void SinglyLL<T>::removeLast() {
    if (head == nullptr)
        return;

    if (head->next == nullptr) {
        delete head;
        head = nullptr;
        return;
    }

    PNODE<T> current = head;
    while (current->next->next != nullptr) {
        current = current->next;
    }

    delete current->next;
    current->next = nullptr;
}

template <typename T>
void SinglyLL<T>::removeAtPosition(int position) {
    if (position < 0)
        throw std::out_of_range("Invalid position!");

    if (position == 0) {
        removeFirst();
        return;
    }

    PNODE<T> current = head;
    for (int i = 0; i < position - 1; i++) {
        if (current == nullptr || current->next == nullptr)
            throw std::out_of_range("Invalid position!");
        current = current->next;
    }

    PNODE<T> temp = current->next;
    current->next = current->next->next;
    delete temp;
}

template <typename T>
void SinglyLL<T>::display() {
    PNODE<T> current = head;
    while (current != nullptr) {
        std::cout << current->data << " ";
        current = current->next;
    }
    std::cout << std::endl;
}

template <typename T>
int SinglyLL<T>::count() {
    int count = 0;
    PNODE<T> current = head;
    while (current != nullptr) {
        count++;
        current = current->next;
    }
    return count;
}
//----------------------------------------------------//
template <typename T>
class DoublyLL {
private:
    PNODE<T> head;
    PNODE<T> tail;

public:
    DoublyLL();
    void insertFirst(T value);
    void insertLast(T value);
    void insertAtPosition(T value, int position);
    void removeFirst();
    void removeLast();
    void removeAtPosition(int position);
    void display();
    int count();
};

template <typename T>
DoublyLL<T>::DoublyLL() : head(nullptr), tail(nullptr) {}

template <typename T>
void DoublyLL<T>::insertFirst(T value) {
    PNODE<T> newNode = new Node<T>;
    newNode->data = value;
    newNode->prev = nullptr;
    newNode->next = head;

    if (head != nullptr) {
        head->prev = newNode;
    } else {
        tail = newNode;
    }

    head = newNode;
}

template <typename T>
void DoublyLL<T>::insertLast(T value) {
    PNODE<T> newNode = new Node<T>;
    newNode->data = value;
    newNode->prev = tail;
    newNode->next = nullptr;

    if (tail != nullptr) {
        tail->next = newNode;
    } else {
        head = newNode;
    }

    tail = newNode;
}

template <typename T>
void DoublyLL<T>::insertAtPosition(T value, int position) {
    if (position < 0)
        throw std::out_of_range("Invalid position!");

    if (position == 0) {
        insertFirst(value);
        return;
    }

    PNODE<T> newNode = new Node<T>;
    newNode->data = value;

    PNODE<T> current = head;
    for (int i = 1; i < position; i++) {
        if (current == nullptr)
            throw std::out_of_range("Invalid position!");
        current = current->next;
    }

    newNode->prev = current;
    newNode->next = current->next;
    if (current->next != nullptr) {
        current->next->prev = newNode;
    } else {
        tail = newNode;
    }
    current->next = newNode;
}

template <typename T>
void DoublyLL<T>::removeFirst() {
    if (head == nullptr)
        return;

    PNODE<T> temp = head;
    head = head->next;

    if (head != nullptr) {
        head->prev = nullptr;
    } else {
        tail = nullptr;
    }

    delete temp;
}

template <typename T>
void DoublyLL<T>::removeLast() {
    if (tail == nullptr)
        return;

    PNODE<T> temp = tail;
    tail = tail->prev;

    if (tail != nullptr) {
        tail->next = nullptr;
    } else {
        head = nullptr;
    }

    delete temp;
}

template <typename T>
void DoublyLL<T>::removeAtPosition(int position) {
    if (position < 0)
        throw std::out_of_range("Invalid position!");

    if (position == 0) {
        removeFirst();
        return;
    }

    PNODE<T> current = head;
    for (int i = 0; i < position; i++) {
        if (current == nullptr)
            throw std::out_of_range("Invalid position!");
        current = current->next;
    }

    if (current->prev != nullptr) {
        current->prev->next = current->next;
    } else {
        head = current->next;
    }

    if (current->next != nullptr) {
        current->next->prev = current->prev;
    } else {
        tail = current->prev;
    }

    delete current;
}

template <typename T>
void DoublyLL<T>::display() {
    PNODE<T> current = head;
    while (current != nullptr) {
        std::cout << current->data << " ";
        current = current->next;
    }
    std::cout << std::endl;
}

template <typename T>
int DoublyLL<T>::count() {
    int count = 0;
    PNODE<T> current = head;
    while (current != nullptr) {
        count++;
        current = current->next;
    }
    return count;
}

//----------------------------------------------------//

template <typename T>
class Singly_CircularLL {
private:
    PNODE<T> head;

public:
    Singly_CircularLL();
    void insertFirst(T value);
    void insertLast(T value);
    void insertAtPosition(T value, int position);
    void removeFirst();
    void removeLast();
    void removeAtPosition(int position);
    void display();
    int count();
};

template <typename T>
Singly_CircularLL<T>::Singly_CircularLL() : head(nullptr) {}

template <typename T>
void Singly_CircularLL<T>::insertFirst(T value) {
    PNODE<T> newNode = new Node<T>;
    newNode->data = value;

    if (head == nullptr) {
        newNode->next = newNode;
    } else {
        PNODE<T> last = head;
        while (last->next != head) {
            last = last->next;
        }
        last->next = newNode;
        newNode->next = head;
    }

    head = newNode;
}

template <typename T>
void Singly_CircularLL<T>::insertLast(T value) {
    PNODE<T> newNode = new Node<T>;
    newNode->data = value;
    newNode->next = head;

    if (head == nullptr) {
        head = newNode;
        newNode->next = newNode;
    } else {
        PNODE<T> last = head;
        while (last->next != head) {
            last = last->next;
        }
        last->next = newNode;
    }
}

template <typename T>
void Singly_CircularLL<T>::insertAtPosition(T value, int position) {
    if (position < 0)
        throw std::out_of_range("Invalid position!");

    if (position == 0) {
        insertFirst(value);
        return;
    }

    PNODE<T> newNode = new Node<T>;
    newNode->data = value;

    PNODE<T> current = head;
    int count = 0;
    while (current->next != head && count < position - 1) {
        current = current->next;
        count++;
    }

    if (count < position - 1)
        throw std::out_of_range("Invalid position!");

    newNode->next = current->next;
    current->next = newNode;
}

template <typename T>
void Singly_CircularLL<T>::removeFirst() {
    if (head == nullptr)
        return;

    PNODE<T> temp = head;

    if (head->next == head) {
        head = nullptr;
    } else {
        PNODE<T> last = head;
        while (last->next != head) {
            last = last->next;
        }
        last->next = head->next;
        head = head->next;
    }

    delete temp;
}

template <typename T>
void Singly_CircularLL<T>::removeLast() {
    if (head == nullptr)
        return;

    PNODE<T> temp = nullptr;
    PNODE<T> current = head;

    while (current->next != head) {
        temp = current;
        current = current->next;
    }

    if (temp == nullptr) {
        head = nullptr;
    } else {
        temp->next = head;
    }

    delete current;
}

template <typename T>
void Singly_CircularLL<T>::removeAtPosition(int position) {
    if (position < 0)
        throw std::out_of_range("Invalid position!");

    if (position == 0) {
        removeFirst();
        return;
    }

    PNODE<T> current = head;
    PNODE<T> prev = nullptr;
    int count = 0;

    while (current->next != head && count < position) {
        prev = current;
        current = current->next;
        count++;
    }

    if (count < position)
        throw std::out_of_range("Invalid position!");

    prev->next = current->next;

    if (current == head)
        head = prev->next;

    delete current;
}

template <typename T>
void Singly_CircularLL<T>::display() {
    if (head == nullptr)
        return;

    PNODE<T> current = head;
    do {
        std::cout << current->data << " ";
        current = current->next;
    } while (current != head);

    std::cout << std::endl;
}

template <typename T>
int Singly_CircularLL<T>::count() {
    if (head == nullptr)
        return 0;

    int count = 0;
    PNODE<T> current = head;
    do {
        count++;
        current = current->next;
    } while (current != head);

    return count;
}

//------------------------------------------------------------//

template <typename T>
class Doubly_CircularLL {
private:
    PNODE<T> head;

public:
    Doubly_CircularLL();
    void insertFirst(T value);
    void insertLast(T value);
    void insertAtPosition(T value, int position);
    void removeFirst();
    void removeLast();
    void removeAtPosition(int position);
    void display();
    int count();
};

template <typename T>
Doubly_CircularLL<T>::Doubly_CircularLL() : head(nullptr) {}

template <typename T>
void Doubly_CircularLL<T>::insertFirst(T value) {
    PNODE<T> newNode = new Node<T>;
    newNode->data = value;

    if (head == nullptr) {
        newNode->prev = newNode;
        newNode->next = newNode;
    } else {
        PNODE<T> last = head->prev;
        newNode->prev = last;
        newNode->next = head;
        head->prev = newNode;
        last->next = newNode;
    }

    head = newNode;
}

template <typename T>
void Doubly_CircularLL<T>::insertLast(T value) {
    PNODE<T> newNode = new Node<T>;
    newNode->data = value;

    if (head == nullptr) {
        newNode->prev = newNode;
        newNode->next = newNode;
        head = newNode;
    } else {
        PNODE<T> last = head->prev;
        newNode->prev = last;
        newNode->next = head;
        head->prev = newNode;
        last->next = newNode;
    }
}

template <typename T>
void Doubly_CircularLL<T>::insertAtPosition(T value, int position) {
    if (position < 0)
        throw std::out_of_range("Invalid position!");

    if (position == 0) {
        insertFirst(value);
        return;
    }

    PNODE<T> newNode = new Node<T>;
    newNode->data = value;

    PNODE<T> current = head;
    int count = 0;
    while (current->next != head && count < position - 1) {
        current = current->next;
        count++;
    }

    if (count < position - 1)
        throw std::out_of_range("Invalid position!");

    newNode->prev = current;
    newNode->next = current->next;
    current->next->prev = newNode;
    current->next = newNode;
}

template <typename T>
void Doubly_CircularLL<T>::removeFirst() {
    if (head == nullptr)
        return;

    PNODE<T> temp = head;

    if (head->next == head) {
        head = nullptr;
    } else {
        PNODE<T> last = head->prev;
        head = head->next;
        head->prev = last;
        last->next = head;
    }

    delete temp;
}

template <typename T>
void Doubly_CircularLL<T>::removeLast() {
    if (head == nullptr)
        return;

    PNODE<T> temp = nullptr;
    PNODE<T> current = head;

    while (current->next != head) {
        temp = current;
        current = current->next;
    }

    if (temp == nullptr) {
        head = nullptr;
    } else {
        temp->next = head;
        head->prev = temp;
    }

    delete current;
}

template <typename T>
void Doubly_CircularLL<T>::removeAtPosition(int position) {
    if (position < 0)
        throw std::out_of_range("Invalid position!");

    if (position == 0) {
        removeFirst();
        return;
    }

    PNODE<T> current = head;
    int count = 0;
    while (current->next != head && count < position) {
        current = current->next;
        count++;
    }

    if (count < position)
        throw std::out_of_range("Invalid position!");

    current->prev->next = current->next;
    current->next->prev = current->prev;

    delete current;
}

template <typename T>
void Doubly_CircularLL<T>::display() {
    if (head == nullptr)
        return;

    PNODE<T> current = head;
    do {
        std::cout << current->data << " ";
        current = current->next;
    } while (current != head);

    std::cout << std::endl;
}

template <typename T>
int Doubly_CircularLL<T>::count() {
    if (head == nullptr)
        return 0;

    int count = 0;
    PNODE<T> current = head;
    do {
        count++;
        current = current->next;
    } while (current != head);

    return count;
}

//--------------------------------------------------//

template <typename T>
class Stack {
private:
    struct Node {
        T data;
        Node* next;
    };

    Node* topNode;
    int count;

public:
    Stack();
    ~Stack();
    void push(T value);
    void pop();
    T top();
    bool isEmpty();
    int countStack();
    void display();
};

template <typename T>
Stack<T>::Stack() {
    topNode = nullptr;
    count = 0;
}

template <typename T>
Stack<T>::~Stack() {
    while (!isEmpty()) {
        pop();
    }
}

template <typename T>
void Stack<T>::display() {
    if (isEmpty()) {
        std::cout << "Stack is empty. Nothing to display." << std::endl;
        return;
    }

    Node* currentNode = topNode;
    while (currentNode != nullptr) {
        std::cout << currentNode->data << " ";
        currentNode = currentNode->next;
    }
    std::cout << std::endl;
}


template <typename T>
void Stack<T>::push(T value) {
    Node* newNode = new Node;
    newNode->data = value;
    newNode->next = topNode;
    topNode = newNode;
    count++;
}


template <typename T>
void Stack<T>::pop() {
    if (isEmpty()) {
        std::cout << "Stack is empty. Cannot pop element." << std::endl;
        return;
    }

    Node* temp = topNode;
    topNode = topNode->next;
    delete temp;
    count--;
}

template <typename T>
T Stack<T>::top() {
    if (isEmpty()) {
        std::cout << "Stack is empty. No top element." << std::endl;
        return T();
    }

    return topNode->data;
}

template <typename T>
bool Stack<T>::isEmpty() {
    return (topNode == nullptr);
}

template <typename T>
int Stack<T>::countStack() {
    return count;
}

//-------------------------------------------------//

template <typename T>
class Queue {
private:
    struct Node {
        T data;
        Node* next;
    };

    Node* frontNode;
    Node* backNode;
    int count;

public:
    Queue();
    ~Queue();
    void push(T value);
    void pop();
    T front();
    T back();
    bool empty();
    int countQueue();
    void display();
};

template <typename T>
Queue<T>::Queue() {
    frontNode = nullptr;
    backNode = nullptr;
    count = 0;
}

template <typename T>
Queue<T>::~Queue() {
    while (!empty()) {
        pop();
    }
}

template <typename T>
void Queue<T>::display() {
    if (empty()) {
        std::cout << "Queue is empty. Nothing to display." << std::endl;
        return;
    }

    Node* currentNode = frontNode;
    while (currentNode != nullptr) {
        std::cout << currentNode->data << " ";
        currentNode = currentNode->next;
    }
    std::cout << std::endl;
}

template <typename T>
void Queue<T>::push(T value) {
    Node* newNode = new Node;
    newNode->data = value;
    newNode->next = nullptr;

    if (empty()) {
        frontNode = newNode;
        backNode = newNode;
    } else {
        backNode->next = newNode;
        backNode = newNode;
    }

    count++;
}

template <typename T>
void Queue<T>::pop() {
    if (empty()) {
        std::cout << "Queue is empty. Cannot pop element." << std::endl;
        return;
    }

    Node* temp = frontNode;
    frontNode = frontNode->next;
    delete temp;

    if (frontNode == nullptr) {
        backNode = nullptr;
    }

    count--;
}

template <typename T>
T Queue<T>::front() {
    if (empty()) {
        std::cout << "Queue is empty. No front element." << std::endl;
        return T();
    }

    return frontNode->data;
}

template <typename T>
T Queue<T>::back() {
    if (empty()) {
        std::cout << "Queue is empty. No back element." << std::endl;
        return T();
    }

    return backNode->data;
}

template <typename T>
bool Queue<T>::empty() {
    return (frontNode == nullptr);
}

template <typename T>
int Queue<T>::countQueue() {
    return count;
}

