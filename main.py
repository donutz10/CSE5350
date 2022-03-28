import math




def fxn(x):
    return x**2-2

def secant(p0,p1,tol,n0):
    i = 2
    q0 = fxn(p0)
    q1 = fxn(p1)
    while (i <= n0):
        p = p1 - q1*(p1-p0)/(q1-q0)
        if(abs(p-p1) < tol):
            print("method was successful, root: ", p)
            break;
        i+=1
        q=fxn(p)
        if(q*q1 < 0):
            p0 = p1
            q0 = q1
        p1 = p
        q1 = q
        if(abs(p-p1)>tol):
            print("Method failed at N iterations, N:.", i)
            break;
        

secant(1,2,0.0001,10)