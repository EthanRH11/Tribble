#ifndef STACK_HPP
#define STACK_HPP

template <typename T>
class Node
{
public:
    Node() : next(0) {}
    Node(const T &val) : data(val), next(0) {}

private:
    T data;
    Node<T> *next;
};
template <typename T>
class Stack
{
public:
    Stack() : tos(nullptr) {}

    ~Stack();
    Stack(const Stack<T> &);
    Stack<T> &operator=(Stack<T>);
    void swap(Stack<T> &);

    void push(const T &);
    T pop();
    T top() const;
    void display(const Stack<T> &);

    bool isEmpty() const;
    bool isFull() const;

private:
    Node<T> *tos;
};
template <typename T>
Stack<T>::~Stack()
{
    Node<T> *temp = tos;
    while (temp != 0)
    {
        temp = temp->next;
        delete temp;
        temp = tos;
    }
}
template <typename T>
Stack<T>::Stack(const Stack<T> &copy)
{
    Node<T> *bottom;
    Node<T> *temp = copy.tos;
}
template <typename T>
Stack<T> &Stack<T>::operator=(Stack<T> rhs)
{
    swap(rhs);
    return *this;
}
template <typename T>
void Stack<T>::swap(Stack<T> &rhs)
{
    Node<T> *tempTos = tos;
    tos = rhs.tos;
    rhs.tos = tempTos;
}
template <typename T>
void Stack<T>::push(const T &val)
{
    assert(!isFull());
    Node<T> *temp = new Node<T>(val);
    temp->next = tos;
    tos = temp;
}
template <typename T>
T Stack<T>::pop()
{
    assert(!isEmpty());
    Node<T> *temp = tos;
    T newData = tos->data;
    tos = tos->next;
    delete temp;
    return newData;
}
template <typename T>
T Stack<T>::top() const
{
    return tos->data;
}
template <typename T>
void Stack<T>::display(const Stack<T> &)
{
}
template <typename T>
bool Stack<T>::isEmpty() const
{
    return tos == nullptr;
}
template <typename T>
bool Stack<T>::isFull() const
{
    Node<T> *temp = new (std::nothrow) Node<T>();
    if (temp == nullptr)
    {
        return true;
    }
    delete temp;
    return false;
}
#endif