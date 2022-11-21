def membership():
    print("아이디와 비밀번호를 등록하세요.")
    inid=input("아이디 : ")
    inpwd=input("비밀번호 : ")

    with open("./login.txt","a") as f:
        num=0
        f.writelines(inid+" "+inpwd+"\n")

def login():
    inid=input("아이디 입력 : ")
    inpwd=input("비밀번호 입력 : ")
    result = 0
    with open("./login.txt","r") as f:
        
        lines=f.readlines()
        for data in lines:
            data = data.rstrip("\n")
            items=data.split()
            if items[0]==inid and items[1]==inpwd:
                print("안녕하세요.")
                result=1
                break
    if result==0:
        print("아이디와 비밀번호를 확인하세요")

def chpwd():
    inid=input("아이디 입력 : ")
    inpwd=input("비밀번호 입력 : ")
    ppwd=input("변경할 비밀번호 입력 : ")
    b=inid+" "+inpwd
    with open("./login.txt","r") as f:
        lines=f.readlines()
    with open("./login.txt", "w") as f:
        for line in lines:
            if line.strip("\n") != b:  
                f.write(line)
    with open("./login.txt","a") as f:
        f.writelines("\n"+inid+" "+ppwd+"\n")



print("1.회원가입 2.로그인")
x=int(input("숫자를 입력하세요"))
if x==1:
    membership()
elif x==2:
    login()
    print("1.비밀번호 변경 2.종료")
    k=int(input("숫자를 입력하세요"))
    if k==1:
        chpwd()
    else:
        exit()
