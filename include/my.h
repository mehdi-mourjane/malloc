/*
** EPITECH PROJECT, 2021
** malloc
** File description:
** my
*/

#ifndef MY_H
#define MY_H

#include <unistd.h>
#include <stdint.h>
#include <string.h>
#include <stdio.h>

#define false 0
#define true 1

typedef struct node_s node_t;
struct node_s {
    node_t *next;
    void *addr;
    int taken;
    size_t size;
};

static node_t *node = NULL;

void *reallocarray(void *addr, size_t nmeb, size_t size);
void *realloc(void *, size_t);
void *calloc(size_t, size_t);
void *malloc(size_t);
void free(void *);

void *find_best_chunk(size_t size);
void *add_in_list(size_t size);
node_t *get_from_ptr(void *addr);

#endif