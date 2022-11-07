/*


Copyright 2013 Oleg Kostyuk <cub.uanic@gmail.com>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

/*
 * scan matrix
 */
#include <stdint.h>
#include <stdbool.h>
#include "wait.h"
#include "action_layer.h"
#include "print.h"
#include "debug.h"
#include "util.h"
#include "matrix.h"
#include "debounce.h"

//#include "hardware/spi.h"

#include QMK_KEYBOARD_H

static matrix_row_t raw_matrix[MATRIX_ROWS];  // raw values
static matrix_row_t matrix[MATRIX_ROWS];      // debounced values

__attribute__((weak)) void matrix_init_kb(void) { matrix_init_user(); }
__attribute__((weak)) void matrix_scan_kb(void) { matrix_scan_user(); }
__attribute__((weak)) void matrix_init_user(void) {}
__attribute__((weak)) void matrix_scan_user(void) {}


matrix_row_t matrix_get_row(uint8_t row) {
    // TODO: return the requested row data
}

void matrix_print(void) {
    // TODO: use print() to dump the current matrix state to console
}

void matrix_init(void) {
    // TODO: initialize hardware and global matrix state here

    // Unless hardware debouncing - Init the configured debounce routine
    debounce_init(MATRIX_ROWS);

    // This *must* be called for correct keyboard behavior
    matrix_init_quantum();
}

uint8_t matrix_scan(void) {
    bool changed = false;

    // TODO: add matrix scanning routine here

    // Unless hardware debouncing - use the configured debounce routine
    changed = debounce(raw_matrix, matrix, MATRIX_ROWS, changed);

    // This *must* be called for correct keyboard behavior
    matrix_scan_quantum();

    return changed;
}



