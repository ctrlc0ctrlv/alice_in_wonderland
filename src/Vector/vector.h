/**
 * Header containing Vector class declaration.
 *
 * @author ctrlc0ctrlv
 */

#ifndef _CUSTOM_VECTOR_
#define _CUSTOM_VECTOR_

#include <map>
#include <cmath>
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <cassert>
#include <type_traits>

#include "./../Rational_number/Rational_number.h"

/**
 * @brief Class that implements sparse vector using std::map as a container.
 *
 * @tparam T type of values
 */
template <class T>
class Vector
{
private:
    /**
     * @brief Data storage of Vector.
     */
    std::map<size_t, T> _vec;

    /**
     * @brief Theshold value: values that are lower than _eps are treated as zeros.
     */
    double _eps = 1e-6;

    /**
     * @brief Filters out zeros from vector.
     */
    void filter_eps();

public:
    /**
     * @brief Default constructor
     *
     * @note deault vector size is zero
     */
    Vector() : _vec() {}

    /**
     * @brief Default value constructor
     *
     * @param len length of constructed vector
     * @param def_value default value to fill the vector
     *
     * @note values will have indices in range [1, len]
     */
    Vector(size_t len, T def_value = T());

    /**
     * @brief Constructs a Vector from map
     *
     * @param vector_map vector keys and values storage
     */
    Vector(std::map<size_t, T> vector_map) : _vec(vector_map) { filter_eps(); };

    /**
     * @brief Constructs a Vector from file
     *
     * @param filename file storing vector data in a specific format
     */
    Vector(std::string filename);

    /**
     * @brief Copying constructor
     *
     * @param v vector to copy
     */
    Vector(const Vector<T> &v) : _vec(v._vec) { filter_eps(); }

    /**
     * @brief Copying operator
     *
     * @param other vector to copy
     * @return Vector&
     */
    Vector &operator=(const Vector<T> &other);

    /**
     * @brief Moving constructor
     *
     * @param other vector to move
     */
    Vector(Vector &&other);

    /**
     * @brief Moving operator
     *
     * @param other vector to move
     * @return Vector&
     */
    Vector &operator=(Vector &&other);

    /**
     * @brief Destructor
     *
     * @note empty: std::map should clear all itself
     */
    ~Vector() {}

    /**
     * @brief Addition assignment operator
     *
     * @return Vector&
     */
    Vector &operator+=(const Vector &);

    /**
     * @brief Addition operator
     *
     * @return Vector
     */
    Vector operator+(const Vector &);

    /**
     * @brief Unary minus sign operator
     *
     * @return Vector
     */
    Vector operator-();

    /**
     * @brief Subtraction assignment operator
     *
     * @return Vector&
     */
    Vector &operator-=(const Vector &);

    /**
     * @brief Subtraction operator
     *
     * @return Vector&
     */
    Vector operator-(const Vector &);

    /**
     * @brief Multiplication operator
     *
     * @tparam TT second multiplier
     * @return Vector
     */
    template <typename TT>
    Vector operator*(const TT &);

    /**
     * @brief Division operator
     *
     * @tparam TT devisor (denominator)
     * @return Vector
     */
    template <typename TT>
    Vector operator/(const TT &);

    /**
     * @brief Returns value stored with key vec_key
     *
     * @param vec_key key to search in vector
     * @return T&
     *
     * @note if there is no such key an exception will be produced
     */
    T &operator()(size_t vec_key);

    /**
     * @brief Returns const value stored with key vec_key
     *
     * @param vec_key key to search in vector
     * @return T&
     *
     * @note if there is no such key an exception will be produced
     */
    T const &operator()(size_t i) const;

    /**
     * @brief Converts vector data to string in a specific format
     *
     * @return std::string
     */
    std::string to_string();

    /**
     * @brief Returns size of the vector (amount of stored non-zero values)
     *
     * @return size_t
     */
    size_t size() const { return _vec.size(); };

    /**
     * @brief Returns iterator pointing on the start of the vector
     *
     * @return std::map<size_t, T>::iterator
     */
    std::map<size_t, T>::iterator begin() { return this->_vec.begin(); };

    /**
     * @brief Returns iterator pointing on the end of the vector
     *
     * @return std::map<size_t, T>::iterator
     */
    std::map<size_t, T>::iterator end() { return this->_vec.end(); };

    /**
     * @brief Writes vector in file in a specific format
     *
     * @param filename file where to store vector
     */
    void to_file(std::string filename);
};

//////////////////////////////////////////////////////////////////////////////////////////////

template <typename T>
Vector<T>::Vector(size_t n, T def_value) : _vec()
{
    for (size_t i = 1; i <= n; i++)
    {
        _vec[i] = def_value;
    }
    filter_eps();
}

template <typename T>
Vector<T>::Vector(Vector<T> &&other)
{
    _vec = other._vec;
}

template <typename T>
Vector<T>::Vector(std::string filename) : _vec()
{
    std::ifstream infile(filename);
    std::string header, type, size;
    infile >> header >> type >> size;

    T a, b;
    while (infile >> a >> b)
    {
        _vec[a] = b;
    }
    infile.close();
}

template <typename T>
Vector<T> &Vector<T>::operator=(Vector<T> &&other)
{
    if (this != &other)
    {
        delete[] _vec;
        _vec = other._vec;
    }
    return *this;
}

template <typename T>
T &Vector<T>::operator()(size_t i)
{
    assert((i >= 1) && (i <= _vec.rbegin()->first));
    return _vec.at(i);
}

template <typename T>
T const &Vector<T>::operator()(size_t i) const
{
    assert((i >= 1) && (i <= _vec.rbegin()->first));
    return _vec.at(i);
}

template <typename T>
Vector<T> &Vector<T>::operator=(const Vector<T> &other)
{
    if (this != &other)
    {
        _vec = other._vec;
        _vec.size() = other.size();
    }
    filter_eps();
    return *this;
}

template <class T>
Vector<T> &Vector<T>::operator+=(const Vector<T> &b)
{
    assert(this->size() == b.size());
    typename std::map<size_t, T>::iterator it;
    for (it = this->_vec.begin(); it != this->_vec.end(); it++)
        this->_vec.at(it->first) += b(it->first);
    filter_eps();
    return *this;
}
template <class T>
Vector<T> &Vector<T>::operator-=(const Vector<T> &b)
{
    assert(this->size() == b.size());
    typename std::map<size_t, T>::iterator it;
    for (it = this->_vec.begin(); it != this->_vec.end(); it++)
        this->_vec.at(it->first) -= b(it->first);
    filter_eps();
    return *this;
}

template <class T>
Vector<T> Vector<T>::operator+(const Vector<T> &b)
{
    assert(this->size() == b.size());
    Vector<T> result(*this);
    result += b;
    filter_eps();
    return result;
}

template <class T>
Vector<T> Vector<T>::operator-(const Vector<T> &b)
{
    assert(_vec.size() == b.size());
    Vector<T> result(*this);
    result -= b;
    filter_eps();
    return result;
}

template <class T>
Vector<T> Vector<T>::operator-()
{
    Vector<T> result(*this);
    typename std::map<size_t, T>::iterator it;
    for (it = this->_vec.begin(); it != this->_vec.end(); it++)
    {
        result(it->first) *= -1;
    }
    filter_eps();
    return result;
}

template <typename T>
template <typename TT>
Vector<T> Vector<T>::operator*(const TT &param)
{
    Vector<T> result(*this);
    typename std::map<size_t, T>::iterator it;
    for (it = this->_vec.begin(); it != this->_vec.end(); it++)
    {
        result(it->first) *= param;
    }
    filter_eps();
    return result;
}

template <typename T>
template <typename TT>
Vector<T> Vector<T>::operator/(const TT &param)
{
    // check if param value is zero
    assert(fabs(param) >= std::numeric_limits<TT>::epsilon());
    Vector<T> result(*this);
    typename std::map<size_t, T>::iterator it;
    for (it = this->_vec.begin(); it != this->_vec.end(); it++)
    {
        result(it->first) /= param;
    }
    filter_eps();
    return result;
}

template <class T>
std::string Vector<T>::to_string()
{
    std::stringstream ss;
    typename std::map<size_t, T>::iterator it;
    for (it = this->_vec.begin(); it != this->_vec.end(); it++)
    {
        ss << it->first << " " << it->second << std::endl;
    }
    return ss.str();
}

template <typename T>
void Vector<T>::filter_eps()
{
    typename std::map<size_t, T>::iterator it;
    for (it = this->_vec.begin(); it != this->_vec.end();)
    {
        if (fabs(double(it->second)) < _eps)
            this->_vec.erase(it++);
        else
            ++it;
    }
}

template <typename T>
void Vector<T>::to_file(std::string filename)
{
    std::ofstream out_file(filename);
    out_file << "vector "
             << "int " << this->size() << std::endl;

    out_file << this->to_string();
    out_file.close();
}

#endif // _CUSTOM_VECTOR_