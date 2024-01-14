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
        ~HashTable() = default; // destructor
        HashTable();            // constructor

        void Insertion(my::Pair<K, T> put);       // Associates a key-value pair in the hashtable.
        T Retrieval(K Get);                       // Retrieves the value associated with a given key.
        void Deletion(K key);                     // Removes the key-value pair associated with a given key.
        void put(K key, const T& value);          // nserts a key-value pair into the hashtable.
        T get(K key);                             // Retrieves the value associated with the given key.
        void remove(K key);                       // Removes the key-value pair associated with the given key
        bool containsKey(K key) const;            // Checks if the hashtable contains a specific key.
        bool containsValue(const T& value) const; // Checks if the hashtable contains a specific value.
        size_t size() const;                      // Returns the number of key-value pairs in the hashtable
        bool isEmpty();                           // Checks if the hashtable is empty
        void clear();                             // Removes all key-value pairs from the hashtable
        std::vector<K> keySet();                  // Returns a set of all keys in the hashtable
        std::vector<T> values();                  // Returns a collection of all values in the hashtable
        std::vector<my::Pair<K, T>> entrySet();   // Returns a set of key-value pairs (entries) in the hashtable

    private:
        void rehash();  // Increases the size of the hashtable and rehashes its contents
        size_t prime(); // function to find prime numbers
        typename my::Forward_list<my::Pair<K, T>>::f_itr find_key(const K& key); /* function to find key in linked
                                                                                  * list and return iterator on it if
                                                                                  * not found return end()(nullptr)*/

        typename my::Forward_list<my::Pair<K, T>>::f_itr find_val(const T& val); /* function to find val in linked
                                                                                  * list and return iterator on it if
                                                                                  * not found return end()(nullptr) */

    private:
        std::vector<my::Forward_list<my::Pair<K, T>>> m_table; // our hashTable
        K m_key;                                               // key for hashing
        int m_max_size;                                        // for holdingt hee amount of nodes of largest list
    };

} // namespace my

#include "Hash_table_impl.hpp"

#endif // HASH_TABLE_H