#include <iostream>
#include <cmath>

using std::cout;
using std::cin;
using std::string;
using std::endl;

bool searchVer(size_t hor, size_t ver, int n, int* arr) {
    int count{ 0 };

    for (ver = 0; ver < n; ver++) {
        if (*(arr + ver * n + hor)) {
            count++;
            if (count >= 2) {
                return true;
            }
        }
    }
    return false;
}

bool searchHor(size_t hor, size_t ver, int n, int* arr) {
    int count{ 0 };

    for (ver = 0; ver < n; ver++) {
        if (*(arr + hor * n + ver)) {
            count++;
            if (count >= 2) {
                return true;
            }
        }
    }
    return false;
}


void canAttack(int* arr, int n, int rowA, int rowB, int columnA, int columnB) {

    // Initialize variables for the loops
    size_t i{ 0 }, j{ 0 };

    // Print the matrix
    cout << "The matrix:" << endl;
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            cout << *(arr + i * n + j) << "\t";
        }
        cout << endl;
    }

    // Print the coordinates of the Queens
    cout << "\n\n\nThe White Queen is in: [" << rowA << "," << columnA << "]" << endl;
    cout << "\nThe Black Queen is in: [" << rowB << "," << columnB << "]" << endl;

    // First if checks if the queens can attack one another diagonally
    // The two else if - checks if the queens can attack one another horizontally
    // and vertically , through a function called searchHor and searchVer
    // For the first if we use (|x1-x2|=|y1-y2|) statement!
    if (abs((rowA - rowB)) == abs((columnA - columnB))) {
        cout << "\n\n\nThe Queens can attack one another diagonally!" << endl;
        return;
    }
    else if (searchHor(rowA, j, n, arr)) {
        cout << "\n\n\nThe Queens can attack one another horizontally!" << endl;
        return; // We have an empty return in the void function to call it 
                //stop it when one of the 3 conditions are true
    }
    else if (searchVer(columnA, i, n, arr)) {
        cout << "\n\n\nThe Queens can attack one another vertically!" << endl;
        return;
    }
    else {
        cout << "\n\n\nThe Queens cannot attack one another!" << endl;
    }

}


int main()
{
    int matrix[8][8] = { 0 }; // Set up the matrix
    unsigned int rowA{}, columnA{}, rowB{}, columnB{}; // Initialiaze variables for the coordinates of the two queens!

    system("color 6\n"); // Set the color of the background

    // Getting coordinates for the first(white) queen
    do {
        cout << "Enter at which row and column do you want the white queen to be: " << endl;
        cin >> rowA >> columnA;
    } while (rowA > 7 || columnA > 7);

    matrix[rowA][columnA] = 1; // Appending the queen in the matrix

    // Getting coordinates for the second(black) queen
    do {
        cout << "Enter at which row and column do you want the black queen to be: " << endl;
        cin >> rowB >> columnB;
    } while (rowB > 7 || columnB > 7);

    matrix[rowB][columnB] = 1; // Appending the queen in the matrix

    system("cls");

    // Calling the canAttack function with the coordinates and the array
    canAttack((int*)matrix, 8, rowA, rowB, columnA, columnB);

    return (0);
}