string1='역삼역'
string2=''
reverse_string=''
string1=string1.lower()
for i in string1:
    if i.isalpha()==1:
        string2+=i
print(string2)

for i in string1:
    reverse_string=i+reverse_string
    
if string2==reverse_string:
    print("true")
else:
    print("false")
