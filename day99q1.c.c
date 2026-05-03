#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int position;
    int speed;
} Car;

int compare(const void *a, const void *b) {
    Car *c1 = (Car *)a;
    Car *c2 = (Car *)b;
    
    return c2->position - c1->position;
}

int carFleet(int target, int position[], int speed[], int n) {
    Car cars[n];
    
    for(int i = 0; i < n; i++)
        cars[i].position = position[i];
    
    for(int i = 0; i < n; i++)
        cars[i].speed = speed[i];
    
    qsort(cars, n, sizeof(Car), compare);
    
    int fleets = 0;
    double lastTime = 0.0;
    
    for(int i = 0; i < n; i++) {
        double time = (double)(target - cars[i].position) / cars[i].speed;
        
        if(time > lastTime) {
            fleets++;
            lastTime = time;
        }
    }
    
    return fleets;
}

int main() {
    int target = 12;
    
    int position[] = {10, 8, 0, 5, 3};
    int speed[] = {2, 4, 1, 1, 3};
    
    int n = 5;
    
    printf("Number of car fleets: %d\n", carFleet(target, position, speed, n));
    
    return 0;
}