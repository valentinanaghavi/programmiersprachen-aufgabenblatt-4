#define CATCH_CONFIG_RUNNER

#include "catch.hpp"
#include "List.hpp"
#include <iostream>
#include <list>

int main(int argc, char *argv[])
{
  return Catch::Session().run(argc, argv);
}


TEST_CASE("size and empty","[List]")
{
    List<int> list1;
    REQUIRE(list1.empty());
    REQUIRE(list1.size()==0);
}


TEST_CASE("add an element with push_front","[modifiers]")
{
        List<int> list2;
        list2.push_front(2);
        list2.push_front(42);
        REQUIRE(42==list2.front());
}

TEST_CASE("add an element with push_back","[modifiers]")
{
        List<int> list22;
        list22.push_back(42);
        list22.push_back(2);
        REQUIRE(2==list22.back());

}

TEST_CASE("remove an element with pop_front","[modifiers]")
{
        List<int> list3;
        list3.push_back(3);
        list3.push_back(4);

        list3.pop_front();
        REQUIRE(4==list3.front());

        list3.pop_front();
        REQUIRE(list3.empty());

}

TEST_CASE("remove an element with pop_back","[modifiers]")
{
        List<int>list4;
        list4.push_back(4);
        list4.push_back(3);
        list4.push_back(7);

        list4.pop_back();
        REQUIRE(3==list4.back());

}

TEST_CASE("should be empty after clearing","[modifiers]")
{
        List<int>list;
        list.push_front(1);
        list.push_front(2);
        list.push_front(3);
        list.push_front(4);

        list.clear();

        REQUIRE(list.empty());
}

TEST_CASE("should be an empty range after default construction", "[iterators]")
{
    List<int> list;
    auto b = list.begin();
    auto e = list.end();

    REQUIRE(b == e);
}

TEST_CASE("provide acces to the first element with begin", "[iterators]")
{
    List<int> list;
    list.push_front(42);

    REQUIRE(42 == *list.begin());
}

TEST_CASE ( " copy constructor " , " [ constructor ] " )
{
    List<int>list;
    list.push_front(1);
    list.push_front(2);
    list.push_front(3);
    list.push_front(4);
    List<int>list2{list};
    REQUIRE(list==list2);
}

TEST_CASE ( " reverse " , " [ reverse ] " )
{
    List<int>list;
    list.push_back(1);
    list.push_back(2);
    list.push_back(3);
    list.push_back(4);
    list.reverse();
    REQUIRE( list.front()==4 );
    REQUIRE( list.back()==1 );

}

TEST_CASE ( " move constructor " , " [ constructor ] " )
{
    List<int>list;
    list.push_front(1);
    list.push_front(2);
    list.push_front(3);
    list.push_front(4);
    List<int>list2=std::move(list);
    REQUIRE(0==list.size());
    REQUIRE(list.empty());
    REQUIRE(4==list2.size());
}
