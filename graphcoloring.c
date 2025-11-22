#include <stdio.h>
#include <string.h>

#define MAX 20

typedef struct {
    char name[10];
    int start, end;
    int reg;   // assigned register
} Variable;

int interfere(Variable a, Variable b) {
    // Overlap if ranges intersect
    if (a.end < b.start || b.end < a.start)
        return 0;  // no overlap
    return 1;      // interference
}

int main() {
    int n, k, i, j;

    Variable v[MAX];
    int graph[MAX][MAX] = {0};

    printf("Enter number of variables: ");
    scanf("%d", &n);

    printf("Enter variable name and live range (start end):\n");
    for (i = 0; i < n; i++) {
        scanf("%s %d %d", v[i].name, &v[i].start, &v[i].end);
        v[i].reg = -1;  // unassigned
    }

    printf("Enter number of available registers: ");
    scanf("%d", &k);

    // Build interference graph
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            if (i != j)
                graph[i][j] = interfere(v[i], v[j]);
        }
    }

    // Print interference graph
    printf("\nInterference Graph (Adjacency Matrix):\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++)
            printf("%d ", graph[i][j]);
        printf("\n");
    }

    // Graph Coloring (simple greedy)
    for (i = 0; i < n; i++) {
        int used[MAX] = {0};

        // Mark registers used by neighbors
        for (j = 0; j < n; j++) {
            if (graph[i][j] == 1 && v[j].reg != -1)
                used[v[j].reg] = 1;
        }

        // Find available register
        int found = 0;
        for (int r = 0; r < k; r++) {
            if (!used[r]) {
                v[i].reg = r;
                found = 1;
                break;
            }
        }

        if (!found)
            v[i].reg = -2; // spilled
    }

    // Print register allocation
    printf("\nRegister Allocation Result:\n");
    for (i = 0; i < n; i++) {
        if (v[i].reg >= 0)
            printf("%s -> R%d\n", v[i].name, v[i].reg);
        else
            printf("%s -> SPILLED\n", v[i].name);
    }

    return 0;
}
