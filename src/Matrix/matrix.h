#ifndef MATRIX_HPP
#define MATRIX_HPP

#include <utility>
#include <iostream>
#include <map>

#include "../Proxy/ValProxy.h"
#include "../exceptions/exceptions.h"
#include "../TypeName/TypeName.h"

template <typename T>
class Matrix
{
    static constexpr double EPS = 1e-6;
    using KeyType = std::pair<size_t, size_t>;
    using DataType = std::map<KeyType, T>;

public:
    Matrix(size_t N_, size_t M_, double eps_ = EPS) : N(N_), M(M_), eps(eps_) {}
    Matrix(const Matrix &m) : N(m.N), M(m.M), eps(m.eps), data(m.data), transp(m.transp) {}

    size_t getN() const { return N; }
    size_t getM() const { return M; }
    double getEpsilon() const { return eps; }
    size_t nonZeroCount() const { return data.size(); }

    void addValues(const std::initializer_list<std::pair<KeyType, T>> &l)
    {
        for (auto [key, val] : l)
        {
            data[key] = val;
        }
    }

    ValProxy<DataType, KeyType> operator()(size_t n, size_t m)
    {
        if (transp)
        {
            std::swap(n, m);
        }
        checkRange(n, m);
        return ValProxy(data, std::make_pair(n, m), eps);
    }

    ValProxy<DataType, KeyType> operator()(KeyType p)
    {
        return this->operator()(p.first, p.second);
    }

    T at(size_t n, size_t m) const
    {
        if (transp)
        {
            std::swap(n, m);
        }
        checkRange(n, m);
        if (data.find({n, m}) == data.end())
        {
            return T(0.0);
        }
        return data.at({n, m});
    }

    T at(KeyType p) const
    {
        return this->at(p.first, p.second);
    }

    Matrix<T> operator+(const Matrix<T> &v) const
    {
        if (v.getN() != this->N || v.getM() != this->M)
        {
            throw DimensionsMismatch();
        }
        Matrix<T> res(*this);
        for (auto [key, val] : v.data)
        {
            res(key) = res.at(key) + val;
        }
        return res;
    }

    Matrix<T> operator*(const T &k) const
    {
        Matrix<T> res(*this);
        for (auto &[key, val] : res.data)
        {
            val *= k;
        }
        return res;
    }

    Matrix<T> operator-() const
    {
        return this->operator*(-1);
    }

    Matrix<T> operator-(const Matrix<T> &m) const
    {
        if (m.getN() != this->N || m.getM() != this->M)
        {
            throw DimensionsMismatch();
        }
        Matrix<T> res(*this);
        for (auto [key, val] : m.data)
        {
            res(key) = res.at(key) - val;
        }
        return res;
    }

    Matrix<T> operator*(const Matrix<T> &m) const
    {
        double eps_ = std::min(eps, m.eps);
        Matrix<T> res(N, m.M, eps_);
        for (auto [key, val] : data)
        {
            auto [i, j] = key;
            if (transp)
            {
                std::swap(i, j);
            }
            for (auto [key2, val2] : m.data)
            {
                auto [i2, j2] = key2;
                if (m.transp)
                {
                    std::swap(i2, j2);
                }

                if (j == i2)
                {
                    res({i, j2}) = res.at(i, j2) + val * val2;
                }
            }
        }
        return res;
    }

    bool operator==(const Matrix<T> &m) const
    {
        if (N != m.N || M != m.M)
        {
            return false;
        }
        for (auto [key, val] : data)
        {
            auto [i, j] = key;
            if (transp)
            {
                std::swap(i, j);
            }
            if (val != m.at(i, j))
            {
                return false;
            }
        }
        for (auto [key, val] : m.data)
        {
            auto [i, j] = key;
            if (m.transp)
            {
                std::swap(i, j);
            }
            if (val != this->at(i, j))
            {
                return false;
            }
        }
        return true;
    }

    void transpose()
    {
        std::swap(N, M);
        transp = !transp;
    }

    std::string to_str()
    {
        std::stringstream ss;
        ss << *this;
        return ss.str();
    }

    friend std::ostream &operator<<(std::ostream &out, const Matrix<T> &m)
    {
        out << "Matrix " << get_type_name<T>() << " " << m.N << " " << m.M << "\n";
        for (auto [key, val] : m.data)
        {
            auto [i, j] = key;
            if (m.transp)
            {
                std::swap(i, j);
            }
            out << i << " " << j << " " << val << "\n";
        }
        return out;
    }

private:
    size_t N, M;
    double eps;

    DataType data;

    bool transp = false;

    void checkRange(size_t n, size_t m) const
    {
        if (!(1 <= n && n <= N))
        {
            throw OutOfRange(1, N, n, "Matrix::N");
        }
        if (!(1 <= m && m <= M))
        {
            throw OutOfRange(1, M, m, "Matrix::M");
        }
    }
};

#endif // MATRIX_HPP
