#ifndef LIST_HPP_SENTRY
#define LIST_HPP_SENTRY

template <class T>
class ListCursor;


template <class T>
class List {
    friend class ListCursor<T>;
    friend class Iterator;
    struct item {
        T val;
        item *next;
    };

    item *first;
    int len;

public:
    List() : first(0), len(0) {}
    ~List();

    int GetLen() { return len; }
    void Push(T val);
    void Pop();

    ListCursor<T> operator[](int idx);

    class Iterator {
        List<T> *the_master;
        typename List<T>::item *first;
    public:
        Iterator(List<T> *_the_master, typename List<T>::item *_first)
            : the_master(_the_master), first(_first) {}

        bool More();
        ListCursor<T> Next();
    };

    Iterator* Iterate() { return new Iterator(this, first); }

private:
    List(const List<T>&);
    const List<T> operator=(const List<T>&);
};

template <class T>
List<T>::~List()
{
    while (first)
    {
        item *tmp = first;
        first = first->next;
        delete tmp;
    }
}

template <class T>
class ListCursor {
    friend class List<T>;
    List<T> *the_master;
    typename List<T>::item *node;

public:
    ListCursor(List<T> *_the_master, typename List<T>::item *_node)
        : the_master(_the_master), node(_node) {}

    operator T() const { return node->val; }
    const ListCursor& operator=(T val) 
    {
        node->val = val;
        return *this;
    }
};

template <class T>
ListCursor<T> List<T>::operator[](int idx)
{
    int i;
    item *tmp = first;
    for (i = 0; i < idx; i++)
        tmp = tmp->next;
    
    return ListCursor<T>(this, tmp);
}

template <class T>
bool List<T>::Iterator::More()
{
    return first;
}

template <class T>
ListCursor<T> List<T>::Iterator::Next()
{
    ListCursor<T> res(the_master, first);
    first = first->next;
    return res;
}

template <class T>
void List<T>::Push(T val)
{
    item *tmp = new item;
    tmp->val = val;
    tmp->next = first;
    first = tmp;
    len++;
}

template <class T>
void List<T>::Pop()
{
    item *tmp = first->next;
    delete first;
    first = tmp;
    len--;
}

#endif