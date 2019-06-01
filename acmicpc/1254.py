def check(s):
    if s == s[::-1]:
        return True
    return False
def run(s):
    for i in range(len(s)):
        if check(s[i:]):
            return len(s)+i
    return len(s)*2
print(run(input()))
