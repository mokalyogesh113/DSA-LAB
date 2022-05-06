class set:
    
    def __init__(self, n):
        self.s=[]
        for i in range(n):
            e=int(input("Enter Element :- "))
            if e not in self.s:
                self.s.append(e)
    
    def add(self,e):
        if e not in self.s:
                self.s.append(e)
                
    def delete(self,e):
        if e in self.s:
            self.s.remove(e);
    
    def intersect(self,s2):
        res=[]
        for i in self.s:
            if i in s2.s:
                res.append(i)
        return res
    
    def union(self,s2):
        res=[]
        for i in self.s:
            res.append(i)
        for i in s2.s:
            if i not in self.s:
                res.append(i)
        return res
    
    def diff(self,s2):
        res=[]
        for i in self.s:
            if i not in s2.s:
                res.append(i)
        return res
    
    def subset(self):
        res=[]
        res.append("phi")
        n=2**len(self.s)
        for i in range(n):
            j=i
            s2=[]
            cnt=0
            while (j>0):
                if(j%2==1):
                    s2.append(self.s[cnt])
                j=j>>1
                cnt=(cnt+1)%len(self.s)
            res.append(s2)
        return res
        
        