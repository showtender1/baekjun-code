a,x,b,y=map(int,input().split())
U=[]

for i in range(a,b+1):
    u=[]
    U+=[u]

    for j in range(x,y+1):
        k=2*max(-i,i,-j,j)
        u+=[1+k*k+(-1)**(i<j)*(i+j+k)]

for z in U:
    print(*[f"%{len(str(max(U[0]+u)))}d"%i for i in z])
