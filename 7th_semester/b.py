import numpy as np

def fif():
    f_or = [14,13,12,9,6,2,0]
    for a in range(1,7):
        f = [a*x%15 for x in f_or]
        s = ''
        for i in f:
            s += str(_2pow(i))+'^'
        res = eval(s[:-1])
        
        print('2^'+'+2^'.join([str(x) for x in f]), end='=')
        print('+'.join([str(_2pow(x)) for x in f]), end='=')
        print('_2+'.join([bin(_2pow(x))[2:].zfill(4) for x in f]), end='=')
        print(bin(res)[2:].zfill(4)+'_2='+str(res))

def mult(x, y):
    x = [int(i) for i in bin(x)[2:]]
    y = [int(i) for i in bin(y)[2:]]
    res = np.polydiv(np.polymul(x,y), [1, 0, 0, 1, 1])
    res = [int(r)%2 for r in res[1]]
    res = [str(r) for r in res]
    res = ''.join(res)
    return int(res, 2)
    
def _2pow(n):
    return [1,2,4,8,3,6,12,11,5,10,7,14,15,13,9,1][n]

def indn(n):
    return [15,0,1,4,2,8,5,10,3,14,9,7,6,13,11,12][n]
    
def ord2(m):
    return mult(m[0],m[3])^mult(m[1],m[2])
 
def ord(m):
    return mult(m[0],(mult(m[4],m[8])^mult(m[5],m[7])))^mult(m[1],(mult(m[3],m[8])^mult(m[5],m[6])))^mult(m[2],(mult(m[3],m[7])^mult(m[4],m[6])))


print(fif())

'''for i in range(15):
    for j in range(15):
        for k in range(15):
            if mult(mult(i,j),k)==8 and mult(i,j)^mult(i,k)^mult(j,k)==3 and i^j^k==10:
                print(i,j,k)'''
                
'''for i in range(15):
    for j in range(15):
        if mult(i,j)==4 and i^j==14:
            print(i,j)'''