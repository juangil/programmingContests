#include <cstdio>
#include <cstdlib>
#include <cstring>

// swap everything we can
int swap(char *s, char *t, size_t size) {
    size_t a = 0, b = 0, moves = 0;
    while (true) {
        while (a < size && !(s[a] != t[a] && s[a] == '0'))
            ++a;
        while (b < size && !(s[b] != t[b] && s[b] == '1'))
            ++b;
        if (a < size && b < size) {
            s[a] = t[a];
            s[b] = t[b];
            ++moves;
        } else
            break;
    }
    return moves;
}


int min_moves(char *s, char *t) {
    int moves = 0, zeroes = 0;
    size_t size = strlen(s);

    moves += swap(s, t, size);

    // convert 0 to 1
    for (size_t i = 0; i < size; ++i)
        if (s[i] == '0' && t[i] == '1') {
            s[i] = '1';
            moves++;
        }

    // count the number of zeroes we need
    for (size_t i = 0; i < size; ++i)
        if (s[i] == '1' && t[i] == '0')
            zeroes++;

    // convert the ? into 0 or 1
    for (size_t i = 0; i < size; ++i)
        if (s[i] == '?') {
            if (t[i] == '1' && zeroes > 0) {
                s[i] = '0';
                zeroes--;
            } else
                s[i] = t[i];
            moves++;
        }

    moves += swap(s, t, size);

    if (strcmp(s, t) != 0)
        return -1;
    return moves;
}

int main(int argc, char *argv[]) {
    int n;
    char s[201], t[201];
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        scanf("%s%s", s, t);
        printf("Case %d: %d\n", i, min_moves(s, t));
    }
    return EXIT_SUCCESS;
}
