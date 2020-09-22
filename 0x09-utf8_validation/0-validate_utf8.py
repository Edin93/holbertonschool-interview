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
        if len(bytes[i]) <= 7:
            pass
        elif len(bytes[i]) > 8:
            return False
        elif len(bytes[i]) == 8:
            j = 1
            end = ''
            while (
                    i < limit - 1 and
                    len(bytes[i]) == 8 and
                    bytes[i][:2].startswith('10') and
                    j <= 4
            ):
                i += 1
                j += 1
                end = '1' * j + '0'
            i += 1
            last = bytes[i]
            if not len(last) == 8:
                return False
            if not (last[:j].startswith(end)):
                return False
        i += 1
    return True
