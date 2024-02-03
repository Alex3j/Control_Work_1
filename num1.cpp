#include <iostream>
#include <random>

void fill(int **arr, int row, int col){
    std::random_device dev;
    std::default_random_engine eng{dev()};
    std::uniform_int_distribution d{10,50};
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++){
            arr[i][j] = d(eng);
        }
    }
}

void show(int **arr, int row, int col) {
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++){
            std::cout << arr[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

void sum(int **arr, int row, int col) {
    int sumD = 0;
    for (int i=0; i < col; i++)
        sumD+=arr[i][row-1-i];
    std::cout << sumD;
}

void del(int **arr,int col){
    for (int i=0; i<col; i++){
        delete[] arr[i];
    }
    delete[] arr;
}

int main() {
    int col, row;
    std::cout << "Enter the rows and cols:";
    std::cin >> row >> col;
    int **arr = new int*[row];
    for (int i = 0; i < row; i++)
        arr[i] = new int[col];
    fill(arr,row,col);
    show(arr,row,col);
    sum(arr,row,col);
    del(arr,col);
    return 0;
}