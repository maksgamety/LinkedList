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
    int size{};
public:
    LinkedList() : head(nullptr) {}

    ~LinkedList() {
        clear();
    }

    void pushBack(int value) {
        size++;

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
        head = nullptr;
        size = 0;
    }

    int getSize() const {
        return size;
    }

    int& operator[](int index) {
		return get(index);
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

    //list.clear();

    //cout << list[0] << endl;
    //cout << list[1] << endl;

    //LinkedList list2;

    //list2.pushBack(8);
    //list2.pushBack(4);

    //list1 + list2;
}
