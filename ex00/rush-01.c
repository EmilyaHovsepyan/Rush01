/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush-01.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehovsepy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 21:10:43 by ehovsepy          #+#    #+#             */
/*   Updated: 2024/12/08 21:10:50 by ehovsepy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

#define SIZE 4


int is_valid(int grid[SIZE][SIZE], int row, int col, int num, int row_left_clue[SIZE], int row_right_clue[SIZE], int col_top_clue[SIZE], int col_bottom_clue[SIZE]) {
    
    int i = 0;
    while (i < SIZE) {
        if (grid[row][i] == num || grid[i][col] == num) {
            return 0;
        }
        i++;
    }

    
    if (col < SIZE - 1 || row < SIZE - 1) {
        return 1;
    }

    
    int max_height = 0, visible_count = 0;
    i = 0;
    while (i < SIZE) {
        if (grid[row][i] > max_height) {
            max_height = grid[row][i];
            visible_count++;
        }
        i++;
    }
    if (visible_count != row_left_clue[row]) return 0;

    
    max_height = 0;
    visible_count = 0;
    i = SIZE - 1;
    while (i >= 0) {
        if (grid[row][i] > max_height) {
            max_height = grid[row][i];
            visible_count++;
        }
        i--;
    }
    if (visible_count != row_right_clue[row]) return 0;

    
    max_height = 0;
    visible_count = 0;
    i = 0;
    while (i < SIZE) {
        if (grid[i][col] > max_height) {
            max_height = grid[i][col];
            visible_count++;
        }
        i++;
    }
    if (visible_count != col_top_clue[col]) return 0;

    
    max_height = 0;
    visible_count = 0;
    i = SIZE - 1;
    while (i >= 0) {
        if (grid[i][col] > max_height) {
            max_height = grid[i][col];
            visible_count++;
        }
        i--;
    }
    if (visible_count != col_bottom_clue[col]) return 0;

    return 1;
}


void print_grid(int grid[SIZE][SIZE]) {
   int i = 0;
   char c = ' ';
   while(i < SIZE) {
        int j = 0;
        while(j < SIZE) {
            grid[i][j] = grid[i][j] + '0';
            write(1, &grid[i][j], 1);
            write(1, &c, 1);
            j++;
        }
        write(1, "\n", 1);
        i++;
   }
}

int solve(int grid[SIZE][SIZE], int col, int row, int row_left_clue[SIZE], int row_right_clue[SIZE], int col_top_clue[SIZE], int col_bottom_clue[SIZE]) {
    if (row == SIZE) return 1; 
    if (col == SIZE) return solve(grid, 0, row + 1, row_left_clue, row_right_clue, col_top_clue, col_bottom_clue);

    int num = 1;
    while (num <= SIZE) {
        if (is_valid(grid, row, col, num, row_left_clue, row_right_clue, col_top_clue, col_bottom_clue)) {
            grid[row][col] = num;
            if (solve(grid, col + 1, row, row_left_clue, row_right_clue, col_top_clue, col_bottom_clue)) return 1;
            grid[row][col] = 0; 
        }
        num++;
    }
    return 0;
}

int main(int argc, char** argv) {

    int row_left_clue[SIZE];
    int row_right_clue[SIZE];
    int col_top_clue[SIZE];
    int col_bottom_clue[SIZE];

    int i = 1;
    int j = 0;
    while(i < argc) {
    while(j < SIZE) {
         row_left_clue[j] = argv[i][0] - '0'; 
         j++;
         i++;
    }
    
    j = 0;
    while(j < SIZE) {
         row_right_clue[j] = argv[i][0] - '0';
         i++;
         j++;
    }

    j = 0;
    while(j < SIZE) {
        col_top_clue[j] = argv[i][0] - '0';
        i++;
        j++;
    }

    j = 0;
    while(j < SIZE) {
        col_bottom_clue[j] = argv[i][0] - '0';
        i++;
        j++;
    }
}
    int grid[SIZE][SIZE] = {0};

    
    if (solve(grid, 0, 0, row_left_clue, row_right_clue, col_top_clue, col_bottom_clue)) {
        print_grid(grid);
    } else {
        write(1, "Error\n", 6);
    }

    return 0;
}

