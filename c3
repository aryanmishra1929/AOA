def restoring_division(dividend, divisor):
    A = 0
    Q = dividend
    M = divisor

    n = len(bin(dividend)) - 2

    print(f"Initial: A = {A}, Q = {Q}")

    for i in range(n):
        A = (A << 1) | (Q >> (n - 1))
        Q = (Q << 1) & ((1 << n) - 1)
        
        A = A - M
        
        if A < 0:
            A = A + M
            Q = Q & ~1
            print("Restore")
        else:
            Q = Q | 1
            print("No restore")
            
        print("A =", bin(A)[2:], "Q =", bin(Q)[2:])

    print(f"\nQuotient = {Q}")
    print(f"Remainder = {A}")

restoring_division(int(input("Enter dividend")), int(input("Enter divisor")))
