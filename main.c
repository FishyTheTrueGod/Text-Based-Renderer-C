#include <stdio.h>
// inlclude standard Input/Output
#include <unistd.h>
// usleep() function is needed for frame delay 2D ( aka frame buffer when 3D)

#define HEIGHT 24
#define WIDTH 80
//define the screen before the main, needs update and render logic
int main(void) {
    int x = 0;
    int y = 0;
// starting position and starting velocity
    int dx = 1;
    int dy = 1;
// 2D array represents a grid allocate memory to create 2D grid using                HEIGHT and WIDTH constants
    char buffer[HEIGHT][WIDTH];

    while (1) {
        for (int row = 0; row < HEIGHT; row++) {
            for (int col = 0; col < WIDTH; col++) {
                buffer[row][col] = ' '; // Fills entire canvas with spaces
            }
        }
       // move the position cordinates forward
       x += dx;
       y += dy;

       if (x <= 0) {
        x = 0;      // Lock to left edge
        dx = -dx;   // Flip direction
       }
       if (x >= 79) {
        x = 79;     // Lock to right edge (Prevents x from staying at 80!)
        dx = -dx;   // Flip direction
       }
       if (y <= 0) {
           y = 0;     // Force position back onto the top edge
           dy = -dy;  // Flip direction to move down
       }
       if (y >= 23) {
           y = 23; // Force position back onto bottom edge
           dy = -dy; // FLip direction to move up
       }
       buffer[y][x] = '*';
       // plot the star and then include your ANSI escape codes
       
       printf("\033[H"); // teleport cursor back to top left corner

       for (int row = 0; row < HEIGHT; row++) {
           for (int col = 0; col < WIDTH; col++) {
               printf("%c", buffer[row][col]);
           }
           printf("\n");
       }
       // include the frame pacing now that you are updating the star to current position

       usleep(33333);
    } // closes while loop
    
    return 0;
}

