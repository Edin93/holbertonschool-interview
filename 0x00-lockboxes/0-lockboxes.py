#!/usr/bin/python3
"""
You have n number of locked boxes in front of you.
Each box is numbered sequentially from 0 to n - 1 and
each box may contain keys to the other boxes.
Write a method that determines if all the boxes can be opened.
"""


def openBox(d, box_index):
    '''Opens the b_keys of the current box_index box.'''
    for k in d[box_index].get('b_keys'):
        if not d[k]['Open']:
            d[k]['Open'] = True
            openBox(d, k)


def canUnlockAll(boxes):
    '''Returns True if all boxes can be opened, else False.'''
    boxes_length = len(boxes)
    d = {
        0: {
            "Open": True,
            "b_keys": boxes[0]
        }
    }
    for i in range(1, boxes_length):
        d[i] = {
            "Open": False,
            "b_keys": boxes[i]
        }
    openBox(d, 0)
    for v in d.values():
        if not v['Open']:
            return False
    return True
