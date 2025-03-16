import numpy as np

def secure_communication(T, M):
    """
    Perform secure message decoding using matrix inversion and compute RREF.

    Args:
        T (numpy.ndarray): Encoding matrix of size n x n.
        M (numpy.ndarray): Encoded message matrix.

    Returns:
        tuple: (C, RREF, rank, nullity)
    """

    inv = np.linalg.inv(T)
    C = np.dot(inv, M)

    rref = T.astype(float)  
    m, n = rref.shape
    lead = 0

    for r in range(m):
        if lead >= n:
            break
        if rref[r, lead] == 0:
            for i in range(r + 1, m):
                if rref[i, lead] != 0:
                    rref[[r, i]] = rref[[i, r]]  
                    break
        if rref[r, lead] != 0:
            rref[r] = rref[r] / rref[r, lead]  
        for i in range(m):
            if i != r:
                rref[i] = rref[i] - rref[i, lead] * rref[r]  
        lead += 1


    rank = np.linalg.matrix_rank(T)

   
    nullity = T.shape[1] - rank

    return C, rref, rank, nullity

def main():
    T, M = [], []

    # Read dimensions of T
    rows, cols = map(int, input().split())  
    for _ in range(rows):
        T.append(list(map(float, input().split())))

    # Read dimensions of M
    rows, cols = map(int, input().split())
    for _ in range(rows):
        M.append(list(map(float, input().split())))

    T = np.array(T)
    M = np.array(M)

    # Perform Secure Communication Processing
    C, RREF, rank, nullity = secure_communication(T, M)

    # Print results
    print("C =")
    for row in C:
        print(" ".join(f"{x:.1f}" for x in row))

    print("\nRREF =")
    for row in RREF:
        print(" ".join(f"{x:.1f}" for x in row))

    print("\nRank =", rank)
    print("Nullity =", nullity)

if __name__ == "__main__":
    main()
