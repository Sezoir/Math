// Testing lib
#include <Catch/catch.hpp>
// Math lib
#include <Array.hpp>
#include <iostream>
TEST_CASE("Arrays can be created through various methods", "[Array]")
{
    SECTION("Creating an array from initializer list")
    {
        Math::Array<int, 3> array{1, 2, 3};
        REQUIRE(array[0] == 1);
        REQUIRE(array[1] == 2);
        REQUIRE(array[2] == 3);
    }
    SECTION("Creating an array from an array")
    {
        Math::Array<int, 3> array = {2, 3, 4};
        REQUIRE(array[0] == 2);
        REQUIRE(array[1] == 3);
        REQUIRE(array[2] == 4);
    }
    SECTION("Testing conversion of r-values to array type with std::forward")
    {
        Math::Array<float, 3> array = {2, 3, 4};
        REQUIRE(array[0] == 2);
        REQUIRE(array[1] == 3);
        REQUIRE(array[2] == 4);
    }
    SECTION("Setting values in an empty array")
    {
        Math::Array<int, 3> array;
        REQUIRE(array[0] == 0);
        REQUIRE(array[1] == 0);
        REQUIRE(array[2] == 0);
        array[0] = 4;
        array[1] = 3;
        array[2] = -5;
        REQUIRE(array[0] == 4);
        REQUIRE(array[1] == 3);
        REQUIRE(array[2] == -5);
    }
    SECTION("Empty array initialises with 0")
    {
        Math::Array<int, 3> arrayOne;
        REQUIRE(arrayOne[0] == 0);
        REQUIRE(arrayOne[1] == 0);
        REQUIRE(arrayOne[2] == 0);
        Math::Array<float, 3> arrayTwo;
        REQUIRE(arrayTwo[0] == 0);
        REQUIRE(arrayTwo[1] == 0);
        REQUIRE(arrayTwo[2] == 0);
    }
}

TEST_CASE("Array has various iterator methods", "[Array]")
{
    SECTION("Testing begin function")
    {
        Math::Array<int, 3> array{1, 2, 3};
        Math::Array<int, 3>::Iterator it = array.begin();
        REQUIRE(*it == 1);
    }
    SECTION("Testing cbegin function")
    {
        Math::Array<int, 3> array{1, 2, 3};
        Math::Array<int, 3>::ConstIterator it = array.cbegin();
        REQUIRE(*it == 1);
    }
    SECTION("Testing end function")
    {
        Math::Array<int, 3> array{1, 2, 3};
        Math::Array<int, 3>::Iterator it = array.end();
        REQUIRE(*it == 3);
    }
    SECTION("Testing cend function")
    {
        Math::Array<int, 3> array{1, 2, 3};
        Math::Array<int, 3>::ConstIterator it = array.cend();
        REQUIRE(*it == 3);
    }
    SECTION("Testing prefix and postfix increments")
    {
        Math::Array<int, 3> array{1, 2, 3};
        Math::Array<int, 3>::Iterator it = array.begin();
        REQUIRE(*(it++) == 1);
        REQUIRE(*it == 2);
        REQUIRE(*(++it) == 3);
    }
    SECTION("Testing ranged base for loop")
    {
        Math::Array<int, 3> array{1, 2, 3};
        int i = 0;
        for(int& value : array)
        {
            REQUIRE(array[i] == value);
            i++;
        }
    }
}

TEST_CASE("Array has several useful functions", "[Array]")
{
    SECTION("Testing fill")
    {
        Math::Array<int, 3> array{1, 2, 3};
        array.fill(5);
        REQUIRE(array[0] == 5);
        REQUIRE(array[1] == 5);
        REQUIRE(array[2] == 5);
    }
    SECTION("Testing swap")
    {
        Math::Array<int, 3> arrayOne{1, 2, 3};
        Math::Array<int, 3> arrayTwo{4, 5, 6};
        arrayOne.swap(arrayTwo);
        REQUIRE(arrayOne[0] == 4);
        REQUIRE(arrayOne[1] == 5);
        REQUIRE(arrayOne[2] == 6);
        REQUIRE(arrayTwo[0] == 1);
        REQUIRE(arrayTwo[1] == 2);
        REQUIRE(arrayTwo[2] == 3);
    }
    SECTION("Testing conversion to function")
    {
        Math::Array<int, 3> arrayOne{1, 2, 3};
        Math::Array<float, 3> arrayTwo{4, 5, 6};
        Math::Array<int, 3> result = arrayOne + arrayTwo.to<int>();
        REQUIRE(result[0] == 5);
        REQUIRE(result[1] == 7);
        REQUIRE(result[2] == 9);
    }
}

TEST_CASE("Operator overloads", "[Array]")
{
    SECTION("Testing arithmetic operators")
    {
        SECTION("+ overload")
        {
            Math::Array<int, 3> arrayOne{1, 2, 3};
            Math::Array<int, 3> arrayTwo{4, 5, 6};
            Math::Array<int, 3> result = arrayOne + arrayTwo;
            REQUIRE(result[0] == 5);
            REQUIRE(result[1] == 7);
            REQUIRE(result[2] == 9);
        }
        SECTION("- overload")
        {
            Math::Array<int, 3> arrayOne{1, 2, 13};
            Math::Array<int, 3> arrayTwo{4, 7, 9};
            Math::Array<int, 3> result = arrayOne - arrayTwo;
            REQUIRE(result[0] == -3);
            REQUIRE(result[1] == -5);
            REQUIRE(result[2] == 4);
        }
        SECTION("/ overload")
        {
            Math::Array<float, 3> arrayOne{6, 10, 3};
            Math::Array<float, 3> arrayTwo{2, 5, 6};
            Math::Array<float, 3> result = arrayOne / arrayTwo;
            REQUIRE(result[0] == 3);
            REQUIRE(result[1] == 2);
            REQUIRE(result[2] == 0.5);
        }
        SECTION("* overload")
        {
            Math::Array<int, 3> arrayOne{1, 2, -3};
            Math::Array<int, 3> arrayTwo{4, 5, 6};
            Math::Array<int, 3> result = arrayOne * arrayTwo;
            REQUIRE(result[0] == 4);
            REQUIRE(result[1] == 10);
            REQUIRE(result[2] == -18);
        }
        SECTION("+= overload")
        {
            Math::Array<int, 3> arrayOne{1, 2, 3};
            Math::Array<int, 3> arrayTwo{4, 5, 6};
            arrayOne += arrayTwo;
            REQUIRE(arrayOne[0] == 5);
            REQUIRE(arrayOne[1] == 7);
            REQUIRE(arrayOne[2] == 9);
        }
        SECTION("-= overload")
        {
            Math::Array<int, 3> arrayOne{1, 7, -3};
            Math::Array<int, 3> arrayTwo{4, 5, 6};
            arrayOne -= arrayTwo;
            REQUIRE(arrayOne[0] == -3);
            REQUIRE(arrayOne[1] == 2);
            REQUIRE(arrayOne[2] == -9);
        }
        SECTION("/= overload")
        {
            Math::Array<float, 3> arrayOne{8, -10, 3};
            Math::Array<float, 3> arrayTwo{4, 5, 6};
            arrayOne /= arrayTwo;
            REQUIRE(arrayOne[0] == 2);
            REQUIRE(arrayOne[1] == -2);
            REQUIRE(arrayOne[2] == 0.5);
        }
        SECTION("*= overload")
        {
            Math::Array<int, 3> arrayOne{1, 2, -3};
            Math::Array<int, 3> arrayTwo{4, 5, 6};
            arrayOne *= arrayTwo;
            REQUIRE(arrayOne[0] == 4);
            REQUIRE(arrayOne[1] == 10);
            REQUIRE(arrayOne[2] == -18);
        }
    }
    SECTION("Testing comparison operators")
    {
        SECTION("== overload")
        {
            Math::Array<int, 3> arrayOne = {1, 2, 3};
            Math::Array<int, 3> arrayTwo = {1, 2, 3};

            REQUIRE((arrayOne == arrayTwo));
        }
        SECTION("!= overload")
        {
            Math::Array<int, 3> arrayOne = {1, 2, 3};
            Math::Array<int, 3> arrayTwo = {2, 2, 3};

            REQUIRE((arrayOne != arrayTwo));
        }
    }
}