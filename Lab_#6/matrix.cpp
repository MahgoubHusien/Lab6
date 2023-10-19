#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
const int msize = 100;

std::vector<std::vector<int> > make_matrix(int num, std::ifstream &file){
    std::vector<std::vector<int> > matrix(num, std::vector<int>(num));
    for (int x = 0; x < num; x++){
        for (int y = 0; y < num; y++){
            file >> matrix[x][y];
        }
    }
    return matrix;
}

std::vector<std::vector<int> > sum(std::vector<std::vector<int> >& matrix1, std::vector<std::vector<int> >& matrix2, int num){
    std::vector<std::vector<int> > results(num, std::vector<int>(num));
    for (int x = 0; x < matrix1.size(); x++){
        for (int y = 0; y < matrix2.size(); y++){
            results[x][y] = matrix1[x][y] + matrix2[x][y];
        }
    }
    return results;
}

std::vector<std::vector<int> > product(std::vector<std::vector<int> >& matrix1, std::vector<std::vector<int> >& matrix2, int num){
    std::vector<std::vector<int> > results(num, std::vector<int>(num));
    for (int x = 0; x < matrix1.size(); x++){
        for (int y = 0; y < matrix2[0].size(); y++){
            for (int z = 0; z < matrix1[0].size(); z++){
            results[x][y] += matrix1[x][z] * matrix2[z][y];
        }
        }
    }
    return results;
}

std::vector<std::vector<int> > difference(std::vector<std::vector<int> >& matrix1, std::vector<std::vector<int> >& matrix2, int num){
    std::vector<std::vector<int> > results(num, std::vector<int>(num));
    for (int x = 0; x < matrix1.size(); x++){
        for (int y = 0; y < matrix2.size(); y++){
            results[x][y] = matrix1[x][y] - matrix2[x][y];
        }
    }
    return results;
}


int main(){
    std::ifstream file("matrix.txt");
    if (!file){
        std::cout << "Error with opening file" << std::endl;
        return 1;
    }
    int num;
    file >> num;
    auto matrix1 = make_matrix(num, file);
    auto matrix2 = make_matrix(num, file);
    std::cout << "\nMahgoub Husien" << std::endl;
    std::cout << "Lab #6: Matrix manipulation\n" << std::endl;
    std::cout << "Matrix A: " << std::endl;
    for(int i = 0; i < num; ++i) {
        for(int j = 0; j < num; ++j) {
            std::cout << matrix1[i][j] << ' ';
        }
        std::cout <<std::endl;
    }
    std::cout << "\nMatrix B: " << std::endl;
    for(int i = 0; i < num; ++i) {
        for(int j = 0; j < num; ++j) {
            std::cout << matrix2[i][j] << ' ';
        }
        std::cout <<std::endl;
    }
    std::cout << "\nMatrix Sum (A + B): " << std::endl;
    auto matrix3 = sum(matrix1, matrix2, num);
    for(int i = 0; i < num; ++i) {
        for(int j = 0; j < num; ++j) {
            std::cout << std::setw(2) << matrix3[i][j] << ' ';
        }
        std::cout <<std::endl;
    }
    std::cout << "\nMatrix Product (A * B): " << std::endl;
    auto matrix4 = product(matrix1, matrix2, num);
    for(int i = 0; i < num; ++i) {
        for(int j = 0; j < num; ++j) {
            std::cout << std::setw(3) << matrix4[i][j] << ' ';
        }
        std::cout <<std::endl;
    }
    std::cout << "\nMatrix Difference (A - B): " << std::endl;
    auto matrix5 = difference(matrix1, matrix2, num);
    for(int i = 0; i < num; ++i) {
        for(int j = 0; j < num; ++j) {
            std::cout << matrix5[i][j] << ' ';
        }
        std::cout <<std::endl;
    }
    file.close();
    return 0;

}
