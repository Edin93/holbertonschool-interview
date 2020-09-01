#!/usr/bin/python3
'''Parses the log from the generator file.'''
import sys


status_codes = {
    '200': 0, '301': 0, '400': 0, '401': 0,
    '403': 0, '404': 0, '405': 0, '500': 0
}
file_size = 0
i = 1
sorted_codes = ['200', '301', '400', '401', '403', '404', '405', '500']
try:
    for line in sys.stdin:
        infos = line.split(' ')
        if len(infos) > 2:
            file_size += int(infos[-1])
            if infos[-2] in status_codes:
                status_codes[infos[-2]] += 1

        if i % 10 == 0:
            print('File size: {}'.format(file_size))
            for k in sorted_codes:
                if status_codes[k] != 0:
                    print('{}: {}'.format(k, status_codes[k]))
        i += 1
except KeyboardInterrupt:
    pass
finally:
    print('File size: {}'.format(file_size))
    for k in sorted_codes:
        if status_codes[k] != 0:
            print('{}: {}'.format(k, status_codes[k]))
