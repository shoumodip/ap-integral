#include "make.h"

#define CC "cc"
#define CFLAGS "-Wall", "-Wextra", "-std=c11", "-pedantic"

int main(int argc, char **argv)
{
    make_rebuild(argc, argv);
    make_assert(argc > 1, "no subcommand provided");

    if (strcmp(argv[1], "build") == 0) {
        make_cc("scale", "scale.c", CFLAGS);
    } else if (strcmp(argv[1], "run") == 0) {
        make_assert(argc > 2, "no output file path provided");
        make_cc("scale", "scale.c", CFLAGS);
        make_cmd("./scale", argv[2]);
    } else {
        make_error("unknown subcommand `%s`", argv[1]);
    }
}
