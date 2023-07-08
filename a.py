import sys
input=sys.stdin.readline
while True:
    s=input().rstrip()
    if s==".":
        break
    else:
        d=[]
        for i in s:
            if i=="(":
                d.append(i)
            elif i=="[":
                d.append(i)
            elif i==")":
                if len(d)==0:
                    d.append(i)
                elif d[-1]=="(" and len(d)!=0:
                    del d[-1]
            elif i=="]":
                if len(d)==0:
                    d.append(i)
                elif d[-1]=="["and len(d)!=0:
                    del d[-1]

        if len(d)==0:
            print("yes")
        else:
            print("no")

