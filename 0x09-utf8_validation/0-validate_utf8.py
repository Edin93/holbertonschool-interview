#!/usr/bin/python3
"""
Contains a function that validate a utf-8 data.
"""


def intToBin(n):
    """Converts an integer to binary."""
    return '{:b}'.format(n)


def validUTF8(data):
    """
    Check if given data is a valid UTF-8 encoding.
    """
    i = len(data) - 1
    last_byte_endings = ['110', '1110', '11110']

    while (i >= 0):
        b = intToBin(data[i])
        if len(b) <= 7:
            pass
        else:
            j = 0
            while (i > 0 and intToBin(data[i])[:2].startswith('10') and j < 3):
                i -= 1
                j += 1
            last = data[i - 1]
            if not (last in last_byte_endings):
                return False
            else:
                continue
        i -= 1
    return True
