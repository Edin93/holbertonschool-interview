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
    bytes = [intToBin(x) for x in data]
    bytes = bytes[::-1]
    limit = len(bytes)
    i = 0

    while (i < limit):
        b = bytes[i]
        if len(b) <= 7:
            pass
        elif len(b) > 8:
            return False
        elif len(b) == 8:
            j = 0
            while (
                    i < limit - 1 and
                    len(bytes[i]) == 8 and
                    bytes[i][:2].startswith('10') and
                    j < 3
            ):
                i += 1
                j += 1
            i += 1
            last = intToBin(data[i])
            if not len(last) == 8:
                return False
            if not (j == 1 and last[:3].startswith('110')):
                return False
            elif not (j == 2 and last[:4].startswith('1110')):
                return False
            elif not (j == 3 and last[:5].startswith('11110')):
                return False
        i += 1
    return True
