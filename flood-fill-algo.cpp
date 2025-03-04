/*

Problem :-
S1. Given Matrix->contain anything(0/1/2/3/4/5/6/7..............);
S2. Given starting row and starting column->containg one initial number say initial color;


Task :- 
S0. Remember the starting row and starting column's color.
S1. Color the starting row and starting column with the given new color;
S2. Color all the (up, down, right, left) nodes of the starting row and starting column with the new color which have same color as the color of starting row and starting column cordinates;
S3. Give the final updated matrix;

*/


#include <iostream>
#include <vector>
using namespace std;

// Flood fill algorithm implementation
void floodFill(vector<vector<int>> &screen, int x, int y, int newColor, int oldColor) {
    int rows = screen.size();
    int cols = screen[0].size();

    cout << "Checking position (" << x << ", " << y << ")" << endl;

    // Base cases
    if (x < 0 || x >= rows || y < 0 || y >= cols) {
        cout << "Out of bounds. Returning." << endl;
        return;
    }
    if (screen[x][y] != oldColor) {
        cout << "Current pixel doesn't match oldColor. Returning." << endl;
        return;
    }
    if (screen[x][y] == newColor) {
        cout << "Current pixel already filled with newColor. Returning." << endl;
        return;
    }

    // Fill the current pixel
    cout << "Filling position (" << x << ", " << y << ") with color " << newColor << endl;
    screen[x][y] = newColor;

    // Recursively fill neighboring pixels
    floodFill(screen, x + 1, y, newColor, oldColor);
    floodFill(screen, x - 1, y, newColor, oldColor);
    floodFill(screen, x, y + 1, newColor, oldColor);
    floodFill(screen, x, y - 1, newColor, oldColor);
}

void startFloodFill(vector<vector<int>> &screen, int x, int y, int newColor) {
    int oldColor = screen[x][y];
    cout << "Starting flood fill at position (" << x << ", " << y << ") with new color " << newColor << " and old color " << oldColor << endl;
    if (oldColor != newColor) {
        floodFill(screen, x, y, newColor, oldColor);
    } else {
        cout << "New color and old color are the same. No fill needed." << endl;
    }
}

void printScreen(const vector<vector<int>> &screen) {
    for (const auto &row : screen) {
        for (int pixel : row) {
            cout << pixel << " ";
        }
        cout << endl;
    }
}

int main() {
    vector<vector<int>> screen = {
        {1, 1, 1, 1, 1},
        {1, 1, 0, 0, 1},
        {1, 0, 0, 1, 1},
        {1, 1, 1, 1, 1}
    };

    cout << "Original screen:\n";
    printScreen(screen);

    int x = 1, y = 2, newColor = 2;
    cout << "\nUpdating screen with flood fill...\n";
    startFloodFill(screen, x, y, newColor);

    cout << "\nUpdated screen:\n";
    printScreen(screen);

    return 0;
}
