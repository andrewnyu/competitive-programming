#CF 1B: Spreadsheets
from math import floor

ap = 'ABCDEFGHIJKLMNOPQRSTUVWXYZ'

gap = [0 for i in range(7)]
for i in range(1,6):
    gap[i] = 26**(i-1) + gap[i-1]

def bin_to_xnry(x):
    num_len = 0
    temp_num = x
    while(temp_num>0):
        num_len += 1
        temp_num -= (26**num_len)

    #print(num_len)
    res = ""
    for i in reversed(range(num_len)):
        curr = floor((x-gap[i])/(26**i))
        #print(curr)
        
        res += ap[curr-1]

        x -= curr*(26**i)
        #print(x)

    assert x==0

    return res

def xnry_to_bin(x):
    res = 0
    for c,i in zip(x, reversed(range(len(x)))):
        res += (26**i)*(ord(c)-ord('A')+1)
    
    return res


t = int(input())

'''
test:

if t==-1:
    for i in range(1,int(1e5+1)):
        sample = bin_to_xnry(i)
        assert(i == xnry_to_bin(sample))
'''

for _ in range(t):
    num = input()

    #number uses R..C..format if 
    # a.) second char is num AND b.) another letter appears
    xnry = True
    second_is_num = num[1] not in ap

    #print(second_is_num)

    if second_is_num:
        for c in num[2:]:
            if c=='C':
                xnry = False
    

    if xnry:
        
        bp = 0
        for  i in range(len(num)):
            bp = i
            if num[i] not in ap:
                break
        
        col = str(xnry_to_bin(num[:bp]))
        row = num[bp:]

        res = "R"+row+"C"+col
        print(res)
    
    else:
        bp = 0
        for i in range(len(num)):
            bp = i
            if num[i] == 'C':
                break
        
        row = num[1:bp]
        col = bin_to_xnry(int(num[bp+1:]))
        res = col+row
        print(res)


        


    