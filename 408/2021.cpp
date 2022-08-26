#include <bits/stdc++.h>

using namespace std;

//

typedef struct {
    int numVertices, numEdges;
    char VerticesList[100];
    int Edge[100][100];
} MGraph;

class Solution {
public:
    int IsExistEL(MGraph G) {
        int ans = 0;
        for (int i = 0; i < G.numVertices; i++) {
            int cnt = 0;
            for (int j = 0; j < G.numVertices; j++)
                if (G.Edge[i][j] != 0)
                    cnt++;
            if (cnt % 2 == 1)
                ans++;
        }
        if (ans == 0 || ans == 2)
            return 1;
        return 0;
    }
};
