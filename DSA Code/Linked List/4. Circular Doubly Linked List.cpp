#include<iostream>
using namespace std;

class Student {
    public:
    string rollno;
    string name;
    Student *next = nullptr, *prev = nullptr;
    Student(string rollno, string name) {
        this-> rollno = rollno;
        this->name = name;
    }
};

class List {
    Student *head = nullptr;
    public:
    List(string rollno, string name) {
        head = new Student(rollno,name);
        head->next = head;
        head->prev = head;
    }

    bool isEmpty() {
        if( head == nullptr ) {
            return true;
        }
        else {
            return false;
        }
    }

    void insertAtStart(string rollno, string name) {
        if(head == nullptr) {
            head = new Student(rollno,name);
            head->next = head;
            head->prev = head;
        }
        else {
            Student *temp = new Student(rollno,name);
            temp->next = head;
            temp->prev = head->prev;
            head->prev->next = temp;
            head->prev = temp;
            head = temp;
        }
    }

    void insertAtLast(string rollno, string name) {
        if(head == nullptr) {
            head = new Student(rollno,name);
            head->next = head;
            head->prev = head;
        } 
        else {
            Student *temp = new Student(rollno,name);
            temp->next = head;
            temp->prev = head->prev;
            head->prev->next = temp;
            head->prev = temp;
        }
    }

    void showList() {
        if(head == nullptr) {
            cout<<"List is Empty!" <<endl;
        }
        else {
            Student *temp = head;
            cout<<"Roll Number    |   Name" <<endl;
            while(temp->next != head) {
                cout<<temp->rollno <<"   |   " <<temp->name <<endl;
                temp = temp->next;
            }
            cout<<temp->rollno <<"   |   " <<temp->name <<endl;
        }
        cout<<"---------------------------------------------" <<endl;
    }

    Student* searchStudent(string rollno) {
        if(head != nullptr) {
            Student *temp = head;
            while(temp->next != head) {
                if(temp->rollno == rollno) {
                    return temp;
                }
                temp = temp->next;
            }
            if(temp->rollno == rollno) {
                return temp;
            }
        }
        return nullptr;
    }

    void insertAfter(Student *n, string rollno, string name) {
        if(n == nullptr) {
            cout<<"Student doesn't Exist!" <<endl;
        }
        else {
            // only one student
            if((n->next == head) && (n->prev == head)) {
                Student *temp = new Student(rollno,name);
                temp->next = head;
                temp->prev = n;
                n->next = temp;
                n->prev = temp;
            }
            // more than one Students exist and last node
            else if((n->next == head) && ( n->prev != head)) {
                Student *temp = new Student(rollno,name);
                temp->next = head;
                temp->prev = n;
                n->next = temp;
                head->prev = temp;
            }
            // middle nodes
            else {
                Student *temp = new Student(rollno,name);
                temp->next = n->next;
                temp->prev = n;
                n->next->prev = temp;
                n->next = temp;
            }
        }
    }

    void deleteFirst() {
        if(head != nullptr) {
            if(head->next == head) {
                delete head;
                head = nullptr;
            }
            else {
                Student *temp = head;
                head->prev->next = head->next;
                head->next->prev = head->prev;
                head = head->next;
                delete temp;
            }
        }
    }

    void deleteLast() {
        if(head != nullptr) {
            if(head->next == head) {
                delete head;
                head = nullptr;
            }
            else {
                Student *temp = head->prev;
                head->prev->prev->next = head;
                head->prev = head->prev->prev;
                delete temp;
            }
        }
    }

    void deleteStudent(Student *s) {
        if(s != nullptr) {
            // case for only one student
            if((s->next == head) && (s->prev == head)) {
                delete head;
                head = nullptr;
            }
            // case for 1st student but more than one student exists
            else if((s == head) && (s->next != head)) {
                s->prev->next = s->next;
                s->next->prev = s->prev;
                head = s->next;
                delete s;
            }
            // case for last node
            else if((s->next == head) && (s->prev != head)) {
                s->prev->next = head;
                s->next->prev = s->prev;
                delete s;
            }
            // case for middle nodes
            else {
                s->next->prev = s->prev;
                s->prev->next = s->next;
                delete s;
            }
        }
    }

    void clearList() {
        if(head != nullptr) {
            Student *temp = head;
            while(temp->next != temp) {
                head->next->prev = head->prev;
                head->prev->next = head->next;
                head = head->next;
                delete temp;
                temp = head;
            }
            delete temp;
            head = nullptr;
        }
    }

    ~List() {
        clearList();
    }
};

int main () {
    List l1("23014198-002","Asjad Hafeez");
    l1.showList();

    l1.insertAtStart("23014198-001","Fazal Shah");
    l1.showList();

    l1.insertAtStart("23014198-004","Talha Raza");
    l1.showList();

    l1.insertAfter(l1.searchStudent("23014198-002"),"23014198-003","Syed Haroon Bukhari");
    l1.showList();
 
    l1.insertAtLast("23014198-005","Ayesha Azhar");
    l1.showList();

    l1.deleteFirst();
    l1.showList();

    l1.deleteLast();
    l1.showList();

    l1.deleteStudent(l1.searchStudent("23014198-002"));
    l1.showList();

    l1.clearList();
    l1.showList();

    return 0;
}
