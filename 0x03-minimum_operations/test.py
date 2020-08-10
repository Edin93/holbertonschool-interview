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
    chars_to_paste = 1

    while (Hs < n):
        print("Hs = ", Hs)
        print("copy = ", copy)
        print("paste = ", paste)
        print("chars_to_paste = ", chars_to_paste)
        print('-------------------')
        if (n % (Hs * 2) == 0 and Hs * 2 <= n):
            if Hs * 2 < n:
                copy += 1
            paste += 1
            chars_to_paste = Hs
            Hs *= 2
        elif (n % (Hs + chars_to_paste) == 0 and Hs + chars_to_paste <= n):
            if Hs + chars_to_paste < n:
                copy += 1
            paste += 1
            Hs += chars_to_paste
            chars_to_paste = Hs
        else:
            paste += 1
            Hs += chars_to_paste
    print("Hs = ", Hs)
    print("copy = ", copy)
    print("paste = ", paste)
    print("chars_to_paste = ", chars_to_paste)
    print('-------------------')
    #print("******************************************************")
    if Hs == n:
        return (copy + paste)
    return 0
