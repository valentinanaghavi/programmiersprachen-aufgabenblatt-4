#ifndef BUW_LIST_HPP
#define BUW_LIST_HPP
#include <cstddef>
#include <list>
#include <vector>
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
    Self& operator++() // iterator++ mit ListIterator<T>
    {
        node = (*node).next;
        return *this;
    }
    Self operator++( int ) //erst ausgabe des Wertes , folgend i++ , ListIterator<T>
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
    {};

    List(List<T> const& list):     //(4.8)Copy Constructor
    size_{0},
    first_{nullptr},
    last_{nullptr}
    {
        for(auto i = list.begin(); i != list.end(); ++i)
        {
            push_back(*i);
        }
    };


    ~List()                 // (4.4) Destructor 
    {
        clear();
    }

    List(List<T>&& list):    //(4.11) Move Constructor = called when an object is initialized, transfer
    size_(list.size()),
    first_(list.first_),
    last_(list.last_)
    {
        list.size_ = 0;
        list.first_ = nullptr;
        list.last_ = nullptr;
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
        return (*first_).value;
    }
    

    T back() const         
    {
        return (*last_).value;    //Wert worauf der Pointer zeigt   
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
  
    }

    void pop_front()
    {
        if (empty() == true)
        {
            std::cout<<"empty list ";            
        }
        else if (size() == 1)
        {
            first_= nullptr;
            last_ = nullptr;
            size_--;
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
            std::cout<<"empty list ";            
        }
        else if (size() == 1)
        {
            first_= nullptr;
            last_ = nullptr;
            size_--;
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
    	iterator begin() const{

		iterator b{first_}; //ListIterator<T>
		return b; 
	    }

	    iterator end() const{

		return ListIterator<T>{}; //nullptr
        }

    //aufgabe(4.9)
     void insert(ListIterator<T> position, T const& wert)
     {
         if (size_ == 0)
         {
             push_front(wert);
         }
         else
         {
            auto p = begin();
            while (p != position)
            {
                p++;
            }
            ListNode<T>* node = new ListNode<T> {wert, p -> prev, p};
            p -> prev -> next = node;
            p -> prev = node;
         }
         size_++;
     }

        //aufgabe (4.13)
        void reverse()
        {
		    List<T> revlist{*this}; //Copy list
		    clear(); 
		    for(iterator i = revlist.begin(); i!=revlist.end(); ++i)
            {
			    push_front(*i);
		    }
        }
        //zusatzaufgabe(4.11)
        void copyy()
        {
            List<T> listObject{*this};
            std::vector <T> v;
            std::copy(listObject.begin(), listObject.end(), v.begin());
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

//aufgabe (4.10)
template <typename T> List<T> reverse (List<T> const& revlist)
{
    List<T> list(revlist);
    list.reverse();
    return list;
}

# endif // #define BUW_LIST_HPP