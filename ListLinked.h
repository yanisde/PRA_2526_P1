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
void check_get_pos(int pos) const {
        if (pos < 0 || pos >= n)
            throw std::out_of_range("pos fuera de rango");
    }

    void check_insert_pos(int pos) const {
        if (pos < 0 || pos > n)
            throw std::out_of_range("pos fuera de rango");
    }

    Node<T>* nodeAt(int pos) const {
        Node<T>* curr = first;
        for (int i = 0; i < pos; i++)
            curr = curr->next;
        return curr;
    }
public:
    ListLinked() : first(nullptr), n(0) {}

    ~ListLinked() {
        while (first != nullptr) {
            Node<T>* tmp = first;
            first = first->next;
            delete tmp;
        }
    }
    void insert(int pos, T e) override {
        check_insert_pos(pos);

        if (pos == 0) {
            first = new Node<T>(e, first);
        } else {
            Node<T>* prev = nodeAt(pos - 1);
            prev->next = new Node<T>(e, prev->next);
        }
        n++;
    }

    void append(T e) override {
        insert(n, e);
    }

    void prepend(T e) override {
        insert(0, e);
    }

    T remove(int pos) override {
        check_get_pos(pos);

        Node<T>* removed;
        if (pos == 0) {
            removed = first;
            first = first->next;
        } else {
            Node<T>* prev = nodeAt(pos - 1);
            removed = prev->next;
            prev->next = removed->next;
        }

        T data = removed->data;
        delete removed;
        n--;
        return data;
    }

    T get(int pos) override {
        check_get_pos(pos);
        return nodeAt(pos)->data;
    }

    int search(T e) override {
        Node<T>* curr = first;
        int i = 0;
        while (curr != nullptr) {
            if (curr->data == e) return i;
            curr = curr->next;
            i++;
        }
        return -1;
    }

    bool empty() override {
        return n == 0;
    }

    int size() override {
        return n;
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

