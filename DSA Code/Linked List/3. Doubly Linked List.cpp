#include<iostream>
using namespace std;

class Customer {
    public:
    string name;
    int id;
    Customer *next = nullptr, *prev = nullptr;
    Customer(string name, int id) {
        this->name = name;
        this->id = id;
    }
};

class List {
    Customer *head;
    public:
    List(string name, int id) {
        head = new Customer(name,id);
    }

    bool isEmpty() {
        return head == nullptr;
    }

    void insertAtStart(string name, int id) {
        Customer *temp = new Customer(name,id);
        if(head != nullptr) {
            temp->next = head;
            head->prev = temp;
        }
        head = temp;
    }

    void insertAtLast(string name, int id)
    {
        Customer *temp = new Customer(name,id);
        if(head == nullptr) {
            head = temp;
            return;
        }
        Customer *last = head;
        while(last->next != nullptr) {
            last = last->next;
        }
        last->next = temp;
        temp->prev = last;
    }

    void showList() {
        cout<<"Customer id | Customer Name" <<endl;
        Customer *temp = head;
        while(temp != nullptr) {
            cout<<temp->id <<"         | " <<temp->name <<endl;
            temp = temp->next;
        }
        cout<<"----------------------------" <<endl;
    }

    Customer* searchCustomer(int id)
    {
        Customer* temp = head;
        while(temp != nullptr) {
            if(temp->id == id) {
                return temp;
            }
            temp = temp->next;
        }
        return nullptr;
    }

    void insertAfter(Customer *c, string name, int id)
    {
        if(c == nullptr) {
            return;
        }
        Customer *temp = new Customer(name,id);
        temp->next = c->next;
        temp->prev = c;
        if(c->next != nullptr) {
            c->next->prev = temp;
        }
        c->next = temp;
    }

    void deleteFirst() {
        if(head == nullptr) return;

        Customer *temp = head;
        head = head->next;
        if(head != nullptr) {
            head->prev = nullptr;
        }
        delete temp;
    }

    void deleteLast()
    {
        if(head == nullptr) {
            return;
        }

        Customer *temp = head;
        if(temp->next == nullptr) {
            delete head;
            head = nullptr;
            return;
        }

        while(temp->next != nullptr) {
            temp = temp->next;
        }
        temp->prev->next = nullptr;
        delete temp;
    }

    void deleteCustomer(int id) {
        Customer *temp = head;
        while(temp != nullptr) {
            if(temp->id == id) {
                if(temp->prev != nullptr) {
                    temp->prev->next = temp->next;
                }
                else {
                    head = temp->next;
                }
                    
                if(temp->next != nullptr) {
                    temp->next->prev = temp->prev;
                }

                delete temp;
                return;
            }
            temp = temp->next;
        }
    }

    void clearList() {
        Customer *temp = head;
        while(head != nullptr) {
            head = head->next;
            delete temp;
            temp = head;
        }
    }

    ~List() {
        clearList();
    }
};

int main()
{
    List l1("Shaheer Sheraz", 102);
    l1.showList();

    l1.insertAtStart("Abdullah",101);
    l1.showList();

    l1.insertAtLast("Talha Raza",104);
    l1.showList();

    l1.insertAfter(l1.searchCustomer(102),"Fazal Shah",103);
    l1.showList();
    
    l1.insertAtLast("Ahmed", 105);
    l1.showList();

    l1.deleteFirst();
    l1.showList();

    l1.deleteLast();
    l1.showList();

    l1.deleteCustomer(103);
    l1.showList();

    l1.clearList();
    l1.showList();
    
    return 0;
}
