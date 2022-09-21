#ifndef OUTOFRANGE_H
#define OUTOFRANGE_H

#include <cinttypes>
#include <cstdlib>
#include <string>
#include <sstream>

class OutOfRange {
public:
    OutOfRange(size_t l_, size_t r_, size_t ind_, const std::string &name_) :
        l(l_), r(r_), ind(ind_), name(name_) {}
    std::string what() {
        std::stringstream ss;
        ss << name << " out of range\n";
        ss << "Expected range: " << l << "..." << r << "\n";
        ss << "Recieved index: " << ind << "\n";
        return ss.str();
    }
private:
    size_t l, r, ind;
    std::string name;
};

#endif // OUTOFRANGE_H
