//NAME: Forrest Burton
//EMAIL: burton.forrest10@gmail.com
//ID: 005324612


#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <getopt.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#define BUFFERSIZE 1024

void cause_segfault() {
    char* ptr = NULL;
    (*ptr) = 0;
    return;
}

void handle_sigint(int seg) {
    if (seg == SIGSEGV) {
        fprintf(stderr, "--catch Exit code 4: Segmentation fault caught\n");
        exit(4);
    }
}

int main(int argc, char *argv[]) {
    char* input = NULL;
    char* output = NULL;
    int seg_fault = 0;
    int c;

    while(1) {
        int option_index = 0;
        static struct option long_options[] = {
            {"input", required_argument, 0, 'i' },
            {"output", required_argument, 0, 'o' },
            {"segfault", no_argument, 0, 's' },
            {"catch", no_argument, 0, 'c' },
            {0,     0,                  0, 0 }};
        c = getopt_long(argc, argv, "", long_options, &option_index);
        if (c == -1) break;
        switch (c) {
            case 'i':
                input = optarg;
                break;
            case 'o':
                output = optarg;
                break;
            case 's':
                seg_fault = 1;
                break;
            case 'c':
                signal(SIGSEGV, handle_sigint);
                break;
            default:
                printf("accepted options are: [--input=inputFile --output=outputFile --segfault --catch]\n");
                exit(1);
        }
    }

    if (input) {
        int ifd = open(input, O_RDONLY);
        if (ifd >= 0) {
            close(0);
            dup(ifd);
            close(ifd);
        }
        else {
            fprintf(stderr, "--input error while opening the file: %s, which was caused by: %s\n", input, strerror(errno));
            exit(2);
        }
    }

    if (output) {   
        int ofd = creat(output, S_IRWXU); //second parameter - who can do modifcations to the file
        if (ofd >= 0) {
            close(1);
            dup(ofd);  //Make the lowest available file descriptor to point to the same file as fd.
            close(ofd);
        }
        else {
            fprintf(stderr, "--output error while opening the file: %s, which was caused by: %s\n", output, strerror(errno));
            exit(3);
        }
    }

    if (seg_fault) {
        cause_segfault();
    }

    //copies standard input to standard output by read(2)-ing from file descriptor 0 (until encountering an end of file) and write(2)-ing to file descriptor 1
    char buf[BUFFERSIZE];
    ssize_t ret;
    while ((ret = read(0, buf, 1)) > 0) //(src, buffer, bytes read)
        write(1, buf, 1);   //(des_fd, buffer, bytes written)

    close(0);
    close(1);
    exit(0);
}