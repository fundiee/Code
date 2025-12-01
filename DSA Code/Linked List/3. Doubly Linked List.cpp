#include<iostream>
using namespace std;

class Customer // customer class
{
    public:
    string name;
    int id;
    Customer *next = NULL, *prev = NULL;
    Customer(string name, int id) // constructor
    {
        this->name = name;
        this->id = id;
    }
};

class List // List class
{
    Customer *head;
    public:
    List(string name, int id) // constructor
    {
        head = new Customer(name,id);
    }
    bool is_empty() // function
    {
        if(head == NULL)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    void insert_at_start(string name, int id) // function
    {
        if(head == NULL)
        {
            Customer *temp = new Customer(name,id);
        }
        else
        {
            Customer *temp = new Customer(name,id);
            temp->next = head;
            head->prev = temp;
            head = temp;
        }
    }
    void insert_at_last(string name, int id) // function
    {
        if(head == NULL)
        {
            head = new Customer(name,id);
        }
        else
        {
            Customer *temp = head;
            while(temp->next != NULL)
            {
                temp = temp->next;
            }
            temp->next = new Customer(name,id);
            temp->next->prev = temp;
        }
    }
    void show_list() // function
    {
        cout<<"Customer id | Customer Name" <<endl;
        Customer *temp = head;
        while(temp != NULL)
        {
            cout<<temp->id <<"         | " <<temp->name <<endl;
            temp =temp->next;
        }
        cout<<"----------------------------" <<endl;
    }
    Customer* search_Customer(int id) // function
    {
        if(head == NULL)
        {
            return NULL;
        }
        else
        {
            Customer* temp = head;
            while(temp != NULL)
            {
                if(temp->id == id)
                {
                    return temp;
                }
                temp = temp->next;
            }
            return NULL;
        }
    }
    void insert_after(Customer *c, string name, int id) // function
    {
        if(c->next == NULL) // if last customer
        {
            c->next = new Customer(name,id);
            c->next->prev = c;
        }
        else // if middle customer
        {
            Customer *temp = new Customer(name,id);
            temp->next = c->next;
            temp->prev = c;
            c->next->prev = temp;
            c->next = temp;
        }
    }
    void delete_first() // function
    {
        if(head->next == NULL)
        {
            delete head;
            head = NULL;
        }
        else
        {
            Customer *temp = head;
            head = head->next;
            head->prev = NULL;
            delete temp;
        }
    }
    void delete_last() // function
    {
        if(head->next == NULL) // only 1 customer
        {
            delete head;
            head = NULL;
        }
        else
        {
            Customer *temp = head; // last customer
            while(temp->next != NULL)
            {
                temp = temp->next;
            }
            temp->prev->next = NULL;
            delete temp;
        }
    }
    void delete_customer(int id) // function
    {
        if(head->next == NULL) // first Customer case:1
        {
            if(head->id == id)
            {
                delete head;
                head = NULL;
                return;
            }
        }
        else if(head->next != NULL) // first customer case:2
        {
            if(head->id == id)
            {
                Customer *temp = head;
                head = head->next;
                head->prev = NULL;
                delete temp;
                return;
            }
        }

        Customer *temp = head;
        while(temp != NULL)
        {
            if(temp->next == NULL) // last customer case
            {
                if(temp->id == id)
                {
                    temp->prev->next = NULL;
                    delete temp;
                    break;
                }
                temp = temp->next;
            }
            else
            {
               if(temp->id == id) // middle customer case
                {
                    Customer *t = temp;
                    temp->prev->next = temp->next;
                    temp->next->prev = temp->prev;
                    delete t;
                    break;
                }
                 temp = temp->next;
            }
        }  
    }
    void clear_list() // function
    {
        Customer *temp = head;
        while(head != NULL)
        {
            head = head->next;
            delete temp;
            temp = head;
        }
    }
    ~List() // destructor
    {
        clear_list();
    }
};

int main() // main function
{
    List l1("Shaheer Sheraz", 102);
    l1.show_list();

    l1.insert_at_start("Abdullah",101);
    l1.show_list();

    l1.insert_at_last("Talha Raza",104);
    l1.show_list();

    l1.insert_after(l1.search_Customer(102),"Fazal Shah",103);
    l1.show_list();
    
    l1.insert_at_last("Ahmed", 105);
    l1.show_list();

    l1.delete_first();
    l1.show_list();

    l1.delete_last();
    l1.show_list();

    l1.delete_customer(103);
    l1.show_list();

    l1.clear_list();
    l1.show_list();
    
    return 0;
}