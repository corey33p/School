# computes the gcd of two numbers by means of Euclid's algorithm
def gcd(a,b,to_print=False):
    if a == 0 and b == 0: return 0
    elif a == 0: return b
    elif b == 0: return a
    if not (a >= b):
        b,a=a,b
    r=[a,b]
    going = True
    while going: 
        r.append(r[len(r)-2]%r[len(r)-1])
        x1=r[len(r)-3]
        x2=r[len(r)-2]
        x3=r[len(r)-1]
        c=x1//x2
        if to_print: print(str(x1) + " = " + str(c) + "*" + str(x2) + " + " + str(x3))
        going = (x1%x2) != 0
    if to_print: print("gcd("+str(a)+","+str(b)+')='+str(x2))
    return x2

# determines whether a number is prime
def isPrime(n):
    if n<2: return False
    for i in range(2,int(n**.5+1)):
        if n%i==0: return False
    return True

# finds the prime factorization of a number
def prime_factorization(a):
    if not (a%1==0): return
    prime_factors = []
    for i in range(int(a*.5)+1):
        if isPrime(i):
            while a%i == 0:
                prime_factors.append(i)
                a=int(a/i)
        if a == 1: return [1]+prime_factors
    if not prime_factors:
        return [1,a]

pf = prime_factorization

# finds the factorization of a number
def factorization(a):
    if a == 0: return set([0])
    if not (a%1==0): return
    factors = set()
    for i in range(1,int(a*.5)+1):
        modulo = a%i
        if modulo == 0:
            factors.add(i)
    if not factors:
        factors = list(set([1,a]))
    else:
        factors.add(a)
        factors = list(factors)
    factors.sort()
    return factors

f = factorization


# Euler's phi function. Finds the number of numbers less than a number 
# that are coprime with the number. IE, # of a<n such that gcd(a,n) = 1
def euler_phi(n):
    number_of_coprime=0
    for i in range(n):
        if gcd(i,n,False)==1: number_of_coprime +=1
    return number_of_coprime

phi=euler_phi

# finds the multiplicative inverse of a number n mod m
def modular_inverse(n,m):
    for i in range(1,m+1):
        product = n*i
        if product % m == 1:
            return i
    print("no solution")

mi = modular_inverse

# prints a table of the phi function values
def phi_seq(n=-1):
    i = 1
    while True:
        input("phi("+str(i)+"): " + str(phi(i)))
        i+=1
        if n!=-1:
            if i == n: return

# creates a list of numbers less than n 
# relatively prime to n
def relative_primes(n):
    list_of_rps=[]
    for i in range(n):
        if gcd(i,n,False)==1:
            list_of_rps.append(i)
    return list_of_rps

rps = relative_primes

# prints a table of the sum of the numbers less than n 
# that are relatively prime to n
def rp_seq(n):
    for i in range(n,printAll=True):
        if printAll: print("sum of relatively prime to ("+str(i)+"): " + str(rps(i)))
        else: input("sum of relatively prime to ("+str(i)+"): " + str(rps(i)))

# finds the order of a number a modulo n
# returns k where a^k ≡ 1 (mod n)
def modular_order(a,n,to_print=True):
    if a == n: 
        if to_print: return print("ord of " + str(a) + " (mod " + str(n)+") is: 0")
        else: return 0
    for i in range(1,n):
        if a**i % n == 1:
            if to_print: return print("ord of " + str(a) + " (mod " + str(n)+") is: "+ str(i))
            else: return i

ord = modular_order

# a is a primitive root of n if when you take powers, 
# a^k such that k>1 and k<n, the number of unique 
# answers you get (mod n) is equal to phi(n). that is, 
# there is a unique value modulo n for each coprime < n
def find_primitive_root(n,to_print=True):
    r = 2
    found = False
    while not found:
        residues = set()
        for i in range(0,n):
            x = r**i%n
            residues.add(x)
            if len(residues)== phi(n): 
                if to_print: return print(str(r) +" is a primitive root of "+str(n))
                else: return r
        r+=1

pr = find_primitive_root

# determines if a is a primitive root of n
def is_primitive_root(a,n):
    return modular_order(a,n,False)==n-1

ipr = is_primitive_root

# determines if n is a quadratic residue mod m
# that is, there exists a k such that 
# n^k is congruent to 1 mod m
def quadratic_residue(n,m):
    for i in range(int(m/2)+2):
        if (i**2 % m) == n: return True
    return False

qr = quadratic_residue

# returns 1 if a is a quadratic residue mod b
# returns -1 if a is a quadratic nonresidue mod b
# returns 0 if a divides b
def legendre(a,b):
    while a <= 0: a+=b
    if a == 1: return 1
    if b%a==0: return 0
    if quadratic_residue(a,b): return 1
    else: return -1

def sum_of_squares(num):
    debug = False
    max = int(num**.5)
    max_number_of_components = 6
    squares = [(i+1)**2 for i in range(max)]
    squares.reverse()
    solutions = set()
    for i, starting_square in enumerate(squares):
        current_sum = starting_square
        current_components = [int(starting_square**.5)]
        number_of_components = 1
        working_squares = squares[i:]
        over_limit = False
        if current_sum == num: solutions.add(tuple(current_components))
        for square in working_squares:
            while ((current_sum + square) <= num) and not over_limit:
                current_sum += square
                if debug: print("current_sum: " + str(current_sum))
                current_components.append(int(square**.5))
                if debug: print("current_components: " + str(current_components))
                number_of_components += 1
                if (number_of_components >= max_number_of_components): over_limit = True
                if current_sum == num: solutions.add(tuple(current_components))
    if solutions: 
        solutions = list(solutions)
        solutions.sort(key=len)
        for solution in solutions: print(solution)
    else: print("No solutions found.")

ss = sum_of_squares

# evaluates a continued fraction from the notation [a,b,c,...,n]
# where the result is a+a/(b+1/(c+1/...+(1/n)...))
def cf_fromlist(theList,num=None,den=None,_print=True):
    if theList == []:
        print(str(den) + " / " + str(num))
        return den, num
    else:
        last_in_list = theList.pop(len(theList)-1)
        if (num is None) and (den is None):
            num = 1
            den = last_in_list
        else:
            num = den * last_in_list + num
            num, den = den, num
        den,num = cf_fromlist(theList,num,den,_print)
        return den,num

cf = cf_fromlist

# takes a rational number and returns the continued fraction representation
# in the form [a,b,c,...,n] explained above
def rn_to_cf(num,den):
    theList = []
    while den != 0:
        theList.append(num//den)
        oldDen = den
        den = num % den
        num = oldDen
    return theList

rn = rn_to_cf

