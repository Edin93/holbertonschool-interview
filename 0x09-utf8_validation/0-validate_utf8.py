#!/usr/bin/python3
"""
Contains a function that validate a utf-8 data.
"""


def validUTF8(data):
    """
    Check if given data is a valid UTF-8 encoding.
    """

    for n in data:
        if n in range(0, 128):
            pass
        elif n in range(128, 256):
            b = '{:b}'.format(n)
            b = b[::-1]
            b = (b[:8])[::-1]
            if not b.startswith('10'):
                return False
        else:
            return False
    return True
