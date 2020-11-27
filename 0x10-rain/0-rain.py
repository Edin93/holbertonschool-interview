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
    start = 0
    end = 0
    current_max = 0
    rain = 0
    edges = []
    n = len(walls)

    end = start + 1
    current_max = end
    while end < n:
        while end < n and walls[start] > walls[end]:
            end += 1
            if end < n and walls[current_max] <= walls[end]:
                current_max = end
        # print('START = ', start)
        # print('END = ', end)
        # print('CURRENT MAX = ', current_max)
        # print('---------------------------')
        end = current_max
        if end > start + 1:
            edges.append((start, end))
        start = end
        end = start + 1
        current_max = end

    # print('EDGES ==> ', edges)

    for t in edges:
        t0 = t[0]
        t1 = t[1]
        holding_wall = min(walls[t0], walls[t1])
        for i in walls[t0 + 1: t1]:
            rain += holding_wall - i

    return rain
