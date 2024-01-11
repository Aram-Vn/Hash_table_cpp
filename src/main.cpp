#include <Single_linked_list.h>
#include <iostream>
#include <my_pair.h>
#include "Hash_table.h"

int main()
{
    // my::Forward_list<int> my_list = { 8, 7, 6, 4, 9, 2, 7, 15, 1, 5 };
    // my_list.print();
    // my::Pair<int, bool> a{ 10, true };

    // return 0;


    my::HashTable<int, int> h;

    std::cout << h.m_primes.size() << std::endl;

    for(auto& elem : h.m_primes)
    {
        std::cout << elem << " ";
    }
    std::cout << std::endl;
}
