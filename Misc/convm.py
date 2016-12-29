a=[[1,2,3,4,5],[1,2,3,4,5],[1,2,3,4,5]]
b=[[1,2,3,4],[3,4,5,5]]

def convMatrix(a, b, mode='full'):
    if mode == 'full':
        row=len(a)+len(b) - 1
        col=len(a[0])+len(b[0]) - 1
        c= [[0 for i in range(col)] for i in range(row)]
        for i in range(len(a)):
            for j in range(len(a[0])):
                for m in range(len(b)):
                    for n in range(len(b[0])):
                        c[i+m][j+n] += a[i][j] * b[m][n]
        return c
        
    if mode == 'same':
        row=len(a)
        col=len(a[0])
        c= [[0 for i in range(col)] for i in range(row)]
        for i in range(len(a)):
            for j in range(len(a[0])):
                for m in range(len(b)):
                    for n in range(len(b[0])):
                        if (0 <= i+m-len(b)/2 < row and 0 <= j+n-len(b[0])/2 < col):
                            c[i+m-len(b)/2][j+n-len(b[0])/2] += a[i][j] * b[m][n]
        return c
        
    if mode == 'valid':
        row=len(a)-len(b) + 1
        col=len(a[0])-len(b[0]) + 1
        c= [[0 for i in range(col)] for i in range(row)]
        for i in range(len(a)):
            for j in range(len(a[0])):
                for m in range(len(b)):
                    for n in range(len(b[0])):
                        r = i-len(b)+m+1
                        co = j+n-len(b[0])+1
                        if (0 <= r < row and 0 <= co < col):
                            c[r][co] += a[i][j] * b[m][n]
        return c

def convArray(a, b, mode='full'):
    if mode == 'full':
        c=[0 for i in range(len(a) + len(b) - 1)]
        for i, value in enumerate(a):
            for j, key in enumerate(b):
                c[i+j] += a[i] * b[j]
        return c
        
    if mode == 'same':
        c=[0 for i in range(len(a))]
        for i, value in enumerate(a):
            for j, key in enumerate(b):
                if (i+j-len(b)/2>=0 and i+j-len(b)/2<len(a)):
                    c[i+j-len(b)/2] += a[i] * b[j]
        return c
        
    if mode == 'valid':
        c=[0 for i in range(len(a) - len(b)+1)]
        for i, value in enumerate(a):
            for j, key in enumerate(b):
                if (i+j-len(b)+1>=0 and i+j-len(b)+1 < len(c)):
                    c[i+j-len(b)+1] += a[i] * b[j]
        return c
    
print convArray(a[0], b[0],'full')
print convArray(a[0], b[0],'same')
print convArray(a[0], b[0],'valid')
print convMatrix(a, b,'full')
print convMatrix(a, b,'same')
print convMatrix(a, b,'valid')