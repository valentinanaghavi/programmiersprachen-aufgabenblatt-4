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
    // not implemented yet
    // do not forget about the initialiser lists !
    private :
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

    ~List()                 // (4.5) Destructor 
    {
        clear();
    }

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
            return first_->value;
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
            return last_->value;    //Wert worauf die Referenz zeigt   
        }
    }

    void push_front(T const& value)
    {
        if (empty != 0 )
    }

    void push_back(T const& value)
    {

    }

    void pop_front()
    {
        if (empty != 0 )
    }

    void pop_back()
    {

    }

    void clear()
    {
        if (empty == false)
        {
            while (empty == false)
            {
                pop_back();
            }
        }
        else
        {
            std::cout<<"empty list";  
        }
    }


    private :
    std::size_t size_ ;
    ListNode <T>* first_;
    ListNode <T>* last_ ;
};

# endif // #define BUW_LIST_HPP