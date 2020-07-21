#!/usr/bin/python3
"""
You have n number of locked boxes in front of you.
Each box is numbered sequentially from 0 to n - 1 and
each box may contain keys to the other boxes.
Write a method that determines if all the boxes can be opened.
"""


def isInRange(i, boxes_length):
    '''Checks if indes of a box is outta the boxes range or not.'''
    if 0 <= i and i < boxes_length:
        return True
    return False


def openBox(boxes, opened, box_index, boxes_length):
    '''Opens the b_keys of the current box_index box.'''
    if not isinstance(boxes[box_index], list):
        raise TypeError('Element is not a list.')
    for k in boxes[box_index]:
        if (
            isinstance(k, int) and isInRange(k, boxes_length) and
            k not in opened
        ):
            opened.append(k)
            openBox(boxes, opened, k, boxes_length)


def canUnlockAll(boxes):
    '''Returns True if all boxes can be opened, else False.'''
    if not isinstance(boxes, list) or not len(boxes):
        return False
    boxes_length = len(boxes)
    opened = [0, ]
    try:
        openBox(boxes, opened, 0, boxes_length)
    except:
        return False
    for i in range(boxes_length):
        if i not in opened:
            return False
    return True
