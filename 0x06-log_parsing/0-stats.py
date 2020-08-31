#!/usr/bin/python3
'''
Parses the log from the generator file.
'''
import signal
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
        infos = [int(x) for x in line.split()[-2:]]
        file_size += infos[1]
        status_codes[str(infos[0])] += 1

        output += 'File size: {}\n'.format(file_size)

        for k in sorted(status_codes):
            if status_codes[k] != 0:
                output += '{}: {}\n'.format(k, status_codes[k])

        output = output[:-1]

        if i % 10 == 0:
            print(output)
            output = ''
except KeyboardInterrupt:
    pass
finally:
    print(output)
