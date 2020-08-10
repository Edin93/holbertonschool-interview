#!/usr/bin/python3
"""
A function that calculates the min number of operations to get to n number of
letter 'H', if not possible return 0.
"""


def minOperations(n):
    """
    Return the min number of operations to get to n H characters
    """
    Hs = 1
    copy = 0
    paste = 0
    chars_to_paste = 0

    while (Hs < n):
        if (n % Hs == 0):
            copy += 1
            chars_to_paste = Hs
        elif (n % (Hs * 2) == 0 and Hs * 2 <= n):
            copy += 1
            chars_to_paste = Hs
        if Hs + chars_to_paste <= n:
            paste += 1
            Hs += chars_to_paste
    if Hs == n:
        return (copy + paste)
    return 0
