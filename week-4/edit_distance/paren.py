#!/usr/bin/env python3.4

import sys


def min_max(i,j,M,m,operations):
    """Use tables M and m of sub problem solutions to compute."""

    def add(a,b): return a+b
    def sub(a,b): return a-b
    def mul(a,b): return a*b

    op_map = { "+" : add, "-" : sub, "*": mul }

    minimum =  float('inf')
    maximum = -float('inf')

    for k in range(i,j):
        op  = op_map[operations[k]]
        a = op(M[i][k],M[k+1][j])
        b = op(M[i][k],m[k+1][j])
        c = op(m[i][k],m[k+1][j])
        d = op(m[i][k],M[k+1][j])

        #print("a:%d b:%d c:%d d:%d" % (a,b,c,d))

        minimum   = min(minimum,a,b,c,d)
        maximum = max(maximum,a,b,c,d)

    return (minimum,maximum)


def parens(nums,ops,operations):
    n  = len(nums)
    M = [ [ 0 for i in range(n)] for i in range(n) ]
    m = [ [ 0 for i in range(n)] for i in range(n) ]

    # Initialize the diagonal for minimum and maximum.
    for i in range(n):
        m[i][i] = M[i][i] = nums[i]

    for s in range(1,n):
        for i in range(0,n-s):
            j = (i+s)
            m[i][j],M[i][j] = min_max(i,j,M,m,operations)

    print("M:")
    for i in range(n):
        for j in range(n):
            print(" %3d "%M[i][j],end="")
        print()

    print("m:")
    for i in range(n):
        for j in range(n):
            print(" %3d "% m[i][j],end="")
        print()

    return M[0][n-1]


def t1():
    exp = "5-8+7*4-8+9"

    nums,ops = parse(exp)
    print(nums)
    operations = list(map(exp.__getitem__,ops))
    max_value = parens(nums,ops,operations)    
    print("max_value = %d " % max_value)


def parse(exp, ops=["+","-","*"]):
    """parse ..."""

    pos = {}
    for op in ops:
        pos[op] = []

    positions = []
    for op in ops:
        start = 0
        while True:
            op_pos = exp.find(op, start)
            if op_pos == -1:
                break
            pos[exp[op_pos]].append(op_pos)
            positions.append(op_pos)
            start = op_pos + 1

    positions.sort()

    nums = []
    prev = -1

    for cur in positions:
        d = exp[prev+1:cur]
        if len(d) > 0:
            nums.append(int(d))
        prev = cur
        
    nums.append(int(exp[prev+1:]))


    return (nums, positions)


if __name__ == "__main__":
    print("paren")
