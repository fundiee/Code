// one to one function so, no collision
#include<iostream>
#include<string>
using namespace std;

class Student
{
    public:
    long long rollno;
    string name, department, section, semester, contact;
    // address etc not implemented
    Student(long long rollno, string name,string department, string semester, string section, string contact)
    {
        this->rollno = rollno;
        this->name = name;
        this->department = department;
        this->semester = semester;
        this->section = section;
        this->contact = contact;
    }
};

class DataBase
{
    Student **array = nullptr;
    int size;
    long long firstRollno;
    public:
    DataBase(int size, long long firstRollno)
    {
        this->size = size;
        this->firstRollno = firstRollno;
        array = new Student*[size];
        for(int i = 0; i < size; i++)
        {
            array[i] = nullptr;
        }
    }
    int hashFunction(long long key)
    {
        return (key-1)%size;
    }

    // O(1) Time Complexity
    void insertStudent(long long rollno, string name,string department, string semester, string section, string contact)
    {
        if(array != nullptr)
        {
            int index = hashFunction(rollno);
            if(array[index] == nullptr)
            {
                array[index] = new Student(rollno,name,department,semester,section,contact);
            }
        }
        else
        {
            cout<<"Hash Table doesn't Exist!" <<endl;
        }
    }

    // O(1) Time Complexity
    void showStudent(long long rollno)
    {
        cout<<"----------Student Info----------" <<endl;
        int index = hashFunction(rollno);
        if(array[index] != nullptr)
        {
            cout<<"Rollno: " <<array[index]->rollno <<endl <<"Name: " <<array[index]->name <<endl;
            cout<<"Department: " <<array[index]->department <<endl <<"Semester: " <<array[index]->semester <<endl;
            cout<<"Section: " <<array[index]->section <<endl <<"Contact: " <<array[index]->contact <<endl;
        }
        else
        {
            cout<<"Student doesn't Exist!" <<endl;
        }
        cout<<"------------------------------------------" <<endl <<endl <<endl;
    }

    // O(n) Time Complexity
    void showTable()
    {
        if(array != nullptr)
        {
            int index = hashFunction(firstRollno);
            int i;
            for(i = index; i+1 != index; i = (i+1)%size)
            {
                if(array[i] == nullptr)
                {
                    continue;
                }
                cout<<"Rollno: " <<array[i]->rollno <<endl <<"Name: " <<array[i]->name <<endl;
                cout<<"Department: " <<array[i]->department <<endl <<"Semester: " <<array[i]->semester <<endl;
                cout<<"Section: " <<array[i]->section <<endl <<"Contact: " <<array[i]->contact <<endl;
                cout<<"------------------------------------------" <<endl;
            }
            if(array[i] != nullptr)
            {
                cout<<"Rollno: " <<array[i]->rollno <<endl <<"Name: " <<array[i]->name <<endl;
                cout<<"Department: " <<array[i]->department <<endl <<"Semester: " <<array[i]->semester <<endl;
                cout<<"Section: " <<array[i]->section <<endl <<"Contact: " <<array[i]->contact <<endl;
                cout<<"------------------------------------------" <<endl;
            }
            cout<<endl <<endl;
        }  
    }

    // O(1) Time Complexity
    void deleteStudent(long long rollno)
    {
        int index = hashFunction(rollno);
        if(array[index] != nullptr)
        {
            delete array[index];
            array[index] = nullptr;
        }
    }

    void deleteTable()
    {
        if(array != nullptr)
        {
            for(int i = 0; i < size; i++)
            {
                if(array[i] != nullptr)
                {
                    delete array[i];
                    array[i] = nullptr;
                }
            }
            delete []array;
            array = nullptr;
        } 
    }
    
    void createTable(int size,long long firstRollno)
    {
        if(array == nullptr)
        {
            this->size = size;
            this->firstRollno = firstRollno;
            array = new Student*[size];
            for(int i = 0; i < size; i++)
            {
                array[i] = nullptr;
            }
        }
        else
        {
            cout<<"Records Already Exist in Hash Table, First delete it" <<endl;
        }
        
    }

    ~DataBase()
    {
        deleteTable();
    }
};

int main()
{
    // Rollno range: 23014198001 to 23014198180 for Hash Table size 180
    DataBase se(180,23014198001);
    se.insertStudent(23014198001,"Fazal","Software Engineering","3rd","A","03000000000");
    se.insertStudent(23014198002,"Asjad","Software Engineering","3rd","A","03000000000");
    se.insertStudent(23014198003,"Haroon","Software Engineering","3rd","A","03000000000");
    se.insertStudent(23014198004,"Talha","Software Engineering","3rd","A","03000000000");
    se.insertStudent(23014198005,"Ayesha","Software Engineering","3rd","A","03000000000");
    se.insertStudent(23014198006,"Mashhood","Software Engineering","3rd","A","03000000000");
    se.insertStudent(23014198007,"Muhammad","Software Engineering","3rd","A","03000000000");
    se.insertStudent(23014198008,"Hashim","Software Engineering","3rd","A","03000000000");
    se.insertStudent(23014198009,"Ali Haider","Software Engineering","3rd","A","03000000000");
    se.insertStudent(23014198010,"Moaaz","Software Engineering","3rd","A","03000000000");
    se.insertStudent(23014198011,"Arslan","Software Engineering","3rd","A","03000000000");
    se.insertStudent(23014198012,"Akif","Software Engineering","3rd","A","03000000000");
    se.insertStudent(23014198013,"Habib Ullah","Software Engineering","A","3rd","03000000000");
    se.insertStudent(23014198014,"Laiba","Software Engineering","3rd","A","03000000000");
    se.insertStudent(23014198015,"Amir","Software Engineering","3rd","A","03000000000");
    se.insertStudent(23014198016,"Ali Raza","Software Engineering","3rd","A","03000000000");

    cout<<"---------Software Engineering Record---------" <<endl;
    se.showTable();

    se.deleteStudent(23014198007);
    se.deleteStudent(23014198012);
    se.deleteStudent(23014198013);
    se.deleteStudent(23014198015);

    cout<<endl <<endl;
    cout<<"---------Software Engineering Record---------" <<endl;
    se.showTable();

    se.deleteTable();
    cout<<endl <<endl;
    cout<<"---------Software Engineering Record---------" <<endl;
    se.showTable();

    // Hash Table doesn't exist!
    se.insertStudent(23014198001,"Fazal","Software Engineering","3rd","A","03000000000");
    cout<<endl <<endl;
    
    // Rollno range: 23014198001 to 23014198180 for Hash Table size 180
    se.createTable(180,23014198001);
    se.insertStudent(23014198001,"Fazal","Software Engineering","3rd","A","03000000000");
    se.insertStudent(23014198180,"Noor Shah","Software Engineering","3rd","C","03000000000"),
    cout<<"-------Software Engineering New Record-------" <<endl;
    se.showTable();
    
    return 0;
}