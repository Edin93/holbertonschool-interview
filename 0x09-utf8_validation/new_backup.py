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
    r5 = range(1067307794560, 1081253806016)
    r6 = range(277628841918592, 278999997595583)
    i = 0

    while (i < len(data)):
        n = data[i]
        b = '{:048b}'.format(n)
        if n in r1:
            pass
        elif n in r2:
            if not (b[32:].startswith('110') and b[40:].startswith('10')):
                return False
        elif n in r3:
            if not (
                    b[24:].startswith('1110') and
                    b[32:].startswith('10') and
                    b[40:].startswith('10')
            ):
                return False
        elif n in r4:
            if not (
                    b[16:].startswith('11110') and b[24:].startswith('10') and
                    b[32:].startswith('10') and b[40:].startswith('10')
            ):
                return False
        elif n in r5:
            if not (
                    b[8:].startswith('111110') and b[16:].startswith('10') and
                    b[24:].startswith('10') and b[32:].startswith('10') and
                    b[40:].startswith('10')
            ):
                return False
        elif n in r6:
            if not (
                    b.startswith('1111110') and b[40:].startswith('10') and
                    b[32:].startswith('10') and b[24:].startswith('10') and
                    b[16:].startswith('10') and b[8:].startswith('10')
            ):
                return False
        else:
            return False
        i += 1
    return True
