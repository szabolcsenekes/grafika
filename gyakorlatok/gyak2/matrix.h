#ifndef MATRIX_H
#define MATRIX_H

#define PI 3.14159265358979323846
#define MAX_STACK_SIZE 100

typedef struct {
    double matrix[3][3];
} TransformMatrix;

typedef struct {
    TransformMatrix stack[MAX_STACK_SIZE];
    int top;
} MatrixStack;

// Veremkezelő műveletek
void initStack(MatrixStack *s);
int isEmpty(MatrixStack *s);
int isFull(MatrixStack *s);
void push_matrix(MatrixStack *s, TransformMatrix matrix);
TransformMatrix pop_matrix(MatrixStack *s);

// Mátrixműveletek
void printMatrix(TransformMatrix m);
TransformMatrix identityMatrix();
TransformMatrix copy_matrix(TransformMatrix src);
void scale_matrix(TransformMatrix *matrix, double sx, double sy);
void shift_matrix(TransformMatrix *matrix, double tx, double ty);
void rotate_matrix(TransformMatrix *matrix, double angle);
void multiply_matrices(const TransformMatrix *a, const TransformMatrix *b, TransformMatrix *c);
void transform_point(const TransformMatrix *matrix, const double point[3], double result[3]);

#endif
