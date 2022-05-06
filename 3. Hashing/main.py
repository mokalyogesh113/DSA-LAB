HT=[[] for _ in range(10)]
print("Blank= ",HT)

def insert(HT,key,value):
    loc=key%10
    bucket=HT[loc]
    exist=False
    for i,kv in enumerate(bucket):
        k,v=kv
        if key==k:
            exist=True
            break
    if exist==True:
        bucket[i]=(key,value)
    else:
        bucket.append((key,value))
    
def delete(HT,key):
    loc=key%10
    bucket=HT[loc]
    exist=False
    for i,kv in enumerate(bucket):
        k,v=kv
        if(key==k):
            exist=True
            break
    if exist==True:
        del bucket[i]
    else:
        print("Element not Found to Delete")

def search(HT,key):
    loc=key%10
    bucket=HT[loc]
    exist=False
    for i,kv in enumerate(bucket):
        k,v=kv
        if(key==k):
            exist=True
            break
    if exist==True:
        print("Element Found i.e ",v)
    else:
        print("Element Not Found ")

def display(HT):
    for i,bucket in enumerate(HT):
        print("Bucket ",i," Elements:- ",bucket)

#=========Main Program===========#
while(True):
    print("\n1.Insert")
    print("2.Delete")
    print("3.Search key")
    print("4.Print Hash Table")
    print("0.Exit")
    ch=int(input("Enter Choice:- "))
    
    if(ch==1):
        key=int(input("Enter key:- "))
        value=input("Enter Value:- ")
        insert(HT,key,value)
    elif(ch==2):
        key=int(input("Enter the key:- "))
        delete(HT,key)
    elif(ch==3):
        key=int(input("Enter the key:- "))
        search(HT,key)
    elif(ch==4):
        display(HT)
    elif(ch==0):
        break
    else:
        print("Wrong Choice ")

