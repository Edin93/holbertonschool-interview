#!/usr/bin/python3
"""
Nqueens solver
"""
import sys


def main():
    """
    Solves the Nqueens chess challenge on an NxN chessboard.
    """
    if len(sys.argv) != 2:
        print('Usage: nqueens N')
        exit(1)
    elif not sys.argv[1].isdigit():
        print('N must be a number')
        exit(1)
    elif int(sys.argv[1]) < 4:
        print('N must be at least 4')
        exit(1)
    n = int(sys.argv[1])
    sols = []
    solved = False
    i = 0
    while (i < n and not solved and len(sols) != n):
        for j in range(n):
            p = [i, j]
            sols.append(p)
            for x in sols:
                if p[0] == x[0] or p[1] == x[1]:
                    sols.remove(p)
                    i = 0
        i += 1
    return sols

r = main()
print(r)
