// one to one fuction so, no collison
#include<iostream>
using namespace std;

class Student
{
    public:
    long long rollno;
    string name, department, semester, section, contact;
    // address etc not implemented
    Student() : rollno(0), name(""), department(""), semester(""), section(""), contact("") 
    { }
};

class DataBase
{
    Student *array = nullptr;
    int size;
    // for sorted results
    long long firstRollno;
    public:
    DataBase(int size,long long firstRollno)
    {
        this->size = size;
        this->firstRollno = firstRollno;
        array = new Student[size];
    }

    int hashFunction(long long key)
    {
        return (key-1)%size;
    }

    // O(1) Time Complexity
    void insertStudent(long long rollno, string name, string department, string semester, string section, string contact)
    {
        if(array != nullptr)
        {
            int index = hashFunction(rollno);
            array[index].rollno = rollno;
            array[index].name = name;
            array[index].department = department;
            array[index].semester = semester;
            array[index].section = section;
            array[index].contact = contact;
        }
        else
        {
            cout<<"Hash Table doesn't exist!" <<endl <<endl <<endl;
        }
    }

    // O(1) Time Complexity
    void showStudent(long long rollno)
    {
        if(array != nullptr)
        {
            int index = hashFunction(rollno);
            cout<<"---------Student Record---------" <<endl;
            if(array[index].rollno != 0)
            {
                cout<<"Rollno: " <<array[index].rollno <<endl <<"Name: " <<array[index].name <<endl;
                cout<<"Department: " <<array[index].department <<endl <<"Semester: " <<array[index].semester <<endl;
                cout<<"Section: " <<array[index].section <<endl <<"Contact: " <<array[index].contact <<endl;    
                cout<<"------------------------------------------" <<endl <<endl <<endl;
            }
            else
            {
                cout<<rollno <<" doesn't exist!" <<endl <<endl <<endl;
            }

        }
        else
        {
            cout<<"Hash Table doesn't exist!" <<endl <<endl <<endl;
        }
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
                if(array[i].rollno != 0)
                {
                    cout<<"Rollno: " <<array[i].rollno <<endl <<"Name: " <<array[i].name <<endl;
                    cout<<"Department: " <<array[i].department <<endl <<"Semester: " <<array[i].semester <<endl;
                    cout<<"Section: " <<array[i].section <<endl <<"Contact: " <<array[i].contact <<endl;
                    cout<<"------------------------------------------" <<endl;        
                }
            }
            if(array[i].rollno != 0)
            {
                cout<<"Rollno: " <<array[i].rollno <<endl <<"Name: " <<array[i].name <<endl;
                cout<<"Department: " <<array[i].department <<endl <<"Semester: " <<array[i].semester <<endl;
                cout<<"Section: " <<array[i].section <<endl <<"Contact: " <<array[i].contact <<endl;
                cout<<"------------------------------------------" <<endl; 
            }
            cout<<endl <<endl;
        }
        else
        {
            cout<<"Hash Table doesn't exist!" <<endl <<endl <<endl;
        }
    }

    // O(1) Time Complexity 
    void deleteStudent(long long rollno)
    {
        if(array != nullptr)
        {
            int index = hashFunction(rollno);
            array[index].rollno = 0;
            /* no need of other updation because memory cannot shrink ( for string ) and empty string 
            itself have 24 to 32 bytes + data in characters bytes, alot of memory is wasted if record is 
            not inserted or deleted, so dynamic implementaion is better with double pointers approach */
        }
        else
        {
            cout<<"Hash Table doesn't exist!" <<endl <<endl <<endl;
        }
    }

    
    void deleteTable()
    {
        if(array != nullptr)
        {
            delete []array;
            array = nullptr;
        }
    }

    void createTable(int size, long long firstRollno)
    {
        if(array == nullptr)
        {
            this->size = size;
            this->firstRollno = firstRollno;
            array = new Student[size];
        }
        else
        {
            cout<<"Records Already Exist!" <<endl <<endl <<endl;
        }
    }

    ~DataBase()
    {
        deleteTable();
    }
};

int main()
{ 
    // Rollno range: 23014198001 to 23014198063 for Hash Table size 63
    DataBase se(63,23014198001);

    se.showStudent(23014198004);

    se.insertStudent(23014198004,"Talha","Software Engineering","3rd","A","03000000000");
    se.showStudent(23014198004);

    se.insertStudent(23014198001,"Fazal","Software Engineering","3rd","A","03000000000");
    se.insertStudent(23014198002,"Asjad","Software Engineering","3rd","A","03000000000");
    se.insertStudent(23014198003,"Haroon","Software Engineering","3rd","A","03000000000");
    se.insertStudent(23014198005,"Ayesha","Software Engineering","3rd","A","03000000000");
    se.insertStudent(23014198006,"Mashhood","Software Engineering","3rd","A","03000000000");
    se.insertStudent(23014198007,"Muhammad","Software Engineering","3rd","A","03000000000");
    se.insertStudent(23014198008,"Hashim","Software Engineering","3rd","A","03000000000");
    se.insertStudent(23014198009,"Ali Haider","Software Engineering","3rd","A","03000000000");
    se.insertStudent(23014198010,"Moaaz","Software Engineering","3rd","A","03000000000");
    se.insertStudent(23014198011,"Arslan","Software Engineering","3rd","A","03000000000");
    se.insertStudent(23014198012,"Akif","Software Engineering","3rd","A","03000000000");
    se.insertStudent(23014198013,"Habib Ullah","Software Engineering","3rd","A","03000000000");
    se.insertStudent(23014198014,"Laiba","Software Engineering","3rd","A","03000000000");
    se.insertStudent(23014198015,"Amir","Software Engineering","3rd","A","03000000000");
    se.insertStudent(23014198016,"Ali Raza","Software Engineering","3rd","A","03000000000");

    cout<<"-----Software Enigineering Records-----" <<endl;
    se.showTable();

    se.deleteStudent(23014198007);
    se.deleteStudent(23014198012);
    se.deleteStudent(23014198013);
    se.deleteStudent(23014198015);

    cout<<"-----Software Enigineering Records-----" <<endl;
    se.showTable();

    // Records Already Exist! Hash Table will not create!
    se.createTable(180,23014198001);

    se.deleteTable();
    cout<<"-----Software Enigineering Records-----" <<endl;
    se.showTable();

    // Rollno range: 23014198001 to 23014198180 for Hash Table size 180
    se.createTable(180,23014198001);
    se.insertStudent(23014198001,"Fazal","Software Engineering","3rd","A","03000000000");
    se.insertStudent(23014198180,"Noor Shah","Software Engineering","3rd","C","03000000000");

    cout<<"-----Software Enigineering 3 Sections Records-----" <<endl;
    se.showTable();

    return 0;
}