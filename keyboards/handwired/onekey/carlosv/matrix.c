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

#include QMK_KEYBOARD_H
#include "analog.h"
#include "spi_master.h"

#define CHIP 0x40       // The chip's address (set by pins 4 & 5)
#define IO_DIR_REG 0x00 // The Input/Output Register
#define GPIO_REG 0x09   // The GPIO Register

/* void keyboard_post_init_kb(void) { */
/*     // Enable RGB current limiter and wait for a bit before allowing RGB to continue */
/*     /\* setPinOutput(RGB_ENABLE_PIN); *\/ */
/*     /\* writePinHigh(RGB_ENABLE_PIN); *\/ */
/*     /\* wait_ms(20); *\/ */

/*     // Offload to the user func */
/*     keyboard_post_init_user(); */
/*     print("Probando1...\n"); */
/* } */

void mcp_write(uint8_t device, uint8_t spiRegister, uint8_t value){
  /* This function sends data to the chip */
  /* It's a 5 step process */
  /* 1) Pull the Slave/Chip select LOW */
  writePinLow(SPI_MATRIX_CHIP_SELECT_PIN);
  
  /* 2) Send the chip's address to the chip */
  //spi_write(CHIP); // con este funciona
  spi_write(0b01000000 | (device << 1)); // y con este también

  /* 3) Send the register to the chip */
  spi_write(spiRegister);
  /* 4) Send the value to the chip */
  spi_write(value);
  /* 5) Pull the Slave/Chip select HIGH */
  //wait_ms(20);
  writePinHigh(SPI_MATRIX_CHIP_SELECT_PIN);
}

matrix_row_t mcp_read(uint8_t device, uint8_t addr){
  writePinLow(SPI_MATRIX_CHIP_SELECT_PIN);

  spi_write(0b01000001 | ((device) << 1));
  spi_write(addr);

  matrix_row_t resultado = spi_read();

  writePinHigh(SPI_MATRIX_CHIP_SELECT_PIN);

  return resultado;
}

void matrix_init_custom(void) {
  // SPI Matrix
  
  setPinOutput(SPI_MATRIX_CHIP_SELECT_PIN);
  writePinHigh(SPI_MATRIX_CHIP_SELECT_PIN);
  wait_ms(100);

  spi_init();
  spi_start(SPI_MATRIX_CHIP_SELECT_PIN, false, 0, SPI_MATRIX_DIVISOR);

  wait_ms(20);
  
  /* mcp_write(IO_DIR_REG,0x00); // Set all pins to OUTPUT */
  mcp_write(0,IO_DIR_REG,0xff); // Set all pins to INPUT
  mcp_write(0,GPIO_REG,0x00);   // Set all pins LOW
}

/* static matrix_row_t read_cols(uint8_t row) { */
/*     return 0xff ^ mcp_read(0, GPIO_REG); */
/* } */

bool matrix_scan_custom(matrix_row_t current_matrix[]) {
    bool changed = false;

    /* // Set pin 1 HIGH */
    /* print("Encendiendo\n"); */
    /* mcp_write(0,GPIO_REG,0x05); */
    /* wait_ms(1000); */
    /* // Set pin 1 LOW */
    /* print("Apagando\n"); */
    /* mcp_write(0,GPIO_REG,0x00); */
    /* wait_ms(1000); */

    matrix_row_t read_result =  mcp_read(0,GPIO_REG);
    
    /* //static matrix_row_t temp_matrix[MATRIX_ROWS] = {0}; */
    /* static matrix_row_t current_row_value = 0; */
    /* //int i = 0; */

    /* // Read from SPI the matrix */

    /* spi_status_t read_result = spi_read(); */
    /* /\* spi_status_t read_result = *\/ */
    /* /\*   spi_receive((uint8_t*)temp_matrix, MATRIX_ROWS * sizeof(matrix_row_t)); *\/ */


    if (read_result >= 0) {
      /* only if SPI read successful: populate the matrix row with the
    	 state of the 8 consecutive column bits */
      //current_row_value |= ((matrix_row_t)read_result << col_index);
      uprintf("Parece que lee algo...%i\n",(uint8_t)read_result);
      //current_row_value |= ((matrix_row_t)read_result << 0);
      //uprintf("Contenido de current_row_value, %d\n",(uint8_t)current_row_value);
    }
    
    //writePinHigh(SPI_MATRIX_CHIP_SELECT_PIN);
    //spi_stop();

    /* print("Contenido de temp_matrix: "); */
    /* for (int i = 0; i < MATRIX_ROWS; i++){ */
    /*   uprintf("%d ",temp_matrix[i]); */
    /* } */
    /* print("\n"); */


    // Read from the encoder pushbutton. Se almacena en la última posición del vector
    //    temp_matrix[5] = readPin(ENCODER_PUSHBUTTON_PIN) ? 1 : 0;

    // Check if we've changed, return the last-read data
    /* bool changed = memcmp(current_matrix, temp_matrix, sizeof(temp_matrix)) != 0; */
    /* if (changed) { */
    /*     memcpy(current_matrix, temp_matrix, sizeof(temp_matrix)); */
    /* } */
    return changed;
}


/* static matrix_row_t raw_matrix[MATRIX_ROWS];  // raw values */
/* static matrix_row_t matrix[MATRIX_ROWS];      // debounced values */

/* __attribute__((weak)) void matrix_init_kb(void) { matrix_init_user(); } */
/* __attribute__((weak)) void matrix_scan_kb(void) { matrix_scan_user(); } */
/* __attribute__((weak)) void matrix_init_user(void) {} */
/* __attribute__((weak)) void matrix_scan_user(void) {} */


/* matrix_row_t matrix_get_row(uint8_t row) { */
/*     // TODO: return the requested row data */
/* } */

/* void matrix_print(void) { */
/*     // TODO: use print() to dump the current matrix state to console */
/* } */

/* void matrix_init(void) { */
/*     // TODO: initialize hardware and global matrix state here */

/*     // Unless hardware debouncing - Init the configured debounce routine */
/*     debounce_init(MATRIX_ROWS); */

/*     // This *must* be called for correct keyboard behavior */
/*     matrix_init_quantum(); */
/* } */

/* uint8_t matrix_scan(void) { */
/*     bool changed = false; */

/*     // TODO: add matrix scanning routine here */

/*     // Unless hardware debouncing - use the configured debounce routine */
/*     changed = debounce(raw_matrix, matrix, MATRIX_ROWS, changed); */

/*     // This *must* be called for correct keyboard behavior */
/*     matrix_scan_quantum(); */

/*     return changed; */
/* } */



