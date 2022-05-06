from setop import set

def createset():
    n=int(input("Enter total no. of elements "))
    s1=set(n)
    return s1

print("Creating Set1....")
s1=createset()
print("set1:- ")
print(s1.s)


print("Creating Set2....")
s2=createset()
print("set2:- ")
print(s2.s)


while True:
    print("\n\n1.add")
    print("2.remove")
    print("3.contain")
    print("4.size")
    print("5.intersection")
    print("6.union")
    print("7.diff")
    print("8.All possible Subsets of the set")
    print("0.Exit")
    ch=int(input("Enter Choice :- "))
    if(ch==1):
        ele=int(input("Enter Element :- "))
        s1.add(ele)
        print("Set :- ",s1.s)
    elif(ch==2):
        ele=int(input("Enter Element :- "))
        s1.delete(ele)
        print("Set :- ",s1.s)
    elif(ch==3):
        ele=int(input("Enter Element :- "))
        if ele in s1.s:
            print("Element is preset in set ")
        else:
            print("Element is not present in set ")
    elif(ch==4):
        print("The size of the set is ",len(s1.s))
    elif(ch==5):
        s3=s1.intersect(s2)
        print("Intersection :- ",s3)
    elif(ch==6):
        s3=s1.union(s2)
        print("union :- ",s3)
    elif(ch==7):
        print("s1-s2:- ", s1.diff(s2))
        print("s2-s1:- ", s2.diff(s1))
    elif(ch==8):
        s2=s1.subset()
        print("All the Subsets of the set are :- ")
        for i in s2:
            print(i)
    elif(ch==0):
        break
    else:
        print("Wrong Choice ")
    