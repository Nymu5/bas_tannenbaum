#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "main.h"

char decorations[] = {'@', '*', '#', 'x', '~'};
int dec_amount = 5;

int main(void) {
    int height, width, i;
    char tree_array[990];
    srand(time(0));

    height = tree_height(3, 17)+5;
    width = 2*height+1;
    for (i = 0; i < width*height; i++) {
        tree_array[i] = ' ';
    }
    draw_tree(tree_array, height, width);
    print_array(tree_array, height, width);
    return 0;
}

void draw_tree(char tree_array[], int height, int width) {
    star(tree_array, width);
    tree(tree_array, height, width);
    draw_fill(tree_array, height, width);
    stand(tree_array, height, width);
}

void print_array(char array[], int height, int width) {
    int i;
    for (i = 0; i < width*height; i++) {
        if (i % width == 0 && i != 0) {
            printf("\n");
        }
        if (i / width < 3) {
            printf("\x1b[33m");
        } else if (i / width >= height-1) {
            printf("\x1b[30m");
        } else {
            switch (array[i]) {
                case 'A':
                    printf("\x1b[32m");
                    break;
                case '/':
                    printf("\x1b[32m");
                    break;
                case '\\':
                    printf("\x1b[32m");
                    break;
                case '#':
                    printf("\x1b[32m");
                    break;
                case '@':
                    printf("\x1b[31m");
                    break;
                case '*':
                    printf("\x1b[33m");
                    break;
                case '~':
                    printf("\x1b[34m");
                    break;
            }
        }
        printf("%c\x1b[0m", array[i]);
    }
}

void star(char array[], int width) {
    int i, j;
    char star_symbols[] = {'\\',' ','/','-','X','-','/','|','\\', ' ', 'A', ' '};
    for (i = 0; i < 4; i++) {
        for (j = 0; j < 3; j++) {
            array[i*width+j+(width-1)/2] = star_symbols[i*3+j];
        }
    }
}

void stand(char array[], int height, int width) {
    int i;
    for (i = 0; i < 3; i++) {
        array[((height-1)*width)+((width-1)/2)+i] = '|';
    }
}

void tree(char array[], int height, int width) {
    int i;
    for (i = 4; i < height-1; i++) {
        array[i*width+height-(i-4)] = '/';
        array[i*width+height+(i-2)] = '\\';
    }
}

void draw_fill(char array[], int height, int width) {
    int i, j;
    for (i = 4; i < height-1; i++) {
        for (j = 0; j < (i-4)*2+1 ; j++) {
            char decoration;
            do {
                decoration = random_decoration();
                array[i*width+height-(i-4)+1+j] = decoration;
            } while (
                    array[i*width+height-(i-4)+1+j+1] == decoration ||
                    array[i*width+height-(i-4)+1+j-1] == decoration ||
                    array[i*width+height-(i-4)+1+j-width] == decoration ||
                    array[i*width+height-(i-4)+1+j+width] == decoration
                    );
        }
    }
}

char random_decoration(void) {
    return decorations[rand() % dec_amount];
}

int tree_height(int min, int max) {
    if (min < 3 || max < min) {
        min = 3;
        max = 17;
    }
    return (rand() % (max - min + 1)) + min;
}
