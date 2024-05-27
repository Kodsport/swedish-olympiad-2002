#!/usr/bin/python3
import sys
import re

int_pat = "(0|[1-9][0-9]*)"


line = sys.stdin.readline()
assert re.match("^" + int_pat + " " + int_pat + " " + int_pat + "$", line)
b, h, n = [int(x) for x in line.split()]
assert 0 < b <= 40000
assert 0 < h <= 40000
assert 4 <= n <= 50

for i in range(n):
    line = sys.stdin.readline()
    assert re.match("^" + int_pat + " " + int_pat + " " + int_pat + " " + int_pat + "$", line)
    x1, y1, x2, y2 = [int(x) for x in line.split()]
    assert 0 <= x1 <= b
    assert 0 <= x2 <= b

    assert 0 <= y1 <= h
    assert 0 <= y2 <= h

assert len(sys.stdin.readline()) == 0

sys.exit(42)
