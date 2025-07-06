#include "task3.h"
#define BLOCKS 4

void xoor(unsigned char block1[], unsigned char block2[], size_t block_size) {
    for (int i = 0; i < block_size; i++) {
        block1[i] ^= block2[i];
    }
}

void s_box(unsigned char block[], unsigned char key[], size_t block_size) {
    for (int i = 0; i < block_size; i++) {
        block[i] ^= key[i];
    }
}

void p_box(unsigned char block[], size_t block_size) {
    unsigned char aux[block_size];
    for (int i = 0; i < block_size; i++) {
        aux[i] = block[i];
    }
    for (int i = 0; i < block_size; i++) {
        block[i] = aux[(i * (block_size - 1) + 2) % block_size];
    }
}

void cripteaza_studenti(secretariat *secretariat, void *key, size_t key_len,
                        void *iv, size_t iv_len, char *cale_output) {
    FILE *f = fopen(cale_output, "wb");
    unsigned char *bytes_studenti = (unsigned char *) secretariat->studenti;
    size_t size = secretariat->nr_studenti * sizeof(student);
    size_t block_size = 0;
    if (size % BLOCKS != 0) {
        block_size = size / BLOCKS + 1;
    } else {
        block_size = size / BLOCKS;
    }
    unsigned char block1[block_size];
    unsigned char block2[block_size];
    unsigned char block3[block_size];
    unsigned char block4[block_size];
    unsigned char iv_extended[block_size];
    unsigned char key_extended[block_size];
    for (int i = 0; i < block_size; i++) {
        block1[i] = block2[i] = block3[i] = block4[i] = 0;
    }
    for (int i = 0; i < size; i++) {
        if (i < block_size) {
            block1[i] = bytes_studenti[i];
        } else if (i < 2 * block_size) {
            block2[i % block_size] = bytes_studenti[i];
        } else if (i < 3 * block_size) {
            block3[i % block_size] = bytes_studenti[i];
        } else {
            block4[i % block_size] = bytes_studenti[i];
        }
    }
    for (int i = 0; i < block_size; i++) {
        iv_extended[i] = ((unsigned char *) iv)[i % iv_len];
        key_extended[i] = ((unsigned char *) key)[i % key_len];
    }
    xoor(block1, iv_extended, block_size);
    s_box(block1, key_extended, block_size);
    p_box(block1, block_size);
    fwrite(block1, sizeof(unsigned char), block_size, f);
    xoor(block2, block1, block_size);
    s_box(block2, key_extended, block_size);
    p_box(block2, block_size);
    fwrite(block2, sizeof(unsigned char), block_size, f);
    xoor(block3, block2, block_size);
    s_box(block3, key_extended, block_size);
    p_box(block3, block_size);
    fwrite(block3, sizeof(unsigned char), block_size, f);
    xoor(block4, block3, block_size);
    s_box(block4, key_extended, block_size);
    p_box(block4, block_size);
    fwrite(block4, sizeof(unsigned char), block_size, f);
    fclose(f);
}
