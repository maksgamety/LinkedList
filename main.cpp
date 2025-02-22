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

public:
    LinkedList() : head(nullptr) {}

    ~LinkedList() {
        clear();
    }

    void pushBack(int value) {
        Pair* newPair = new Pair(value);

        if (head == nullptr) {
            head = newPair;
        }
        else {
            Pair* tmp = head;

            while (tmp->next != nullptr) {
                tmp = tmp->next;
            }
            tmp->next = newPair;
        }
    }

    int& get(int index) {
        Pair* tmp = head;
        int i = 0;

        while (tmp != nullptr) {
            if (i == index) {
                return tmp->data;
            }
            tmp = tmp->next;
            i++;
        }
        throw out_of_range("Out of bounds error");
    }

    void clear() {
        Pair* tmp = head;

        while (tmp != nullptr) {
            Pair* next = tmp->next;
            delete tmp;
            tmp = next;
        }
        head = nullptr
;
    }
    int& operator[](int index) {
		return get(index);
    }
};

int main() {
    LinkedList list;

    list.pushBack(7);
    list.pushBack(1);

    list[0] = 2;

    cout << list[0] << endl;
    cout << list[1] << endl;

    //list.clear();

    //cout << list[0] << endl;
    //cout << list[1] << endl;
}
