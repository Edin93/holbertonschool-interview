#!/usr/bin/python3
"""
Contains a function that validate a utf-8 data.
"""


def intToBin(n):
    """Converts an integer to binary."""
    return '{:08b}'.format(n)


def isValidByte(data):
    """Checks if the given data is a valid utf-8 byte."""
    if not(len(data)):
        return False
    for i in data:
        if not i.startswith('10'):
            return False
    return True


def validUTF8(data):
    """Check if given data is a valid UTF-8 encoding."""
    bytes = [intToBin(x) for x in data]
    i = 0
    limit = len(bytes)

    while (i < limit):
        if not bytes[i].startswith('0'):
            if bytes[i][:3].startswith('110'):
                if not isValidByte(bytes[i+1:i+2]):
                    return False
                i += 2
            elif bytes[i][:4].startswith('1110'):
                if not isValidByte(bytes[i+1:i+3]):
                    return False
                i += 3
            elif bytes[i][:5].startswith('11110'):
                if not isValidByte(bytes[i+1:i+4]):
                    return False
                i += 4
        i += 1
    return True
