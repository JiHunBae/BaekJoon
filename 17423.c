#include <stdio.h>
#include <stdlib.h>

#define MIN(x,y) (((x) > (y)) ? (y) : (x))

typedef struct __Point {
    int x,y;
} Point;

int main() {
    int numberOfSpeakers;
    int index;
    int sizeOfSpeakers[100000] = { 0 };
    int volumeOfSpeakers = 1000000;
    Point pointOfSpeakers[100000];

    // Input 처리 부분
    scanf("%d", &numberOfSpeakers);

    for(index = 0; index < numberOfSpeakers; ++index) {
        scanf("%d", &sizeOfSpeakers[index]);
    }

    for(index = 0; index < numberOfSpeakers; ++index) {
        scanf("%d %d", &pointOfSpeakers[index].x, &pointOfSpeakers[index].y);
    }

    // Calculation 부분

    for(index = 0; index < numberOfSpeakers; ++index) {
        int calcIndex;
        int calcTemp;
        for(calcIndex = 0; calcIndex < numberOfSpeakers; ++calcIndex) {
            if(index != calcIndex) {
                calcTemp = (abs(pointOfSpeakers[index].x - pointOfSpeakers[calcIndex].x) + abs(pointOfSpeakers[index].y - pointOfSpeakers[calcIndex].y));
                calcTemp /= (sizeOfSpeakers[index] + sizeOfSpeakers[calcIndex]);
                volumeOfSpeakers = MIN(volumeOfSpeakers, calcTemp);
            }
        }
    }

    printf("%d", volumeOfSpeakers);

    return 0;
}
