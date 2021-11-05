#include <stdio.h> // Use standard libraries
#define HEIGHT 15 // Has no type; not a variable

// Start main class
int main() {
  
  // Attributes
  int height = TRIHEIGHT;
  int rows, columns;

  // Outer loop determines number of rows
  for (rows = 1; rows <= height; ++rows) {
    
    // Inner loop determines number of columns 
    for (columns = 1; columns <= rows; ++columns) {
     
      // Print asterisks
      printf("*");

    } // End inner for loop
   
    // Prints a new line every iteration
    printf("\n");

  } // End outer for loop

  // Everything went well; return 0
  return 0;

} // End main class
