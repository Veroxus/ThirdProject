#include "babies.h"

int removeCommas (char *line)
{
    int total = 0;
    int stop = 0;
    int count = 0;
    int i;

        while (strlen(line) > total)
        {
            stop = total;
                if (line[stop] == ',')
                {
                    for (i = stop; i < strlen(line); i++)
                    {
                      line[i] = line[i+1];
                    }
                    count++;
                }
            total++;
        }
return (count);
}
