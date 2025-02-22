#include <iostream>

using namespace std;

struct Pair {
    int data;
    Pair* next;

    Pair(int value) :
        data(value),
        next(nullptr) {
    }
};

class LinkedList {
private:
    Pair* head;
    int size;
public:
    LinkedList() : head(nullptr), size(0) {}

    LinkedList(const LinkedList& other) : head(nullptr), size(0) {
        Pair* tmp = other.head;
        while (tmp) {
            pushBack(tmp->data);
            tmp = tmp->next;
        }
    }

    LinkedList& operator=(const LinkedList& other) {
        if (this == &other) return *this;
        clear();
        Pair* tmp = other.head;
        while (tmp) {
            pushBack(tmp->data);
            tmp = tmp->next;
        }
        return *this;
    }

    ~LinkedList() {
        clear();
    }

    void pushBack(int value) {
        size++;
        Pair* newPair = new Pair(value);

        if (!head) {
            head = newPair;
        }
        else {
            Pair* tmp = head;
            while (tmp->next) {
                tmp = tmp->next;
            }
            tmp->next = newPair;
        }
    }

    int& get(int index) {
        if (index < 0 || index >= size) {
            throw out_of_range("Out of bounds error");
        }

        Pair* tmp = head;
        for (int i = 0; i < index; i++) {
            tmp = tmp->next;
        }
        return tmp->data;
    }

    void clear() {
        Pair* tmp = head;
        while (tmp) {
            Pair* next = tmp->next;
            delete tmp;
            tmp = next;
        }
        head = nullptr;
        size = 0;
    }

    int getSize() const {
        return size;
    }

    int& operator[](int index) {
        return get(index);
    }

    LinkedList operator+(const LinkedList& otherList) const {
        LinkedList result(*this);
        Pair* tmp = otherList.head;
        while (tmp) {
            result.pushBack(tmp->data);
            tmp = tmp->next;
        }
        return result;
    }

    void operator+=(const LinkedList& otherList) {
        Pair* tmp = otherList.head;
        while (tmp) {
            pushBack(tmp->data);
            tmp = tmp->next;
        }
    }
};

int main() {
    LinkedList list1;
    list1.pushBack(7);
    list1.pushBack(1);
    list1[0] = 2;

    cout << list1[0] << endl;
    cout << list1[1] << endl;
    cout << "rozmiar: " << list1.getSize() << endl;

    LinkedList list2;
    list2.pushBack(8);
    list2.pushBack(4);

    list1 += list2;

    cout << "Lista list1 po u¿yciu operatora +=" << endl;
    for (int i = 0; i < list1.getSize(); i++) {
        cout << "Element: " << list1[i] << endl;
    }

    return 0;
}