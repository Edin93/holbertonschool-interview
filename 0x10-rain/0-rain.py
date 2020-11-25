#!/usr/bin/python3
"""
Module for calculating water retention after it rains.
"""


def rain(walls: list) -> int:
    """
    Calculates how much water will be retained after it rains.

    Parameters:
        walls (list): list of non-negative integers.

    Returns:
        (int): the amount of rainwater retained, as an integer.
    """
    i = 0
    j = 0
    rain = 0
    diff = 0
    end = len(walls)

    i = j + 1
    separation = 0

    while i < end:
        if walls[j] > walls[i]:
            diff += walls[i]
            separation += 1
            i += 1
        elif walls[j] <= walls[i] or i == end - 1:
            rain += min(walls[i], walls[j]) * separation - diff
            separation = 0
            diff = 0
            j = i
            i += 1

    return rain
