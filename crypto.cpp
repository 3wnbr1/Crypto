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
    for (int i = 0; i <= n; i++) {
        if (isalpha(text[i])) {
            text[i] = tolower(text[i]);
            if (text[i] + key > 122) {
                text[i] = (text[i] + key) % 26 + 97 ;
            }
            else {
                text[i] += key;
            }
        }
    }
    return text;
}

string Cesar::decode(string text, int key) {

}


/*
CUSTOM GRID CYPHER
*/

Grid::Grid() {

}

string Grid::encode(string text) {
    int n = text.size();
    return "HELLO";
}

string Grid::decode(string text) {

}

