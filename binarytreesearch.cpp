#include <iostream>
#include <climits> // Necesario solo para INT_MAX

struct Node {
    int data;
    Node* left;
    Node* right;
};

int encontrarMinimo(Node* root) {
    // Caso base: Si el nodo es nulo, regresamos el número más grande posible.
    // Esto sirve para que, al comparar, este valor nunca sea elegido como el menor.
    if (root == nullptr) {
        return INT_MAX;
    }

    // 1. Asumimos temporalmente que el dato actual es el menor
    int minimo = root->data;

    // 2. Buscamos recursivamente en la izquierda y derecha
    int minIzq = encontrarMinimo(root->left);
    int minDer = encontrarMinimo(root->right);

    // 3. Comparamos manualmente:
    // Si lo que encontramos a la izquierda es menor que lo que tenemos, actualizamos
    if (minIzq < minimo) {
        minimo = minIzq;
    }
-
    // Si lo que encontramos a la derecha es menor que el nuevo mínimo, actualizamos
    if (minDer < minimo) {
        minimo = minDer;
    }

    return minimo;
}