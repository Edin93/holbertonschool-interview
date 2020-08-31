#!/usr/bin/python3
'''
Parses the log from the generator file.
'''
import sys


status_codes = {
    '200': 0, '301': 0, '400': 0, '401': 0,
    '403': 0, '404': 0, '405': 0, '500': 0
}
file_size = 0
try:
    for i, line in enumerate(sys.stdin, 1):
        split_line = line.split()
        if len(split_line) > 2:
            infos = [int(x) for x in split_line[-2:]]
            file_size += infos[1]
            if str(infos[0]) in status_codes:
                status_codes[str(infos[0])] += 1

        if i % 10 == 0:
            print('File size: {}'.format(file_size))
            for k in sorted(status_codes):
                if status_codes[k] != 0:
                    print('{}: {}'.format(k, status_codes[k]))
except KeyboardInterrupt:
    pass
finally:
    print('File size: {}'.format(file_size))
    for k in sorted(status_codes):
        if status_codes[k] != 0:
            print('{}: {}'.format(k, status_codes[k]))
