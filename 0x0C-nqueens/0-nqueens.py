#!/usr/bin/python3
"""
Nqueens solver
"""
import sys


def verify_collision(a, b):
    """
    Checks if 2 Queens at 2 different positions collide.
    If they collide the function returns True, False otherwise.
    """
    if a[0] == b[0] or a[1] == b[1]:
        return True

    rx = abs(a[0] - b[0])
    ry = abs(a[1] - b[1])

    r = min(rx, ry)

    if r == 0:
        return False

    if a[0] > b[0]:
        if a[1] > b[1]:
            x = [a[0] - r, a[1] - r]
            if x == b:
                return True
        else:
            x = [a[0] - r, a[1] + r]
            if x == b:
                return True
    if b[0] > a[0]:
        if b[1] > a[1]:
            x = [b[0] - r, b[1] - r]
            if x == a:
                return True
        else:
            x = [b[0] - r, b[1] + r]
            if x == a:
                return True
    return False


def do_queens_collide(arr):
    """
    Verify if a group of Queens positioned differently collide or not.
    If one of the Queens collide with another one, the function returns True,
    False otherwise.
    """
    ln = len(arr)
    for i in range(ln - 1):
        c = arr[i]
        for j in range(i + 1, ln):
            if verify_collision(c, arr[j]):
                return True
    return False


def generate_N_Queens(arr, line_index, n, solutions, new_arr=[]):
    """
    A recursive function that looks for NxN Queens solutions.
    It appends each solution to the solutions list.
    """
    for i in arr[line_index]:
        na = new_arr[:]
        if do_queens_collide(na + [i]) is False:
            na.append(i)
            if line_index + 1 == n:
                solutions.append(na)
            else:
                generate_N_Queens(arr, line_index + 1, n, solutions, na)


def nqueens(n):
    """
    Solves the Nqueens chess challenge on an NxN chessboard.
    """
    solutions = []
    lines = []

    for i in range(n):
        current_list = []
        for j in range(n):
            a = [i, j]
            if a not in lines:
                current_list.append(a)
        lines.append(current_list)

    generate_N_Queens(lines, 0, n, solutions)

    return solutions


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
    solutions = nqueens(n)
    for s in solutions:
        print(s)


main()
