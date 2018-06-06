# ifndef BUW_LIST_HPP
# define BUW_LIST_HPP
# include <cstddef>
// List . hpp

template <typename T>
class List;

template <typename T>
struct ListNode
{
    T value = T ();
    ListNode * prev = nullptr ;
    ListNode * next = nullptr ;
};

template <typename T>
class ListIterator
{
    public :
    // not implemented yet
    // do not forget about the initialiser lists !
    private :
    ListNode <T >* node ;
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

    // not implemented yet
    // do not forget about the initialiser list !
    private :
    std::size_t size_ ;
    ListNode <T>* first ;
    ListNode <T>* last_ ;
};

# endif // # define BUW_LIST_HPP