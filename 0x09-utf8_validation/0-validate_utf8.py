#!/usr/bin/python3
"""
Contains a function that validate a utf-8 data.
"""


def intToBin(n):
    """Converts an integer to binary."""
    return '{:08b}'.format(n)


def validUTF8(data):
    """
    Check if given data is a valid UTF-8 encoding.
    """
    bytes = [intToBin(x) for x in data]
    i = len(bytes) - 1

    while (i >= 0):
        if bytes[i].startswith('0'):
            pass
        else:
            j = 0
            while (
                    i > 0 and
                    bytes[i][:2].startswith('10') and
                    j < 3
            ):
                i -= 1
                j += 1
            i -= 1
            last = bytes[i]
            if not len(last) == 8:
                return False
            if not (j == 1 and last[:3].startswith('110')):
                return False
            elif not (j == 2 and last[:4].startswith('1110')):
                return False
            elif not (j == 3 and last[:5].startswith('11110')):
                return False
        i -= 1
    return True
