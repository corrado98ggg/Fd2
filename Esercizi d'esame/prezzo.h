#ifndef PREZZO_H
#define PREZZO_H

#include <stdint.h>

struct Articolo {
    char* nome;
    int prezzo;
};

extern void TrovaArticoli(const struct Articolo* a, size_t a_size, int sum);

#endif // !PREZZO_H
