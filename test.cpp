#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Recursive helper function to perform DFS and find the valid path
bool dfs(const vector<vector<int>>& pyramid, int row, int col, int product, int target, string& path) {
    // Multiply the current product with the current pyramid element
    product *= pyramid[row][col];
    
    // If we have reached the last row
    if (row == pyramid.size() - 1) {
        return product == target;
    }
    
    // Try going left (L)
    path.push_back('L');
    if (dfs(pyramid, row + 1, col, product, target, path)) {
        return true;
    }
    path.pop_back();  // Backtrack if this path does not work
    
    // Try going right (R)
    path.push_back('R');
    if (dfs(pyramid, row + 1, col + 1, product, target, path)) {
        return true;
    }
    path.pop_back();  // Backtrack if this path does not work
    
    // If no valid path is found, return false
    return false;
}

// Main function to find the path
string findPath(const vector<vector<int>>& pyramid, int target) {
    string path;
    if (dfs(pyramid, 0, 0, 1, target, path)) {
        return path;  // Return the valid path if found
    }
    return "No valid path found";  // Return this if no path is found
}

int main() {
    // Sample pyramid and target
    vector<vector<int>> pyramid = {
        {2},
        {4, 3},
        {3, 2, 6},
        {2, 9, 5, 2},
        {10, 5, 2, 15, 5}
    };
    int target = 720;

    // Find and print the path
    string path = findPath(pyramid, target);
    cout << "Path: " << path << endl;

    return 0;
}
