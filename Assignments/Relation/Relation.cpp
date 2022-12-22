#include <iostream>
#include "Relation.h"
#include "Set.h"


using namespace std;

template <typename type>
Relation<type>::Relation()
{
    card = 0; //Initialized at 0 since relation is empty
    capacity = 0;
    elements = new Pair<type>[MAX_CARD];

    if (elements == NULL)
        cout << "Not Enough Memory" << endl;
    else
        capacity = MAX_CARD;
}

template <typename type>
Relation<type>::Relation(const Relation<type>& r)
{
    int i;
    elements = new Pair<type>[r.capacity];

    if (elements == NULL)
        cout << "Not Enough Memory" << endl;
    else
    {
        capacity = r.capacity;
        card = r.card;

        for (i = 0; i < r.card; ++i)
            elements[i] = r.elements[i];
    }
}

template <typename type>
Relation<type>::~Relation()
{
    delete[] elements;
}

template <typename type>
int Relation<type>::cardinality()
{
    return card;
}

template <typename type>
bool Relation<type>::add_to_set(type x)
{
    if (root.add_element(x))
        return true;
    return false;
}

template <typename type>
bool Relation<type>::add_element(Pair<type> p)
{
    int i;

    if (card == capacity)
    {
        int new_capacity = capacity + MAX_CARD / 2;
        Pair<type>* temp;

        temp = new Pair<type>[new_capacity];

        if (temp == NULL)
        {
            cout << "Not enough memory" << endl;
            return false;
        }

        for (i = 0; i < card; ++i)
            temp[i] = elements[i];

        delete[] elements;
        elements = temp;
        capacity = new_capacity;
    }
    elements[card++] = p;
    return true;
}

template <typename type>
void Relation<type>::remove_element(Pair<type> p)
{
    int i, j = -1;

    for (i = 0; i < card; ++i)
    {
        if (elements[i].first == p.first && elements[i].second == p.second)
        {
            j = i;
            break;
        }
    }

    if (j != -1)
    {
        for (i = j; i < card; ++i)
            elements[i] = elements[i + 1];
        --card;
    }
}

template <typename type>
bool Relation<type>::is_member(Pair<type> p)
{
    int i;
    for (i = 0; i < card; ++i)
    {
        if (elements[i].first == p.first && elements[i].second == p.second)
        {
            return true;
        }
    }
    return false;
}

template <typename type>
bool Relation<type>::operator==(Relation<type> r)
{
    if (card == r.card) {
        int i;
        for (i = 0; i < card; ++i)
        {
            if (elements[i].first != r.elements[i].first && elements[i].second != r.elements[i].second)
            {
                return false;
            }
        }
        return true;
    }
    else
        return false;
}

template <typename type>
Relation<type>& Relation<type>::operator=(Relation<type> r)
{
    int i;
    Pair<type>* temp;
    size = 0;
    capacity = 0;
    temp = new Pair<type>[r.capacity];
    if (temp == NULL)
        cout << "Not enough memory!" << endl;
    else
    {
        capacity = r.capacity;
        size = r.size;
        root = r.root;

        for (i = 0; i < r.size; ++i)
            temp[i] = r.elements[i];

        delete[] elements;
        elements = temp;
    }

    return (*this);
}

template <typename type>
bool Relation<type>::reflexive()
{
    int i;
    Pair<type> p;

    for (i = 0; i < card; ++i)
    {
        p.first = p.second = i;
        if (!is_member(p))
            return false;
    }
    return true;
}

template <typename type>
bool Relation<type>::irreflexive()
{
    int i;
    Pair<type> p;

    for (i = 0; i < card; ++i)
    {
        p.first = p.second = i;
        if (is_member(p))
            return false;
    }
    return true;
}

template <typename type>
bool Relation<type>::symmetric()
{
    int i;
    Pair<type> p;
    for (i = 0; i < card; ++i)
    {
        p.first = elements[i].second;
        p.second = elements[i].first;

        if (!is_member(p))
        {
            return false;
        }
    }
    return true;
}

template <typename type>
bool Relation<type>::asymmetric()
{
    int i;
    Pair<type> p;
    for (i = 0; i < card; ++i)
    {
        p.first = elements[i].second;
        p.second = elements[i].first;

        if (is_member(p) && p.first != p.second)
        {
            return false;
        }
    }
    return true;
}

template <typename type>
bool Relation<type>::transitive()
{
    int i, j;
    Pair<type> p;
    for (i = 0; i < card; ++i)
    {
        for (j = i + 1; j < card - 2; ++j)
        {
            p.first = elements[i].first;
            p.second = elements[j].second;
            if (elements[i].second == elements[j].first)
            {
                if (is_member(p) == true)
                    return true;
            }

        }
    }
    return false;
}

template <typename type>
bool Relation<type>::is_function()
{
    int i, j;
    Pair<type> p;
    for (i = 0; i < card; ++i)
    {
        for (j = i + 1; j < card - 1; ++j)
        {
            if (elements[i].first == elements[j].first && elements[i].second != elements[j].second)
                return false;
        }
    }
    return true;
}

template <typename typex>
ostream& operator<<(ostream& out, Relation<typex>& r)
{
    int i;
    out << "{ ";
    for (i = 0; i < r.size; ++i)
    {
        if (i != 0) out << ", ";
        out << "(" << r.elements[i].first << ", " << r.elements[i].second << ")";
    }
    out << " }";
}

template <typename type>
Relation<type> Relation<type>::inverse()
{
    Relation<type> R;
    Pair<type> p;
    int i, f, s;

    for (i = 0; i < card; ++i)
    {
        s = elements[i].first; //takes first element of pair at index i and assigns it to s which is second for inversed pair
        f = elements[i].second; //takes the second elem of pair at index i and assigns it to f since it will be the first elem in the inversed relation
        p.first = f;
        p.second = s;
        R.add_element(p);
    }
    return R;
}

template <typename type>
Relation<type> Relation<type>::combination(Relation<type> r)
{
    Relation<type> R;
    Pair<type> p;
    int i;

    if (card == r.card) {
        for (i = 0; i < card; ++i)
        {
            if (elements[i].second == r.elements[i].first)
            {
                p.first = elements[i].first;
                p.second = r.elements[i].second;
                R.add_element(p);
            }
        }
    }
    else
        return R;
}