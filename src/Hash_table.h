#ifndef HASH_TABLE_H
#define HASH_TABLE_H

#include <Single_linked_list.h>
#include <iostream>
#include <my_pair.h>
#include <vector>
#include <cmath>

namespace my {
    template <class K, class T>
    class HashTable
    {
    public:
        ~HashTable() = default;
        HashTable();

        void Insertion(my::Pair<K, T> put);
        T Retrieval(K Get); // delete??
        void Deletion(K key);
        void put(K key, T value);
        T get(K key);
        void remove(K key);
        bool containsKey(K key);
        bool containsValue(T value);
        size_t size();
        bool isEmpty();
        void clear();
        std::vector<K> keySet();
        std::vector<T> values();
        // entrySet()
        void rehash();

    private:
        void prime();

    private:
        std::vector<my::Forward_list<my::Pair<K, T>>> m_table;
        K m_key;

    public:
        std::vector<size_t> m_primes;
    };

} // namespace my

#include "Hash_table_impl.hpp"

#endif // HASH_TABLE_H