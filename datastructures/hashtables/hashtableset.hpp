#ifndef HASHTABLESET_HPP
#define HASHTABLESET_HPP

#include <forward_list>
#include <vector>

template <typename T>
class HashSet{
public:
    HashSet(unsigned int size) : m_size{ size }, loadFactor{ 0.75 }, table(m_size) {}
    ~HashSet() = default;

    unsigned int hashFunction(unsigned int number) {
        return number % table.size();
    }

    
  void insert(T val) {
    if (m_size == 0) {
        std::cerr << "Error: m_size is zero!" << std::endl;
        return;
    }

    if (loadFactor == 0) {
        std::cerr << "Error: loadFactor is zero!" << std::endl;
        return;
    }

   
     if (size/table.size() >= loadFactor) {
        rehash();
    }
   
   

    unsigned int key = hashFunction(val);
    std::cout << key << std::endl;
    table[key].push_front(val);
    ++size;
}


    void rehash() {
        unsigned int newSize = m_size * 2;
        std::vector<std::forward_list<T>> newTable(newSize);
        for (const auto& list : table) {
            for (const auto& element : list) {
                unsigned int newKey = hashFunction(element);
                newTable[newKey].push_front(element);
            }
        }
        table = newTable;
        m_size = newSize;
    }

    T search(const T& val) const {
        unsigned int key = hashFunction(val);
        const std::forward_list<T>& list = table[key];

        for (const auto& element : list) {
            if (element == val) {
                return val;
            }
        }

        throw std::out_of_range("Value not found");
    }

    void remove(const T& val) {
        unsigned int key = hashFunction(val);
        std::forward_list<T>& list = table[key];

        if (list.remove(val)) {
            --size;
        } else {
            throw std::out_of_range("Value not found");
        }
    }

private:
    unsigned int m_size;
    double loadFactor;
    unsigned int size{};
    std::vector<std::forward_list<T>> table;
};

#endif // HASHTABLESET_HPP