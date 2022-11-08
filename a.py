#1
multi=6  # 5~9까지

for i in range(2,10):#2~9까지의 범위 출력
    k=i*multi
    k=list(str(k))
    k.insert(1,i)
    for j in range(3):
        print(k[j],end="")
    print()


