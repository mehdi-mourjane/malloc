/*
** EPITECH PROJECT, 2021
** alloc
** File description:
** alloc
*/

#include "../include/my.h"

void *malloc(size_t size)
{
    void *tmp = NULL;

    if (size == 0)
        return NULL;
    if ((tmp = find_best_chunk(size)) == NULL)
        tmp = add_in_list(size);
    return tmp;
}

void free(void *addr)
{
    node_t *curr = NULL;

    if ((curr = get_from_ptr(addr)) != NULL) {
        curr->taken = false;
        memset(curr->addr, 0, curr->size);
        return;
    }
    write(2, "free(): invalid pointer\n", 24);
}

void *realloc(void *addr, size_t size)
{
    node_t *currblock = get_from_ptr(addr);
    void *tmpcontent;

    if (size == 0 && addr) {
        free(addr);
        return NULL;
    }
    if (size == 0 && !addr)
        return NULL;
    if (!addr && size > 0)
        return malloc(size);
    if (currblock && currblock->size <= size) {
        tmpcontent = malloc(size);
        memcpy(tmpcontent, addr, currblock->size);
        free(addr);
        return tmpcontent;
    }
    if (currblock && currblock->size >= size)
        return currblock->addr;
    return NULL;
}

void *calloc(size_t nmeb, size_t size)
{
    void *tmp = NULL;

    size *= nmeb;
    tmp = malloc(size);
    memset(tmp, 0, size);
    return tmp;
}

void *reallocarray(void *addr, size_t nmeb,size_t size)
{
    node_t *currblock = get_from_ptr(addr);
    void *tmpcontent;

    if ((nmeb == 0 || size == 0) && addr) {
        free(addr);
        return NULL;
    }
    if ((size == 0 || nmeb == 0) && !addr)
        return NULL;
    if (!addr && size > 0)
        return calloc(nmeb, size);
    if (currblock && currblock->size <= size) {
        tmpcontent = calloc(nmeb, size);
        memcpy(tmpcontent, addr, currblock->size);
        free(addr);
        return tmpcontent;
    }
    if (currblock && currblock->size >= size)
        return currblock->addr;
    return NULL;
}