#ifndef HASH_TABLE_IMPL_HPP
#define HASH_TABLE_IMPL_HPP

#include "Hash_table.h"
#include "Single_linked_list.h"
#include "my_pair.h"
#include <cstddef>
#include <vector>

template <class K, class T>
my::HashTable<K, T>::HashTable() : m_prime_ind(3), m_max_size(0)
{
    prime();
    m_key = m_primes[m_prime_ind];
    m_table.resize(m_primes[m_prime_ind]);
}

template <class K, class T>
void my::HashTable<K, T>::Insertion(my::Pair<K, T> put)
{
    K ind = put.first % m_key;
    auto itr = find_key(put.first);

    if (!m_table[ind].empty())
    {
        if (itr == m_table[ind].end())
        {
            m_table[ind].push_front(put);

            if (m_table[ind].size() > m_max_size)
            {
                m_max_size = m_table[ind].size();
            }
            return;
        }
        else
        {
            itr->m_val.second = put.second;
            return;
        }
    }
    m_table[ind].push_front(put);
}

template <typename K, typename T>
T my::HashTable<K, T>::Retrieval(K Get)
{
    K ind = Get % m_key;

    auto itr = find_key(Get);

    if (itr != nullptr)
    {
        return itr->m_val.second;
    }
    else
    {
        std::cout << "In Retrieval\n no val with such key" << std::endl;
    }
}

template <typename K, typename T>
void my::HashTable<K, T>::Deletion(K key)
{
    K ind = key % m_key;

    auto itr = find_key(key);

    if (itr != nullptr)
    {
        m_table[ind].erase(itr);
        return;
    }
    else
    {
        std::cout << "In Deletion\n no val with such key" << std::endl;
    }
}

template <typename K, typename T>
void my::HashTable<K, T>::remove(K key)
{
    Deletion(key);
}

template <typename K, typename T>
void my::HashTable<K, T>::put(K key, const T& value)
{
    K ind = key % m_key;

    auto itr = find_key(key);

    if (!m_table[ind].empty())
    {
        if (itr == m_table[ind].end())
        {
            m_table[ind].push_front(my::make_pair(key, value));

            if (m_table[ind].size() > m_max_size)
            {
                m_max_size = m_table[ind].size();
            }

            return;
        }
        else
        {
            itr->m_val.second = value;
            return;
        }
    }

    m_table[ind].push_front(my::make_pair(key, value));
}

template <typename K, typename T>
bool my::HashTable<K, T>::containsKey(K key)
{
    if (find_key(key) != nullptr)
    {
        return true;
    }

    return false;
}

template <typename K, typename T>
bool my::HashTable<K, T>::containsValue(const T& value)
{
    if (find_val(value) != nullptr)
    {
        return true;
    }
    return false;
}

template <typename K, typename T>
size_t my::HashTable<K, T>::size() const
{
    size_t size = 0;

    for (const auto& ind_of_arr : m_table)
    {
        size += ind_of_arr.size();
    }

    return size;
}

template <typename K, typename T>
bool my::HashTable<K, T>::isEmpty()
{
    if (size() == 0)
    {
        return true;
    }
    return false;
}

template <class K, class T>
void my::HashTable<K, T>::clear()
{
    for (auto& h_table : m_table)
    {
        h_table.clear();
    }
}

template <class K, class T>
std::vector<K> my::HashTable<K, T>::keySet()
{
    std::vector<K> res;

    for (int i = 0; i < m_table.size(); ++i)
    {
        for (auto it = m_table[i].begin(); it != m_table[i].end(); ++it)
        {
            res.push_back(it->m_val.first);
        }
    }

    return res;
}

template <class K, class T>
std::vector<T> my::HashTable<K, T>::values()
{
    std::vector<T> res;

    for (int i = 0; i < m_table.size(); ++i)
    {
        for (auto it = m_table[i].begin(); it != m_table[i].end(); ++it)
        {
            res.push_back(it->m_val.second);
        }
    }

    return res;
}

template <typename K, typename T>
typename my::Forward_list<my::Pair<K, T>>::f_itr my::HashTable<K, T>::find_key(const K& key)
{
    const auto hash_idx = key % m_table.size();
    for (auto it = m_table[hash_idx].begin(); it != m_table[hash_idx].end(); ++it)
    {
        if (it->m_val.first == key)
        {
            return it;
        }
    }

    return m_table[hash_idx].end();
}

template <typename K, typename T>
typename my::Forward_list<my::Pair<K, T>>::f_itr my::HashTable<K, T>::find_val(const T& val)
{
    for (int i = 0; i < m_table.size(); ++i)
    {
        for (auto it = m_table[i].begin(); it != m_table[i].end(); ++it)
        {
            if (it->m_val.second == val)
            {
                return it;
            }
        }
    }

    return nullptr;
}

template <class K, class T>
void my::HashTable<K, T>::prime() // function to find prime numbers
{
    m_primes.reserve(100000);
    int num = 2;
    while (m_primes.size() < 100000)
    {
        bool check = true;
        size_t val = sqrt(num);
        for (auto& elem : m_primes)
        {
            if (elem > val)
            {
                break;
            }

            if (num % elem == 0)
            {
                check = false;
                break;
            }
        }

        if (check)
        {
            m_primes.push_back(num);
        }

        ++num;
    }
}

#endif // HASH_TABLE_IMPL_HPP