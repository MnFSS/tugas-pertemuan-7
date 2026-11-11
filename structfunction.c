#include <stdio.h>

typedef struct
{
    double time;      /* s */
    double voltage;   /* V */
    double current;   /* A */
} ElectricalMeasurement;

double power(const ElectricalMeasurement *m)
{
    return m->voltage * m->current;
}

int main(void)
{
    ElectricalMeasurement measurements[] =
    {
        {0.0, 5.0, 0.1},
        {1.0, 5.0, 0.2},
        {2.0, 5.0, 0.3},
        {3.0, 5.0, 0.4}
    };
    int n = sizeof(measurements) / sizeof(measurements[0]);

    for (int i = 0; i < n; i++)
    {
        double p = power(&measurements[i]);
        printf("t = %.1f s, V = %.2f V, I = %.2f A, P = %.2f W\n",
               measurements[i].time,
               measurements[i].voltage,
               measurements[i].current,
               p);
    }

    return 0;
}