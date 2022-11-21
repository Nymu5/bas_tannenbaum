#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "main.h"

char decorations[] = {'@', '*', '#', 'x', '~'};
int dec_amount = 5;

int main() {
    srand(time(0));

    int height = tree_height(3, 17)+4;
    int width = 2*height+1;
    char tree_array[height*width];
    for (int i = 0; i < width*height; i++) {
        tree_array[i] = ' ';
    }
    star(tree_array, width);
    tree(tree_array, height, width);
    draw_fill(tree_array, height, width);
    stand(tree_array, height, width);



    print_array(tree_array, width, height);


    return 0;
}

void print_array(char array[], int width, int height) {
    for (int i = 0; i < width*height; i++) {
        if (i % width == 0 && i != 0) {
            printf("\n");
        }
        if (i / width < 3) {
            printf("\x1b[33m%c\x1b[0m", array[i]);
        } else if (i / width >= height-1) {
            printf("\x1b[30m%c\x1b[0m", array[i]);
        } else {
            switch (array[i]) {
                case '/':
                    printf("\x1b[32m%c\x1b[0m", array[i]);
                    break;
                case '\\':
                    printf("\x1b[32m%c\x1b[0m", array[i]);
                    break;
                case '#':
                    printf("\x1b[32m%c\x1b[0m", array[i]);
                    break;
                case '@':
                    printf("\x1b[31m%c\x1b[0m", array[i]);
                    break;
                case '*':
                    printf("\x1b[33m%c\x1b[0m", array[i]);
                    break;
                case '~':
                    printf("\x1b[34m%c\x1b[0m", array[i]);
                    break;
                default:
                    printf("%c", array[i]);
                    break;
            }
        }
    }
}

void star(char array[], int width) {
    int x_pos = (width-1)/2;
    char star_symbols[] = {'\\',' ','/','-','X','-','/','|','\\'};
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            array[i*width+j+x_pos] = star_symbols[i*3+j];
        }
    }
}

void stand(char array[], int height, int width) {
    for (int i = 0; i < 3; i++) {
        array[((height-1)*width)+((width-1)/2)+i] = '|';
    }
}

void tree(char array[], int height, width) {
    for (int i = 3; i < height-1; i++) {
        array[i*width+height-(i-3)] = '/';
        array[i*width+height+(i-1)] = '\\';
    }
}

void draw_fill(char array[], int height, int width) {
    for (int i = 3; i < height-1; i++) {
        for (int j = 0; j < (i-3)*2+1 ; j++) {
            char decoration;
            do {
                decoration = random_decoration();
                array[i*width+height-(i-3)+1+j] = decoration;
            } while (
                    array[i*width+height-(i-3)+1+j+1] == decoration ||
                    array[i*width+height-(i-3)+1+j-1] == decoration ||
                    array[i*width+height-(i-3)+1+j-width] == decoration ||
                    array[i*width+height-(i-3)+1+j+width] == decoration
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
