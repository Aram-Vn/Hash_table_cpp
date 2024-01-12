#include "Hash_table.h"
#include <Single_linked_list.h>
#include <iostream>
#include <my_pair.h>
#include <vector>

int main()
{
    my::HashTable<int, int> h;

    my::Pair<int, int> test = my::make_pair(2, 88);

    h.Insertion(test);
    h.put(1, 5);
    h.put(2, 7);
    h.put(3, 9);
    h.put(4, 2);
    h.put(5, 5);
    h.put(6, 7);
    h.put(7, 7);

    std::cout << h.m_table.size() << std::endl;

    std::cout << h.Retrieval(7) << std::endl;

    std::vector<my::Pair<int, int>> res = h.entrySet();

    for( const auto& v : res){
        std::cout << v.first << " " << v.second << " ";
        std::cout << std::endl;
    }


    // h.clear();

    // std::vector<int> vec = h.keySet();

    // for( const auto& v : vec){
    //     std::cout << v << " ";
    // }
    // std::cout << std::endl;

    // vec.clear();

    // vec = h.values();

    // for (const auto& v : vec)
    // {
    //     std::cout << v << " ";
    // }
    // std::cout << std::endl;

    // if (h.containsKey(8))
    // {
    //     std::cout << "yes" << std::endl;
    // }
    // else
    // {
    //     std::cout << "NO" << std::endl;
    // }

    // if (h.containsValue(5))
    // {
    //     std::cout << h.size() << " yes" << std::endl;
    // }
    // else
    // {
    //     std::cout << "NO" << std::endl;
    // }

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
