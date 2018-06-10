#define CATCH_CONFIG_RUNNER

#include "catch.hpp"
#include "List.hpp"
#include <iostream>


int main(int argc, char* argv[])
{
    return Catch::Session().run(argc,argv);
}

TEST_CASE("List-method","[List]")
{
    SECTION("size and empty")
    {
        List<int> list;
        REQUIRE(list.empty());
        REQUIRE(list.size()==0);
    }
}

