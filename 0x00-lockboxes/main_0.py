#!/usr/bin/python3

canUnlockAll = __import__('0-lockboxes').canUnlockAll

boxes = [[1], [2], [3], [4], []]
print(canUnlockAll(boxes), "\t: True")

boxes = [[1, 4, 6], [2, 0], [0, 4, 1], [5, 6, 2], [3], [4, 1], [6]]
print(canUnlockAll(boxes), "\t: True")

boxes = [[1, 4], [2], [0, 4, 1], [3], [], [4, 1], [5, 6]]
print(canUnlockAll(boxes),  "\t: False")

boxes = [[1,3],[3,0,1],[2],[0]]
print(canUnlockAll(boxes),  "\t: False")



boxes = [[1, 4], [2], [0, 4, 1], [3], [], [4, 1], [5, 6], [7]]
print(canUnlockAll(boxes), "\t: False")

boxes = [[1, 4, 6], [2], [0, 4, 1], [5, 6, 2], [3], [4, 1], [6], [7]]
print(canUnlockAll(boxes), "\t: False")

boxes = [[2], [3, 4], [1, 5]]
print(canUnlockAll(boxes), "\t: True")

boxes = [[2]]
print(canUnlockAll(boxes), "\t: True")

boxes = []
print(canUnlockAll(boxes), "\t: False")

boxes = [[1, 2, 3], [], [], [], []]
print(canUnlockAll(boxes), "\t: False")


boxes = None
print(canUnlockAll(boxes), "\t: False")

boxes = [[0, 4, 4], [5], [3], [1], [2], [5]]
print(canUnlockAll(boxes), "\t: True")

boxes = [[1, 4], [2], [0, 4, 1], [6], [3], [4, 1], [5, 6], [7]]
print(canUnlockAll(boxes), "\t: False")

boxes = [[1], [1], [1]]
print(canUnlockAll(boxes), "\t: False")

boxes = [[], [2], [4]]
print(canUnlockAll(boxes), "\t: False")
