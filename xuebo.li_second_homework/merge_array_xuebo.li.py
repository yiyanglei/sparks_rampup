num1 = [1, 2, 2, 4, 7, 9]
num2 = [3, 5, 8]
idx1 = 0
idx2 = 0
length1 = len(num1)
length2 = len(num2)
while idx1 < len(num1) and idx2 < length2:
    if num2[idx2] >= num1[idx1]:
        idx1 += 1
    else:
        num1.insert(idx1, num2[idx2])
        idx1 += 1
        idx2 += 1
while idx2 < length2:
    if num2[idx2] >= num1[len(num1)-1]:
        num1.append(num2[idx2])
        idx2 += 1
print(num1)
