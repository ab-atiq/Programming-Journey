# https://codeforces.com/group/MWSDmqGsZm/contest/219774/problem/P
sz = int(input())
num_lst = [int(x) for x in input().split()]

cnt = 0
flag = True
while flag:
    total_num_div = 0
    for i, n in enumerate(num_lst):
        # pass
        if n%2==0:
            total_num_div+=1
            num_lst[i]=n/2
        else:
            break
    if total_num_div == sz:
        cnt += 1
    else:
        flag = False
        
print(cnt)

# give me solution without - for i, n in enumerate(num_lst):
sz = int(input())
num_lst = [int(x) for x in input().split()]

cnt = 0
flag = True
while flag:
    total_num_div = 0
    i = 0
    while i < sz:
        n = num_lst[i]
        # pass
        if n%2==0:
            total_num_div+=1
            num_lst[i]=n/2
        else:
            break
        i += 1
    if total_num_div == sz:
        cnt += 1
    else:
        flag = False
        
print(cnt)


# optimized solution
n = int(input())
arr = list(map(int,input().split()))

operation = 0
flag = True
while flag:
    num_of_div = 0
    for i in range(0,n):
        if arr[i] % 2 == 0:
            arr[i] = arr[i] / 2 
            num_of_div = num_of_div + 1
        else:
            break
    if num_of_div == n:
        operation += 1
    else:
        flag = False

print(operation)