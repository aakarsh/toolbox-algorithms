#!/usr/bin/env python3.4
import sys

debug = True

def print_opt(opt,x,y):
    if not debug:
        return
    print("----------")
    for i in range(x):
        for j in range(y):
            print("%2d" % opt[i][j],end="")
        print("")
    print("----------")
        
def edit_distance(a,b):    
    x = len(a) + 1
    y = len(b) + 1
    opt  =  [[ 0 for i in range(y)] for j in range(x)]
    opt[0] = list(range(y))
    
    for i in range(x): opt[i][0] = i
    
    print_opt(opt,x,y)

    for i in range(1,x):        
        for j in range(1,y):
            edit_current  = 1  if b[j-1] !=  a[i-1] else 0            
            opt[i][j]= min(opt[i][j-1] + 1,
                           opt[i-1][j] + 1,
                           opt[i-1][j-1] + edit_current)            
    print_opt(opt,x,y)    
    return opt[x-1][y-1]

if __name__ == "__main__":
    debug = False
    if len(sys.argv) <= 2:
        print("-1")
        sys.exit(0)
        
    print(edit_distance(sys.argv[1],sys.argv[2]))
