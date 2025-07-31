#include "rna_transcription.h"

#include <map>
#include <algorithm>
#include <stdexcept>

namespace rna_transcription {

namespace {
    std::map<char, char> trans {
        {'G', 'C'},
        {'C', 'G'},
        {'T', 'A'},
        {'A', 'U'}
    };
}

char to_rna(char dna){
    auto it = trans.find(dna);
    if (it == trans.end()) throw std::invalid_argument("DNA representation may only have values A, C, T, G");
    return it->second;
}

std::string to_rna(std::string dna){
    std::transform(dna.begin(), dna.end(), dna.begin(), [](char c) { return to_rna(c); });
    return dna;
}

}  // namespace rna_transcription
