data = input()
data = input().split()
num = list()
for i in data:
  s = sum([int(j) for j in i])
  if s not in num:
    num.append(s)
   
print(len(num))
num.sort()
print(num[0], end='')
for each in num[1:]:
  print(" %d" % each, end='')
