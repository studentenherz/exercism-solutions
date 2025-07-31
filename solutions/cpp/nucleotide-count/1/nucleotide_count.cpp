#include "nucleotide_count.h"

#include <stdexcept>

namespace nucleotide_count {

std::map<char, int> count(std::string sequence){
    std::map<char, int> cnt{ {'A', 0}, {'C', 0}, {'G', 0}, {'T', 0} };
    for (auto neuclotide: sequence){
        auto it = cnt.find(neuclotide);
        if (it == cnt.end()){
            throw std::invalid_argument("A DNA sequence representation can only have A, C, G, T");
        }
        it->second++;
    }
    return cnt;
}

}  // namespace nucleotide_count
