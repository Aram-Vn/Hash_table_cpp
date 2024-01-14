#ifndef HASH_TABLE_IMPL_HPP
#define HASH_TABLE_IMPL_HPP

// #include "Hash_table.h"
// #include "Single_linked_list.h"
// #include "my_pair.h"
// #include <cstddef>
// #include <vector>

//--------------------_parametrize_ctor_------------------------//
template <class K, class T>
my::HashTable<K, T>::HashTable() : m_max_size(0)
{
    m_key = 7;
    m_table.resize(7);
}

//------------------------_Insertion_---------------------------//
template <class K, class T>
void my::HashTable<K, T>::Insertion(my::Pair<K, T> put)
{
    if (m_key == m_max_size)
    {
        rehash();
    }

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

//----------------------------_Retrieval_--------------------------//
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

//---------------------------_get_-----------------------------------//
template <typename K, typename T>
T my::HashTable<K, T>::get(K key)
{
    return Retrieval(key);
}

//------------------------------_Deletion_--------------------------//
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

//------------------------------_remove_------------------------------//
template <typename K, typename T>
void my::HashTable<K, T>::remove(K key)
{
    Deletion(key);
}

//-----------------------------_put_-------------------------------//
template <typename K, typename T>
void my::HashTable<K, T>::put(K key, const T& value)
{
    if (m_key == m_max_size)
    {
        rehash();
    }

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

//------------------------------_containsKey_-------------------------//
template <typename K, typename T>
bool my::HashTable<K, T>::containsKey(K key) const
{
    if (find_key(key) != nullptr)
    {
        return true;
    }

    return false;
}

//-------------------------------_containsValue_-------------------------//
template <typename K, typename T>
bool my::HashTable<K, T>::containsValue(const T& value) const
{
    if (find_val(value) != nullptr)
    {
        return true;
    }
    return false;
}

//--------------------------------_size_---------------------------------//
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

//--------------------------------_isEmpty_--------------------------------//
template <typename K, typename T>
bool my::HashTable<K, T>::isEmpty()
{
    if (size() == 0)
    {
        return true;
    }
    return false;
}

//-------------------------------_clear_---------------------------------//
template <class K, class T>
void my::HashTable<K, T>::clear()
{
    for (auto& h_table : m_table)
    {
        h_table.clear();
    }
}

//--------------------------------_keySet_------------------------------//
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

//--------------------------------_values_---------------------------------//
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

//--------------------------------_entrySet_-------------------------------//
template <class K, class T>
std::vector<my::Pair<K, T>> my::HashTable<K, T>::entrySet()
{
    std::vector<my::Pair<K, T>> res;

    for (size_t i = 0; i < m_table.size(); ++i)
    {
        for (auto it = m_table[i].begin(); it != m_table[i].end(); ++it)
        {
            res.push_back(it->m_val);
        }
    }

    return res;
}

//-------------------------------------------||
//                                           ||
//--------_private_helper_functins_----------||
//                                           ||
//-------------------------------------------||

//--------------------------------_rehash_------------------------------------//
template <typename K, typename T>
void my::HashTable<K, T>::rehash()
{
    std::cout << "YESSSSS" << std::endl;

    size_t new_prime = prime();
    std::vector<my::Pair<K, T>> elements = entrySet();

    m_table.resize(new_prime);
    m_key = new_prime;

    for (const auto& pairs : elements)
    {
        Insertion(pairs);
    }
}

//--------------------------------_find_key-----------------------------------//
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

//-----------------------------------------_find_val_------------------------------------//
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

//--------------------------------------_prime_------------------------------//
template <class K, class T>
size_t my::HashTable<K, T>::prime() // function to find prime numbers
{
    std::vector<size_t> primes;
    primes.reserve(10);

    int num = 2;
    while (primes.size() < 100000)
    {
        bool check = true;
        size_t val = sqrt(num);
        for (auto& elem : primes)
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
            primes.push_back(num);
            if (num > m_key)
            {
                return num;
            }
        }

        ++num;
    }
}

#endif // HASH_TABLE_IMPL_HPP