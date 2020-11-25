#!/usr/bin/python3
"""
0_main
"""
rain = __import__('0-rain').rain

if __name__ == "__main__":
    walls = [0, 1, 0, 2, 0, 3, 0, 4]
    print('TEST 1 ===>  {}'.format(rain(walls)))

    walls = [0, 1, 0, 2, 0, 3, 0, 4, 0, 0, 2]
    print('TEST 2 ===>  {}'.format(rain(walls)))

    walls = []
    print('TEST 3 ===>  {}'.format(rain(walls)))

    walls = [0, 0, 0, 0, 3]
    print('TEST 4 ===>  {}'.format(rain(walls)))

    walls = [5, 0, 0, 0]
    print('TEST 5 ===>  {}'.format(rain(walls)))

    walls = [0, 0]
    print('TEST 6 ===>  {}'.format(rain(walls)))

    walls = [6, 8, 1, 5, 2]
    print('TEST 7 ===>  {}'.format(rain(walls)))

    walls = [0,1,0,2,1,0,1,3,2,1,2,1]
    print('TEST 8 ===>  {}'.format(rain(walls)))

    walls = [1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1]
    print('TEST 9 ===>  {}'.format(rain(walls)))

