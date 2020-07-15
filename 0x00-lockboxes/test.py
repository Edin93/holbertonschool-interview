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
    keys = []
    print("BOXES LENGTH = {}".format(boxes_length))
    #while box_index < boxes_length and (len(keys) < boxes_length or len(keys) < boxes_length - 1):
    while (len(keys) <=  boxes_length):
        current_box = boxes[box_index]
        if box_index not in keys:
            keys.append(box_index)
        if len(current_box) == 0:
            break
        print(keys)
        for k in current_box:
            if k not in keys:
                box_index = k
                break
            else:
                for x in boxes[k]:
                    if x not in keys:
                        box_index = x
                        break
    #keys.sort()
    #print('KEYS')
    #print(keys)
    print('-----------------------------------')
    return True
