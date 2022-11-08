#4
alpha= [["A","B","C","D","E"],
        ["F","G","H","I","J"],
        ["K","L","M","N","O"],
        ["P","Q","R","S","T"],
        ["U","V","W","X","Y"]]

#노란색 버튼=1 빨간색 버튼=0
num=   [[1,1,0,1,1],
        [1,0,0,0,0],
        [0,1,1,1,1],
        [1,1,0,1,0],
        [0,1,0,1,1]]
#누른 버튼에 해당하는 알파벳을 담을 리스트
alphalist=[]
while(1):
    #alpha와 num 리스트 전체 출력
    for i in range(5):
        for j in range(5):
            print(alpha[i][j],end=" ")
        print()
    print("==========")
    for i in range(5):
        for j in range(5):
            print(num[i][j],end=" ")
        print()
    print()
    #누를 버튼 입력
    button=input()
    # "-1"입력하면 종료
    if button=="-1":
        break
    # 버튼에 해당하는 좌표 값 찾아내기
    for i in range(5):
        for j in range(5):
            if alpha[i][j]==button:
                m=i
                n=j
                break
    alphalist.append(button)
    #빨간색 버튼을 누른 경우
    #상하좌우 바꿔주기
    if num[m][n]==0:
        if num[m-1][n]==1:
            num[m-1][n]=0
        else:
            num[m-1][n]=1

        if num[m+1][n]==1:
            num[m+1][n]=0
        else:
            num[m+1][n]=1

        if num[m][n+1]==1:
            num[m][n+1]=0
        else:
            num[m][n+1]=1

        if num[m][n-1]==1:
            num[m][n-1]=0
        else:
            num[m][n-1]=1
    # 노란색 버튼을 누른 경우
    # 대각선 바꿔주기
    elif num[m][n]==1:

        if num[m-1][n-1]==1:
            num[m-1][n-1]=0
        else:
            num[m-1][n-1]=1
        
        if num[m-1][n+1]==1:
            num[m-1][n+1]=0
        else:
            num[m-1][n+1]=1

        if num[m+1][n-1]==1:
            num[m+1][n-1]=0
        else:
            num[m+1][n-1]=1

        if num[m+1][n+1]==1:
            num[m+1][n+1]=0
        else:
            num[m+1][n+1]=1



print("누른 알파벳 : ", alphalist)
print("버튼 누른 횟수: ", len(alphalist))