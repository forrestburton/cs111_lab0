#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <getopt.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

void cause_segfault() {
    char* ptr = NULL;
    (*ptr) = 0;
    return;
}

int main(int argc, char *argv[]) {
    int arg;
    char* input, output;
    bool seg_fault = false;

    while(1) {
        int option_index = 0;
        static struct option long_options[] = {
            {"input", required_argument, 0, 'i' },
            {"output", required_argument, 0, 'o' },
            {"segfault", no_argument, 0, 's' },
            {"catch", no_argument, 0, 'c' },
            {0,     0,                  0, 0 }};
        c = getopt_long(argc, argv, "ab:0", longoptions, &option_index);
        if (c == -1) break;
        switch (c) {
            case 'i':
                //int file = open(optarg, 0);
                break;
            case 'o':
                printf("option a\n");
                break;
            case 's':
                printf("option b with value '%s'\n", optarg);
                seg_fault = true;
                break;
            case 'c':
                break;
            default:
                printf("?? getopt returned character code 0%o ??\n", c);
        }
    }

    if (seg_fault) {
        cause_segfault();
    }
}