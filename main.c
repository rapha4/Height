#include <stdio.h>
#include <stdlib.h>

void clear_input() {
    char c;
    while ((c = getchar()) != '\n' && c !=  EOF) {}
}

void read_text(char *buffer, int lenght) {
    fgets(buffer, lenght, stdin);
    strtok(buffer, "\n");
}

int main() {

    /** Declaring the constants, variables and arrays **/
    int n;
    double averageheight, percentage;

    printf("How many people will be inserted? ");
    scanf("%d", &n);

    char names[n][50];
    int ages[n];
    double heights[n];


    /** Reading input **/
    for (int i = 0; i < n; i++) {
        printf("Insert the name of the person number %d.\n", i+1);
        printf("Name: ");
        clear_input();
        read_text(names[i], 50);
        printf("Age: ");
        scanf("%d", &ages[i]);
        printf("Height: ");
        scanf("%lf", &heights[i]);
    }


    /** Calculating the average height of the people **/
    averageheight = 0;
    for (int i = 0; i < n; i++) {
        averageheight = averageheight + heights[i];
    }
    averageheight = averageheight/n;


    /** Calculating the percentage of people who are below 16y old**/
    percentage = 0;
    for (int i = 0; i < n; i++) {
        if (ages[i] < 16) {
            percentage = percentage + 1;
        }
    }
    percentage = percentage*100/n;


    /** Output **/
    printf("\nAltura media = %.2lf\n", averageheight);
    printf("Pessoas com menos de 16 anos = %.1lf %%\n", percentage);
    for (int i = 0; i < n; i++) {
        if (ages[i] < 16) {
            printf("%s\n", names[i]);
        }
    }

    return 0;
}
