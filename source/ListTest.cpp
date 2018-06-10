#define CATCH_CONFIG_RUNNER

#include "catch.hpp"
#include "List.hpp"
#include <iostream>


int main(int argc, char* argv[])
{
    return Catch::Session().run(argc,argv);
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
        list2.push_front(42);
        REQUIRE(42==list2.front());

}

TEST_CASE("add an element with push_back","[modifiers]")
{
        List<int> list2{42};

        list2.push_back(2);
        REQUIRE(2==list2.back());

}

TEST_CASE("remove an element with pop_front","[modifiers]")
{
        List<int> list3{3,4};

        list3.pop_front();
        REQUIRE(4==list2.front());

        list3.pop_front();
        REQUIRE(list3.empty());

}

TEST_CASE("remove an element with pop_back","[modifiers]")
{
        List<int> list4{4,3,7};

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

TEST_CASE("return begin and end", "[modifiers]")
{
        List<int> list5{2,4,99,12};


        REQUIRE(2==list5.begin());
        REQUIRE(12==list5.end());

}

