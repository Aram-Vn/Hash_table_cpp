#ifndef HASH_TABLE_H
#define HASH_TABLE_H

#include <Single_linked_list.h>
#include <cmath>
#include <iostream>
#include <my_pair.h>
#include <vector>

namespace my {
    template <typename K, typename T>
    class HashTable
    {
    public:
        ~HashTable() = default; //
        HashTable();            //

        void Insertion(my::Pair<K, T> put);     // Associates a key-value pair in the hashtable.
        T Retrieval(K Get);                     // Retrieves the value associated with a given key.
        void Deletion(K key);                   // Removes the key-value pair associated with a given key.
        void put(K key, const T& value);        // nserts a key-value pair into the hashtable.
        T get(K key);                           // Retrieves the value associated with the given key.
        void remove(K key);                     // Removes the key-value pair associated with the given key
        bool containsKey(K key);                // Checks if the hashtable contains a specific key.
        bool containsValue(const T& value);     // Checks if the hashtable contains a specific value.
        size_t size() const;                    // Returns the number of key-value pairs in the hashtable
        bool isEmpty();                         // Checks if the hashtable is empty
        void clear();                           // Removes all key-value pairs from the hashtable
        std::vector<K> keySet();                // Returns a set of all keys in the hashtable
        std::vector<T> values();                // Returns a collection of all values in the hashtable
        std::vector<my::Pair<K, T>> entrySet(); // Returns a set of key-value pairs (entries) in the hashtable
        void rehash();                          // Increases the size of the hashtable and rehashes its contents

    private:
        size_t prime(); // function to find prime numbers
        // void hasher();
        typename my::Forward_list<my::Pair<K, T>>::f_itr find_key(const K& key);
        typename my::Forward_list<my::Pair<K, T>>::f_itr find_val(const T& val);

    private:
    public:
        std::vector<my::Forward_list<my::Pair<K, T>>> m_table; // our hashTable
        K m_key;                                               // mey for hashing
        int m_max_size;                                        // for holding max size of nodes in some index
    };

} // namespace my

#include "Hash_table_impl.hpp"

#endif // HASH_TABLE_H