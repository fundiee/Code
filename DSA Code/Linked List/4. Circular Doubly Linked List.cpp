#include<iostream>
using namespace std;

class Student // Student class
{
    public:
    string rollno;
    string name;
    Student *next = NULL, *prev = NULL;
    Student(string rollno, string name) // constructor
    {
        this-> rollno = rollno;
        this->name = name;
    }
};

class List // List class
{
    Student *head = NULL;
    public:
    List(string rollno, string name) // constructor
    {
        head = new Student(rollno,name);
        head->next = head;
        head->prev = head;
    }

    bool is_empty() // function
    {
        if( head == NULL )
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    void insert_at_start(string rollno, string name) // function
    {
        if(head == NULL)
        {
            head = new Student(rollno,name);
            head->next = head;
            head->prev = head;
        }
        else
        {
            Student *temp = new Student(rollno,name);
            temp->next = head;
            temp->prev = head->prev;
            head->prev->next = temp;
            head->prev = temp;
            head = temp;
        }
    }

    void insert_at_last(string rollno, string name) // function
    {
        if(head == NULL)
        {
            head = new Student(rollno,name);
            head->next = head;
            head->prev = head;
        } 
        else
        {
            Student *temp = new Student(rollno,name);
            temp->next = head;
            temp->prev = head->prev;
            head->prev->next = temp;
            head->prev = temp;
        }
    }

    void show_list() // function
    {
        if(head == NULL)
        {
            cout<<"List is Empty!" <<endl;
        }
        else
        {
            Student *temp = head;
            cout<<"Roll Number    |   Name" <<endl;
            while(temp->next != head)
            {
                cout<<temp->rollno <<"   |   " <<temp->name <<endl;
                temp = temp->next;
            }
            cout<<temp->rollno <<"   |   " <<temp->name <<endl;
        }
        cout<<"---------------------------------------------" <<endl;
    }

    Student* search_student(string rollno) // function
    {
        if(head != NULL)
        {
            Student *temp = head;
            while(temp->next != head)
            {
                if(temp->rollno == rollno)
                {
                    return temp;
                }
                temp = temp->next;
            }
            if(temp->rollno == rollno)
            {
                return temp;
            }
        }
        return NULL;
    }

    void insert_after(Student *n, string rollno, string name) // function
    {
        if(n == NULL)
        {
            cout<<"Student doesn't Exist!" <<endl;
        }
        else
        {
            if((n->next == head) && (n->prev == head)) // only one student
            {
                Student *temp = new Student(rollno,name);
                temp->next = head;
                temp->prev = n;
                n->next = temp;
                n->prev = temp;
            }
            else if((n->next == head) && ( n->prev != head)) // more than one Students exist and last node
            {
                Student *temp = new Student(rollno,name);
                temp->next = head;
                temp->prev = n;
                n->next = temp;
                head->prev = temp;
            }
            else // middle nodes
            {
                Student *temp = new Student(rollno,name);
                temp->next = n->next;
                temp->prev = n;
                n->next->prev = temp;
                n->next = temp;
            }
        }
    }

    void delete_first() // function
    {
        if(head != NULL)
        {
            if(head->next == head)
            {
                delete head;
                head = NULL;
            }
            else
            {
                Student *temp = head;
                head->prev->next = head->next;
                head->next->prev = head->prev;
                head = head->next;
                delete temp;
            }
        }
    }

    void delete_last() // function
    {
        if(head != NULL)
        {
            if(head->next == head)
            {
                delete head;
                head = NULL;
            }
            else
            {
                Student *temp = head->prev;
                head->prev->prev->next = head;
                head->prev = head->prev->prev;
                delete temp;
            }
        }
    }

    void delete_student(Student *s) // function
    {
        if(s != NULL)
        {
            if((s->next == head) && (s->prev == head)) // case for only one student
            {
                delete head;
                head == NULL;
            }
            else if((s == head) && (s->next != head)) // case for 1st student but more than one student exists
            {
                s->prev->next = s->next;
                s->next->prev = s->prev;
                head = s->next;
                delete s;
            }
            else if((s->next == head) && (s->prev != head)) // case for last node
            {
                s->prev->next = head;
                s->next->prev = s->prev;
                delete s;
            }
            else // case for middle nodes
            {
                s->next->prev = s->prev;
                s->prev->next = s->next;
                delete s;
            }
        }
    }

    void clear_list() // function
    {
        if(head != NULL)
        {
            Student *temp = head;
            while(temp->next != temp)
            {
                head->next->prev = head->prev;
                head->prev->next = head->next;
                head = head->next;
                delete temp;
                temp = head;
            }
            delete temp;
            head = NULL;
        }
    }

    ~List() // destructor
    {
        clear_list();
    }
};

int main () // main function
{
    List l1("23014198-002","Asjad Hafeez");
    l1.show_list();

    l1.insert_at_start("23014198-001","Fazal Shah");
    l1.show_list();

    l1.insert_at_last("23014198-004","Talha Raza");
    l1.show_list();

    l1.insert_after(l1.search_student("23014198-002"),"23014198-003","Syed Haroon Bukhari");
    l1.show_list();

    l1.insert_at_last("23014198-005","Ayesha Azhar");
    l1.show_list();

    l1.delete_first();
    l1.show_list();

    l1.delete_last();
    l1.show_list();

    l1.delete_student(l1.search_student("23014198-002"));
    l1.show_list();

    l1.clear_list();
    l1.show_list();

    return 0;
}