#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "matrix.h"

void initStack(MatrixStack *s) {
    s->top = -1;
}

int isEmpty(MatrixStack *s) {
    return s->top == -1;
}

int isFull(MatrixStack *s) {
    return s->top >= MAX_STACK_SIZE - 1;
}

void push_matrix(MatrixStack *s, TransformMatrix matrix) {
    if (isFull(s)) {
        printf("Error: Stack is full!\n");
        return;
    }
    s->stack[++(s->top)] = copy_matrix(matrix);
}

TransformMatrix pop_matrix(MatrixStack *s) {
    if (isEmpty(s)) {
        printf("Error: Stack is empty!\n");
        exit(EXIT_FAILURE);
    }
    return s->stack[(s->top)--];
}

void printMatrix(TransformMatrix m) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%8.3f ", m.matrix[i][j]);
        }
        printf("\n");
    }
}

TransformMatrix identityMatrix() {
    TransformMatrix m = {{{1, 0, 0}, {0, 1, 0}, {0, 0, 1}}};
    return m;
}

TransformMatrix copy_matrix(TransformMatrix src) {
    TransformMatrix dest;
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            dest.matrix[i][j] = src.matrix[i][j];
    return dest;
}

void scale_matrix(TransformMatrix *matrix, double sx, double sy) {
    matrix->matrix[0][0] *= sx;
    matrix->matrix[1][1] *= sy;
}

void shift_matrix(TransformMatrix *matrix, double tx, double ty) {
    matrix->matrix[0][2] += tx;
    matrix->matrix[1][2] += ty;
}

void rotate_matrix(TransformMatrix *matrix, double angle) {
    double rad = angle * (PI / 180.0);
    double cosA = cos(rad);
    double sinA = sin(rad);

    TransformMatrix rot = {{{cosA, -sinA, 0}, {sinA, cosA, 0}, {0, 0, 1}}};
    TransformMatrix temp = {{{0}}};

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            for (int k = 0; k < 3; k++) {
                temp.matrix[i][j] += rot.matrix[i][k] * matrix->matrix[k][j];
            }
        }
    }

    *matrix = temp;
}

void multiply_matrices(const TransformMatrix *a, const TransformMatrix *b, TransformMatrix *c) {
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            c->matrix[i][j] = 0;
            for (int k = 0; k < 3; ++k) {
                c->matrix[i][j] += a->matrix[i][k] * b->matrix[k][j];
            }
        }
    }
}

void transform_point(const TransformMatrix *matrix, const double point[3], double result[3]) {
    for (int i = 0; i < 3; ++i) {
        result[i] = 0;
        for (int j = 0; j < 3; ++j) {
            result[i] += matrix->matrix[i][j] * point[j];
        }
    }
}
