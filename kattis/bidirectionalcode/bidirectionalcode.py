
def get_num(is_odd, cur):
    if not is_odd:
        return int(cur + cur[::-1])
    return int(cur + cur[::-1][1:])

def modify_cur(s):
    rs = s[::-1]
    for idx, ch in enumerate(rs):
        if int(ch) == 0: continue
        return (rs[:idx] + str(int(ch) - 1) + rs[idx + 1:])[::-1]

def solve(n, res):
    if n < 10:
        res.append(n)
        return 0
    # if n == 109:
    #     res.append(101)
    #     res.append(8)
    #     return 0
    ns = str(n)
    m = len(ns)
    m //= 2
    is_odd = False
    if len(ns) % 2 == 1:
        m += 1
        is_odd = True

    cur = ns[:m]
    if get_num(is_odd, cur) <= n:
        res.append(get_num(is_odd, cur))
        return n - get_num(is_odd, cur)

    while get_num(is_odd, cur) > n:
        # print(cur)
        cur = modify_cur(cur)
        # print('after modify', cur)
        if int(cur) == 0: break
        res.append(get_num(is_odd, cur))
        return n - get_num(is_odd, cur)

    num = int('9' * (len(str(n))  - 1))
    res.append(num)
    return n - num

if __name__ == '__main__':
    res = []
    n = int(input())

    cnt = 11
    while True:
        if cnt == 0: raise ValueError(str(res))
        n = solve(n, res)
        # print(n)
        cnt -= 1
        if n == 0: break

    print(len(res))
    for a in res:
        print(a)
