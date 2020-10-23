import numpy as np

def MERAlg1(S, A):

    _ = 42
    x_points = np.array(S[0, :])
    x_points = np.append(x_points, [A[0], A[1]])
    x_1_best, x_2_best = MGAP(x_points)
    y_1_best, y_2_best = A[2], A[3]
    maxr = (A[3] - A[2])*(x_2_best - x_1_best)

    S = S[:,(-S[1,:]).argsort()][:len(S[0,:])]

    for i in range(0, len(x_points) - 2):

        t_l = A[0]
        t_r = A[1]

        for j in range(i + 1, len(x_points) - 2):

            if (t_l < S[0,j] < t_r):

                s_area = (t_r - t_l) * (S[1,i] - S[1,j])

                if s_area > maxr:

                    x_1_best, x_2_best = t_l, t_r
                    y_1_best, y_2_best = S[1,i], S[1,j]

                    maxr = s_area

                if (S[0, j] > S[0, i]):

                    t_r = S[0, j]

                else:

                    t_l = S[0, j]

        s_area = (t_r - t_l) * (S[1, i] - A[2])

        if s_area > maxr:

            x_1_best, x_2_best = t_l, t_r
            y_1_best, y_2_best = A[2], S[1, i]

            maxr = s_area

    for i in range(0, len(x_points) - 2):

        points = []

        for j in range(0, len(x_points) - 2):

            if (S[1,j] > S[1,i]) and (S[0,j] > S[0, i]):

                points.append((S[0,j]))

        points.append(A[1])

        r = min(points)

        points = []

        for j in range(0, len(x_points) - 2):

            if (S[1, j] > S[1, i]) and (S[0, j] < S[0, i]):

                points.append((S[0, j]))

        points.append(A[0])

        l = max(points)

        s_area = (r - l) * (A[3] - S[1,i])

        if s_area > maxr:
            x_1_best, x_2_best = r, l
            y_1_best, y_2_best = A[3], S[1, i]

            maxr = s_area   

    return (x_1_best, x_2_best, y_1_best, y_2_best, maxr)

def MGAP(P):

    P.sort()
    mgap = 0
    f_p, s_p = 0, 0

    for i in range(1, len(P)):

        if (abs(P[i - 1] - P[i]) > mgap):

            f_p = P[i - 1]
            s_p = P[i]
            mgap = abs(f_p - s_p)


    return (f_p, s_p)


S = [[1,1,2,2,3,6,6,4,4,6,6],[1,5,2,4,5,1,5,1,5,3,4]]
A = [0,7,0,6]       

print(MERAlg1(np.array(S), np.array(A)))

