#include <iostream>
#include <forward_list>
#include "ForwardList.hpp"

#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>

int main()
{
    {
        std::forward_list<int>  stdList;
        ForwardList<int>        ourList;

        for ( size_t i = 1; i <= 10; i++ )
        {
            std::cout << i << ' ';
            stdList.push_front( i );
            ourList.push_front( i );
        }

        std::cout << '\n';

        for ( int elem : stdList )
            std::cout << elem << ' ';
        std::cout << '\n';

        // Range-based for loop test
        for ( int elem : ourList )
            std::cout << elem << ' ';
        std::cout << '\n';

        ourList.print();

        std::cout << '\n';

        // Initializer list test
        ForwardList<int>    initedList  = { 2, 4, 6, 8, 10 };
        initedList.print();

        std::cout << '\n';

        // Operator= test
        ourList = initedList;

        ourList.print();

        std::cout << '\n';

        // Copy ctor test
        ForwardList<int>    copiedList( ourList );

        copiedList.print();

        std::cout << '\n';

        // Pop front test
        copiedList.pop_front();

        copiedList.print();

        std::cout << '\n';

        // Push front test
        copiedList.push_front( 9 );
        copiedList.push_front( 42 );

        copiedList.print();

        std::cout << '\n';

    }

    _CrtDumpMemoryLeaks();

    return 0;
}
