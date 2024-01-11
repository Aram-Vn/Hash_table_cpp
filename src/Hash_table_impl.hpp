#ifndef HASH_TABLE_IMPL_HPP
#define HASH_TABLE_IMPL_HPP

#include "Single_linked_list.h"
#include "my_pair.h"
template <class K, class T>
my::HashTable<K, T>::HashTable() : m_prime_ind(3)
{
    prime();
    m_key = m_primes[m_prime_ind];
    m_table.resize(m_primes[m_prime_ind]);
}

template <class K, class T>
void my::HashTable<K, T>::Insertion(my::Pair<K, T> put)
{
    K ind =  put.first % m_key;

    m_table[ind].push_front(put);
}

// template <class K, class T>
// void my::HashTable<K, T>::hasher()
// {

// }

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