#!/usr/bin/env python3.4

import sys




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

    return (nums,positions)


if __name__ == "__main__":
    print("paren")
    pass
