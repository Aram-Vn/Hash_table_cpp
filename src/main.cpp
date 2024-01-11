#include "Hash_table.h"
#include <Single_linked_list.h>
#include <iostream>
#include <my_pair.h>

int main()
{
    my::HashTable<int, int> h;

    my::Pair<int, int> test = my::make_pair(2, 88);

    h.Insertion(test);
    h.put(8, 5);
    h.put(7, 7);
    h.put(6, 7);

    std::cout << h.m_table.size() << std::endl;

    std::cout << h.Retrieval(8) << std::endl;

    // h.clear();

    if (h.containsKey(8))
    {
        std::cout << "yes" << std::endl;
    }
    else
    {
        std::cout << "NO" << std::endl;
    }

    if (h.containsValue(5))
    {
        std::cout << h.size() << " yes" << std::endl;
    }
    else
    {
        std::cout << "NO" << std::endl;
    }

    // std::cout << h.m_primes.size() << std::endl;

    // for(auto& elem : h.m_primes)
    // {
    //     std::cout << elem << " ";
    // }
    // std::cout << std::endl;

    // for(int i = 0; i < 10; ++i)
    // {
    //     std::cout << h.m_primes[i] << " ";
    // }
    // std::cout << std::endl;
}
