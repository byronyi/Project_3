#ifndef DEQUE_H
#define DEQUE_H

#include <iterator>

template <class T>
class Deque
{
public:

    struct List
    {
        List* prev;
        List* next;
        T data;
    };

    struct Iterator : public std::iterator<std::bidirectional_iterator_tag, T>
    {
        List* p;
    public:
        Iterator(List* x) : p(x) {}
        Iterator(const Iterator& mit) : p(mit.p) {}
        Iterator& operator++() {p = p->next;return *this;}
        Iterator operator++(int) {Iterator tmp(*this); operator++(); return tmp;}
        Iterator& operator--() {p = p->prev; return *this;}
        Iterator operator--(int) {Iterator tmp(*this); operator--(); return tmp;}
        bool operator==(const List& rhs) {return p==rhs.p;}
        bool operator!=(const List& rhs) {return p!=rhs.p;}
        T& operator*() {return p->data;}
    };

    Deque(): head(0), end(0), _size(0){}

    ~Deque(){

    }
    bool isEmpty() const {return _size != 0;}
    int size() const {return _size;}

    void addFirst(const T& item) {

        if(_size == 0) {

            head = new List;
            head->data = item;
            head->prev = 0;
            head->next = 0;
            end = head;

        }
        else {

        List* temp = new List;
        head->prev = temp;
        temp->next = head;
        temp->prev = 0;
        temp->data = item;
        head = temp;

        }

        ++_size;

    }

    void addLast(const T& item) {

        if(_size == 0) {

            end = new List;
            end->data = item;
            end->prev = 0;
            end->next = 0;
            head = end;
        }
        else {

        List* temp = new List;
        end->next = temp;
        temp->prev = end;
        temp->next = 0;
        temp->data = item;
        end = temp;

        }

        ++_size;

    }


    T removeFirst() {

        List* temp = head;
        T data = temp->data;
        head = head->next;
        delete temp;
        --_size;
        return data;

    }

    T removeLast() {

        List* temp = end;
        T data = temp->data;
        end = end->prev;
        delete temp;
        --_size;
        return data;

    }

    Iterator iterator() {return Iterator(head);}

private:
    List* head;
    List* end;
    unsigned int _size;
};

#endif // DEQUE_H
