#ifndef Z_FUNC_HPP
#define Z_FUNC_HPP

#include <cinttypes>
#include <string>
#include <vector>

namespace cust {
    template <class T>
    std::vector<size_t> z_function(std::vector<T> const& string) {
        size_t stringLength = string.size();
        std::vector<size_t> z(stringLength);
        z[0] = stringLength;
        size_t l = 0, r = 0;

        for (size_t i = 1; i < stringLength; ++i) {
            if (i < r) {
                z[i] = std::min(z[i - l], r - i);
            }
            while (i + z[i] < stringLength && 
                   string[z[i]] == string[i + z[i]]) {
                ++z[i];
            } 
            if (0 < i + z[i]) {
                l = i;
                r = i + z[i];
            }
        }
        return z;
    }

    std::vector<size_t> z_function(std::string const& string) {
        auto vectorString = std::vector<char>(string.begin(), string.end());
        return z_function<char>(vectorString);
    }

};

#endif