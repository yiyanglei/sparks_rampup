def add_binary(x, y):
    ret = int(x) + int(y)
    m = str(ret)[::-1]
    res = list()
    z = 0
    for i in m:
        i = int(i) + z
        if i == 2:
            res.append(0)
            z = 1
        elif i == 3:
            res.append(1)
            z = 1
        else:
            res.append(i)
            z = 0
    if z:
        res.append(z)
    n = ""
    for j in res:
        n += str(j)
    return n[::-1]
a = "1011"
b = "0111"
result = add_binary(a, b)
print(f"0b{a}+0b{b}=0b{result}")
