#ifndef VALPROXY_HPP
#define VALPROXY_HPP

#include <cmath>
#include <iterator>

template <typename C, typename K>
class ValProxy
{
    using T = typename C::mapped_type;

public:
    ValProxy(C &cont_, K key_, double eps_) : cont(cont_), key(key_), eps(eps_) {}
    void operator=(T new_val)
    {
        if (std::abs(new_val) < eps)
        {
            cont.erase(key);
        }
        else
        {
            cont[key] = new_val;
        }
    }
    operator T() const
    {
        if (cont.find(key) != cont.end())
        {
            return cont[key];
        }
        else
        {
            return T(0);
        }
    }

private:
    C &cont;
    K key;
    double eps;
};

#endif // VALPROXY_HPP
