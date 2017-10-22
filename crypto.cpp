#include "crypto.h"
#include <stdio.h>



Crypto::Crypto() {

}

/*
   CESAR CYPHER
 */

Cesar::Cesar() {
}

string Cesar::encode(string text, int key) {
	int n = text.size();
	bool upper;
	for (int i = 0; i <= n; i++) {
		if (isalpha(text[i])) {
			if (isupper(text[i])) {
				upper = true;
			} else {
				upper = false;
			}
			text[i] = tolower(text[i]);
			if ((text[i] + key > 122)||(text[i] + key < 97)) {
				text[i] = (text[i] - 97) % 26;
				if (upper) {
					text[i] = toupper((text[i] + key) % 26 + 97);
				} else {
					text[i] = (text[i] + key) % 26 + 97;
				}
			} else {
				if (upper) {
					text[i] = toupper(text[i] + key);
				} else {
					text[i] += key;
				}
			}
		}
	}
	return text;
}

string Cesar::decode(string text, int key) {
	return Cesar::encode(text, (26-key % 26));
}


/*
   CUSTOM GRID CYPHER
 */

Grid::Grid() {
	n = 0;
	p = 0;
	index = -1;
}

void Grid::size(int l) {
	n = int(l**(1/2));
	m = int(l**(1/2));
	if (n*m < l) {
		m += 1;
	}
	while ((n*m - l) >= 0.2*l) {
		m += 1;
		while ((n-1)*m > l) {
			n -= 1
		}
	}
}

string Grid::encode(string text) {
	return "HELLO" + text;
}

string Grid::decode(string text) {
	return "HEllo" + text;
}
