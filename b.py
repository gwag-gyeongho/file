tri=[]
ans=0
for _ in range(3):
    abc=list(map(int,input().split()))
    tri.append(abc)
a=tri[0][0]*tri[1][1]+tri[1][0]*tri[2][1]+tri[2][0]*tri[0][1]
b=tri[0][1]*tri[1][0]+tri[1][1]*tri[2][0]+tri[2][1]*tri[0][0]
ans = float(abs(a-b)/2)
print("{0:.2f}".format(ans))
