#!/usr/bin/python3
"""
You have n number of locked boxes in front of you.
Each box is numbered sequentially from 0 to n - 1 and
each box may contain keys to the other boxes.
Write a method that determines if all the boxes can be opened.
"""


def canUnlockAll(boxes):
    '''Returns True if all boxes can be opened, else False.'''
    boxes_length = len(boxes)
    box_index = 0
    opened = [0]
    while (box_index != boxes_length):
        current_box = boxes[box_index]
        if len(current_box) == 0:
            break
        for k in current_box:
            if k not in opened:
                opened.append(k)
        box_index += 1
    #print('KEYS')
    #print(sorted(opened))
    #print('-------------------------------')
    if len(opened) == boxes_length:
        return True
    return False
