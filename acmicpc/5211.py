A, C = 0, 0
s = input().split('|')
for i in s:
    if i[0] in ['A', 'D', 'E']:
        A += 1
    if i[0] in ['C', 'F', 'G']:
        C += 1
if A == C:
    if s[-1][-1] in ['A', 'D', 'E']:
        A += 1
    if s[-1][-1] in ['C', 'F', 'G']:
        C += 1
if A < C:
    print("C-major")
else:
    print("A-minor")
