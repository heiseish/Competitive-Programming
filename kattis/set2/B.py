from fractions import *
def gcd(a, b):
  if b == 0:
    return a
  else:
    return gcd(b, a%b)

def main():
  tc = int(input(''))
  for _ in range(tc):
    inp = raw_input()
    [x1, n1, x2, n2] = inp.split()
    n1 = int(n1)
    if n1 == 0:
      n1 = 1
      x1 += '0'
    l1 = len(x1)
    b1 = 10**(l1 + n1) - 10**l1
    x1 = int(x1)
    a1 = x1 * 10**n1 + x1 % (10**n1) - x1

    t1 = gcd(a1, b1)
    a1//=t1
    b1//=t1

    n2 = int(n2)
    if n2 == 0:
      n2 = 1
      x2 += '0'
    l2 = len(x2)

    b2 = 10**(l2 + n2) - 10**l2
    x2 = int(x2)
    a2 = x2 * 10**n2 + x2 % (10**n2) - x2
    t2 = gcd(a2, b2)
    a2//=t2
    b2//=t2

    num = a1 * b2 + a2 * b1
    denom = b1 * b2
    t = gcd(num, denom)
    num//=t
    denom//=t

    print('{}/{}'.format(num, denom))

main()
