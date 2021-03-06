#include <cassert>
#include <cctype>
#include <cmath>
#include <cstdarg>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <set>
#include <map>
#include <list>
#include <queue>
#include <stack>
#include <vector>
#include <string>
#include <utility>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <functional>
using namespace std;

#define ALL(c) (c).begin(), (c).end()
#define FOR(i, n) for (int i = 0; i < (int)(n); ++i)
#define FOREACH(i, n) for (typeof(n.begin()) i = n.begin(); i != n.end(); ++i)
#define MEMSET(p, c) memset(p, c, sizeof(p))
typedef long long llint;
typedef pair<int, int> PII;
/// BEGIN CUT HERE
#define WATASHI_PC

inline void errf(const char *fmt, ...) {
	va_list args;
	va_start(args, fmt);
	vfprintf(stderr, fmt, args);
	va_end(args);
}

template<typename T>
inline void errf(const char *fmt, const vector<T>& v) {
	errf("{");
	FOR(i, v.size()) {
		errf(fmt, v[i]);
	}
	errf("}\n");
}
// TODO
/// END CUT HERE
#ifndef WATASHI_PC
#define errf(fmt, ...) do { } while (false)
#endif

struct Incubator {
	int maxMagicalGirls(vector <string> love);
};

const int MAXN = 256;
const int MAXM = 32768;

struct Edge {
    int v, c, w;
    Edge() { }
    Edge(int v, int c, int w) : v(v), c(c), w(w) { }
};

struct NegativeCostCircuitExistsException {
};

template<int MAXX, int MAXY>
struct Hungary {
	int nx, ny, mx[MAXX], my[MAXY];
	vector<int> e[MAXX];

	bool mark[MAXX];

	void init(int nx, int ny) {
		this->nx = nx;
		this->ny = ny;
		for (int i = 0; i < nx; ++i) {
			e[i].clear();
		}
	}

	void add(int a, int b) {
		e[a].push_back(b);
	}

	bool augment(int i) {
		if (!mark[i]) {
			mark[i] = true;
			for (vector<int>::const_iterator j = e[i].begin(); j != e[i].end(); ++j) {
				if (my[*j] == -1 || augment(my[*j])) {
					mx[i] = *j;
					my[*j] = i;
					return true;
				}
			}
		}
		return false;
	}

	int gao() {
		int ret = 0;
		fill(mx, mx + nx, -1);
		fill(my, my + ny, -1);
		for (int i = 0; i < nx; ++i) {
			fill(mark, mark + nx, false);
			if (augment(i)) {
				++ret;
			}
		}
		return ret;
	}
};

Hungary<MAXN, MAXN> h;

bool w[MAXN][MAXN], id[MAXN];
int sz[MAXN];

int Incubator::maxMagicalGirls(vector <string> love) {
  int n = love.size();
  MEMSET(w, 0);
  FOR (i, n) {
    FOR (j, n) {
      w[i][j] = love[i][j] == 'Y';
    }
  }
  FOR (k, n) {
    FOR (i, n) {
      FOR (j, n) {
        w[i][j] = w[i][j] || (w[i][k] && w[k][j]);
      }
    }
  }

  int ans = 0;
  h.init(n, n);
  FOR (i, n) {
    if (!w[i][i]) {
      ++ans;
      FOR (j, n) {
        if (!w[j][j] && w[i][j]) {
          h.add(i, j);
        }
      }
    }
  }
  ans -= h.gao();

  puts("NEW");
  return ans;
}

/// BEGIN CUT HERE
// TODO
#define ARRSIZE(x) (sizeof(x)/sizeof(x[0]))

template<typename T>
ostream& operator<<(ostream& os, vector<T>& v) {
	os << "{";
	FOR(i, v.size()) {
		os << "\"" << v[i] << "\",";
	}
	os << "}";

	return os;
}

template<typename S, typename T>
void eq(int id, S v1, T v2) {
	ostringstream s1, s2;

	s1 << v1;
	s2 << v2;

	errf("Case #%d: ", id);
	if (s1.str() == s2.str()) {
		errf("\033[1;32mPassed\033[0m\n");
	} else {
		errf("\033[1;31mFailed\033[0m\n");
		errf("\tReceived \"%s\"\n", s1.str().c_str());
		errf("\tExpected \"%s\"\n", s2.str().c_str());
	}
}

int main(int argc, char *argv[]) {
	  {
        string loveARRAY[] = {"NYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYN","NNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNY","NNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNY","NNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNY","NNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNY","NNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNY","NNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNY","NNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNY","NNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNY","NNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNY","NNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNY","NNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNY","NNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNY","NNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNY","NNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNY","NNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNY","NNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNY","NNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNY","NNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNY","NNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNY","NNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNY","NNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNY","NNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNY","NNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNY","NNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNY","NNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNY","NNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNY","NNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNY","NNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNY","NNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNY","NNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNY","NNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNY","NNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNY","NNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNY","NNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNY","NNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNY","NNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNY","NNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNY","NNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNY","NNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNY","NNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNY","NNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNY","NNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNY","NNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNY","NNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNY","NNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNY","NNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNY","NNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNY","NNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNY","NNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNN"};
        vector <string> love( loveARRAY, loveARRAY+ARRSIZE(loveARRAY) );
        Incubator theObject;
        eq(9, theObject.maxMagicalGirls(love),48);
    }

    {
        string loveARRAY[] = {"NY","NN"};
        vector <string> love( loveARRAY, loveARRAY+ARRSIZE(loveARRAY) );
        Incubator theObject;
        eq(0, theObject.maxMagicalGirls(love),1);
    }
    {
        string loveARRAY[] = {"NYN", "NNY", "NNN"};
        vector <string> love( loveARRAY, loveARRAY+ARRSIZE(loveARRAY) );
        Incubator theObject;
        eq(1, theObject.maxMagicalGirls(love),1);
    }
    {
        string loveARRAY[] = {"NNYNN","NNYNN","NNNYY","NNNNN","NNNNN"};
        vector <string> love( loveARRAY, loveARRAY+ARRSIZE(loveARRAY) );
        Incubator theObject;
        eq(2, theObject.maxMagicalGirls(love),2);
    }
    {
        string loveARRAY[] = {"NNNNN","NYNNN","NYNYN","YNYNN","NNNNN"};
        vector <string> love( loveARRAY, loveARRAY+ARRSIZE(loveARRAY) );
        Incubator theObject;
        eq(3, theObject.maxMagicalGirls(love),2);
    }
    {
        string loveARRAY[] = {"NNNNN","NNNNN","NNNNN","NNNNN","NNNNN"};
        vector <string> love( loveARRAY, loveARRAY+ARRSIZE(loveARRAY) );
        Incubator theObject;
        eq(4, theObject.maxMagicalGirls(love),5);
    }
    {
        string loveARRAY[] = {"NNYNNNNN","NNNYNNNN","NNNNYNNN","NNYNNNNN","NNNNNYYN","NNNYNNNY","NNNNNNNN","NNNNNNNN"};
        vector <string> love( loveARRAY, loveARRAY+ARRSIZE(loveARRAY) );
        Incubator theObject;
        eq(5, theObject.maxMagicalGirls(love),2);
    }
    {
        string loveARRAY[] = {"Y"};
        vector <string> love( loveARRAY, loveARRAY+ARRSIZE(loveARRAY) );
        Incubator theObject;
        eq(6, theObject.maxMagicalGirls(love),0);
    }

	puts("\033[1;33mPress any key to continue...\033[0m");
	getchar();

	return 0;
}

/*
 * __builtin_popcount __builtin_ctz make_pair
 * priority_queue
 * push_back
 * first second iterator const_iterator
 */
/*
 * vim: ft=cpp.doxygen nowrap
 */
/// END CUT HERE

