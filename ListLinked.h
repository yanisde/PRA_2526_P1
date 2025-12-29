#ifndef LISTLINKED_H
#define LISTLINKED_H

#include <stdexcept>
#include <ostream>
#include "List.h"
#include "Node.h"

template <typename T>
class ListLinked : public List<T> {
private:
    Node<T>* first;
    int n;

public:
    ListLinked() : first(nullptr), n(0) {}

    ~ListLinked() {
        while (first != nullptr) {
            Node<T>* tmp = first;
            first = first->next;
            delete tmp;
        }
    }

    T operator[](int pos) {
        if (pos < 0 || pos >= n)
            throw std::out_of_range("pos fuera de rango");

        Node<T>* curr = first;
        for (int i = 0; i < pos; i++)
            curr = curr->next;

        return curr->data;
    }

    friend std::ostream& operator<<(std::ostream& out, const ListLinked<T>& list) {
        out << "[";
        Node<T>* curr = list.first;
        while (curr != nullptr) {
            out << curr->data;
            if (curr->next != nullptr)
                out << ", ";
            curr = curr->next;
        }
        out << "]";
        return out;
    }
};

#endif

