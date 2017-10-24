#!/Users/ewen/anaconda3/bin/python3
# -*- encode: utf-8 -*-


"""Custom Grid cypher."""


import sys
import numpy as np


class Grid:
    def __init__(self, text):
        self._n = 0
        self._p = 0
        self._index = -1
        self._text = text
        self.size(len(text))
        self._tab = np.matrix([[""] * self._p] * self._n)

    def size(self, l):
        n = int(l**(1/2))
        m = int(l**(1/2))
        if n*m < l:
            m += 1
        while (n*m - l) >= 0.2*l:
            m += 1
            while (n-1)*m > l:
                n -= 1
        self._n = n
        self._p = m

    def text(self):
        self._index += 1
        try:
            return self._text[self._index]
        except:
            return " "

    def diag_indexes(self, diag=0, axis=0):
        if -1 >= diag >= -1 * (self._n - 1):
            return self._n + diag
        elif 0 <= diag <= abs(self._p - self._n):
            return self._n
        elif abs(self._p - self._n) + 1 <= diag <= self._p + self._n + 1:
            return self._p - diag

    def encode(self):
        n = 0
        for diag in range(-1 * (self._n - 1), 0):
            for i in range(self.diag_indexes(diag)):
                self._tab[abs(i - diag), abs(i)] = self.text().upper()
                n += 1
        for diag in range(self._p - self._n + 1):
            for i in range(self.diag_indexes(diag)):
                self._tab[i, i + diag] = self.text().upper()
                n += 1
        for diag in range(self._p - self._n + 1, self._p):
            for i in range(self.diag_indexes(diag)):
                self._tab[abs(i), abs(i + diag)] = self.text().upper()
                n += 1
        self.pprint()

    def pprint(self):
        out = ""
        n, p = self._tab.shape
        for r in range(n):
            for i in range(p):
                out += (self._tab[r, i] + ' ')
            out += '\n'
        print(out)


if __name__ == '__main__':
    if len(sys.argv) != 2:
        print("Usage crypto.py <text>")
        sys.exit(0)
    text = sys.argv[1]
    grid = Grid(text)
    grid.encode()
