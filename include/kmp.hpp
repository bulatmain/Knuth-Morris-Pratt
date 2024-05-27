#ifndef KMP_HPP
#define KMP_HPP

#ifdef KMP_TESTING
#define private public
#define protected public
#endif

#include <functional>
#include <iostream>
#include <iomanip>
#include <memory>

#include "strong_prefix_function.hpp"

namespace cust {
    template <class T>
    class KnuthMorrisPrattAlgorithm {
    public:
        KnuthMorrisPrattAlgorithm(
            std::vector<T> const& pattern,
            std::vector<T> const& text
            ) : pattern(pattern), text(text) {
            this->spf = strongPrefixFunction(pattern);
        }

        KnuthMorrisPrattAlgorithm(
            std::vector<T>&& pattern,
            std::vector<T>&& text
            ) = delete;

        std::vector<size_t> findAllOccurences() {
            if (occurences.empty()) {
                size_t i = 0, prev_i;
                while (i < text.size()) {
                    prev_i = i;
                    if (foundNextOccurence(i)) {
                        occurences.push_back(prev_i);
                    }
                }
            }
            return occurences;
        }

    protected:
        size_t findNextMismatch(size_t i) {
            auto j = i;
            while (j < std::min(pattern.size() + i, text.size()) && 
                   pattern[j - i] == text[j]) {
                ++j;
            }
            return j;
        }

        bool foundNextOccurence(size_t& i) {
            auto j = findNextMismatch(i);
            bool patternFound = pattern.size() <= j - i;
            if (j == i) {
                i += 1;
            } else {
                i += j - i - spf[j - i - 1];
            }
            return patternFound;
        }

    protected:
        std::vector<T> const& pattern;
        std::vector<T> const& text; 
        std::vector<size_t> spf;
        std::vector<size_t> occurences;

    };

    std::vector<size_t> knuthMorrisPrattAlgorithm(std::string const& pattern, std::string const& text) {
        std::vector<char> vpattern(pattern.begin(), pattern.end());
        std::vector<char> vtext(text.begin(), text.end());

        KnuthMorrisPrattAlgorithm<char> kmp(
            vpattern,
            vtext
        );
        return kmp.findAllOccurences();
    }

};

#endif