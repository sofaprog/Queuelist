#pragma once

// программа для реализации очереди на связном списке
template<class T>
struct Node {
    T data;
    Node* next;
};

template<class T>
class Queue {
    Node<T>* front;
    Node<T>* rear;

public:
    Queue()
        : front(nullptr), rear(nullptr)
    {
    }
    Queue(const Queue& other)
        : front(nullptr), rear(nullptr)
    {
        Node<T>* temp = other.front;
        while (temp != nullptr) {
            enqueue(temp->data);
            temp = temp->next;
        }
    }
    ~Queue()
    {
        while (!isEmpty()) {
            dequeue();
        }
    }
    Queue& operator=(const Queue& other)
    {
        if (this != &other) {
            while (!isEmpty()) {
                dequeue();
            }
            Node<T>* temp = other.front;
            while (temp != nullptr) {
                enqueue(temp->data);
                temp = temp->next;
            }
        }
        return *this;
    }
    bool isEmpty() const
    {
        return front == nullptr;
    }
    bool operator==(const Queue& other) const
    {
        if (isEmpty() && other.isEmpty()) {
            return true;
        }
        Node<T>* thisTemp = front;
        Node<T>* otherTemp = other.front;
        while (thisTemp != nullptr && otherTemp != nullptr) {
            if (thisTemp->data != otherTemp->data) {
                return false;
            }
            thisTemp = thisTemp->next;
            otherTemp = otherTemp->next;
        }
        return thisTemp == nullptr && otherTemp == nullptr;
    }
    bool operator !=(const Queue& other) const {
        return !(*this == other);
    }
    void enqueue(T x)
    {
        Node<T>* newNode = new Node<T>{ x, nullptr };
        if (rear == nullptr) {
            front = rear = newNode;
        }
        else {
            rear->next = newNode;
            rear = newNode;
        }
    }
    void dequeue()
    {
        if (front == nullptr) throw -1;
        Node<T>* temp = front;
        front = front->next;
        if (front == nullptr) rear = nullptr;
        delete temp;
    }
    T peekhead()
    {
        if (!isEmpty())
            return front->data;
        else
            throw - 1;
    }
    T peektail()
    {
        if (!isEmpty())
            return rear->data;
        else
            throw - 1;
    }
};
//meow
/*/\_/\
 ( o.o )
  > ^ <*/