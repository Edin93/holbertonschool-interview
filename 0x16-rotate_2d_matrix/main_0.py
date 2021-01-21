#!/usr/bin/python3
"""
Test 0x16 - Rotate 2D Matrix
"""
rotate_2d_matrix = __import__('0-rotate_2d_matrix').rotate_2d_matrix

if __name__ == "__main__":
    matrix1 = [[1, 2, 3],
              [4, 5, 6],
              [7, 8, 9]]

    rotate_2d_matrix(matrix1)
    print(matrix1)

    matrix2 = [[10, 20, 30],
              [40, 50, 60],
              [70, 80, 90]]

    rotate_2d_matrix(matrix2)
    print(matrix2)
