#include <stdlib.h>
#include <stdio.h>


typedef struct {
    int profit;
    int duration;
    int deadline;
}job;


int ScheduleJobsRec(const job* v, size_t j_size, int* appetibilita, size_t size, int profitto) {


    //caso base:
    if (j_size == 0) {
        return profitto;
    }

    int t = 0;
    int v_max = appetibilita[0];
    int index = 0;

    int tmp = 0;

    for (size_t i = 0; i < size; i++) {
        if (size == 1) {
            index = 1;
        }
        if (v_max < appetibilita[i]) {
            v_max = appetibilita[i];
            index = i;
        }
    }

    t = t + v[index].duration;

    if (t < v[index].deadline && t != 0 ) {
        printf("%d ", index);
        profitto = profitto + v[index].profit;

        if (size != 1) {
            tmp = appetibilita[size - 1];
            appetibilita[size - 1] = v_max;

            appetibilita[index] = tmp;

            realloc(appetibilita, sizeof(int) * j_size - 1);
        }
    }

    ScheduleJobsRec(v, j_size - 1, appetibilita, size - 1, profitto);

}

int ScheduleJobs(const job* v, size_t j_size) {

    int* appetibilita = malloc(sizeof(int) * j_size);
    int* appetibilita_temp = calloc(j_size, sizeof(int));

    for (int i = 0; i < j_size; i++) {
        appetibilita[i] = v[i].profit / v[i].duration;
    }

    int* cnt = 0;

    return ScheduleJobsRec(v, j_size, appetibilita, j_size, 0);
}


/*
int main() {


    job* primo = malloc(sizeof(job));
    primo->duration = 2;
    primo->profit = 80;
    primo->deadline = 4;


    job* secondo = malloc(sizeof(job));
    secondo->duration = 5;
    secondo->profit = 100;
    secondo->deadline = 6;

    job* terzo = malloc(sizeof(job));
    terzo->duration = 1;
    terzo->profit = 30;
    terzo->deadline = 3;

    job* v = malloc(sizeof(job) * 3);
    v[0] = *primo;
    v[1] = *secondo;
    v[2] = *terzo;

    return ScheduleJobs(v, 3);

}*/