#include <iostream>
#include <random>

using namespace std;

void show(int arr[][3]);
void show(int** matrix, int rows, int cols);
void switch_rows(int** matrix, int rows, int cols);

void swap_rows(int** matrix, int row1, int row2) {
    if (row1 == row2) return;

    int* temp = matrix[row1];
    matrix[row1] = matrix[row2];
    matrix[row2] = temp;
}

void find_min_addres_and_destroy(int arr[][3]) {
    int min = arr[0][0];
    int min_index_i = 0;
    int min_index_j = 0;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (arr[i][j] < min) {
                min = arr[i][j];
                min_index_i = i;
                min_index_j = j;
            }
        }
    }
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (min_index_i==i || min_index_j==j) {
                arr[i][j] = -100;
            }
        }
    }
    show(arr);
}

void show(int arr[][3]) {
    for (int i = 0; i < 3; i++) {
        cout << endl;
        for (int j = 0; j < 3; j++) {
            cout << arr[i][j] << " ";
        }
    }
}

void show(int** matrix, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        cout << endl;
        for (int j = 0; j < cols; j++) {
            cout << matrix[i][j] << " ";
        }
    }
}

int main() {
    const int N = 3;
    int arr[N][N] = {{1, 2, 3},{4,0,6},{7,8,9}};
    show(arr);
    cout << endl;
    find_min_addres_and_destroy(arr);
    cout << endl;
    int n, m;
    cout << "Enter number of rows: ";
    cin >> n;
    cout << "Enter number of columns: ";
    cin >> m;
    int** matrix = new int*[n];
    for (int i = 0; i < n; i++) {
        matrix[i] = new int[m];
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            matrix[i][j] = rand() % 100;
        }
    }

    show(matrix, n, n);
    cout << endl;
    swap_rows(matrix, n-1, n-2);

    show(matrix, n, n);
    return 0;
}