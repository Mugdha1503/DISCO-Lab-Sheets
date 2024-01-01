#include <stdio.h>
#include <stdbool.h>
// Define a pair structure
struct Pair {
    int x;
    int y;
};
typedef struct Pair point;
// Function to check if a point is in the set
bool contains(point p, point points[], int size) {
    for (int i = 0; i < size; i++) {
        if (points[i].x == p.x && points[i].y == p.y) {
            return true;
        }
    }
    return false;
}
int main() {
    int answer = 0;
    // Create an array to store points
    point points[1000]; // Assuming a maximum of 1000 points
    int n; // Number of points
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &points[i].x, &points[i].y);
    }
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            point p1 = points[i];
            point p2 = points[j];
            if (p1.x == p2.x || p1.y == p2.y) {
                continue;
            }
            point p3 = {p1.x, p2.y};
            point p4 = {p2.x, p1.y};
            if (contains(p3, points, n) && contains(p4, points, n)) {
                answer++;
            }
        }
    }
    printf("%d\n", answer / 2);
    return 0;
}

