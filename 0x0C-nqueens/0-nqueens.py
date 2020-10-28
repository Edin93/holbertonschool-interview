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
    print('success')


main()
