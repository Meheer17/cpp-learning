#include <cassert>
#include <iostream>

class DoubleArray
{
private:
    int m_length{};
    double *m_data{};

public:
    DoubleArray(int length)
    {
        assert(length > 0);
        m_data = new double[length]{};
        m_length = length;
    }

    DoubleArray(const DoubleArray &) = delete;
    DoubleArray &operator=(const DoubleArray &) = delete;

    ~DoubleArray()
    {
        delete[] m_data;
    }

    void erase()
    {
        delete[] m_data;
        // We need to make sure we set m_data to 0 here, otherwise it will
        // be left pointing at deallocated memory!
        m_data = nullptr;
        m_length = 0;
    }

    double &operator[](int index)
    {
        assert(index >= 0 && index < m_length);
        return m_data[index];
    }

    int getLength() const { return m_length; }
};

template <typename T> // added
class Array
{
private:
    int m_length{};
    T *m_data{}; // changed type to T

public:
    Array(int length)
    {
        assert(length > 0);
        m_data = new T[length]{}; // allocated an array of objects of type T
        m_length = length;
    }

    Array(const Array &) = delete;
    Array &operator=(const Array &) = delete;

    ~Array()
    {
        delete[] m_data;
    }

    void erase()
    {
        delete[] m_data;
        // We need to make sure we set m_data to 0 here, otherwise it will
        // be left pointing at deallocated memory!
        m_data = nullptr;
        m_length = 0;
    }

    // templated operator[] function defined below
    T &operator[](int index); // now returns a T&

    int getLength() const { return m_length; }
};

// member functions defined outside the class need their own template declaration
template <typename T>
T &Array<T>::operator[](int index) // now returns a T&
{
    assert(index >= 0 && index < m_length);
    return m_data[index];
}

int main()
{
    const int length{12};
    Array<int> intArray{length};
    Array<double> doubleArray{length};

    for (int count{0}; count < length; ++count)
    {
        intArray[count] = count;
        doubleArray[count] = count + 0.5;
    }

    for (int count{length - 1}; count >= 0; --count)
        std::cout << intArray[count] << '\t' << doubleArray[count] << '\n';

    return 0;
}