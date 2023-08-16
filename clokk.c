#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SECONDS_IN_HOUR 3600

// NOTE: Adjust to fit your timezone
#define HOUR_CORRECTION 2

#define DIGIT_WIDTH 7
#define DIGIT_HEIGHT 7
#define DIGIT_SEPARATOR '*'
#define DIGIT_PAD(n) (n * (DIGIT_WIDTH + 1))

const char *digits[] = {
    "#######       # ####### ####### #     # ####### ####### ####### ####### #######",
    "#     #       #       #       # #     # #       #             # #     # #     #",
    "#     #       #       #       # #     # #       #             # #     # #     #",
    "#     #       # ####### ####### ####### ####### #######       # ####### #######",
    "#     #       # #             #       #       # #     #       # #     #       #",
    "#     #       # #             #       #       # #     #       # #     #       #",
    "#######       # ####### #######       # ####### #######       # #######       #",
};

void clokk(int hour, int min);

int main(void) {
    time_t rawTime;
    time(&rawTime);

    if (rawTime == -1) {
        return EXIT_FAILURE;
    }

    time_t correctedTime = rawTime + (SECONDS_IN_HOUR * HOUR_CORRECTION);
    struct tm *t = gmtime(&correctedTime);

    clokk(t->tm_hour, t->tm_min);

    return EXIT_SUCCESS;
}

void clokk(int hour, int min) {
    int hourr = hour % 10;
    int hourl = (hour - hourr) / 10;
    
    int minr = min % 10;
    int minl = (min - minr) / 10;

    char c;
    for (int i = 0; i < DIGIT_HEIGHT; ++i) {
        fprintf(stdout, "%.*s ", DIGIT_WIDTH, &digits[i][DIGIT_PAD(hourl)]);
        fprintf(stdout, "%.*s", DIGIT_WIDTH, &digits[i][DIGIT_PAD(hourr)]);

        c = (i == 1 || i == 2 || i == 4 || i == 5) ? DIGIT_SEPARATOR : ' ';
        fprintf(stdout, "  %c  ", c);

        fprintf(stdout, "%.*s ", DIGIT_WIDTH, &digits[i][DIGIT_PAD(minl)]);
        fprintf(stdout, "%.*s\n", DIGIT_WIDTH, &digits[i][DIGIT_PAD(minr)]);
    }
}