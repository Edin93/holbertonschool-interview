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
output = ''
try:
    for i, line in enumerate(sys.stdin, 1):
        output = ''
        split_line = line.split()
        if len(split_line) > 2:
            infos = [int(x) for x in split_line[-2:]]
            file_size += infos[1]
            if str(infos[0]) in status_codes:
                status_codes[str(infos[0])] += 1

        output += 'File size: {}\n'.format(file_size)

        for k in sorted(status_codes):
            if status_codes[k] != 0:
                output += '{}: {}\n'.format(k, status_codes[k])

        output = output[:-1]

        if i % 10 == 0:
            if output != '':
                print(output)
                output = ''
except KeyboardInterrupt:
    pass
finally:
    if output != '':
        print(output)
