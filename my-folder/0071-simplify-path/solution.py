class Solution:
    def simplifyPath(self, path: str) -> str:
        stack = []
        s = ""
        
        for i in path + "/":
            if i == "/":
                if s == "..":
                    if stack:
                        stack.pop()
                elif s != "" and s != ".":
                    stack.append(s);
                s = ""
            else:
                s+=i
        return "/"+"/".join(stack);
