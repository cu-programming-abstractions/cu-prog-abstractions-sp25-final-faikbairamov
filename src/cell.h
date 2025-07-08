#pragma once

/**
 * Simple coordinate structure for representing positions in the dungeon.
 * Used throughout the pathfinding algorithms to track locations.
 */
struct Cell {
    int r, c;

    Cell(int row = 0, int col = 0) : r(row), c(col) {}

    bool operator==(const Cell& other) const {
        return r == other.r && c == other.c;
    }

    bool operator!=(const Cell& other) const {
        return !(*this == other);
    }
};

/**
 * Hash function for using Cell in unordered containers like unordered_set.
 * This enables efficient lookups in the BFS visited tracking.
 */
struct CellHash {
    size_t operator()(const Cell& cell) const {
        return static_cast<size_t>(cell.r) * 1000 + static_cast<size_t>(cell.c);
    }
};

const int DIRECTIONS[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
const int NUM_DIRECTIONS = 4;
