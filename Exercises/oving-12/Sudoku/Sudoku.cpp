//
//  Sudoku.hpp
//  oving12
//
//  Created by Gjert Ingar Gjersund on 13.04.2018.
//  Copyright © 2018 Gjert Ingar Gjersund. All rights reserved.
//

#include "Sudoku.hpp"


// Constructor
Sudoku::Sudoku() {
    size = 9;
    board = new int*[size];
    for (int i = 0; i < size; i++) {
        
        board[i] = new int[size];
        
        for (int j = 0; j < size; j++) {
            board[i][j] = 0;
        }
    }
    
    rows = new std::set<int>[size];
    cols = new std::set<int>[size];
    boxes = new std::set<int>*[size / 3];
    
    for (int i = 0; i < size / 3; i++) {
        boxes[i] = new std::set<int>[size / 3];
    }
}

// Destructor
Sudoku::~Sudoku() {
    for (int i = 0; i < size; i++) {
        delete[] board[i];
    }
    delete[] board;
}

// Save and Load
void Sudoku::Save(std::string filename) {
    std::ofstream file;
    file.open(filename);
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            file << board[i][j] << "\t";
        }
        file << "\n";
    }
    file.close();
}

void Sudoku::Load(std::string filename) {
    
    char val;
    int j = 0;
    int i = 0;
    
    std::ifstream file;
    file.open(filename);
    
    while (file.get(val)) {
        if (val != '\t' && val != '\n' && val != '|' && val != '_' && val != ' ') {
            InsertValue(i, j, static_cast<int>(val - 48));
            j++;
        } else if (val == '\n') {
            i++;
            j = 0;
        }
    }
    file.close();
}

// Checks
void Sudoku::Box(int row, int col, int &h, int &v) {
    h = row / (size / 3);
    v = col / (size / 3);
}
void Sudoku::InsertValue(int x, int y, int number) {
    int h, v;
    Box(x, y, h, v);
    
    bool in_row = rows[x].find(number) != rows[x].end();
    bool in_col = cols[y].find(number) != cols[y].end();
    bool in_box = boxes[h][v].find(number) != boxes[h][v].end();
    
    if (board[x][y] == number) {
        std::cout << "Number already exists in that position." << std::endl;
    } else if (in_row) {
        std::cout << "Number already exists in the row." << std::endl;
    } else if (in_col) {
        std::cout << "Number already exists in the column." << std::endl;
    } else if (in_box) {
        std::cout << "Number already exists in the box." << std::endl;
    } else {
        board[x][y] = number;
        rows[x].insert(number);
        cols[y].insert(number);
        boxes[h][v].insert(number);
        std::cout << "Your value has been inserted." << std::endl;
    }
}

// Interact
void Sudoku::Edit() {
    int x, y, number;
    std::cout << "Select row [0-8]" << std::endl;
    std::cin >> x;
    std::cout << "Select column [0-8]" << std::endl;
    std::cin >> y;
    std::cout << "Select number [0-9]" << std::endl;
    std::cin >> number;
    
    if (x < 0 || x >= 9) {
        std::cout << "Row out of range." << std::endl;
    } else if (y < 0 || y >= 9) {
        std::cout << "Column out of range." << std::endl;
    } else if (number < 0 || y > 9) {
        std::cout << "Number out of range." << std::endl;
    } else {
        InsertValue(x, y, number);
    }
}

void Sudoku::Play() {
    std::cout << "Welcome to super simple Sudoku!" << std::endl;
    
    bool quit = false;
    while (!quit) {
        int command = 0;
        std::string filename;
        std::cout << "Select your action" << std::endl;
        std::cout << "[1] Add number to board" << std::endl;
        std::cout << "[2] Display board" << std::endl;
        std::cout << "[3] Load board" << std::endl;
        std::cout << "[4] Save board" << std::endl;
        std::cout << "Any other number to quit the game." << std::endl;
        std::cin >> command;
        
        switch (command) {
            case 1:
                Edit();
                break;
            case 2:
                std::cout << *(this) << std::endl;
                break;
            case 3:
                std::cout << "Enter the filename of your previously saved board" << std::endl;
                std::cin >> filename;
                Load(filename);
                std::cout << "Your file has been loaded." << std::endl;
                break;
            case 4:
                std::cout << "Enter the saves filename" << std::endl;
                std::cin >> filename;
                Save(filename);
                std::cout << "Your file has been saved." << std::endl;
                break;
            default:
                std::cout << "Thank you for playing!" << std::endl;
                quit = true;
                break;
        }
    }
}

// Operator
std::ostream& operator <<(std::ostream& os, const Sudoku& sudoku) {
    for (int i = 0; i < 9; i++) {
        if (i % 3 == 0) {
            os << "______________________________________________\n\n";
        }
        for (int j = 0; j < 9; j++) {
            if (j % 3 == 0) {
                os << "|   ";
            }
            os << sudoku.board[i][j] << "   ";
        }
        os << "\n";
    }
    os << "______________________________________________" << std::endl;
    return os;
}
