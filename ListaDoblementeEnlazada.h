#pragma once
template <typename T>
class DoubleLinkedList
{
public:
    class Nodo
    {
    public:
        T dato;
        Nodo* anterior;
        Nodo* sgte;
        Nodo() {}
        Nodo(T dato)
        {
            this->dato = dato;
        }
    };
private:
    Nodo* cabeza, * tail;
    int length;
public:
    DoubleLinkedList()
    {
        cabeza = NULL;
        tail = NULL;
        length = 0;
    }

public:
    int Length() { return length; }

public:
    void agregar(T dato)
    {
        Nodo* nuevo = new Nodo(dato);
        if (cabeza == NULL)
        {
            cabeza = tail = nuevo;
            cabeza->anterior = NULL;
            tail->sgte = NULL;
        }
        else
        {
            tail->sgte = nuevo;
            nuevo->anterior = tail;
            tail = nuevo;
            tail->sgte = NULL;
        }
        length++;
    }

    T at(int indice)
    {
        T* p = new T();

        Nodo* actual = cabeza;
        int i = 0;
        while (actual != NULL)
        {
            if (indice == i)
            {
                return actual->dato;
            }
            actual = actual->sgte;
            i++;
        }
        return *p;
    }

    void modify_by_index(int index, T x)
    {
        T* p = new T();

        Nodo* actual = cabeza;
        int i = 0;
        while (actual != NULL)
        {
            if (index == i)
            {
                actual->dato = x;
                break;
            }
            actual = actual->sgte;
            i++;
        }
    }
    void eliminar_pos(int n)
    {
        if (n < 0) return;

        if (cabeza == NULL) return;
 
        else
        {
            length--;
            Nodo* actual = cabeza;

            int pos = n;

            for (int i = 0; i < pos; i++)
                actual = actual->sgte;

            if (actual == cabeza)
                cabeza = actual->sgte;
          
            else if (actual == tail)
                tail = tail->anterior;
            
            else
            {
                actual->anterior->sgte = actual->sgte;
                actual->sgte->anterior = actual->anterior;
            }
            actual = NULL;
        }
    }
};
