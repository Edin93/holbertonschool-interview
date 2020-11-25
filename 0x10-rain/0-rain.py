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
    left = 0
    right = 0
    rain = 0
    if not isinstance(walls, list):
        return 0
    end = len(walls)
    if end == 0:
        return 0

    while left < 0 and walls[left] == 0:
        left += 1

    right = left + 1

    while right < end:
        if walls[left] > walls[right]:
            rain += walls[left] - walls[right]
            right += 1
        else:
            left = right
            right += 1
    return rain

    # while j < end and walls[j] == 0:
    #     j += 1

    # i = j + 1
    # separation = 0

    # while i < end:
    #     if walls[i] == 0:
    #         i += 1
    #         separation += 1
    #     else:
    #         rain += min(walls[i], walls[j]) * separation
    #         separation = 0
    #         j = i
    #         i += 1

    # return rain
