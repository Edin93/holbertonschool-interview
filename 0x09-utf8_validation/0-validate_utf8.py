#!/usr/bin/python3
"""
Contains a function that validate a utf-8 data.
"""


def validUTF8(data):
    """
    Check if given data is a valid UTF-8 encoding.
    """
    r1 = range(0, 128)
    r2 = range(49280, 57280)
    r3 = range(14712960, 15712192)
    r4 = range(4034953344, 4156538816)
    i = 0

    while (i < len(data)):
        n = data[i]
        if n > 127:
            return False
        i += 1
    return True
