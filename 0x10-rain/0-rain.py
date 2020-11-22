#!/usr/bin/env python3
"""
Module for calculating water retention after it rains.
"""


def rain(walls):
    """
    Calculates how much water will be retained after it rains.

    Parameters:
        walls (list): list of non-negative integers.

    Returns:
        (int): the amount of rainwater retained, as an integer.
    """
    end = len(walls)
    rain = 0
    i = 0
    j = 0

    if end == 0:
        return 0

    while j < end and walls[j] == 0:
        j += 1

    i = j + 1
    separation = 0

    while i < end:
        if walls[i] == 0:
            i += 1
            separation += 1
        else:
            rain += min(walls[i], walls[j]) * separation
            separation = 0
            j = i
            i += 1

    return rain
