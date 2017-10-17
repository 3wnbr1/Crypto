#ifndef CRYPTO_H
#define CRYPTO_H
#include <string>
#include <vector>

using namespace std;

class Crypto {
public:
    Crypto();
};


class Cesar {
public:
    Cesar();
    string encode(string text, int key = 0);
    string decode(string text, int key = 0);
};

class Grid {
public:
    Grid();
    string encode(string text);
    string decode(string text);
};

#endif // CRYPTO_H
