#!/usr/bin/python3
'''
Module contains a rotation function.
'''


def rotate_2d_matrix(matrix):
    ''' Rotates a 2D matrix 90 degrees clockwise. '''

    n = len(matrix)
    clone = []
    for i in range(n):
        sublist = []
        for j in range(n):
            sublist.append(matrix[i][j])
        clone.append(sublist)

    for i in range(n):
        for j in range(n):
            matrix[i][j] = clone[n - j - 1][i]
