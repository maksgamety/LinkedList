#include <iostream>

using namespace std;


// Struktura reprezentujaca pojedynczy element listy (wezel)
struct Pair {
    int data;
    Pair* next;

    Pair(int value) :
        data(value),
        next(nullptr) {
    }
};

// Klasa implementuj¹ca listê jednokierunkow¹
class LinkedList {
private:
    // wskaznik na pierwszy element tablicy
    Pair* head;

public:
    // Konstruktor klasy - inicjalizuje pusta liste (head = nullptr)
    LinkedList() : head(nullptr) {}

    // Destruktor - wywoluje metode clear() aby zwolnic pamiec
    ~LinkedList() {
        clear();
    }

    // Metoda dodaj¹ca element na koniec listy
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

    // Metoda pobierajaca element o zadanym indeksie
    int get(int index) {
        Pair* tmp = head;
        int i = 0;

        while (tmp != nullptr) {
            if (i == index) {
                return tmp->data;
            }
            tmp = tmp->next;
            i++;
        }
        return 0;
    }

    // Metoda czyszczaca liste (zwalniajaca pamiec)
    void clear() {
        Pair* tmp = head;

        while (tmp != nullptr) {
            Pair* next = tmp->next;
            delete tmp;
            tmp = next;
        }
        head = nullptr;
    }
};



// Program glowny - przyklad uzycia listy:
int main()
{
    // Tworzy pusta liste
    LinkedList list;

    // Dodaje dwa elementy
    list.pushBack(7);
    list.pushBack(1);

    // Wyswietla elementy o indeksach 0 i 1
    cout << list.get(0) << endl;
    cout << list.get(1) << endl;

    // Czyci liste
    list.clear();

    // Proba wyswietlenia elementy z pustej listy
    cout << list.get(0) << endl;
    cout << list.get(1) << endl;
}