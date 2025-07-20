#include <stdio.h>

int rob(int* nums, int numsSize) {
    if (numsSize == 0) {
        return 0;
    }

    // rob1 representa o lucro máximo até a casa i-2
    // rob2 representa o lucro máximo até a casa i-1
    int rob1 = 0;
    int rob2 = 0;
    
    // Itera por cada casa no array
    for (int i = 0; i < numsSize; i++) {
        // Para a casa atual (nums[i]), a escolha é:
        // 1. Roubar a casa atual (nums[i] + rob1)
        // 2. Não roubar a casa atual (rob2)
        int temp;
        if ((nums[i] + rob1) > rob2) {
            temp = nums[i] + rob1;
        } else {
            temp = rob2;
        }
        // Atualiza as variáveis para a próxima iteração
        rob1 = rob2;
        rob2 = temp;
    }
    
    // rob2 conterá o resultado final
    return rob2;
}