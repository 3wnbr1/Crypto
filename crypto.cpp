#include "crypto.h"

vector< int > factor(int n) {
    vector< int > factors;
    for (int i = 0; i < n; i++) {
        if (n % i == 0) {
            factors.push_back(i);
        }
    }
}

Crypto::Crypto()
{

}


Grid::Grid()
{

}

string Grid::encode(string text)
{
    int n = text.size();
    return "HELLO";
}

string Grid::decode(string text)
{

}

