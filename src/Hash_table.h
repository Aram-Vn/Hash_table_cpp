#ifndef HASH_TABLE_H
#define HASH_TABLE_H

#include <Single_linked_list.h>
#include <cmath>
#include <iostream>
#include <my_pair.h>
#include <vector>

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
        void prime(); // function to find prime numbers
        // void hasher(); 

    private:
    public:
        std::vector<my::Forward_list<my::Pair<K, T>>> m_table; // our hashTable
        std::vector<size_t> m_primes;                          // to hold prime numbers for m_kee
        size_t m_prime_ind;                                    // to hold prime number index
        K m_key;                                               // mey for hashing
    };

} // namespace my

#include "Hash_table_impl.hpp"

#endif // HASH_TABLE_H