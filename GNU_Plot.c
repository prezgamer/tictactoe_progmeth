#include <stdio.h>

int main() {
    // Open a pipe to GNU Plot
    FILE *gnuplotPipe = popen("gnuplot -persist", "w");

    if (gnuplotPipe == NULL) {
        fprintf(stderr, "Error opening pipe to GNU Plot.\n");
        return -1;
    }

    // Send GNU Plot commands through the pipe
    fprintf(gnuplotPipe, "plot sin(x)\n");

    // Close the pipe
    pclose(gnuplotPipe);

    return 0;
}

// #include <stdio.h>
// #include <stdlib.h>

// void create_gnuplot_script(char *filename, int matrix[][2], int num_classes) {
//     FILE *script = fopen(filename, "w");
//     if (!script) {
//         perror("Error opening script file");
//         exit(1);
//     }

//     fprintf(script, "set terminal png\n");
//     fprintf(script, "set output 'plot.png'\n");
//     fprintf(script, "set title 'Confusion Matrix'\n");
//     fprintf(script, "set xlabel 'Predicted'\n");
//     fprintf(script, "set ylabel 'Actual'\n");

//     for (int i = 0; i < num_classes; i++) {
//         for (int j = 0; j < num_classes; j++) {
//             fprintf(script, "set label '%d' at %d, %d\n", matrix[i][j], j+1, i+1);
//         }
//     }

//     fprintf(script, "plot [-0.5:%d.5] [-0.5:%d.5] '%%g' using 1:2:3 with labels notitle\n", num_classes, num_classes);

//     fclose(script);
// }

// int main() {
//     int num_classes = 2;
//     int matrix[][2] = {{1, 0},
//                        {0, 1}};

//     char script_filename[] = "script.gp";
//     create_gnuplot_script(script_filename, matrix, num_classes);
//     system("gnuplot script.gp");

//     return 0;
// }


// #include <stdio.h>


// int main(void){
//     int x=0;
//     int y=0;
//     FILE *fp = NULL;
//     FILE *gnupipe = NULL;

//     char *gnuCommand[] = {"set title \"Demo\"", "plot 'data.tmp'"};

//     fp= fopen("data.tmp", "w");
//     gnupipe = _popen("gnuplot -persitent", "w");

//     for (int i = 0; i < 11; i++)
//     {
//         fprintf(fp, "%d %d\n", x, y);

//         x= x+1;
//         y= y+1;
//     }

//     for (int i = 0; i < 2; i++)
//     {
//         fprintf(gnupipe, "%s\n", gnuCommand[i]);
//     }
    
//     return 0;
// }
