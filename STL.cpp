#include <iostream>
using namespace std;

template <class T>
struct node
{
    T data;
    struct node *next;
};

template <class T>
struct node1
{
    T data;
    struct node1 *next;
    struct node1 *prev;
};

template <class T>
class SinglyLL
{
private:
    node <T> *first;
    int size;

public:
    SinglyLL();
    void InsertFirst(T no);
    void InsertLast(T no);
    void InsertAtPos(T no, int ipos);
    void DeleteFirst();
    void DeleteLast();
    void DeleteAtPos(int ipos);
    void Display();
    int Count();
};

template <class T>
SinglyLL<T>::SinglyLL()
{
    first = NULL;
    size = 0;
}

template <class T>
void SinglyLL<T>::InsertFirst(T no)
{
    node<T> *newn = new node<T>; // newn = (PNODE)malloc(sizeof(NODE))

    newn->data = no;
    newn->next = NULL;

    if (first == NULL)
    {
        first = newn;
    }
    else
    {
        newn->next = first;
        first = newn;
    }
    size++;
}

template <class T>
void SinglyLL<T>::InsertLast(T no)
{
    node<T> *newn = new node<T>; // newn = (PNODE)malloc(sizeof(NODE))

    newn->data = no;
    newn->next = NULL;

    if (first == NULL)
    {
        first = newn;
    }
    else
    {
        node<T> *temp = first;

        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newn;
    }
    size++;
}

template <class T>
void SinglyLL<T>::InsertAtPos(T no, int ipos)
{
    if(ipos < 1 || ipos > size+1)
    {
        return;
    }
    
    if(ipos==1)
    {
        InsertFirst(no);
    }
    else if(ipos==size+1)
    {
        InsertLast(no);
    }
    else 
    {
        node <T> * newn=NULL;
        node <T> * temp=first;

        newn=new node<T>;

        newn->data=no;
        newn->next=NULL;

        for(int i=1;i<ipos-1;i++)
        {
            temp=temp->next;
        }
        newn->next=temp->next;
        temp->next=newn;

        size++;
    }
}

template <class T>
void SinglyLL<T>::DeleteFirst()
{
    node<T> *temp = first;

    if (first != NULL)
    {
        first = first->next;
        delete temp;

        size--;
    }
}

template <class T>
void SinglyLL<T>::DeleteLast()
{
    node<T> *temp = first;

    if (first == NULL)
    {
        return;
    }
    else if (first->next == NULL)
    {
        delete first;
        first = NULL;
        size--;
    }
    else
    {
        while (temp->next->next != NULL)
        {
            temp = temp->next;
        }

        delete temp->next;
        temp->next = NULL;
        size--;
    }
}

template <class T>
void SinglyLL<T>::DeleteAtPos(int ipos)
{
    if(ipos < 1 || ipos > size)
    {
        return;
    }

    if(ipos==1)
    {
        DeleteFirst();
    }
    else if(ipos==size)
    {
        DeleteLast();
    }
    else 
    {
        node <T> * temp=first;
        node <T> * targeted=NULL;

        for(int i=1;i<ipos-1;i++)
        {
            temp=temp->next;
        }
        targeted=temp->next;
        temp->next=targeted->next;
        delete targeted;

        size--;
    }
}

template <class T>
void SinglyLL<T>::Display()
{
    node<T> *temp = first;

    while (temp != NULL)
    {
        cout <<"|"<<temp->data <<"|->";
        temp = temp->next;
    }
    cout<<"NULL";
    cout << "\n";
}

template <class T>
int SinglyLL<T>::Count()
{
    return size;
}

template <class T>
class DoublyLL
{
    private:
            node1 <T>* first;
            int size;

    public:
           DoublyLL();
           void InsertFirst(int no);
           void InsertLast(int no);
           void InsertAtPos(int no,int ipos);
           void DeleteFirst();
           void DeleteLast();
           void DeleteAtPos(int ipos);
           void Display();
           int Count();
};

template <class T>
DoublyLL <T>::DoublyLL()
{
    first=NULL;
    size=0;
}

template <class T>
void DoublyLL <T>::InsertFirst(int no)
{
    node1 <T>* newn=NULL;

    newn=new node1 <T>;

    newn->data=no;
    newn->prev=NULL;
    newn->next=NULL;

    if(first==NULL)
    {
        first=newn;
    }
    else
    {
        first->prev=newn;
        newn->next=first;
        first=newn;
    }
    size++;
}

template <class T>
void DoublyLL <T>::InsertLast(int no)
{
    node1 <T>* newn=NULL;

    newn=new node1 <T>;

    newn->data=no;
    newn->prev=NULL;
    newn->next=NULL;

    if(first==NULL)
    {
        first=newn;
    }
    else
    {
        node1 <T>* temp=first;

        while(temp->next!=NULL)
        {
            temp=temp->next;
        }
        newn->prev=temp;
        temp->next=newn;
    }
    size++;
}

template <class T>
void DoublyLL <T>::InsertAtPos(int no,int ipos)
{
    if(ipos < 1 || ipos > size+1)
    {
        return;
    }

    if(ipos==1)
    {
        InsertFirst(no);
    }
    else if(ipos==size+1)
    {
        InsertLast(no);
    }
    else
    {
        node1 <T>* temp=first;
        node1 <T>* newn=NULL;

        newn=new node1<T>;

        newn->data=no;
        newn->prev=NULL;
        newn->next=NULL;

        for(int i=1;i<ipos-1;i++)
        {
            temp=temp->next;
        }
        newn->next=temp->next;
        newn->prev=temp;
        temp->next->prev=newn;
        temp->next=newn;

        size++;
    }
}

template <class T>
void DoublyLL<T>::DeleteFirst()
{
    if(first==NULL)
    {
        return;
    }
    else if(first->next==NULL)
    {
        delete first;
        first=NULL;
    }
    else
    {
        first=first->next;
        delete first->prev;
        first->prev=NULL;
    }
    size--;
}

template <class T>
void DoublyLL<T>::DeleteLast()
{
    node1<T>* temp=first;
    if(first==NULL)
    {
        return;
    }
    else if(first->next==NULL)
    {
        delete first;
        first=NULL;
    }
    else
    {
        while(temp->next->next!=NULL)
        {
            temp=temp->next;
        }
        delete temp->next;
        temp->next=NULL;
    }
    size--;
}

template <class T>
void DoublyLL<T>::DeleteAtPos(int ipos)
{
    if(ipos < 1 || ipos > size)
    {
        return;
    }

    if(ipos==1)
    {
        DeleteFirst();
    }
    else if(ipos==size)
    {
        DeleteLast();
    }
    else
    {
        node1<T>* temp=first;
        node1<T>* targeted=NULL;

        for(int i=1;i<ipos-1;i++)
        {
            temp=temp->next;
        }
        targeted=temp->next;
        temp->next=targeted->next;
        targeted->next->prev=temp;
        delete targeted;

        size--;
    }
}

template <class T>
void DoublyLL<T>::Display()
{
    node1<T>* temp=first;

    while(temp!=NULL)
    {
        cout<<"|"<<temp->data<<"|->";
        temp=temp->next;
    }
    cout<<"NULL";
    cout<<"\n";
}

template <class T>
int DoublyLL<T>::Count()
{
    return size;
}


template <class T>
class SinglyCL
{
    private:
            node <T>* first;
            node <T>* last;
            int size;

    public:
           SinglyCL();
           void InsertFirst(int no);
           void InsertLast(int no);
           void InsertAtPos(int no,int ipos);
           void DeleteFirst();
           void DeleteLast();
           void DeleteAtPos(int ipos);
           void Display();
           int Count();
};

template <class T>
SinglyCL<T>::SinglyCL()
{
    first=NULL;
    last=NULL;
    size=0;
}

template <class T>
void SinglyCL<T>::InsertFirst(int no)
{
   node <T>* newn=NULL;

   newn=new node<T>;

   newn->data=no;
   newn->next=NULL;

   if(first==NULL && last==NULL)
   {
       first=newn;
       last=newn;
   }
   else
   {
       newn->next=first;
       first=newn;
   }

   last->next=first;

   size++;
}

template <class T>
void SinglyCL<T>::InsertLast(int no)
{
   node <T>* newn=NULL;

   newn=new node<T>;

   newn->data=no;
   newn->next=NULL;

   if(first==NULL && last==NULL)
   {
       first=newn;
       last=newn;
   }
   else
   {
       last->next=newn;
       last=newn;
   }

   last->next=first;

   size++;
}

template <class T>
void SinglyCL<T>::InsertAtPos(int no,int ipos)
{
    if(ipos < 1 || ipos > size+1)
    {
        return;
    }

    if(ipos==1)
    {
        InsertFirst(no);
    }
    else if(ipos==size+1)
    {
        InsertLast(no);
    }
    else
    {
        node <T>* newn=NULL;
        node <T>* temp=first;

        newn=new node<T>;

        newn->data=no;
        newn->next=NULL;

        for(int i=1;i<ipos-1;i++)
        {
            temp=temp->next;
        }
        newn->next=temp->next;
        temp->next=newn;

        size++;
    }
}

template <class T>
void SinglyCL<T>::DeleteFirst()
{
    if(first==NULL && last==NULL)
    {
        return;
    }
    else if(first==last)
    {
        delete first;
        first=NULL;
        last=NULL;
    }
    else
    {
        first=first->next;
        delete last->next;

        last->next=first;
    }
    size--;
}

template <class T>
void SinglyCL<T>::DeleteLast()
{
    if(first==NULL && last==NULL)
    {
        return;
    }
    else if(first==last)
    {
        delete last;
        first=NULL;
        last=NULL;
    }
    else
    {
        node <T>* temp=first;

        while(temp->next!=last)
        {
            temp=temp->next;
        }
        delete last;
        last=temp;

        last->next=first;
    }
    size--;
}

template <class T>
void SinglyCL<T>::DeleteAtPos(int ipos)
{
    if(ipos < 1 || ipos > size)
    {
        return;
    }

    if(ipos==1)
    {
        DeleteFirst();
    }
    else if(ipos==size)
    {
        DeleteLast();
    }
    else 
    {
        node <T>* temp=first;
        node <T>* targeted=NULL;

        for(int i=1;i<ipos-1;i++)
        {
            temp=temp->next;
        }
        targeted=temp->next;
        temp->next=targeted->next;
        delete targeted;

        size--;
    }
}

template <class T>
void SinglyCL<T>::Display()
{
    node <T>* temp=first;

    if(first==NULL && last==NULL)
    {
        return;
    }

    do
    {
        cout<<"|"<<temp->data<<"|->";
        temp=temp->next;
    } while(temp!=last->next);

    cout<<"NULL";
    cout<<"\n";
}

template <class T>
int SinglyCL<T>::Count()
{
    return size;
}

template <class T>
class DoublyCL
{
private:
    node1 <T>* first;
    node1 <T>* last;
    int size;
    
public:
    DoublyCL()
    {
        first = NULL;
        last = NULL;
        size = 0;
    }
    
    void Display();
    int Count();
    void InsertFirst(int no);
    void InsertLast(int no);
    void InsertAtPos(int no , int ipos);
    void DeleteFirst();
    void DeleteLast();
    void DeleteAtPos(int ipos);
};

template <class T>
void DoublyCL<T>::InsertFirst(int no)
{
    node1<T>* newn = new node1 <T>;
    
    newn->data = no;
    newn->next = NULL;
    newn->prev = NULL;
    
    if((first == NULL) && (last == NULL))
    {
        first = newn;
        last = newn;
    }
    else
    {
        newn->next = first;
        first -> prev = newn;
        first = newn;
    }
    
    last->next = first;
    first->prev = last;
    size++;
}

template <class T>
void DoublyCL<T>::InsertLast(int no)
{
    node1<T>* newn = new node1<T>;
    
    newn->data = no;
    newn->next = NULL;
    newn->prev = NULL;
    
    if((first == NULL) && (last == NULL))
    {
        first = newn;
        last = newn;
    }
    else
    {
        last -> next = newn;
        newn->prev = last;
        last = newn;
    }
    
    last->next = first;
    first->prev = last;
    size++;
}

template <class T>
void DoublyCL<T>::InsertAtPos(int no, int ipos)
{
    if((ipos < 1) || (ipos > size+1))
    {
        return;
    }
    
    if(ipos == 1)
    {
        InsertFirst(no);
    }
    else if(ipos == size +1)
    {
        InsertLast(no);
    }
    else
    {
        node1<T>* newn= new node1<T>;
        
        newn->data = no;
        newn->next = NULL;
        newn->prev = NULL;
        
        node1<T>* temp = first;
        
        for(int i = 1; i < ipos -1; i++)
        {
            temp = temp -> next;
        }
        
        newn->next = temp->next;
        newn->next->prev = newn;
        temp->next = newn;
        newn->prev = temp;
        size ++;
    }
}

template <class T>
void DoublyCL<T>::DeleteFirst()
{
    if((first == NULL) && (last == NULL))
    {
        return;
    }
    else if(first == last)
    {
        delete first;
        first  = NULL;
        last = NULL;
    }
    else
    {
        first = first -> next;
        delete last->next;
        first->prev = last;
        last->next = first;
    }
    size--;
}

template <class T>
void DoublyCL<T>::DeleteLast()
{
    if((first == NULL) && (last == NULL))
    {
        return;
    }
    else if(first == last)
    {
        delete first;
        first  = NULL;
        last = NULL;
    }
    else
    {
        last = last -> prev;
        delete last->next;
        first->prev = last;
        last->next = first;
    }
    size--;
}

template <class T>
void DoublyCL<T>::DeleteAtPos(int ipos)
{
    if((ipos < 1) || (ipos > size))
    {
        return;
    }
    if(ipos==1)
    {
        DeleteFirst();
    }
    else if(ipos == size)
    {
        DeleteLast();
    }
    else
    {
        node1<T>* temp = first;
        
        for(int i=1;i<ipos-1;i++)
        {
            temp = temp -> next;
        }
       
        temp -> next = temp->next->next;
        delete temp->next->prev;
        temp->next->prev = temp;
        
        size--;
    }
}

template <class T>
void DoublyCL<T>::Display()
{
    node1<T>* temp = first;
    
    for(int i = 1; i <= size; i++)
    {
        cout<<"|"<<temp->data<<"|-> ";
        temp = temp->next;
    }
    cout<<"NULL";
    cout<<"\n";
}

template <class T>
int DoublyCL<T>::Count()
{
    return size;
}

template <class T>
class Stack    
{
 private:
       node<T>* first;
       int size;
    
 public:
       Stack();
       void Push(int no);
       int Pop();
       void Display();
       int Count();
};

template <class T>
Stack<T>::Stack()
{
    first = NULL;
    size = 0;
}

template <class T>   
void Stack<T>:: Push(int no) 
{
    node<T>* newn = new node<T>;

    newn->data = no;
    newn->next = NULL;
        
    if(first == NULL)
    {
        first = newn;
    }
    else
    {
        newn->next = first;
        first = newn;
    }
    size++;
}

template <class T>
int Stack<T>:: Pop() 
{
    int no = 0;
    node<T>* temp = first;
        
    if(first==NULL)
    {
        cout<<"Stack is empty\n";
        return -1;
    }
    
    if(first->next==NULL)
    {
        no = first->data;
        delete first;
        first = NULL;
    }
    else
    {
        no = first->data;
        first = first -> next;
        delete temp;
    }
        
    size--;
    return no;
}

template <class T>
void Stack<T>:: Display()
{
    node<T>* temp = first;
        
    while(temp != NULL)
    {
        cout<<"|"<<temp->data<<"|"<<"\n";
        temp = temp->next;
    }
}
    
template <class T>
int Stack<T>::Count()
{
    return size;
}

template <class T>
class Queue 
{
 private:
        node<T>* first;
        int size;
    
 public:
        Queue();
        void Enqueue(int no);
        int Dequeue();
        void Display();
        int Count();
};

template <class T>
Queue<T>::Queue()
{
    first = NULL;
    size = 0;
}

template <class T>    
void Queue<T>::Enqueue(int no) 
{
    node<T>* newn = new node<T>;
    newn->data = no;
    newn -> next = NULL;
        
    if(size == 0)   // if(first == NULL)
    {
        first = newn;
    }
    else
    {
        node<T>* temp = first;

        while(temp->next != NULL)
        {
            temp = temp -> next;
        }
        temp->next = newn;
    }
    size++;
}
    
template <class T>    
int Queue<T>::Dequeue() 
{
    int no = 0;
    node<T>* temp = first;
               
    if(size == 0)
    {
        cout<<"Queue is empty\n";
        return -1;
    }
               
    if(size == 1)
    {
        no = first->data;
        delete first;
        first = NULL;
    }
    else
    {
        no = first->data;
        first = first -> next;
        delete temp;
    }
               
    size--;
    return no;
}
    
template <class T>
void Queue<T>::Display()
{
    node<T>* temp = first;

    for(int i=1;i<= size;i++)
    {
        cout<<"|"<<temp->data<<"|-> ";
        temp = temp->next;
    }
    cout<<"\n";
}
    
template <class T>
int Queue<T>::Count()
{
    return size;
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int main()
{
    SinglyLL<char> slobj1;

    int iret1 = 0;

    slobj1.InsertFirst('A');
    slobj1.InsertFirst('B');
    slobj1.InsertFirst('C');

    slobj1.InsertLast('D');
    slobj1.InsertLast('E');

    slobj1.InsertAtPos('a',3);

    slobj1.DeleteFirst();
    slobj1.DeleteAtPos(3);
    slobj1.DeleteLast();

    cout<<"_________________________________________________________________________________________________\n";
    cout<<"Nodes in SinglyLL is : "<<"\n";
    slobj1.Display();

    iret1 = slobj1.Count();
    cout << "Number of elemensts in SinglyLL are : " << iret1 << "\n";

    SinglyLL<int> slobj2;

    int iret2 = 0;

    slobj2.InsertFirst(11);
    slobj2.InsertFirst(21);
    slobj2.InsertFirst(51);

    slobj2.InsertLast(101);
    slobj2.InsertLast(111);

    slobj2.DeleteFirst();
    slobj2.DeleteAtPos(3);
    slobj2.DeleteLast();
    
    cout<<"Nodes in SinglyLL is : "<<"\n";
    slobj2.Display();

    iret2 = slobj2.Count();
    cout << "Number of elemensts in SinglyLL are : " << iret2 << "\n";
    
    cout<<"___________________________________________________________________________________________\n";

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    DoublyLL<char> dlobj1;

    int iret3 = 0;

    dlobj1.InsertFirst('A');
    dlobj1.InsertFirst('B');
    dlobj1.InsertFirst('C');
    dlobj1.InsertLast('D');
    dlobj1.InsertLast('E');

    dlobj1.InsertAtPos('a',3);

    dlobj1.DeleteFirst();
    dlobj1.DeleteAtPos(3);
    dlobj1.DeleteLast();

    cout<<"Nodes in DoublyLL is : "<<"\n\n";
    dlobj1.Display();

    iret3 = dlobj1.Count();
    cout << "Number of elemensts in DoublyLL are : " << iret3 << "\n";

    DoublyLL<int> dlobj2;

    int iret4 = 0;

    dlobj2.InsertFirst(11);
    dlobj2.InsertFirst(21);
    dlobj2.InsertFirst(51);
    dlobj2.InsertLast(101);
    dlobj2.InsertLast(111);

    dlobj2.InsertAtPos(100,3);

    dlobj2.DeleteFirst();
    dlobj2.DeleteAtPos(3);
    dlobj2.DeleteLast();
    
    cout<<"Nodes in DoublyLL is : "<<"\n";
    dlobj2.Display();

    iret4 = dlobj2.Count();
    cout << "Number of elemensts DoublyLL are : " << iret4 << "\n";
    
    cout<<"___________________________________________________________________________________________\n";

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    SinglyCL<char> scobj1;

    int iret5 = 0;

    scobj1.InsertFirst('A');
    scobj1.InsertFirst('B');
    scobj1.InsertFirst('C');
    scobj1.InsertLast('D');
    scobj1.InsertLast('E');

    scobj1.InsertAtPos('a',3);

    scobj1.DeleteFirst();
    scobj1.DeleteAtPos(3);
    scobj1.DeleteLast();

    cout<<"Nodes in SinglyCL is : "<<"\n";
    scobj1.Display();

    iret5 = scobj1.Count();
    cout << "Number of elemensts in SinglyCL are : " << iret5 << "\n";

    SinglyCL<int> scobj2;

    int iret6 = 0;

    scobj2.InsertFirst(11);
    scobj2.InsertFirst(21);
    scobj2.InsertFirst(51);
    scobj2.InsertLast(101);
    scobj2.InsertLast(111);

    scobj2.InsertAtPos(100,3);

    scobj2.DeleteFirst();
    scobj2.DeleteAtPos(3);
    scobj2.DeleteLast();
    
    cout<<"Nodes in SinglyCL is : "<<"\n";
    scobj2.Display();

    iret6 = scobj2.Count();
    cout << "Number of elemensts SinglyCL are : " << iret6 << "\n";
    
    cout<<"___________________________________________________________________________________________\n";

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    DoublyCL<char> dcobj1;

    int iret7 = 0;

    dcobj1.InsertFirst('A');
    dcobj1.InsertFirst('B');
    dcobj1.InsertFirst('C');

    dcobj1.InsertLast('D');
    dcobj1.InsertLast('E');

    dcobj1.InsertAtPos('a',3);

    dcobj1.DeleteFirst();
    dcobj1.DeleteAtPos(3);
    dcobj1.DeleteLast();

    cout<<"Nodes in DoublyCL is : "<<"\n";
    dcobj1.Display();

    iret7 = dcobj1.Count();
    cout << "Number of elemensts in DoublyCL are : " << iret7 << "\n";

    DoublyCL<int> dcobj2;

    int iret8 = 0;

    dcobj2.InsertFirst(11);
    dcobj2.InsertFirst(21);
    dcobj2.InsertFirst(51);
    dcobj2.InsertLast(101);
    dcobj2.InsertLast(111);

    dcobj2.InsertAtPos(100,3);

    dcobj2.DeleteFirst();
    dcobj2.DeleteAtPos(3);
    dcobj2.DeleteLast();
    
    cout<<"Nodes in DoublyCL is : "<<"\n";
    dcobj2.Display();

    iret8 = dcobj2.Count();
    cout << "Number of elemensts DoublyCL are : " << iret8 << "\n";
    
    cout<<"___________________________________________________________________________________________\n";

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    Stack<int> sobj;
    
    sobj.Push(11);
    sobj.Push(21);
    sobj.Push(51);
    sobj.Push(101);
    
    cout<<"Elements of stack\n";
    sobj.Display();
    
    int iret9 = sobj.Pop();       // 101
    cout<<"Poped element is : "<<iret9<<"\n";                     // 101
    
    cout<<"Elements of stack\n";
    sobj.Display();          // 51       21      11
    iret9 = sobj.Count();
    
    cout<<"Size of stack is : "<<iret9<<"\n";        // 3
    cout<<"_________________________________________________________________________________________\n";

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    Queue<int> qobj;
    
    qobj.Enqueue(11);
    qobj.Enqueue(21);
    qobj.Enqueue(51);
    qobj.Enqueue(101);
    
    cout<<"Elements of Queue :\n";
    
    qobj.Display();
    int iret10 = qobj.Dequeue();       // 11
    cout<<"Removed element from queue : "<<iret10<<"\n";                     // 11
    
    cout<<"Elements from queue : \n";
    qobj.Display();          // 21  51  101
    iret10 = qobj.Count();    
    
    cout<<"Size of queue is : "<<iret10<<"\n";        // 3
    return 0;
}