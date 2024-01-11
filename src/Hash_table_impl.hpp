#ifndef HASH_TABLE_IMPL_HPP
#define HASH_TABLE_IMPL_HPP


template <class K, class T>
my::HashTable<K, T>::HashTable()
{
    prime();
}

template <class K, class T>
void my::HashTable<K, T>::prime()
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