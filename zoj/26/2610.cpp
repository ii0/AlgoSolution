#include <cstdio>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

typedef vector<string> Triangle;

Triangle rotate(const Triangle& tri) {
    int n = tri.size();
    Triangle ret = vector<string>(n);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < i; ++j) {
            ret[i] += tri[n - 1 - j][2 * (i - j)];
            ret[i] += tri[n - 1 - j][2 * (i - j) - 1];
        }
        ret[i] += tri[n - 1 - i][0];
    }
    return ret;
}

bool ok(const Triangle& tri) {
    bool lr = true, rl = true;
    for (vector<string>::const_iterator i = tri.begin(); i != tri.end(); ++i) {
        lr &= count(find(i->begin(), i->end(), '1'), i->end(), '0') == 0;
        rl &= count(find(i->begin(), i->end(), '0'), i->end(), '1') == 0;
    }
    return lr || rl;
}

int main() {
    int ri = 0, n;
    char buf[1024];
    Triangle tri;

    while (scanf("%d", &n) != EOF && n > 0) {
        tri.clear();
        for (int i = 0; i < n; ++i) {
            scanf("%s", buf);
            tri.push_back(buf);
        }
        printf("Puzzle %d\n", ++ri);
        printf("Parts can%s be separated\n", ok(tri) || ok(rotate(tri)) || ok(rotate(rotate(tri))) ? "" : "not");
    }

    return 0;
}

//Run ID    Submit Time     Judge Status    Problem ID      Language    Run Time(ms)    Run Memory(KB)      User Name
//2176335   2010-04-25 13:30:43     Accepted    2610    C++     40  176     watashi@Zodiac

// 2012-09-07 01:32:06 | Accepted | 2610 | C++ | 40 | 180 | watashi | Source
