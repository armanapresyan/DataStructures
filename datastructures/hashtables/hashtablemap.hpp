#ifndef HASHTABLEMAP_HPP
#define HASHTABLEMAP_HPP

#include <forward_list>
#include <vector>
#include <iostream>
#include <string>

template <typename T1, typename T2>
class Hashmap {
public:
    struct Pair {
        T1 str;
        T2 val;
    };

    Hashmap(unsigned int size) : m_size{size}, loadFactor{0.75}, table(m_size) {}

    unsigned int hashFunction(const std::string& word) {
        int seed = 131;
        unsigned long hash = 0;
        for (int i = 0; i < word.length(); i++) {
            hash = (hash * seed) + word[i];
        }
        return hash % table.size();
    }

    void insert(const T1& str, const T2& val) {
        if (m_size == 0) {
            std::cerr << "Error: m_size is zero!" << std::endl;
            return;
        }

        if (loadFactor == 0) {
            std::cerr << "Error: loadFactor is zero!" << std::endl;
            return;
        }

        if (this->size / table.size() >= loadFactor) {
            rehash();
        }

        unsigned int key = hashFunction(str);
        Pair pair;
        pair.str = str;
        pair.val = val;
        std::cout << key << std::endl;
        table[key].push_front(pair);
        ++this->size;
    }

    void rehash() {
        unsigned int newSize = m_size * 2;
        std::vector<std::forward_list<Pair>> newTable(newSize);
        for (const std::forward_list<Pair>& list : table) {
            for (const Pair& element : list) {
                unsigned int newKey = hashFunction(element.str);
                newTable[newKey].push_front(element);
            }
        }
        table = newTable;
        m_size = newSize;
    }

    T2 search(const T1& str) const {
        unsigned int key = hashFunction(str);
        const std::forward_list<Pair>& list = table[key];

        for (const Pair& element : list) {
            if (element.str == str) {
                return element.val;
            }
        }

        throw std::out_of_range("Value not found");
    }

    void remove(const T1& str) {
        unsigned int key = hashFunction(str);
        std::forward_list<Pair>& list = table[key];

        // Implement your removal logic here
        // e.g., using std::forward_list::remove_if
        list.remove_if([&str](const Pair& element) { return element.str == str; });

        --this->size;
    }

private:
    unsigned int m_size;
    double loadFactor;
    unsigned int size{};
    std::vector<std::forward_list<Pair>> table;
};

#endif // HASHTABLEMAP_HPP

