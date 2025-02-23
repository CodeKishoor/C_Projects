#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

struct teamA
{
    char name[20];
    int run;
    int ball;
    int wic;
} a[11];

struct teamB
{
    char name[20];
    int run;
    int ball;
    int wic;
} b[11];

void touppercase(char str[])
{
    for (int i = 0; str[i] != '\0'; i++)
    {
        if (isalpha(str[i]))
        {
            str[i] = toupper(str[i]);
        }
    }
}

int result(int tot1, int tot2, char teamA[], char teamB[])
{
    if (tot1 > tot2)
    {
        printf("\n%s won the game", teamA);
    }
    else if (tot2 > tot1)
    {
        printf("\n%s won the game", teamB);
    }
    else
    {
        printf("\nMatch gets Draw");
    }
}

void main()
{
    char teamA[20], teamB[20], str[20], nostr[20], bow[20], temp[20], crun[10], toss[20];
    int over, run = 0, r1 = 0, r2 = 0, b1 = 0, b2 = 0, tot1 = 0, tot2 = 0, s1 = 0, s2 = 0, out = 0, awic = 0, bwic = 0, pl;
    int t1 = 0, t2 = 0, t, c1 = 0, c2 = 0, game_over = 0, game_over2 = 0, p = 0, d1 = 0, d2 = 0, g1 = 0, g2 = 0;

    for (int i = 0; i < 11; i++)
    {
        strcpy(a[i].name, "N/A");
        a[i].run = 0;
        a[i].ball = 0;
        a[i].wic = 0;
    }

    for (int i = 0; i < 11; i++)
    {
        strcpy(b[i].name, "N/A");
        b[i].run = 0;
        b[i].ball = 0;
        b[i].wic = 0;
    }
    printf("\nHow many players in each team : ");
    scanf("%d", &pl);

    system("cls");
    printf("\nEnter Team A: ");
    scanf(" %[^\n]s", teamA);
    printf("\nEnter Team B: ");
    scanf(" %[^\n]s", teamB);

    printf("\nEnter Team A Player Names:");
    for (int i = 0; i < pl; i++)
    {
        printf("\nEnter player %d: ", i + 1);
        scanf(" %[^\n]s", a[i].name);
    }

    system("cls");
    printf("\nEnter Team B Player Names:");
    for (int i = 0; i < pl; i++)
    {
        printf("\nEnter player %d: ", i + 1);
        scanf(" %[^\n]s", b[i].name);
    }

    system("cls");
    printf("\nTeam A: %s", teamA);
    for (int i = 0; i < pl; i++)
    {
        printf("\nPlayer %s", a[i].name);
    }

    printf("\nTeam B: %s", teamB);
    for (int i = 0; i < pl; i++)
    {
        printf("\nPlayer %s", b[i].name);
    }

    printf("\nEnter No. of Overs: ");
    scanf("%d", &over);

    printf("\nToss Result (won)if Team A wins type teama: ");
    scanf(" %s", toss);
    touppercase(toss);

    if (strcmp(toss, "TEAMA") == 0)
    {
        t1 = 1;
    }
    else if (strcmp(toss, "TEAMB") == 0)
    {
        t2 = 1;
    }
    else
    {
        printf("\nInvalid toss result.\n");
        return;
    }

    if (t1 == 1)
    {
        printf("\nTeam A won the toss: ");
        printf("\n1 for Bat, 2 for Bowl: ");
        scanf("%d", &t);
        if (t == 1)
        {
            d1 = 1;
        }
        else
        {
            d2 = 1;
        }
    }
    else if (t2 == 1)
    {
        printf("\nTeam B won the toss: ");
        printf("\n1 for Bat, 2 for Bowl: ");
        scanf("%d", &t);
        if (t == 1)
        {
            d2 = 1;
        }
        else
        {
            d1 = 1;
        }
    }

    if (d1 == 1)
    {

        while (c1 != 1 && p < pl)
        {
            printf("\nTeam A starts batting...\n");
            printf("\nEnter Striker: ");
            scanf(" %[^\n]s", str);
            for (int i = 0; i < pl; i++)
            {
                if (strcmp(str, a[i].name) == 0)
                {
                    c1 = 1;
                    break;
                }
            }
            if (!c1)
            {
                printf("\nPlayer not found, try again\n");
            }
        }
        c1 = 0;

        while (c2 != 1 && p < pl)
        {
            printf("\nEnter Non-Striker: ");
            scanf(" %[^\n]s", nostr);
            for (int i = 0; i < pl; i++)
            {
                if (strcmp(nostr, a[i].name) == 0)
                {
                    c2 = 1;
                    break;
                }
            }
            if (!c2)
            {
                printf("\nPlayer not found, try again\n");
            }
        }
        c2 = 0;
        p = 0;

        for (int i = 0; i < over && !game_over; i++)
        {
            while (c1 != 1 && p < pl)
            {
                printf("\nEnter Bowler: ");
                scanf(" %[^\n]s", bow);
                for (int i = 0; i < pl; i++)
                {
                    if (strcmp(bow, b[i].name) == 0)
                    {
                        c1 = 1;
                        break;
                    }
                }
                if (!c1)
                {
                    printf("\nPlayer not found, try again\n");
                }
            }
            p = 0;
            c1 = 0;

            for (int j = 1; j <= 6 && !game_over; j++)
            {
                printf("\nOver %d.%d", i, j);
                printf("\nEnter run: ");
                scanf(" %s", crun);

                if (strcmp(crun, "o") == 0)
                {
                    if (s1 >= pl)
                    {
                        printf("\nCannot add more players.\n");
                        break;
                    }
                    while (c1 != 1 && p < pl)
                    {
                        for (int i = 0; i < pl; i++)
                        {
                            if (strcmp(str, a[i].name) == 0)
                            {
                                c1 = 1;
                                a[i].run = r1;
                                a[i].ball = b1;
                                break;
                            }
                        }
                    }
                    p = 0;
                    c1 = 0;

                    while (c1 != 1 && p < pl)
                    {
                        for (int i = 0; i < pl; i++)
                        {
                            if (strcmp(nostr, a[i].name) == 0)
                            {
                                c1 = 1;
                                a[i].run = r2;
                                a[i].ball = b2;
                                break;
                            }
                        }
                    }
                    p = 0;
                    c1 = 0;

                    while (c1 != 1 && p < pl)
                    {
                        for (int i = 0; i < pl; i++)
                        {
                            if (strcmp(bow, b[i].name) == 0)
                            {
                                c1 = 1;
                                b[i].wic += 1;
                                break;
                            }
                        }
                    }
                    p = 0;
                    c1 = 0;

                    out++;
                    if (out == pl - 1)
                    {
                        game_over = 1;
                        break;
                    }

                    while (c1 != 1 && p < pl)
                    {
                        printf("\nEnter new Striker: ");
                        scanf(" %[^\n]s", str);
                        for (int i = 0; i < pl; i++)
                        {
                            if (strcmp(str, a[i].name) == 0)
                            {
                                c1 = 1;
                                break;
                            }
                        }
                        if (!c1)
                        {
                            printf("\nPlayer not found, try again\n");
                        }
                    }
                    p = 0;
                    c1 = 0;
                    b1 = 0, r1 = 0;
                }
                else if (strcmp(crun, "w") == 0)
                {
                    j--;
                    tot1++;
                }
                else if (crun[0] == 'n')
                {
                    j--;
                    run = atoi(&crun[1]);
                    r1 += run;
                    tot1 += run + 1;
                }
                else if (isdigit(crun[0]))
                {
                    run = atoi(crun);
                    if (run % 2 == 0)
                    {
                        r1 += run;
                        tot1 += run;
                        b1++;
                    }
                    else
                    {
                        r1 += run;
                        tot1 += run;
                        b1++;
                        strcpy(temp, str);
                        strcpy(str, nostr);
                        strcpy(nostr, temp);
                        t1 = b1;
                        b1 = b2;
                        b2 = t1;
                        t2 = r1;
                        r1 = r2;
                        r2 = t2;
                    }
                }
                else
                {
                    printf("\nInvalid input. Try again.");
                    j--;
                }

                printf("\nStriker: %s %d[%d]", str, r1, b1);
                printf("\nNon-Striker: %s %d[%d]", nostr, r2, b2);
                printf("\nScore: %d", tot1);
            }

            strcpy(temp, str);
            strcpy(str, nostr);
            strcpy(nostr, temp);
            t1 = b1;
            b1 = b2;
            b2 = t1;
            t2 = r1;
            r1 = r2;
            r2 = t2;
        }

        for (int i = 0; i < pl; i++)
        {
            bwic += b[i].wic;
        }
        out = 0;
        g1 = 1;

        if (g1 == 1)
        {
            if (game_over)
            {
                printf("\nGame Over\n");
                while (c1 != 1 && p < pl)
                {
                    for (int i = 0; i < pl; i++)
                    {
                        if (strcmp(str, a[i].name) == 0)
                        {
                            c1 = 1;
                            a[i].run = r1;
                            a[i].ball = b1;
                            break;
                        }
                    }
                }
                p = 0;
                c1 = 0;

                while (c1 != 1 && p < pl)
                {
                    for (int i = 0; i < pl; i++)
                    {
                        if (strcmp(nostr, a[i].name) == 0)
                        {
                            c1 = 1;
                            a[i].run = r2;
                            a[i].ball = b2;
                            break;
                        }
                    }
                }
                p = 0;
                c1 = 0;
                printf("\nName             runs[balls]");
                for (int i = 0; i < pl; i++)
                {
                    if (strlen(a[i].name) > 0)
                    {
                        printf("\n%-20s %d[%d] %-70d", a[i].name, a[i].run, a[i].ball, a[i].wic);
                    }
                }
            }
            else
            {
                printf("\nName             runs[balls]");
                while (c1 != 1 && p < pl)
                {
                    for (int i = 0; i < pl; i++)
                    {
                        if (strcmp(str, a[i].name) == 0)
                        {
                            c1 = 1;
                            a[i].run = r1;
                            a[i].ball = b1;
                            break;
                        }
                    }
                }
                p = 0;
                c1 = 0;

                while (c1 != 1 && p < pl)
                {
                    for (int i = 0; i < pl; i++)
                    {
                        if (strcmp(nostr, a[i].name) == 0)
                        {
                            c1 = 1;
                            a[i].run = r2;
                            a[i].ball = b2;
                            break;
                        }
                    }
                }
                p = 0;
                c1 = 0;
                for (int i = 0; i < pl; i++)
                {
                    if (strlen(a[i].name) > 0)
                    {
                        printf("\n%-20s %d[%d] %-70d", a[i].name, a[i].run, a[i].ball, a[i].wic);
                    }
                }
            }
        }
        r1 = 0, r2 = 0, b1 = 0, b2 = 0;

        printf("\nTeam A %s Scored %d/%d", teamA, tot1, bwic);

        printf("\nTeam B starts batting...\n");

        while (c1 != 1 && p < pl)
        {
            printf("\nEnter Striker: ");
            scanf(" %[^\n]s", str);
            for (int i = 0; i < pl; i++)
            {
                if (strcmp(str, b[i].name) == 0)
                {
                    c1 = 1;
                    break;
                }
            }
            if (!c1)
            {
                printf("\nPlayer not found, try again\n");
            }
        }
        c1 = 0;

        while (c2 != 1 && p < pl)
        {
            printf("\nEnter Non-Striker: ");
            scanf(" %[^\n]s", nostr);
            for (int i = 0; i < pl; i++)
            {
                if (strcmp(nostr, b[i].name) == 0)
                {
                    c2 = 1;
                    break;
                }
            }
            if (!c2)
            {
                printf("\nPlayer not found, try again\n");
            }
        }
        c2 = 0;
        p = 0;

        for (int i = 0; i < over && !game_over2; i++)
        {
            while (c1 != 1 && p < pl)
            {
                printf("\nEnter Bowler: ");
                scanf(" %[^\n]s", bow);
                for (int i = 0; i < pl; i++)
                {
                    if (strcmp(bow, a[i].name) == 0)
                    {
                        c1 = 1;
                        break;
                    }
                }
                if (!c1)
                {
                    printf("\nPlayer not found, try again\n");
                }
            }
            p = 0;
            c1 = 0;

            for (int j = 1; j <= 6 && !game_over2; j++)
            {
                if (tot2 > tot1)
                {
                    game_over2 = 1;
                    break;
                }
                printf("\nOver %d.%d", i, j);
                printf("\nEnter run: ");
                scanf(" %s", crun);
                if (strcmp(crun, "o") == 0)
                {
                    if (s1 >= pl)
                    {
                        printf("\nCannot add more players.\n");
                        break;
                    }
                    while (c1 != 1 && p < pl)
                    {
                        for (int i = 0; i < pl; i++)
                        {
                            if (strcmp(str, b[i].name) == 0)
                            {
                                c1 = 1;
                                b[i].run = r1;
                                b[i].ball = b1;
                                break;
                            }
                        }
                    }
                    p = 0;
                    c1 = 0;

                    while (c1 != 1 && p < pl)
                    {
                        for (int i = 0; i < pl; i++)
                        {
                            if (strcmp(nostr, b[i].name) == 0)
                            {
                                c1 = 1;
                                b[i].run = r2;
                                b[i].ball = b2;
                                break;
                            }
                        }
                    }
                    p = 0;
                    c1 = 0;

                    while (c1 != 1 && p < pl)
                    {
                        for (int i = 0; i < pl; i++)
                        {
                            if (strcmp(bow, a[i].name) == 0)
                            {
                                c1 = 1;
                                a[i].wic += 1;
                                break;
                            }
                        }
                    }
                    p = 0;
                    c1 = 0;
                    out++;
                    if (out == pl - 1)
                    {
                        game_over2 = 1;
                        break;
                    }

                    while (c1 != 1 && p < pl)
                    {
                        printf("\nEnter new Striker: ");
                        scanf(" %[^\n]s", str);
                        for (int i = 0; i < pl; i++)
                        {
                            if (strcmp(str, b[i].name) == 0)
                            {
                                c1 = 1;
                                break;
                            }
                        }
                        if (!c1)
                        {
                            printf("\nPlayer not found, try again\n");
                        }
                    }
                    p = 0;
                    c1 = 0;
                    b1 = 0, r1 = 0;
                }
                else if (strcmp(crun, "w") == 0)
                {
                    j--;
                    tot2++;
                }
                else if (crun[0] == 'n')
                {
                    j--;
                    run = atoi(&crun[1]);
                    r1 += run;
                    tot2 += run + 1;
                }
                else if (isdigit(crun[0]))
                {
                    run = atoi(crun);
                    if (run % 2 == 0)
                    {
                        r1 += run;
                        tot2 += run;
                        b1++;
                    }
                    else
                    {
                        r1 += run;
                        tot2 += run;
                        b1++;
                        strcpy(temp, str);
                        strcpy(str, nostr);
                        strcpy(nostr, temp);
                        t1 = b1;
                        b1 = b2;
                        b2 = t1;
                        t2 = r1;
                        r1 = r2;
                        r2 = t2;
                    }
                }
                else
                {
                    printf("\nInvalid input. Try again.");
                    j--;
                }

                printf("\nStriker: %s %d[%d]", str, r1, b1);
                printf("\nNon-Striker: %s %d[%d]", nostr, r2, b2);
                printf("\nScore: %d", tot2);
            }

            strcpy(temp, str);
            strcpy(str, nostr);
            strcpy(nostr, temp);
            t1 = b1;
            b1 = b2;
            b2 = t1;
            t2 = r1;
            r1 = r2;
            r2 = t2;
        }

        for (int i = 0; i < pl; i++)
        {
            awic += a[i].wic;
        }

        g2 = 1;

        if (g2 == 1)
        {
            if (game_over2)
            {
                printf("\nGame Over\n");
                while (c1 != 1 && p < pl)
                {
                    for (int i = 0; i < pl; i++)
                    {
                        if (strcmp(str, b[i].name) == 0)
                        {
                            c1 = 1;
                            b[i].run = r1;
                            b[i].ball = b1;
                            break;
                        }
                    }
                }
                p = 0;
                c1 = 0;

                while (c1 != 1 && p < pl)
                {
                    for (int i = 0; i < pl; i++)
                    {
                        if (strcmp(nostr, b[i].name) == 0)
                        {
                            c1 = 1;
                            b[i].run = r2;
                            b[i].ball = b2;
                            break;
                        }
                    }
                }
                p = 0;
                c1 = 0;
                printf("\nName             runs[balls]    wic");
                for (int i = 0; i < pl; i++)
                {
                    if (strlen(b[i].name) > 0)
                    {
                        printf("\n%-20s %d[%d] %-70d", b[i].name, b[i].run, b[i].ball, b[i].wic);
                    }
                }
            }
            else
            {
                printf("\nName             runs[balls]    wic");
                while (c1 != 1 && p < pl)
                {
                    for (int i = 0; i < pl; i++)
                    {
                        if (strcmp(str, b[i].name) == 0)
                        {
                            c1 = 1;
                            b[i].run = r1;
                            b[i].ball = b1;
                            break;
                        }
                    }
                }
                p = 0;
                c1 = 0;

                while (c1 != 1 && p < pl)
                {
                    for (int i = 0; i < pl; i++)
                    {
                        if (strcmp(nostr, b[i].name) == 0)
                        {
                            c1 = 1;
                            b[i].run = r2;
                            b[i].ball = b2;
                            break;
                        }
                    }
                }
                p = 0;
                c1 = 0;
                for (int i = 0; i < pl; i++)
                {
                    if (strlen(b[i].name) > 0)
                    {
                        printf("\n%-20s %d[%d] %-70d", b[i].name, b[i].run, b[i].ball, b[i].wic);
                    }
                }
            }
        }

        printf("\nTeam B %s Scored %d/%d", teamB, tot2, awic);
        result(tot1, tot2, teamA, teamB);
    }

    if (d2 == 1)
    {
        printf("\nTeam B starts Batting\n");
        while (c1 != 1 && p < pl)
        {
            printf("\nEnter Striker: ");
            scanf(" %[^\n]s", str);
            for (int i = 0; i < pl; i++)
            {
                if (strcmp(str, b[i].name) == 0)
                {
                    c1 = 1;
                    break;
                }
            }
            if (!c1)
            {
                printf("\nPlayer not found, try again\n");
            }
        }
        c1 = 0;

        while (c2 != 1 && p < pl)
        {
            printf("\nEnter Non-Striker: ");
            scanf(" %[^\n]s", nostr);
            for (int i = 0; i < pl; i++)
            {
                if (strcmp(nostr, b[i].name) == 0)
                {
                    c2 = 1;
                    break;
                }
            }
            if (!c2)
            {
                printf("\nPlayer not found, try again\n");
            }
        }
        c2 = 0;
        p = 0;

        for (int i = 0; i < over && !game_over2; i++)
        {
            while (c1 != 1 && p < pl)
            {
                printf("\nEnter Bowler: ");
                scanf(" %[^\n]s", bow);
                for (int i = 0; i < pl; i++)
                {
                    if (strcmp(bow, a[i].name) == 0)
                    {
                        c1 = 1;
                        break;
                    }
                }
                if (!c1)
                {
                    printf("\nPlayer not found, try again\n");
                }
            }
            p = 0;
            c1 = 0;

            for (int j = 1; j <= 6 && !game_over2; j++)
            {
                printf("\nOver %d.%d", i, j);
                printf("\nEnter run: ");
                scanf(" %s", crun);

                if (strcmp(crun, "o") == 0)
                {
                    if (s1 >= pl)
                    {
                        printf("\nCannot add more players.\n");
                        break;
                    }
                    while (c1 != 1 && p < pl)
                    {
                        for (int i = 0; i < pl; i++)
                        {
                            if (strcmp(str, b[i].name) == 0)
                            {
                                c1 = 1;
                                b[i].run = r1;
                                b[i].ball = b1;
                                break;
                            }
                        }
                    }
                    p = 0;
                    c1 = 0;

                    while (c1 != 1 && p < pl)
                    {
                        for (int i = 0; i < pl; i++)
                        {
                            if (strcmp(nostr, b[i].name) == 0)
                            {
                                c1 = 1;
                                b[i].run = r2;
                                b[i].ball = b2;
                                break;
                            }
                        }
                    }
                    p = 0;
                    c1 = 0;

                    while (c1 != 1 && p < pl)
                    {
                        for (int i = 0; i < pl; i++)
                        {
                            if (strcmp(bow, a[i].name) == 0)
                            {
                                c1 = 1;
                                a[i].wic += 1;
                                break;
                            }
                        }
                    }
                    p = 0;
                    c1 = 0;

                    out++;
                    if (out == pl - 1)
                    {
                        game_over2 = 1;
                        break;
                    }

                    while (c1 != 1 && p < pl)
                    {
                        printf("\nEnter new Striker: ");
                        scanf(" %[^\n]s", str);
                        for (int i = 0; i < pl; i++)
                        {
                            if (strcmp(str, b[i].name) == 0)
                            {
                                c1 = 1;
                                break;
                            }
                        }
                        if (!c1)
                        {
                            printf("\nPlayer not found, try again\n");
                        }
                    }
                    p = 0;
                    c1 = 0;
                    b1 = 0, r1 = 0;
                }
                else if (strcmp(crun, "w") == 0)
                {
                    j--;
                    tot2++;
                }
                else if (crun[0] == 'n')
                {
                    j--;
                    run = atoi(&crun[1]);
                    r1 += run;
                    tot2 += run + 1;
                }
                else if (isdigit(crun[0]))
                {
                    run = atoi(crun);
                    if (run % 2 == 0)
                    {
                        r1 += run;
                        tot2 += run;
                        b1++;
                    }
                    else
                    {
                        r1 += run;
                        tot2 += run;
                        b1++;
                        strcpy(temp, str);
                        strcpy(str, nostr);
                        strcpy(nostr, temp);
                        t1 = b1;
                        b1 = b2;
                        b2 = t1;
                        t2 = r1;
                        r1 = r2;
                        r2 = t2;
                    }
                }
                else
                {
                    printf("\nInvalid input. Try again.");
                    j--;
                }

                printf("\nStriker: %s %d[%d]", str, r1, b1);
                printf("\nNon-Striker: %s %d[%d]", nostr, r2, b2);
                printf("\nScore: %d", tot2);
            }

            strcpy(temp, str);
            strcpy(str, nostr);
            strcpy(nostr, temp);
            t1 = b1;
            b1 = b2;
            b2 = t1;
            t2 = r1;
            r1 = r2;
            r2 = t2;
        }

        for (int i = 0; i < pl; i++)
        {
            awic += a[i].wic;
        }

        g2 = 1;

        if (g2 == 1)
        {
            if (game_over2)
            {
                printf("\nGame Over\n");
                while (c1 != 1 && p < pl)
                {
                    for (int i = 0; i < pl; i++)
                    {
                        if (strcmp(str, b[i].name) == 0)
                        {
                            c1 = 1;
                            b[i].run = r1;
                            b[i].ball = b1;
                            break;
                        }
                    }
                }
                p = 0;
                c1 = 0;

                while (c1 != 1 && p < pl)
                {
                    for (int i = 0; i < pl; i++)
                    {
                        if (strcmp(nostr, b[i].name) == 0)
                        {
                            c1 = 1;
                            b[i].run = r2;
                            b[i].ball = b2;
                            break;
                        }
                    }
                }
                p = 0;
                c1 = 0;
                printf("\nName             runs[balls]    wic");
                for (int i = 0; i < pl; i++)
                {
                    if (strlen(b[i].name) > 0)
                    {
                        printf("\n%-20s %d[%d] %-70d", b[i].name, b[i].run, b[i].ball, b[i].wic);
                    }
                }
            }
            else
            {
                printf("\nName             runs[balls]    wic");
                while (c1 != 1 && p < pl)
                {
                    for (int i = 0; i < pl; i++)
                    {
                        if (strcmp(str, b[i].name) == 0)
                        {
                            c1 = 1;
                            b[i].run = r1;
                            b[i].ball = b1;
                            break;
                        }
                    }
                }
                p = 0;
                c1 = 0;

                while (c1 != 1 && p < pl)
                {
                    for (int i = 0; i < pl; i++)
                    {
                        if (strcmp(nostr, b[i].name) == 0)
                        {
                            c1 = 1;
                            b[i].run = r2;
                            b[i].ball = b2;
                            break;
                        }
                    }
                }
                p = 0;
                c1 = 0;
                for (int i = 0; i < pl; i++)
                {
                    if (strlen(b[i].name) > 0)
                    {
                        printf("\n%-20s %d[%d] %-70d", b[i].name, b[i].run, b[i].ball, b[i].wic);
                    }
                }
            }
        }

        r1 = 0, r2 = 0, b1 = 0, b2 = 0;

        printf("\nTeam B %s Scored %d/%d", teamB, tot2, awic);
        out = 0;

        for (int i = 0; i < pl; i++)
        {
            a[i].run = 0;
            a[i].ball = 0;
        }

        printf("\nTeam A starts batting\n");

        while (c1 != 1 && p < pl)
        {
            printf("\nEnter Striker: ");
            scanf(" %[^\n]s", str);
            for (int i = 0; i < pl; i++)
            {
                if (strcmp(str, a[i].name) == 0)
                {
                    c1 = 1;
                    break;
                }
            }
            if (!c1)
            {
                printf("\nPlayer not found, try again\n");
            }
        }
        c1 = 0;

        while (c2 != 1 && p < pl)
        {
            printf("\nEnter Non-Striker: ");
            scanf(" %[^\n]s", nostr);
            for (int i = 0; i < pl; i++)
            {
                if (strcmp(nostr, a[i].name) == 0)
                {
                    c2 = 1;
                    break;
                }
            }
            if (!c2)
            {
                printf("\nPlayer not found, try again\n");
            }
        }
        c2 = 0;
        p = 0;

        for (int i = 0; i < over && !game_over; i++)
        {
            while (c1 != 1 && p < pl)
            {
                printf("\nEnter Bowler: ");
                scanf(" %[^\n]s", bow);
                for (int i = 0; i < pl; i++)
                {
                    if (strcmp(bow, b[i].name) == 0)
                    {
                        c1 = 1;
                        break;
                    }
                }
                if (!c1)
                {
                    printf("\nPlayer not found, try again\n");
                }
            }
            p = 0;
            c1 = 0;

            for (int j = 1; j <= 6 && !game_over; j++)
            {
                if (tot1 > tot2)
                {
                    game_over = 1;
                    break;
                }
                printf("\nOver %d.%d", i, j);
                printf("\nEnter run: ");
                scanf(" %s", crun);

                if (strcmp(crun, "o") == 0)
                {
                    if (s1 >= pl)
                    {
                        printf("\nCannot add more players.\n");
                        break;
                    }
                    while (c1 != 1 && p < pl)
                    {
                        for (int i = 0; i < pl; i++)
                        {
                            if (strcmp(str, a[i].name) == 0)
                            {
                                c1 = 1;
                                a[i].run = r1;
                                a[i].ball = b1;
                                break;
                            }
                        }
                    }
                    p = 0;
                    c1 = 0;

                    while (c1 != 1 && p < pl)
                    {
                        for (int i = 0; i < pl; i++)
                        {
                            if (strcmp(nostr, a[i].name) == 0)
                            {
                                c1 = 1;
                                a[i].run = r2;
                                a[i].ball = b2;
                                break;
                            }
                        }
                    }
                    p = 0;
                    c1 = 0;

                    while (c1 != 1 && p < pl)
                    {
                        for (int i = 0; i < pl; i++)
                        {
                            if (strcmp(bow, b[i].name) == 0)
                            {
                                c1 = 1;
                                b[i].wic += 1;
                                break;
                            }
                        }
                    }
                    p = 0;
                    c1 = 0;

                    out++;
                    if (out == pl - 1)
                    {
                        game_over = 1;
                        break;
                    }

                    while (c1 != 1 && p < pl)
                    {
                        printf("\nEnter new Striker: ");
                        scanf(" %[^\n]s", str);
                        for (int i = 0; i < pl; i++)
                        {
                            if (strcmp(str, a[i].name) == 0)
                            {
                                c1 = 1;
                                break;
                            }
                        }
                        if (!c1)
                        {
                            printf("\nPlayer not found, try again\n");
                        }
                    }
                    p = 0;
                    c1 = 0;
                    b1 = 0, r1 = 0;
                }
                else if (strcmp(crun, "w") == 0)
                {
                    j--;
                    tot1++;
                }
                else if (crun[0] == 'n')
                {
                    j--;
                    run = atoi(&crun[1]);
                    r1 += run;
                    tot1 += run + 1;
                }
                else if (isdigit(crun[0]))
                {
                    run = atoi(crun);
                    if (run % 2 == 0)
                    {
                        r1 += run;
                        tot1 += run;
                        b1++;
                    }
                    else
                    {
                        r1 += run;
                        tot1 += run;
                        b1++;
                        strcpy(temp, str);
                        strcpy(str, nostr);
                        strcpy(nostr, temp);
                        t1 = b1;
                        b1 = b2;
                        b2 = t1;
                        t2 = r1;
                        r1 = r2;
                        r2 = t2;
                    }
                }
                else
                {
                    printf("\nInvalid input. Try again.");
                    j--;
                }

                printf("\nStriker: %s %d[%d]", str, r1, b1);
                printf("\nNon-Striker: %s %d[%d]", nostr, r2, b2);
                printf("\nScore: %d", tot1);
            }

            strcpy(temp, str);
            strcpy(str, nostr);
            strcpy(nostr, temp);
            t1 = b1;
            b1 = b2;
            b2 = t1;
            t2 = r1;
            r1 = r2;
            r2 = t2;
        }

        for (int i = 0; i < pl; i++)
        {
            bwic += b[i].wic;
        }

        g1 = 1;

        if (g1 == 1)
        {
            if (game_over)
            {
                printf("\nGame Over\n");
                while (c1 != 1 && p < pl)
                {
                    for (int i = 0; i < pl; i++)
                    {
                        if (strcmp(str, a[i].name) == 0)
                        {
                            c1 = 1;
                            a[i].run = r1;
                            a[i].ball = b1;
                            break;
                        }
                    }
                }
                p = 0;
                c1 = 0;

                while (c1 != 1 && p < pl)
                {
                    for (int i = 0; i < pl; i++)
                    {
                        if (strcmp(nostr, a[i].name) == 0)
                        {
                            c1 = 1;
                            a[i].run = r2;
                            a[i].ball = b2;
                            break;
                        }
                    }
                }
                p = 0;
                c1 = 0;
                printf("\nName             runs[balls]");
                for (int i = 0; i < pl; i++)
                {
                    if (strlen(a[i].name) > 0)
                    {
                        printf("\n%-20s %d[%d] %-70d", a[i].name, a[i].run, a[i].ball, a[i].wic);
                    }
                }
            }
            else
            {
                printf("\nName             runs[balls]");
                while (c1 != 1 && p < pl)
                {
                    for (int i = 0; i < pl; i++)
                    {
                        if (strcmp(str, a[i].name) == 0)
                        {
                            c1 = 1;
                            a[i].run = r1;
                            a[i].ball = b1;
                            break;
                        }
                    }
                }
                p = 0;
                c1 = 0;

                while (c1 != 1 && p < pl)
                {
                    for (int i = 0; i < pl; i++)
                    {
                        if (strcmp(nostr, a[i].name) == 0)
                        {
                            c1 = 1;
                            a[i].run = r2;
                            a[i].ball = b2;
                            break;
                        }
                    }
                }
                p = 0;
                c1 = 0;
                for (int i = 0; i < pl; i++)
                {
                    if (strlen(a[i].name) > 0)
                    {
                        printf("\n%-20s %d[%d] %-70d", a[i].name, a[i].run, a[i].ball, a[i].wic);
                    }
                }
            }
        }

        printf("\nTeam A %s Scored %d/%d", teamA, tot1, bwic);
        result(tot1, tot2, teamA, teamB);
    }

    printf("\n+----------------------+------------+------------+------------+\n");
    printf("| %-20s | %-10s | %-10s | %-10s |\n", "Name", "Runs", "Balls", "Wickets");
    printf("+----------------------+------------+------------+------------+\n");

    for (int i = 0; i < pl; i++) {
        printf("| %-20s | %-10d | %-10d | %-10d |\n", a[i].name, a[i].run, a[i].ball, a[i].wic);
    }

    printf("+----------------------+------------+------------+------------+\n");

    printf("+----------------------+------------+------------+------------+\n");
    printf("| %-20s | %-10s | %-10s | %-10s |\n", "Name", "Runs", "Balls", "Wickets");
    printf("+----------------------+------------+------------+------------+\n");

    for (int i = 0; i < pl; i++) {
        printf("| %-20s | %-10d | %-10d | %-10d |\n", b[i].name, b[i].run, b[i].ball, b[i].wic);
    }

    printf("+----------------------+------------+------------+------------+\n");
}