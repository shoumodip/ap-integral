#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define OUTPUT_PATH "output.log"

double ap_sum(float a, float d, float n)
{
    return (n / 2.0) * (2.0 * a + (n - 1.0) * d);
}

double ap_integral(float a, float d, float n)
{
    return (a * n) + ((n - 1.0) * (n - 1.0) * d * 0.5);
}

void ap_scale(FILE *f, float a, float d, float n)
{
    const double sum = ap_sum(a, d, n);
    const double integral = ap_integral(a, d, n);
    fprintf(f, "%g (%g / %g)\n", sum / integral, sum, integral);
}

int main(int argc, char **argv)
{
    size_t count = 10;

    if (argc == 2) {
        char *end;
        count = strtol(argv[1], &end, 10);

        if (end != argv[1] + strlen(argv[1])) {
            fprintf(stderr, "Error: invalid count `%s`\n", argv[1]);
            fprintf(stderr, "Usage: scale COUNT\n");
            exit(1);
        }
    }

    const size_t padding = snprintf(NULL, 0, "%zu", count);

    FILE *f = fopen(OUTPUT_PATH, "w");
    for (size_t a = 1; a <= count; ++a) {
        for (size_t d = 1; d <= count; ++d) {
            for (size_t n = 1; n <= count; ++n) {
                fprintf(f, "scale(a=%*zu, d=%*zu, n=%*zu) = ",
                        (int) padding, a,
                        (int) padding, d,
                        (int) padding, n);
                ap_scale(f, a, d, n);
            }
        }
    }
    fclose(f);
    return 0;
}
