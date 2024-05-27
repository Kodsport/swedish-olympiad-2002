#!/usr/bin/python3
from sys import stdin
import re, sys

integer = "(0|-?[1-9][0-9]*)"
word = re.compile("^[A-Z]{1,8}$")
oneint = re.compile("^" + integer + "$")

line = stdin.readline()
assert oneint.match(line)

n = int(line)
assert 2 <= n <= 10

for i in range(n+1):
	line = stdin.readline()
	assert word.match(line)

assert len(stdin.readline()) == 0
sys.exit(42)
