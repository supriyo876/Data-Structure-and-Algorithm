#include <iostream>
using namespace std;

// Simple Expansion (32-bit to 48-bit simulation)
unsigned long long expansion(unsigned int R) {
    // Just duplicate some bits (simplified)
    unsigned long long expanded = ((unsigned long long)R << 16) | (R >> 16);
    return expanded & 0xFFFFFFFFFFFF; // 48-bit mask
}

// Simple S-Box simulation
unsigned int sbox(unsigned long long input48) {
    unsigned int output32 = 0;

    for (int i = 0; i < 8; i++) {
        unsigned int sixBits = (input48 >> (42 - 6*i)) & 0x3F; // 6 bits
        unsigned int fourBits = (sixBits ^ (sixBits >> 1)) & 0xF; // fake substitution
        output32 |= (fourBits << (28 - 4*i));
    }

    return output32;
}

// Simple P-Box permutation
unsigned int permutation(unsigned int input) {
    return ((input << 3) | (input >> (32 - 3))); // rotate left by 3
}

// Mangler (F) function
unsigned int mangler(unsigned int R, unsigned long long roundKey) {
    unsigned long long expanded = expansion(R);
    unsigned long long xored = expanded ^ roundKey;
    unsigned int substituted = sbox(xored);
    unsigned int permuted = permutation(substituted);

    return permuted;
}

int main() {
    unsigned int R = 0x12345678;             // 32-bit right half
    unsigned long long roundKey = 0x123456789ABC; // 48-bit round key

    unsigned int result = mangler(R, roundKey);

    cout << "Input R: 0x" << hex << R << endl;
    cout << "Round Key: 0x" << hex << roundKey << endl;
    cout << "Mangler Output: 0x" << hex << result << endl;

    return 0;
}
