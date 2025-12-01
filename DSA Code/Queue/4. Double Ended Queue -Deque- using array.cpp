// Double Ended Queue [ Deque ] using array
#include<iostream>
using namespace std;

class Deque
{
    int front = -1, rear = -1, size = 0, capacity, *deque = NULL;
    public:
    Deque()
    { }
    Deque(int capacity)
    {
        this->capacity = capacity;
        deque = new int[capacity];
    }
    bool isEmpty()
    {
        if(deque != NULL)
        {
            if(front != -1)
            {
                return true;
            }
            else
            {
                return false;
            }
        }
        else
        {
            cout<<"Deque Doesn't Exist!";
            return true; // sentinel
        }
    }
    int dequeCapacity()
    {
        if(deque != NULL)
        {
            return capacity;
        }
        else
        {
            cout<<"Deque Doesn't Exist!";
            return -2; // sentinel
        }
    }
    void insertFront(int data)
    {
        if(deque != NULL)
        {
            if(front == -1) // for front at -1
            {
                front++;
                deque[front] = data; // or [0]
                rear++;
                size++;
            }
            else if (front == 0)
            {
                cout<<"Deque is Overflow!" <<endl;
            }
            else
            {
                front--;
                deque[front] = data;
                size++;
            }
            
        }
        else
        {
            cout<<"Deque Doesn't Exist!" <<endl;
        }
    }
    void insertRear(int data)
    {
        if(deque != NULL)
        {
            if(front == -1)
            {
                rear++;
                deque[rear] = data; // or [0]
                front++;
                size++;
            }
            else
            {
                if(size != capacity) // or size < capacity beacuse first condition check then increament
                {
                    rear++;
                    deque[rear] = data;
                    size++;
                }
                else
                {
                    cout<<"Deque is Overflow!" <<endl;
                }
            }
        }
        else
        {
            cout<<"Deque Doesn't Exist!" <<endl;
        }
    }
    void deleteFront()
    {
        if(deque != NULL)
        {
            if(front != -1)
            {
                if(front == rear)
                {
                    front = rear = -1;
                    size--;
                }
                else
                {
                    front++;
                    size--;
                }
            }
            else
            {
                cout<<"Deque is Underflow!" <<endl;
            }
        }
        else
        {
            cout<<"Deque Doesn't Exist!" <<endl;
        }
    }
    void deleteRear()
    {
        if(deque != NULL)
        {
            if(size > 0)
            {
                if(front == rear)
                {
                    front = rear = -1;
                    size--;
                }
                else
                {
                    rear--;
                    size--;
                }
            }
            else
            {
                cout<<"Deque is Underflow!" <<endl;
            }
        }
        else
        {
            cout<<"Deque Doesn't Exist!" <<endl;
        }
    }
    int getFront()
    {
        if(deque != NULL)
        {
            if(front != -1)
            {
                return deque[front];
            }
            else
            {
                cout<<"Deque is empty!";
                return -1; // sentinel
            }
        }
        else
        {
            cout<<"Deque Doesn't Exist!";
            return -2; // sentinel
        }
    }
    int getRear()
    {
        if(deque != NULL)
        {
            if(front != -1) // or real != -1
            {
                return deque[rear];
            }
            else
            {
                cout<<"Deque is empty!";
                return -1; // sentinel
            }
        }
        else
        {
            cout<<"Deque Doesn't Exist!";
            return -2; // sentinel
        }
    }
    int dequeSize()
    {
        if(deque != NULL)
        {
            return size;
        }
        else
        {
            cout<<"Deque Doesn't Exist!";
            return -2; // sentinel   
        }
    }
    bool isFull()
    {
        if(deque != NULL)
        {
            if(size == capacity)
            {
                return true;
            }
            else
            {
                return false;
            }
        }
        else
        {
            cout<<"Deque Doesn't Exist!";
            return false; // sentinel   
        }    
    }
    void showDeque()
    {
        if(deque != NULL)
        {
            if(front != -1) // or size > 0
            {
                int index = front, tempSize = size;
                cout<<"Deque: ";
                while(tempSize > 0)
                {
                    cout<<deque[index] <<"   ";
                    index++;
                    tempSize--;
                }
                cout<<endl;
            }
            else
            {
                cout<<"Deque is Empty!" <<endl;
            }
        }
        else
        {
            cout<<"Deque Doesn't Exist!" <<endl;
        }
    }
    void deleteDeque()
    {
        if(deque != NULL)
        {
            delete []deque;
            deque = NULL;
            front = rear = -1;
            size = 0;
        }
    }
    void createDeque(int capacity)
    {
        if(deque == NULL)
        {
            this->capacity = capacity;
            deque = new int[capacity];
        }
        else
        {
            cout<<"Deque already Exist!" <<endl;
        }
    }
    ~Deque()
    {
        deleteDeque();
    }
};

int main()
{
    Deque d1(5), d2;
    cout<<"Deque d2 isEmpty: " <<d2.isEmpty() <<endl; // Doesn't Exist
    cout<<"---------------------------------" <<endl;

    d2.createDeque(4);
    cout<<"d1 isEmpty: " <<d1.isEmpty() <<endl;
    cout<<"Deque d1 Capacity: " <<d1.dequeCapacity() <<endl;
    cout<<"d2 isEmpty: " <<d2.isEmpty() <<endl;
    cout<<"Deque d2 Capacity: " <<d2.dequeCapacity() <<endl;
    cout<<"---------------------------------" <<endl;

    d1.insertFront(10);
    d1.insertFront(12); // Deque is overflow because index 0 already filled
    cout<<"---------------------------------" <<endl;

    d1.insertRear(20);
    d1.insertRear(30);
    d1.insertRear(40);
    d1.insertRear(50);
    cout<<"d1 isFULL: " <<d1.isFull() <<endl;
    d1.insertRear(60);
    d1.showDeque();
    cout<<"---------------------------------" <<endl;

    d1.deleteFront();
    d1.deleteFront();
    d1.deleteRear();
    d1.deleteRear();
    d1.showDeque();
    cout<<"---------------------------------" <<endl;

    d1.insertFront(20);
    d1.insertFront(10);
    d1.insertRear(40);
    cout<<"Deque d1 Size: " <<d1.dequeSize() <<endl;
    d1.showDeque();
    cout<<"---------------------------------" <<endl;

    cout<<"Deque Front: " <<d1.getFront() <<endl;
    cout<<"Deque Rear: " <<d1.getRear() <<endl;
    cout<<"---------------------------------" <<endl;

    d1.deleteDeque();
    d2.deleteDeque();
    d1.showDeque();
    cout<<"---------------------------------" <<endl;

    d1.createDeque(2);
    d1.insertFront(10);
    d1.insertRear(20);
    d1.insertRear(30); // Deque is Overflow!
    d1.showDeque();
    cout<<"---------------------------------" <<endl;

    return 0;
}