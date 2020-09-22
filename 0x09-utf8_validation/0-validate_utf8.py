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
        if not bytes[i].startswith('0'):
            if bytes[i].startswith('11'):
                return False
            j = 0
            while (
                    i > 0 and
                    bytes[i][:2].startswith('10') and
                    j < 3
            ):
                i -= 1
                j += 1
            last = bytes[i]
            if (j == 1 and not last[:3].startswith('110')):
                return False
            elif (j == 2 and not last[:4].startswith('1110')):
                return False
            elif (j == 3 and not last[:5].startswith('11110')):
                return False
        i -= 1
    return True
