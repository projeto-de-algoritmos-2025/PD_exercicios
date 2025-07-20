#include <string.h>
#include <stdlib.h>

int getMaxRepetitions(char* s1, int n1, char* s2, int n2) {
    int s1_len = strlen(s1);
    int s2_len = strlen(s2);
    
    // Arrays para guardar o histórico e detectar o ciclo.

    // recall_s1_count[k] guarda o s1_count quando chegamos pela primeira vez em s2_idx = k.
    int* recall_s1_count = (int*)calloc(s2_len + 1, sizeof(int));
    int* recall_s2_count = (int*)calloc(s2_len + 1, sizeof(int));

    int s2_idx = 0;
    int s2_count = 0;
    int s1_count = 0;

    while (s1_count < n1) {
        s1_count++;
        for (int i = 0; i < s1_len; ++i) {
            if (s1[i] == s2[s2_idx]) {
                s2_idx++;
                if (s2_idx == s2_len) {
                    s2_idx = 0;
                    s2_count++;
                }
            }
        }

        // Se já vimos este s2_idx antes, encontramos um ciclo.

        if (recall_s1_count[s2_idx] > 0) {
            int prev_s1_count = recall_s1_count[s2_idx];
            int prev_s2_count = recall_s2_count[s2_idx];

            // Calcula o tamanho do ciclo

            int cycle_s1_len = s1_count - prev_s1_count;
            int cycle_s2_len = s2_count - prev_s2_count;

            // Calcula quantos ciclos cabem no restante de n1

            int remaining_s1s = n1 - s1_count;
            int num_cycles = remaining_s1s / cycle_s1_len;

            // "Pula" para frente, adicionando os resultados de todos os ciclos

            s1_count += num_cycles * cycle_s1_len;
            s2_count += num_cycles * cycle_s2_len;
            
        } else {

             // Grava o estado atual se for a primeira vez que chegamos neste s2_idx
            recall_s1_count[s2_idx] = s1_count;
            recall_s2_count[s2_idx] = s2_count;
        }
    }

    free(recall_s1_count);
    free(recall_s2_count);
    
    return s2_count / n2;
}