#ifndef BUW_LIST_HPP
#define BUW_LIST_HPP
#include <cstddef>
#include <list>
#include <iostream>
// List . hpp

template <typename T>
class List;

template <typename T>
struct ListNode
{
    T value = T();
    ListNode* prev = nullptr ;
    ListNode* next = nullptr ;
};

template <typename T>
class ListIterator
{
    public :
    using Self = ListIterator<T>;
    using value_type = T;
    using pointer = T*;
    using reference = T&;
    using difference_type = ptrdiff_t;
    using iterator_category = std::bidirectional_iterator_tag;
    //Aufgabe (4.5)
    ListIterator():
    node{nullptr}
    {};

    ListIterator(ListNode<T>*n):
    node{n}
    {};

    reference operator*() const //Wert der Referenz zurueckgeben
    {
        return (*node).value;
    } 

    pointer operator->() const // Pointer/Wert - Adresse zurueckgeben
    {
        return &(node -> value);
    } 
    Self& operator++() // iterator++
    {
        node = (*node).next;
        return *this;
    }
    Self operator++( int ) //erst ausgabe des Wertes , folgend i++
    {
        Self wert = *this;
        ++(*this);
        return wert;
    } 
    bool operator==( Self const &x ) const //Vergleich 
    {
        if (node == x.node)  
		{							  
			return true;            
		}
		else
        {
            return false;
        }
    } 
    bool operator!=( Self const &x ) const //Ungleich
   {
        if (node != x.node) 
		{							  
			return true;            
		}
		else
        {
            return false;
        }
    } 
    Self next() const
    {
        if(node)
            return ListIterator(node->next);
        else
            return ListIterator(nullptr);
    }

    private :
    // The Node the iterator is pointing to
    ListNode <T>* node ;
};

template <typename T>
class ListConstIterator
{
public :
// not implemented yet
// do not forget about the initialiser lists !
private :
ListNode <T>* node ;
};

template <typename T>
class List
{
    public :
    using value_type = T;
    using pointer = T*;
    using const_ponter = T const* ;
    using reference = T&;
    using const_reference = T const& ; 
    using iterator = ListIterator <T>;
    using const_iterator =ListConstIterator <T>;

   
    List():                  // (4.2) Default-Constructor
    size_{0},
    first_{nullptr},
    last_{nullptr}
    {}

    ~List()                 // (4.4) Destructor 
    {
        clear();
    }

    List(std::initializer_list<T> list) //initialisierungsliste
        {
            for(auto i : list)
            {
                push_back(i);
            }
};

    bool empty () const     // (4.2)
    {
        if(size() == 0)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    std::size_t size() const // (4.2)
    {
        return size_ ;
    }

    //aufgabe (4.3)

    T front() const         
    {
        if ( empty() == true)
        {
            std::cout<<"empty list";
            return 0;
        }
        else
        {
            return (*first_).value;
        }
    }

    T back() const         
    {
        if ( empty() == true)
        {
            std::cout<<"empty list";
            return 0;
        }
        else
        {
            return (*last_).value;    //Wert worauf die Referenz zeigt   
        }
    }

    void push_front(T const& v)
    {
        ListNode<T>* node = new ListNode<T>;
        (*node).value = v;       //node -> value

        if (empty() == true )
        {
            last_ = node;
        }
        else
        {
            (*first_).prev = node;
            (*node).next = first_;
            first_ = node;
        }
        first_ = node;
        size_++;
        node = nullptr;

    }



    void push_back(T const& v)
    {
        ListNode<T>* node = new ListNode<T>;
        (*node).value = v;       //node -> value

        if (empty() == true )
        {
            first_ = node;
            last_ = first_;
        }
        else
        {
            (*last_).next = node;
            (*node).prev = last_;
            last_ = node;
        }
        size_++;
        node = nullptr;
    }

    void pop_front()
    {
        if (empty() == true)
        {
            std::cout<<"empty list";            
        }
        else
        {
            first_ = (*first_).next;
            (*first_).prev = nullptr;
            size_--;
        }
    }

    void pop_back()
    {
       if (empty() == true)
        {
            std::cout<<"empty list";            
        }
        else
        {
            last_ = (*last_).prev;
            (*last_).next = nullptr;
            size_--;
        }
    }

    void clear()        //aufgabe 4.4
    {
        if (empty() == false)
        {
            while (empty() == false)
            {
                pop_back();
            }
        }
        else
        {
            std::cout<<"empty list";  
        }
    }
    //aufgabe(4.6)
    ListIterator<T> begin() const
    {		
			return ListIterator<T>(first_);
	}
	ListIterator<T> end() const 
    {		
			return ListIterator<T>(nullptr);
    }


    private :
    std::size_t size_ ;
    ListNode <T>* first_;
    ListNode <T>* last_ ;
};
//aufgabe (4.7)
template<typename T>
bool operator ==(List<T>const& xs,List<T>const& ys)
{
    if(xs.size()!=ys.size())
    {
        return false;
    }
    else
    {
    ListIterator<T> x = xs.begin();
    ListIterator<T> y = ys.begin();

    for(int i = 0 ; i <xs.size() ; i++)    
    {
        if(*x != *y )
        {
            return false;
        }
        else
        {
        x++;
        y++;
        }
    }
        return true;
    }

}

template<typename T>
bool operator !=(List<T>const& xs,List<T>const& ys)
{
    return !(xs == ys);
}
# endif // #define BUW_LIST_HPP