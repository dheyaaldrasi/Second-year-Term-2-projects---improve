data = {
    1: 'Admin',
    2: 'User',
    3: 'Guest',
    4: 'Superuser',
    5: 'Reader',
    6: 'Writer',
    7: 'Editor'
}

for k in data:
    print(f"key : {k}, value : {data[k]}")

data[8] = 'Author'

for k in data:
    print(f"key : {k}, value : {data[k]}")

data[3] = 'Visitor'

for k in data:
    print(f"key : {k}, value : {data[k]}")

print(data.get(5))

del data[5]

print(data.get(5))

print(2 in data)
print(5 in data)

print(len(data))

print(data.copy()) # ترجع نسخة من القاموس

data.clear() # تقوم بمسح جميع العناصر من القاموس

print(data)




del data



# for key, value in data.items():
#     print(f"Key: {key}, Value: {value}")

