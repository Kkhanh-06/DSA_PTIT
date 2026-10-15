string = input()
ar_num = []
s = 1
for i in range(len(string)-1):
    if string[i] == string[i + 1]:
        s += 1
    else:
        ar_num.append(s)
        s = 1
ar_num.append(s)

print(max(ar_num))
