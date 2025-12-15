#include <iostream>
#include <climits> // Para INT_MIN

struct Node {
    int data;
    Node* left;
    Node* right;
};

int encontrarMaximo(Node* root) {
    // Caso base: Si el nodo es nulo, regresamos el entero MÍNIMO posible.
    // Así, cualquier dato real será mayor que este valor.
    if (root == nullptr) {
        return INT_MIN; 
    }

    // 1. Asumimos temporalmente que el dato actual es el máximo
    int maximo = root->data;

    // 2. Buscamos recursivamente en la izquierda y derecha
    int maxIzq = encontrarMaximo(root->left);
    int maxDer = encontrarMaximo(root->right);

    // 3. Comparamos manualmente:
                                                    // Si el máximo encontrado a la izquierda e mayor que el actual, actualizamos
    if (maxIzq > maximo) {
        maximo = maxIzq;
    }

    // Si el máximo encontrado a la derecha es mayor que el actual, actualizamos
    if (maxDer > maximo) {
        maximo = maxDer;
    }

    return maximo;
}