#include <iostream>
using namespace std;
template <class T>
struct Elem
{
    T data; 
    Elem* next, * prev;
};
template <class T>
class List
{
    Elem<T>* Head, * Tail;
    int Count;

public:

    List();
    List(const List<T>&);
    ~List();

    int GetCount();
    Elem<T>* GetElem(int);

    void DelAll();
    void Extract();

    void Add(T n);


    void Print();
    void Print(int pos);

    List<T>& operator = (const List<T>&);
    List<T> operator + (const List<T>&);

    bool operator == (const List<T>&);
    bool operator != (const List<T>&);
    bool operator <= (const List<T>&);
    bool operator >= (const List<T>&);
    bool operator < (const List<T>&);
    bool operator > (const List<T>&);

};
template <class T>
List<T>::List()
{
    Head = Tail = NULL;
    Count = 0;
}
template <class T>
List<T>::List(const List<T>& L)
{
    Head = Tail = NULL;
    Count = 0;

    Elem<T>* temp = L.Head;
    while (temp != 0)
    {
        Add(temp->data);
        temp = temp->next;
    }
}
template <class T>
List<T>::~List()
{
    DelAll();
}
template <class T>
void List<T>::Add(T n)
{
    Elem<T>* temp = new Elem<T>;
    temp->next = 0;
    temp->data = n;
    temp->prev = Tail;

    if (Tail != 0)
        Tail->next = temp;

    if (Count == 0)
        Head = Tail = temp;
    else
        Tail = temp;

    Count++;
}
template <class T>
void List<T>::Extract()
{
    Elem<T>* Del = Tail;
    Elem<T>* PrevDel = Del->prev;

    if (PrevDel != 0 && Count != 1)
        PrevDel->next = NULL;

        Tail = PrevDel;
        delete Del;
    Count--;
}
template <class T>
void List<T>::Print(int pos)
{
    if (pos < 1 || pos > Count)
    {
        cout << "Incorrect position !!!\n";
        return;
    }

    Elem<T>* temp;

    if (pos <= Count / 2)
    {
        temp = Head;
        int i = 1;

        while (i < pos)
        {
            temp = temp->next;
            i++;
        }
    }
    else
    {
        temp = Tail;
        int i = 1;

        while (i <= Count - pos)
        {
            temp = temp->prev;
            i++;
        }
    }
    cout << pos << " element: ";
    cout << temp->data << endl;
}
template <class T>
void List<T>::Print()
{
    if (Count != 0)
    {
        Elem<T>* temp = Head;
        cout << "( ";
        while (temp->next != 0)
        {
            cout << temp->data << ", ";
            temp = temp->next;
        }

        cout << temp->data << " )\n";
    }
}
template <class T>
void List<T>::DelAll()
{
    while (Count != 0)
        Extract();
}
template <class T>
int List<T>::GetCount()
{
    return Count;
}
template <class T>
Elem<T>* List<T>::GetElem(int pos)
{
    Elem<T>* temp = Head;

    if (pos < 1 || pos > Count)
    {
        cout << "Incorrect position !!!\n";
        return 0;
    }

    int i = 1;
    while (i < pos && temp != 0)
    {
        temp = temp->next;
        i++;
    }

    if (temp == 0)
        return 0;
    else
        return temp;
}
template <class T>
List<T>& List<T>::operator = (const List<T>& L)
{
    if (this == &L)
        return *this;

    this->~List(); // DelAll();

    Elem<T>* temp = L.Head;

    while (temp != 0)
    {
        Add(temp->data);
        temp = temp->next;
    }

    return *this;
}
template <class T>
List<T> List<T>::operator + (const List<T>& L)
{
    List<T> Result(*this);

    Elem<T>* temp = L.Head;

    while (temp != 0)
    {
        Result.Add(temp->data);
        temp = temp->next;
    }

    return Result;
}
template <class T>
bool List<T>::operator == (const List<T>& L)
{
    if (Count != L.Count)
        return false;

    Elem<T>* t1, * t2;

    t1 = Head;
    t2 = L.Head;

    while (t1 != 0)
    {
        if (t1->data != t2->data)
            return false;

        t1 = t1->next;
        t2 = t2->next;
    }

    return true;
}
template <class T>
bool List<T>::operator != (const List<T>& L)
{
    return !(*this == L);
}
template <class T>
bool List<T>::operator >= (const List<T>& L)
{
    if (Count > L.Count)
        return true;
    if (*this == L)
        return true;

    return false;
}
template <class T>
bool List<T>::operator <= (const List<T>& L)
{
    if (Count < L.Count)
        return true;
    if (*this == L)
        return true;

    return false;
}
template <class T>
bool List<T>::operator > (const List<T>& L)
{
    if (Count > L.Count)
        return true;

    return false;
}
template <class T>
bool List<T>::operator < (const List<T>& L)
{
    if (Count < L.Count)
        return true;

    return false;
}


