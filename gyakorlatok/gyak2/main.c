#include <stdio.h>
#include "matrix.h"

int main() {
    MatrixStack stack;
    initStack(&stack);

    TransformMatrix currentMatrix = identityMatrix();
    push_matrix(&stack, currentMatrix);

    shift_matrix(&currentMatrix, 3.0, 4.0);
    push_matrix(&stack, currentMatrix);
    printf("\nAfter shift:\n");
    printMatrix(currentMatrix);

    scale_matrix(&currentMatrix, 2.0, 2.0);
    push_matrix(&stack, currentMatrix);
    printf("\nAfter scale:\n");
    printMatrix(currentMatrix);

    rotate_matrix(&currentMatrix, 45);
    push_matrix(&stack, currentMatrix);
    printf("\nAfter rotate:\n");
    printMatrix(currentMatrix);

    currentMatrix = pop_matrix(&stack);
    printf("\nUndo (rotate removed):\n");
    printMatrix(currentMatrix);

    currentMatrix = pop_matrix(&stack);
    printf("\nUndo (scale removed):\n");
    printMatrix(currentMatrix);

    currentMatrix = pop_matrix(&stack);
    printf("\nUndo (shift removed):\n");
    printMatrix(currentMatrix);

    return 0;
}
