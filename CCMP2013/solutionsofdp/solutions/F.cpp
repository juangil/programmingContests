#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <cstring>
using namespace std;

#define DEBUG false

struct Point {
    int y;
    int oy; // number of obstacles to the left of y,x
    int x;
    int ox; // number of obstacles above y,x
    char type;
    // both oy, ox count y,x if it has an obstacle

    Point() : y(0), oy(0), x(0), ox(0), type('.') {}
    Point(int y, int x, char type) : y(y), oy(0), x(x), ox(0), type(type) {}
};

// Compare two points using the following order of fields: y, oy, x, ox
bool comp_y (const Point& a, const Point& b) {
    if (a.y != b.y)   return a.y < b.y;
    if (a.oy != b.oy) return a.oy < b.oy;
    if (a.x != b.x)   return a.x < b.x;
    return a.ox < b.ox;
}

// Compare two points using the following order of fields: x, ox, y, oy
bool comp_x (const Point& a, const Point& b) {
    if (a.x != b.x)   return a.x < b.x;
    if (a.ox != b.ox) return a.ox < b.ox;
    if (a.y != b.y)   return a.y < b.y;
    return a.oy < b.oy;
}

// Write debug information to filename.
void print_points(vector<Point> points, const char *filename) {
    FILE *fout = fopen(filename, "w");
    int Y = 0, X = 0, c = 0;
    sort(points.begin(), points.end(), comp_y);
    for (size_t i = 0; i < points.size(); ++i) {
        fprintf(fout, "%c %d %d %d %d\n", points[i].type, points[i].y, points[i].oy, points[i].x, points[i].ox);
        Y = max(Y, points[i].y);
        X = max(X, points[i].x);
    }
    ++Y;
    ++X;

    fprintf(fout, "%d %d\n", Y, X);
    for (int i = 0; i < Y*X; ++i) {
        if (i%X == 0)
            fprintf(fout, "\n");
        if (points.size() &&  points[c].x == i%X && points[c].y == i/X)
            fprintf(fout, " %c", points[c++].type);
        else 
            fprintf(fout, " .");
    }
    fprintf(fout, "\n");
    fclose(fout);
}

int fordFulkerson(vector<vector<int> >&cap, int s, int t) {
    int n = cap.size(); // number of vertices
    vector<vector<int> > fnet(n); // flow network (n*n matrix)
    for (int i = 0; i < n; ++i)
        fnet[i].resize(n);

    // stuff for the BFS
    vector<int> q(n), prev(n);
    int qf, qb;

    int flow = 0;
    while (true) {
        // find an augmenting path
        fill(prev.begin(), prev.end(), -1);
        qf = qb = 0;
        prev[q[qb++] = s] = -2;
        while (qb > qf && prev[t] == -1)
            for (int u = q[qf++], v = 0; v < n; v++)
                if (prev[v] == -1 && fnet[u][v] - fnet[v][u] < cap[u][v])
                    prev[q[qb++] = v] = u;

        // see if we're done
        if (prev[t] == -1)
            break;

        // get the bottleneck capacity
        int bot = 0x7FFFFFFF;
        for (int v = t, u = prev[v]; u >= 0; v = u, u = prev[v])
            bot = min(bot, cap[u][v] - fnet[u][v] + fnet[v][u]);

        // update the flow network
        for (int v = t, u = prev[v]; u >= 0; v = u, u = prev[v])
            fnet[u][v] += bot;
        flow += bot;
    }
    return flow;
}

int min_cover(vector<Point>& points, int rows, int columns) {

    if (DEBUG) {
        // write the graph to a file for debug.
        FILE *fout = fopen("graph.txt", "w");
        for (size_t i = 0; i < points.size(); ++i) {
            if (points[i].type == '#')
                continue;
            fprintf(fout, "%d%c %d%c\n", points[i].y, points[i].oy+'a',
                    points[i].x, points[i].ox+'a');
        }
        fclose(fout);
    }

    // relabel rows and columns from tuple (int, int) to int
    // values 0 and 1 are reserved
    int index = 2;
    map<pair<int,int>, int> relabel;
    for (size_t i = 0; i < points.size(); ++i) {
        if (points[i].type == '#') continue;
        pair<int,int> py = pair<int,int>(points[i].y, points[i].oy);
        if (relabel.find(py) == relabel.end())
            relabel[py] = index++;
        points[i].y = relabel[py];
    }
    int last_row = index;
    for (size_t i = 0; i < points.size(); ++i) {
        if (points[i].type == '#') continue;
        pair<int,int> px = pair<int,int>(1000 + points[i].x, points[i].ox);
        if (relabel.find(px) == relabel.end())
            relabel[px] = index++;
        points[i].x = relabel[px];
    }

    // create a flow network from rows to columns
    vector<vector<int> > graph(index);
    for (int i = 0; i < index; ++i)
        graph[i].resize(index);
    
    int s = 0;
    int t = 1;
    for (int i = 2; i < last_row; ++i)
        graph[s][i] = 1;
    for (int i = last_row; i < index; ++i)
        graph[i][t] = 1;
    for (size_t i = 0; i < points.size(); ++i) { 
        if (points[i].type == '#') continue;
        graph[points[i].y][points[i].x] = 1;
    }

    return fordFulkerson(graph, s, t);
}


int main(int argc, char *argv[]) {
    int Y, X, y, x, p, w, c;
    scanf("%d", &c);
    while (c--) {
        vector<Point> points;

        scanf("%d%d%d", &Y, &X, &p);
        for (int i = 0; i < p; ++i) {
            scanf("%d%d", &y, &x);
            points.push_back(Point(y, x, '*'));
        }
        scanf("%d", &w);
        for (int i = 0; i < w; ++i) {
            scanf("%d%d", &y, &x);
            points.push_back(Point(y, x, '#'));
        }

        // divide by rows
        if (DEBUG) print_points(points, "before.txt");
        sort(points.begin(), points.end(), comp_y);
        int row_gaps = 0, current_row = 0;
        for (size_t i = 0; i < points.size(); ++i) {
            if (current_row != points[i].y) { // new row
                current_row = points[i].y;
                row_gaps = 0;
            }
            if (points[i].type == '#')
                row_gaps++;
            points[i].oy = row_gaps;
        }
    
        // divide by columns
        sort(points.begin(), points.end(), comp_x);
        int column_gaps = 0, current_column = 0;
        for (size_t i = 0; i < points.size(); ++i) {
            if (current_column != points[i].x) { // new column
                current_column = points[i].x;
                column_gaps = 0;
            }
            if (points[i].type == '#')
                column_gaps++;
            points[i].ox = column_gaps;
        }
        if (DEBUG) print_points(points, "after.txt");
    
        printf("%d\n", min_cover(points, Y, X));
    }
    return EXIT_SUCCESS;
}
