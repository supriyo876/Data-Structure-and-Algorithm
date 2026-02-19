#include <iostream>
using namespace std;

// round function
int F(int x, int k){
    return (x + k) % 256;
}

// encryption
void encrypt(int &L, int &R, int key[], int rounds){
    for(int i = 0; i < rounds; i++){
        int newL = R;
        int newR = L ^ F(R, key[i]);

        L = newL;
        R = newR;
    }
}

// decryption
void decrypt(int &L, int &R, int key[], int rounds){
    for(int i = rounds-1; i >= 0; i--){
        int newR = L;
        int newL = R ^ F(L, key[i]);

        L = newL;
        R = newR;
    }
}

int main(){

    int L = 12;   // left half (plaintext)
    int R = 34;   // right half (plaintext)

    int key[4] = {5, 9, 2, 7};
    int rounds = 4;

    cout << "Original: " << L << " " << R << endl;

    encrypt(L, R, key, rounds);
    cout << "Encrypted: " << L << " " << R << endl;

    decrypt(L, R, key, rounds);
    cout << "Decrypted: " << L << " " << R << endl;

    return 0;
}
