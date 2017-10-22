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
	void size();
	string encode(string text);
	string decode(string text);
private:
	int n = 0;
	int p = 0;
	int index = -1;
};
#endif // CRYPTO_H
