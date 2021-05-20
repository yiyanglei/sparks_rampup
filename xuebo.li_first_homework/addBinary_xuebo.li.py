def add_binary(x, y):
    ret = int(x, 2) + int(y, 2)
    ret = bin(ret)
    return ret
a = "1011"
b = "0111"
result = add_binary(a, b)
print(f"0b{a}+0b{b}={result}")
