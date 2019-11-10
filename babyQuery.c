#include "babies.h"

/* Function definitions */
int main (int argc, char *argv[])
{

  int cut = 1;
  char line[100];
  FILE *fp;
  struct pNames data;
  char male[10];
  char female[10];
  char year[100];
  int year1;
  char path[5];
  char ranknumber[50];
  int ranknumber1;
  char choice[100];
  int choice1;
  char name[20];
  int i;
  int j;
  int both;
  int a;
  int b;
  int c;
  char y[5];

b = 1;
while (b)
{
/*Determining the decade*/
cut = 1;
while (cut)
{
printf ("What decade do you want to look at [1880 to 2010]?\n");
fgets (line, 100, stdin);
sscanf (line, "%s", year);
year1 = atoi(year);

    if (year1 != 1880 && year1 != 1890 && year1 != 1900 && year1 != 1910 && year1 != 1920 && year1 != 1930 && year1 != 1940 && year1 != 1950 && year1 != 1960 && year1 != 1970 && year1 != 1980 && year1 != 1990 && year1 != 2000 && year1 != 2010)
    {
        printf ("Acceptable decades are 1880, 1890, 1900, 1910, 1920, 1930, 1940, 1950, 1960, 1970, 1980, 1990, 2000, or 2010. No other numbers are acceptable\n");
    }
        else
        {
            cut = 0;
        }
}

/*Stores Name.txt data*/
strcat (year,"Names.txt");

    if ((fp = fopen(year, "r")) != NULL)
    {
        int i = 0;
        while (fgets (line, ROWS, fp) != NULL)
        {
            sscanf(line, "%d %s %s %s %s", & data.rank[i], data.maleName[i], male, data.femaleName[i], female);
            removeCommas(male);
            removeCommas(female);
            data.maleNumber[i] = atoi(male);
            data.femaleNumber[i] = atoi(female);
            i++;
        }
        fclose(fp);
    }


a = 1;
while (a)
{
/*Determining the pathway*/
cut = 1;
while (cut)
{
printf ("Would you like to see a rank, search for a name, or see the top 10? [rank,search,top]\n");
fgets (line, 100, stdin);
sscanf (line, "%s", path);

    if ((strcmp(path,"rank") == 0) || (strcmp(path,"top") == 0) || (strcmp(path,"search") == 0))
    {
        cut = 0;
    }
        else
        {
            printf ("Please type in rank, search, or top exactly as requested.\n");
        }
}

if ((strcmp(path,"rank") == 0))
{
    cut = 1;
    while (cut)
    {
        printf ("What rank do you wish to see? [1-200]\n");
        fgets (line, 100, stdin);
        sscanf (line, "%s", ranknumber);
        if (atoi(ranknumber) < 1 || atoi(ranknumber) > 200)
        {
            printf ("Only numbers between 1 and 200 are acceptable.\n");
        }
            else
            {
                ranknumber1 = atoi(ranknumber);
                cut = 0;
            }
    }
    cut = 1;
    while (cut)
    {
        printf ("Would you like to see the male(0), female(1), or both(2) name(s)? [0-2]\n");
        fgets (choice, 100, stdin);
        choice[100] = *strtok(choice,"\n");
            if ((strcmp(choice, "0") == 0) || (strcmp(choice, "1") == 0) || (strcmp(choice, "2") == 0))
            {
                choice1 = atoi(choice);
                cut = 0;
            }
                    else
                    {
                        printf ("Only the numbers 0, 1, or 2 are acceptable.\n");
                    }
    }
    if (choice1 == 0)
    {
        printf ("Rank %d: Male: %s (%d)\n", ranknumber1, data.maleName[ranknumber1 - 1], data.maleNumber[ranknumber1 - 1]);
        c = 1;
        while (c)
        {
        printf ("Do you want to ask another question about %d? [Y or N]\n", year1);
        fgets (y, 5, stdin);
        if ((strcmp(y,"Y\n") == 0) || (strcmp(y,"y\n") == 0) || (strcmp(y,"N\n") == 0) || (strcmp(y,"n\n") == 0))
        {
            c = 0;
        }
        else
        {
            printf ("Only the single characters Y or N are acceptable.\n");
        }
        }
        if ((strcmp(y,"Y\n") == 0) || (strcmp(y,"y\n") == 0))
        {
            b = 0;
        }
        if ((strcmp(y,"N\n") == 0) || (strcmp(y,"n\n") == 0))
        {
            c = 1;
            while (c)
            {
            printf ("Would you like to select another year? [Y or N]\n");
            fgets (y, 5, stdin);
                if ((strcmp(y,"Y\n") == 0) || (strcmp(y,"y\n") == 0) || (strcmp(y,"N\n") == 0) || (strcmp(y,"n\n") == 0))
                {
                    c = 0;
                }
                else
                {
                    printf ("Only the single characters Y or N are acceptable.\n");
                }
            }
                    if ((strcmp(y,"Y\n") == 0) || (strcmp(y,"y\n") == 0))
                    {
                        a = 0;
                    }
                    if ((strcmp(y,"N\n") == 0) || (strcmp(y,"n\n") == 0))
                    {
                        printf ("Thank you for using babyQuery\n");
                        return(0);
                    }
        }
    }
        else if (choice1 == 1)
        {
            printf ("Rank %d: Female: %s (%d)\n", ranknumber1, data.femaleName[ranknumber1 - 1], data.femaleNumber[ranknumber1 - 1]);
            c = 1;
            while (c)
            {
            printf ("Do you want to ask another question about %d? [Y or N]\n", year1);
            fgets (y, 5, stdin);
            if ((strcmp(y,"Y\n") == 0) || (strcmp(y,"y\n") == 0) || (strcmp(y,"N\n") == 0) || (strcmp(y,"n\n") == 0))
            {
                c = 0;
            }
            else
            {
                printf ("Only the single characters Y or N are acceptable.\n");
            }
            }
            if ((strcmp(y,"Y\n") == 0) || (strcmp(y,"y\n") == 0))
            {
                b = 0;
            }
            if ((strcmp(y,"N\n") == 0) || (strcmp(y,"n\n") == 0))
            {
                c = 1;
                while (c)
                {
                printf ("Would you like to select another year? [Y or N]\n");
                fgets (y, 5, stdin);
                    if ((strcmp(y,"Y\n") == 0) || (strcmp(y,"y\n") == 0) || (strcmp(y,"N\n") == 0) || (strcmp(y,"n\n") == 0))
                    {
                        c = 0;
                    }
                    else
                    {
                        printf ("Only the single characters Y or N are acceptable.\n");
                    }
                }
                        if ((strcmp(y,"Y\n") == 0) || (strcmp(y,"y\n") == 0))
                        {
                            a = 0;
                        }
                        if ((strcmp(y,"N\n") == 0) || (strcmp(y,"n\n") == 0))
                        {
                            printf ("Thank you for using babyQuery\n");
                            return(0);
                        }
            }
        }
            else
            {
                printf ("Rank %d: Male: %s (%d) and Female: %s (%d)\n", ranknumber1, data.maleName[ranknumber1 - 1], data.maleNumber[ranknumber1 - 1], data.femaleName[ranknumber1 - 1], data.femaleNumber[ranknumber1 - 1]);
                c = 1;
                while (c)
                {
                printf ("Do you want to ask another question about %d? [Y or N]\n", year1);
                fgets (y, 5, stdin);
                if ((strcmp(y,"Y\n") == 0) || (strcmp(y,"y\n") == 0) || (strcmp(y,"N\n") == 0) || (strcmp(y,"n\n") == 0))
                {
                    c = 0;
                }
                else
                {
                    printf ("Only the single characters Y or N are acceptable.\n");
                }
                }
                if ((strcmp(y,"Y\n") == 0) || (strcmp(y,"y\n") == 0))
                {
                    b = 0;
                }
                if ((strcmp(y,"N\n") == 0) || (strcmp(y,"n\n") == 0))
                {
                    c = 1;
                    while (c)
                    {
                    printf ("Would you like to select another year? [Y or N]\n");
                    fgets (y, 5, stdin);
                        if ((strcmp(y,"Y\n") == 0) || (strcmp(y,"y\n") == 0) || (strcmp(y,"N\n") == 0) || (strcmp(y,"n\n") == 0))
                        {
                            c = 0;
                        }
                        else
                        {
                            printf ("Only the single characters Y or N are acceptable.\n");
                        }
                    }
                            if ((strcmp(y,"Y\n") == 0) || (strcmp(y,"y\n") == 0))
                            {
                                a = 0;
                            }
                            if ((strcmp(y,"N\n") == 0) || (strcmp(y,"n\n") == 0))
                            {
                                printf ("Thank you for using babyQuery\n");
                                return(0);
                            }
                }
            }
}

    else if ((strcmp(path,"search") == 0))
    {
        printf ("What name do you want to search for? [Case sensitive]\n");
        fgets (name, 20, stdin);
        cut = 1;
        while (cut)
        {
            printf ("Would you like to see the male(0), female(1), or both(2) name(s)? [0-2]\n");
            fgets (choice, 100, stdin);
            choice[100] = *strtok(choice,"\n");
                if ((strcmp(choice, "0") == 0) || (strcmp(choice, "1") == 0) || (strcmp(choice, "2") == 0))
                {
                    choice1 = atoi(choice);
                    cut = 0;
                }
                        else
                        {
                            printf ("Only the numbers 0, 1, or 2 are acceptable.\n");
                        }
        }
            if (choice1 == 0)
            {
                name[20] = *strtok (name,"\n"); /*Credit = https://rosipov.com/blog/c-strtok-usage-example/*/
                i = 0;
                while (i <= 200)
                {
                    if (strcmp(name, data.maleName[i]) == 0)
                    {
                        printf ("In %d, the male name %s is ranked %d with a count of %d.\n", year1, name, data.rank[i], data.maleNumber[i]);
                        i = 201;
                        c = 1;
                        while (c)
                        {
                        printf ("Do you want to ask another question about %d? [Y or N]\n", year1);
                        fgets (y, 5, stdin);
                        if ((strcmp(y,"Y\n") == 0) || (strcmp(y,"y\n") == 0) || (strcmp(y,"N\n") == 0) || (strcmp(y,"n\n") == 0))
                        {
                            c = 0;
                        }
                        else
                        {
                            printf ("Only the single characters Y or N are acceptable.\n");
                        }
                        }
                        if ((strcmp(y,"Y\n") == 0) || (strcmp(y,"y\n") == 0))
                        {
                            b = 0;
                        }
                        if ((strcmp(y,"N\n") == 0) || (strcmp(y,"n\n") == 0))
                        {
                            c = 1;
                            while (c)
                            {
                            printf ("Would you like to select another year? [Y or N]\n");
                            fgets (y, 5, stdin);
                                if ((strcmp(y,"Y\n") == 0) || (strcmp(y,"y\n") == 0) || (strcmp(y,"N\n") == 0) || (strcmp(y,"n\n") == 0))
                                {
                                    c = 0;
                                }
                                else
                                {
                                    printf ("Only the single characters Y or N are acceptable.\n");
                                }
                            }
                                    if ((strcmp(y,"Y\n") == 0) || (strcmp(y,"y\n") == 0))
                                    {
                                        a = 0;
                                    }
                                    if ((strcmp(y,"N\n") == 0) || (strcmp(y,"n\n") == 0))
                                    {
                                        printf ("Thank you for using babyQuery\n");
                                        return(0);
                                    }
                        }
                    }
                        else if (i < 200 && strcmp(name, data.maleName[i]) != 0)
                        {
                            i++;
                        }
                            else if ((i = 200))
                            {
                                printf ("In %d, the male name %s is not ranked.\n", year1, name);
                                i = 201;
                                c = 1;
                                while (c)
                                {
                                printf ("Do you want to ask another question about %d? [Y or N]\n", year1);
                                fgets (y, 5, stdin);
                                if ((strcmp(y,"Y\n") == 0) || (strcmp(y,"y\n") == 0) || (strcmp(y,"N\n") == 0) || (strcmp(y,"n\n") == 0))
                                {
                                    c = 0;
                                }
                                else
                                {
                                    printf ("Only the single characters Y or N are acceptable.\n");
                                }
                                }
                                if ((strcmp(y,"Y\n") == 0) || (strcmp(y,"y\n") == 0))
                                {
                                    b = 0;
                                }
                                if ((strcmp(y,"N\n") == 0) || (strcmp(y,"n\n") == 0))
                                {
                                    c = 1;
                                    while (c)
                                    {
                                    printf ("Would you like to select another year? [Y or N]\n");
                                    fgets (y, 5, stdin);
                                        if ((strcmp(y,"Y\n") == 0) || (strcmp(y,"y\n") == 0) || (strcmp(y,"N\n") == 0) || (strcmp(y,"n\n") == 0))
                                        {
                                            c = 0;
                                        }
                                        else
                                        {
                                            printf ("Only the single characters Y or N are acceptable.\n");
                                        }
                                    }
                                            if ((strcmp(y,"Y\n") == 0) || (strcmp(y,"y\n") == 0))
                                            {
                                                a = 0;
                                            }
                                            if ((strcmp(y,"N\n") == 0) || (strcmp(y,"n\n") == 0))
                                            {
                                                printf ("Thank you for using babyQuery\n");
                                                return(0);
                                            }
                                }
                            }
                }
            }
            if (choice1 == 1)
            {
                name[20] = *strtok (name,"\n"); /*Credit = https://rosipov.com/blog/c-strtok-usage-example/*/
                i = 0;
                while (i <= 200)
                {
                    if (strcmp(name, data.femaleName[i]) == 0)
                    {
                        printf ("In %d, the female name %s is ranked %d with a count of %d.\n", year1, name, data.rank[i], data.femaleNumber[i]);
                        i = 201;
                        c = 1;
                        while (c)
                        {
                        printf ("Do you want to ask another question about %d? [Y or N]\n", year1);
                        fgets (y, 5, stdin);
                        if ((strcmp(y,"Y\n") == 0) || (strcmp(y,"y\n") == 0) || (strcmp(y,"N\n") == 0) || (strcmp(y,"n\n") == 0))
                        {
                            c = 0;
                        }
                        else
                        {
                            printf ("Only the single characters Y or N are acceptable.\n");
                        }
                        }
                        if ((strcmp(y,"Y\n") == 0) || (strcmp(y,"y\n") == 0))
                        {
                            b = 0;
                        }
                        if ((strcmp(y,"N\n") == 0) || (strcmp(y,"n\n") == 0))
                        {
                            c = 1;
                            while (c)
                            {
                            printf ("Would you like to select another year? [Y or N]\n");
                            fgets (y, 5, stdin);
                                if ((strcmp(y,"Y\n") == 0) || (strcmp(y,"y\n") == 0) || (strcmp(y,"N\n") == 0) || (strcmp(y,"n\n") == 0))
                                {
                                    c = 0;
                                }
                                else
                                {
                                    printf ("Only the single characters Y or N are acceptable.\n");
                                }
                            }
                                    if ((strcmp(y,"Y\n") == 0) || (strcmp(y,"y\n") == 0))
                                    {
                                        a = 0;
                                    }
                                    if ((strcmp(y,"N\n") == 0) || (strcmp(y,"n\n") == 0))
                                    {
                                        printf ("Thank you for using babyQuery\n");
                                        return(0);
                                    }
                        }
                    }
                        else if (i < 200 && strcmp(name, data.femaleName[i]) != 0)
                        {
                            i++;
                        }
                            else if ((i = 200))
                            {
                                printf ("In %d, the female name %s is not ranked.\n", year1, name);
                                i = 201;
                                c = 1;
                                while (c)
                                {
                                printf ("Do you want to ask another question about %d? [Y or N]\n", year1);
                                fgets (y, 5, stdin);
                                if ((strcmp(y,"Y\n") == 0) || (strcmp(y,"y\n") == 0) || (strcmp(y,"N\n") == 0) || (strcmp(y,"n\n") == 0))
                                {
                                    c = 0;
                                }
                                else
                                {
                                    printf ("Only the single characters Y or N are acceptable.\n");
                                }
                                }
                                if ((strcmp(y,"Y\n") == 0) || (strcmp(y,"y\n") == 0))
                                {
                                    b = 0;
                                }
                                if ((strcmp(y,"N\n") == 0) || (strcmp(y,"n\n") == 0))
                                {
                                    c = 1;
                                    while (c)
                                    {
                                    printf ("Would you like to select another year? [Y or N]\n");
                                    fgets (y, 5, stdin);
                                        if ((strcmp(y,"Y\n") == 0) || (strcmp(y,"y\n") == 0) || (strcmp(y,"N\n") == 0) || (strcmp(y,"n\n") == 0))
                                        {
                                            c = 0;
                                        }
                                        else
                                        {
                                            printf ("Only the single characters Y or N are acceptable.\n");
                                        }
                                    }
                                            if ((strcmp(y,"Y\n") == 0) || (strcmp(y,"y\n") == 0))
                                            {
                                                a = 0;
                                            }
                                            if ((strcmp(y,"N\n") == 0) || (strcmp(y,"n\n") == 0))
                                            {
                                                printf ("Thank you for using babyQuery\n");
                                                return(0);
                                            }
                                }
                            }
                }
            }
            if (choice1 == 2)
            {
                name[20] = *strtok (name,"\n"); /*Credit = https://rosipov.com/blog/c-strtok-usage-example/*/
                i = 0;
                while (i <= 200)
                {
                    if (strcmp(name, data.maleName[i]) == 0)
                    {
                        j = 0;
                        while (j <= 200)
                        {
                            if (strcmp(name, data.femaleName[j]) == 0)
                            {
                                both = j;
                                j = 201;
                            }
                        j++;
                        }
                        printf ("In %d, the female name %s is ranked %d with a count of %d and the male name %s is ranked %d with a count of %d.\n", year1, name, data.rank[both], data.femaleNumber[both], name, data.rank[i], data.maleNumber[i]);
                        i = 201;
                        c = 1;
                        while (c)
                        {
                        printf ("Do you want to ask another question about %d? [Y or N]\n", year1);
                        fgets (y, 5, stdin);
                        if ((strcmp(y,"Y\n") == 0) || (strcmp(y,"y\n") == 0) || (strcmp(y,"N\n") == 0) || (strcmp(y,"n\n") == 0))
                        {
                            c = 0;
                        }
                        else
                        {
                            printf ("Only the single characters Y or N are acceptable.\n");
                        }
                        }
                        if ((strcmp(y,"Y\n") == 0) || (strcmp(y,"y\n") == 0))
                        {
                            b = 0;
                        }
                        if ((strcmp(y,"N\n") == 0) || (strcmp(y,"n\n") == 0))
                        {
                            c = 1;
                            while (c)
                            {
                            printf ("Would you like to select another year? [Y or N]\n");
                            fgets (y, 5, stdin);
                                if ((strcmp(y,"Y\n") == 0) || (strcmp(y,"y\n") == 0) || (strcmp(y,"N\n") == 0) || (strcmp(y,"n\n") == 0))
                                {
                                    c = 0;
                                }
                                else
                                {
                                    printf ("Only the single characters Y or N are acceptable.\n");
                                }
                            }
                                    if ((strcmp(y,"Y\n") == 0) || (strcmp(y,"y\n") == 0))
                                    {
                                        a = 0;
                                    }
                                    if ((strcmp(y,"N\n") == 0) || (strcmp(y,"n\n") == 0))
                                    {
                                        printf ("Thank you for using babyQuery\n");
                                        return(0);
                                    }
                        }
                    }
                        else if (strcmp(name, data.femaleName[i]) == 0)
                        {
                            j = 0;
                            while (j <= 200)
                            {
                                if (strcmp(name, data.maleName[j]) == 0)
                                {
                                    both = j;
                                    j = 201;
                                }
                                j++;
                            }
                            printf ("In %d, the female name %s is ranked %d with a count of %d and the male name %s is ranked %d with a count of %d.\n", year1, name, data.rank[i], data.femaleNumber[i], name, data.rank[both], data.maleNumber[both]);
                            i = 201;
                            c = 1;
                            while (c)
                            {
                            printf ("Do you want to ask another question about %d? [Y or N]\n", year1);
                            fgets (y, 5, stdin);
                            if ((strcmp(y,"Y\n") == 0) || (strcmp(y,"y\n") == 0) || (strcmp(y,"N\n") == 0) || (strcmp(y,"n\n") == 0))
                            {
                                c = 0;
                            }
                            else
                            {
                                printf ("Only the single characters Y or N are acceptable.\n");
                            }
                            }
                            if ((strcmp(y,"Y\n") == 0) || (strcmp(y,"y\n") == 0))
                            {
                                b = 0;
                            }
                            if ((strcmp(y,"N\n") == 0) || (strcmp(y,"n\n") == 0))
                            {
                                c = 1;
                                while (c)
                                {
                                printf ("Would you like to select another year? [Y or N]\n");
                                fgets (y, 5, stdin);
                                    if ((strcmp(y,"Y\n") == 0) || (strcmp(y,"y\n") == 0) || (strcmp(y,"N\n") == 0) || (strcmp(y,"n\n") == 0))
                                    {
                                        c = 0;
                                    }
                                    else
                                    {
                                        printf ("Only the single characters Y or N are acceptable.\n");
                                    }
                                }
                                        if ((strcmp(y,"Y\n") == 0) || (strcmp(y,"y\n") == 0))
                                        {
                                            a = 0;
                                        }
                                        if ((strcmp(y,"N\n") == 0) || (strcmp(y,"n\n") == 0))
                                        {
                                            printf ("Thank you for using babyQuery\n");
                                            return(0);
                                        }
                            }
                        }
                            else if (strcmp(name, data.femaleName[i]) == 0)
                            {
                                printf ("In %d, the female name %s is ranked %d with a count of %d and the male name %s is not ranked.\n", year1, name, data.rank[i], data.femaleNumber[i], name);
                                i = 201;
                                c = 1;
                                while (c)
                                {
                                printf ("Do you want to ask another question about %d? [Y or N]\n", year1);
                                fgets (y, 5, stdin);
                                if ((strcmp(y,"Y\n") == 0) || (strcmp(y,"y\n") == 0) || (strcmp(y,"N\n") == 0) || (strcmp(y,"n\n") == 0))
                                {
                                    c = 0;
                                }
                                else
                                {
                                    printf ("Only the single characters Y or N are acceptable.\n");
                                }
                                }
                                if ((strcmp(y,"Y\n") == 0) || (strcmp(y,"y\n") == 0))
                                {
                                    b = 0;
                                }
                                if ((strcmp(y,"N\n") == 0) || (strcmp(y,"n\n") == 0))
                                {
                                    c = 1;
                                    while (c)
                                    {
                                    printf ("Would you like to select another year? [Y or N]\n");
                                    fgets (y, 5, stdin);
                                        if ((strcmp(y,"Y\n") == 0) || (strcmp(y,"y\n") == 0) || (strcmp(y,"N\n") == 0) || (strcmp(y,"n\n") == 0))
                                        {
                                            c = 0;
                                        }
                                        else
                                        {
                                            printf ("Only the single characters Y or N are acceptable.\n");
                                        }
                                    }
                                            if ((strcmp(y,"Y\n") == 0) || (strcmp(y,"y\n") == 0))
                                            {
                                                a = 0;
                                            }
                                            if ((strcmp(y,"N\n") == 0) || (strcmp(y,"n\n") == 0))
                                            {
                                                printf ("Thank you for using babyQuery\n");
                                                return(0);
                                            }
                                }
                            }
                                else if (strcmp(name, data.maleName[i]) == 0)
                                {
                                    printf ("In %d, the female name %s is not ranked and the male name %s is ranked %d with a count of %d.\n", year1, name, name, data.rank[i], data.maleNumber[i]);
                                    i = 201;
                                    c = 1;
                                    while (c)
                                    {
                                    printf ("Do you want to ask another question about %d? [Y or N]\n", year1);
                                    fgets (y, 5, stdin);
                                    if ((strcmp(y,"Y\n") == 0) || (strcmp(y,"y\n") == 0) || (strcmp(y,"N\n") == 0) || (strcmp(y,"n\n") == 0))
                                    {
                                        c = 0;
                                    }
                                    else
                                    {
                                        printf ("Only the single characters Y or N are acceptable.\n");
                                    }
                                    }
                                    if ((strcmp(y,"Y\n") == 0) || (strcmp(y,"y\n") == 0))
                                    {
                                        b = 0;
                                    }
                                    if ((strcmp(y,"N\n") == 0) || (strcmp(y,"n\n") == 0))
                                    {
                                        c = 1;
                                        while (c)
                                        {
                                        printf ("Would you like to select another year? [Y or N]\n");
                                        fgets (y, 5, stdin);
                                            if ((strcmp(y,"Y\n") == 0) || (strcmp(y,"y\n") == 0) || (strcmp(y,"N\n") == 0) || (strcmp(y,"n\n") == 0))
                                            {
                                                c = 0;
                                            }
                                            else
                                            {
                                                printf ("Only the single characters Y or N are acceptable.\n");
                                            }
                                        }
                                                if ((strcmp(y,"Y\n") == 0) || (strcmp(y,"y\n") == 0))
                                                {
                                                    a = 0;
                                                }
                                                if ((strcmp(y,"N\n") == 0) || (strcmp(y,"n\n") == 0))
                                                {
                                                    printf ("Thank you for using babyQuery\n");
                                                    return(0);
                                                }
                                    }
                                }
                                    else if (i < 200 && (strcmp(name, data.femaleName[i]) != 0) && (strcmp(name, data.maleName[i]) != 0))
                                    {
                                        i++;
                                    }
                                        else
                                        {
                                            printf ("In %d, the female name %s is not ranked and the male name %s is not ranked.\n", year1, name, name);
                                            i = 201;
                                            c = 1;
                                            while (c)
                                            {
                                            printf ("Do you want to ask another question about %d? [Y or N]\n", year1);
                                            fgets (y, 5, stdin);
                                            if ((strcmp(y,"Y\n") == 0) || (strcmp(y,"y\n") == 0) || (strcmp(y,"N\n") == 0) || (strcmp(y,"n\n") == 0))
                                            {
                                                c = 0;
                                            }
                                            else
                                            {
                                                printf ("Only the single characters Y or N are acceptable.\n");
                                            }
                                            }
                                            if ((strcmp(y,"Y\n") == 0) || (strcmp(y,"y\n") == 0))
                                            {
                                                b = 0;
                                            }
                                            if ((strcmp(y,"N\n") == 0) || (strcmp(y,"n\n") == 0))
                                            {
                                                c = 1;
                                                while (c)
                                                {
                                                printf ("Would you like to select another year? [Y or N]\n");
                                                fgets (y, 5, stdin);
                                                    if ((strcmp(y,"Y\n") == 0) || (strcmp(y,"y\n") == 0) || (strcmp(y,"N\n") == 0) || (strcmp(y,"n\n") == 0))
                                                    {
                                                        c = 0;
                                                    }
                                                    else
                                                    {
                                                        printf ("Only the single characters Y or N are acceptable.\n");
                                                    }
                                                }
                                                        if ((strcmp(y,"Y\n") == 0) || (strcmp(y,"y\n") == 0))
                                                        {
                                                            a = 0;
                                                        }
                                                        if ((strcmp(y,"N\n") == 0) || (strcmp(y,"n\n") == 0))
                                                        {
                                                            printf ("Thank you for using babyQuery\n");
                                                            return(0);
                                                        }
                                            }
                                        }
                }
            }
    }

        else if ((strcmp(path,"top") == 0))
        {
            i = 0;
            while (i < 10)
            {
                printf ("%-4d %-12s %-10d %-12s %-12d\n", data.rank[i], data.maleName[i], data.maleNumber[i], data.femaleName[i], data.femaleNumber[i]);
                i++;
            }
            c = 1;
            while (c)
            {
            printf ("Do you want to ask another question about %d? [Y or N]\n", year1);
            fgets (y, 5, stdin);
            if ((strcmp(y,"Y\n") == 0) || (strcmp(y,"y\n") == 0) || (strcmp(y,"N\n") == 0) || (strcmp(y,"n\n") == 0))
            {
                c = 0;
            }
            else
            {
                printf ("Only the single characters Y or N are acceptable.\n");
            }
            }
            if ((strcmp(y,"Y\n") == 0) || (strcmp(y,"y\n") == 0))
            {
                b = 0;
            }
            if ((strcmp(y,"N\n") == 0) || (strcmp(y,"n\n") == 0))
            {
                c = 1;
                while (c)
                {
                printf ("Would you like to select another year? [Y or N]\n");
                fgets (y, 5, stdin);
                    if ((strcmp(y,"Y\n") == 0) || (strcmp(y,"y\n") == 0) || (strcmp(y,"N\n") == 0) || (strcmp(y,"n\n") == 0))
                    {
                        c = 0;
                    }
                    else
                    {
                        printf ("Only the single characters Y or N are acceptable.\n");
                    }
                }
                        if ((strcmp(y,"Y\n") == 0) || (strcmp(y,"y\n") == 0))
                        {
                            a = 0;
                        }
                        if ((strcmp(y,"N\n") == 0) || (strcmp(y,"n\n") == 0))
                        {
                            printf ("Thank you for using babyQuery\n");
                            return(0);
                        }
            }
        }
    }
}
return (0);
}
