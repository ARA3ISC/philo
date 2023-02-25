#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void progress_bar(int percent, const char* message) {
    // Clear the screen
    printf("\033[2J");
    // Move the cursor to the top-left corner
    printf("\033[H");

    // Calculate the width of the progress bar
    int bar_width = 50;
    int num_bars = (percent * bar_width) / 100;

    // Draw the progress bar
    printf("[");
    for (int i = 0; i < num_bars; i++) {
        printf("\e[1;32m#");
    }
    for (int i = num_bars; i < bar_width; i++) {
        printf(" ");
    }
    printf("] %d%%\n", percent);

    // Print the message
    printf("%s\n", message);
}

int main() {
    for (int i = 0; i <= 100; i++) {
        progress_bar(i, "Compiling in progress ...\n");
        usleep(10000);
    }

    return 0;
}
