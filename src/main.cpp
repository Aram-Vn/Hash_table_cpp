#include "Hash_table.h"
#include <Single_linked_list.h>
#include <iostream>
#include <my_pair.h>
#include <vector>

int main()
{
    my::HashTable<int, double> h;

    my::Pair<int, double> test = my::make_pair(2.2, 8);

    h.Insertion(test);
    h.put(1, 5);
    h.put(2, 7);
    h.put(3, 9);
    h.put(4, 2);
    h.put(5, 5);
    h.put(6, 7);
    h.put(7, 7);
    h.put(8, 7);
    h.put(9, 7);
    h.put(12, 7);
    h.put(13, 7);
    h.put(14, 7);
    h.put(15, 7);
    h.put(16, 7);
    h.put(17, 7);

    double j = 0.1;

    for (int i = 0; i < 120; ++i)
    {
        ++j;
        h.put(i, j);
    }

    std::cout << h.Retrieval(7) << std::endl;

    std::vector<my::Pair<int, double>> res = h.entrySet();

    for( const auto& v : res){
        std::cout << v.first << " " << v.second << " ";
        std::cout << std::endl;
    }
}
