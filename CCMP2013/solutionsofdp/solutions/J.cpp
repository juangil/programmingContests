#include <cstdio>
#include <cstdlib>
#include <vector>
#include <set>
using namespace std;

struct Node {
    int value;
    char op;
    char used;
    int left;
    int right;
};

vector<Node> nodes;

Node join(int a, int b, char op) {
    Node node;
    node.op = op;
    node.used = nodes[a].used | nodes[b].used;
    node.left = a;
    node.right = b;

    a = nodes[a].value;
    b = nodes[b].value;
    switch (op) {
        case '+':
            node.value = a + b;
            break;
        case '-':
            node.value = a - b;
            if (node.value < 1)
                node.value = -1;
            break;
        case '/':
            if (a%b != 0)
                node.value = -1;
            else
                node.value = a / b;
            break;
        case '*':
            node.value = a * b;
            break;
    }
    return node;
}

inline bool valid(const Node &a, const Node &b) {
    return !(a.used & b.used);
}

void print_result(int n) {
    if (nodes[n].left == -1) {
        printf(" %d ", nodes[n].value);
        return;
    } else {
        printf("(");
        print_result(nodes[n].left);
        printf(" %c ", nodes[n].op);
        print_result(nodes[n].right);
        printf(")");
    }
}

void print_result_bfs(int n) {
    multiset<int> values;
    vector<int> result;
    result.push_back(n);

    for (int i = 0; i < result.size(); ++i) {
        if (nodes[result[i]].left != -1)
            result.push_back( nodes[result[i]].left );
        if (nodes[result[i]].right != -1)
            result.push_back( nodes[result[i]].right );
        if (nodes[result[i]].op == '@')
            values.insert(nodes[result[i]].value);
    }

    for (int i = result.size()-1; i >= 0; --i) {
        if (nodes[result[i]].op == '@') {
            continue;
            //printf(" %d", nodes[result[i]].value);
        } else {
            int left = nodes[nodes[result[i]].left].value;
            int right = nodes[nodes[result[i]].right].value;
            printf("%d %c %d = %d\n", left, nodes[result[i]].op, right, nodes[result[i]].value);
        }
    }
}

int main(int argc, char *argv[]) {
    int ncases;
    if (scanf("%d", &ncases) != 1)
        return EXIT_FAILURE;
    for (int c = 0; c < ncases; ++c) {
    nodes.clear();
    set<pair<int,char> > found;
    Node n;
    int v[6];
    int goal;
    for (int i = 0; i < 6; ++i) {
        if (scanf("%d", &v[i]) != 1)
            return EXIT_SUCCESS;
        n.value = v[i];
        n.op = '@';
        n.left = -1;
        n.right = -1;
        n.used = 1<<i;
        nodes.push_back(n);
        found.insert(pair<int,char>(n.value, n.used));
    }
    if (scanf("%d", &goal) !=1)
        return EXIT_SUCCESS;

    for (int run = 0; run < 5; ++run) {
        //fprintf(stderr, "run: %d %lu\n", run, nodes.size());
        size_t size = nodes.size();
        for (size_t i = 0; i < size; ++i) {
            for (size_t j = i+1; j < size; ++j) {
                if (valid(nodes[i], nodes[j])) {
                    n = join(i, j, '+');
                    pair<int, char> p(n.value, n.used);
                    if (n.value != -1 && found.count(p) == 0) {
                        nodes.push_back(n);
                        found.insert(p);
                        if (n.value == goal) goto end;
                    }

                    n = join(i, j, '*');
                    p = pair<int,char>(n.value, n.used);
                    if (n.value != -1 && found.count(p) == 0) {
                        nodes.push_back(n);
                        found.insert(p);
                        if (n.value == goal) goto end;
                    }

                    if (nodes[i].value > nodes[j].value)
                        n = join(i, j, '-');
                    else
                        n = join(j, i, '-');
                    p = pair<int,char>(n.value, n.used);
                    if (n.value != -1 && found.count(p) == 0) {
                        nodes.push_back(n);
                        found.insert(p);
                        if (n.value == goal) goto end;
                    }

                    if (nodes[i].value > nodes[j].value)
                        n = join(i, j, '/');
                    else
                        n = join(j, i, '/');
                    p = pair<int,char>(n.value, n.used);
                    if (n.value != -1 && found.count(p) == 0) {
                        nodes.push_back(n);
                        found.insert(p);
                        if (n.value == goal) goto end;
                    }
                }
            }
        }
        if (nodes.size() == size)
            break;
    }

    end:

    int best = 0;
    int best_dif = abs(nodes[0].value - goal);
    for (size_t i = 1; i < nodes.size(); ++i) {
        int dif = abs(nodes[i].value - goal);
        if (dif < best_dif) {
            best_dif = dif;
            best = i;
        }
    }

    printf("Target: %d\n", goal);
    //print_result(best);
    print_result_bfs(best);
    printf("Best approx: %d\n", nodes[best].value);
    printf("\n");
    }

    return EXIT_SUCCESS;
}
