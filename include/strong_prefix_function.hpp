#ifndef STRONG_PREFIX_FUNCTION_HPP
#define STRONG_PREFIX_FUNCTION_HPP

#include "z_function.hpp"

namespace cust {
    template <class T>
    std::vector<size_t> strongPrefixFunction(std::vector<T> const& string) {
        auto z = z_function(string);
        std::vector<size_t> spf(z.size());
        for (size_t i = 1, j; i < z.size(); ++i) {
            j = z.size() - i;
            spf[j + z[j] - 1] = z[j];
        }
        return spf;
    }

    std::vector<size_t> strongPrefixFunction(std::string const& string) {
        auto vectorString = std::vector<char>(string.begin(), string.end());
        return strongPrefixFunction<char>(vectorString);
    }

};

#endif