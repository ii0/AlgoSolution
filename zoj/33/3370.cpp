#include <algorithm> // auto fix CE
#include <cmath>
#include <algorithm> // auto fix CE
#include <cstdio>

const double EPS = 5e-7;
const int MAXN = 1234;

struct DisjointSet {
    int p[MAXN];

    void init(int n) {
        for (int i = 1; i <= n; ++i) {
            p[i] = i;
        }
    }

    int root(int i) {
        if (i > 0) {
            return i == p[i] ? i : (p[i] = root(p[i]));
        } else {
            return -i == p[-i] ? i : -(p[-i] = root(p[-i]));
        }
    }

    int _is(int i, int j, bool t) {
        if (i < 0) {
            i = -i;
            t = !t;
        }
        if (j < 0) {
            j = -j;
            t = !t;
        }
        if (t) {
            if (i == j) {
                return 0;
            }
            p[j] = i;
        } else {
            if (i == j) {
                return -1;
            }
            p[j] = -i;
        }
        return 0;
    }

    int istrue(int i, int j) {
        return _is(root(i), root(j), true);
    }

    int isfalse(int i, int j) {
        return _is(root(i), root(j), false);
    }
} ds;

double d[MAXN][MAXN];

int main() {
    int n, x[MAXN], y[MAXN];
    double l, r, m;
    bool flag;

    while (scanf("%d", &n) != EOF) {
        for (int i = 1; i <= n; ++i) {
            scanf("%d%d", &x[i], &y[i]);
            for (int j = 1; j < i; ++j) {
                d[i][j] = hypot(y[i] - y[j], x[i] - x[j]);
            }
        }

        l = 0;
        r = 4e4;
        while (r - l > EPS) {
            m = (l + r) / 2;
            flag = true;
            ds.init(n);
            for (int i = 1; flag && i <= n; ++i) {
                for (int j = 1; flag && j < i; ++j) {
                    if (d[i][j] < m) {
                        flag &= ds.isfalse(i, j) != -1;
                    }
                }
            }
            if (flag) {
                l = m;
            } else {
                r = m;
            }
        }

        ds.init(n);
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j < i; ++j) {
                if (d[i][j] < l) {
                    ds.isfalse(i, j);
                }
            }
        }
        printf("%.10lf\n", l / 2);
        for (int i = 1; i <= n; ++i) {
            printf("%c%c", ds.root(i) > 0 ? '1' : '2', i == n ? '\n' : ' ');
        }
    }

    return 0;
}

//real  0m0.498s
//user  0m0.476s
//sys   0m0.012s

// Run ID   Submit Time     Judge Status    Problem ID      Language    Run Time(ms)    Run Memory(KB)      User Name   Admin
// 180  2010-07-08 14:42:37     Accepted    asc11i  C++     950     12080   watashi@Zodiac  Source

// 2012-09-07 15:49:41 | Accepted | 3370 | C++ | 880 | 12080 | watashi | Source
