//
//  main.cpp
//  matrixulator
//
//  Created by Mehmet Tugrul Savran and Batuhan Erdogan on 5/23/13.
//  Copyright (c) 2013 CuriouScientists. All rights reserved.
//

#include <iostream>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>


int main(int argc, const char * argv[])
{
	char name[50];//Creating space for name :)
    
ULTIMATE:
    
	printf("Please, enter your name: \t");
    
	fgets(name, sizeof(name), stdin);//Pasting the standard input into name array
    
	int len;
	len = strlen(name);
    
    if (len > 0 && name[len-1] == '\n')
        name[len-1] = '\0';  // This is to deal with a foolish problem with fgets. Ignore this.
	int as;
    
	for (as=0;as<100;++as) {
        putchar('\n');
	} // This loop is to leave 100 lines of space to make a better command line interface :)
    
    
	printf("Welcome to Matrixulator, ");
    
	int love=0;
    
	do {
		putchar(name[love]);
		love++;
	} while (name[love] != 0); //Show the name on screen!
	printf("!\n\n");
    
    
	printf("Matrixulator TM is designed to perform fundamental operations with matrices (i.e. this is a matrix calculator!). .\n"
           
	       "Please enter the dimensions of Matrix 1(as #rows #columns, just use a space between): ");
    
	int i_h, i_v, f_h, f_v; //initial horizontal, initial vertical, final h. and final v. a.k.a. dimensions of matrices.
    
	scanf("%d%d", &i_h, &i_v); //telling the computer to read the dimensions
    
    
	printf("Please enter the dimensions of Matrix 2(#rows, #columns): ");
    
	scanf("%d%d", &f_h, &f_v);
    
	for (as=0;as<100;++as) {
		putchar('\n');
	}
    
	int matrix1[i_v][i_h], matrix2[f_v][f_h]; //The legend of matrices!
    
	printf("Stating the values of Matrix 1.\n\n"); //OMG..
    
	int i, j, inp;
    
AGAIN1:
    
	for (i=0; i<i_v; i++) {
        
        printf("\nUsing space between values, enter the suitable information for Row %d:", i+1);
        for (j=0; j<i_h; j++) {
            
            scanf("%d", &inp);
            matrix1[i][j] = inp;
        } //Computer is asking you to provide the values of matrix for each row. For example 4 5 6 7 8 and then asking you the other row (if present).
        
    }
    
WHAT1:
    
    printf("\n\nIs this the matrix you have requested?:\n"); //Validation
    
    for (i=0; i<i_v; i++) {
        putchar('|'); //For aesthetic purposes, computer is putting a | for each column. Neat, right?
        for (j=0; j<i_h; j++) {
            if (j == i_h-1) {
                printf("%d|", matrix1[i][j]);
            } else
            { printf("%d ", matrix1[i][j]);
            }
        }
        putchar('\n');
    }
    
    printf("\nEnter '1' for yes or '0' for no: ");
    
    int conf; //End of validation
    scanf("%d", &conf);
    
    if (conf == 1) {
        printf("\nAwesome. Now...\n\n");
    } else if (conf == 0) {
        for (as=0;as<100;++as) {
            putchar('\n');
        }
        
        printf("Here we go again!\n"); //If the matrices do not match...
        goto AGAIN1;
    } else {
        printf("\n\nWhaaa??\n"); // If you really mess with it:)
        goto WHAT1;
    }
    
    
    
    printf("Stating the values of Matrix 2\n"); //Same thing
    
AGAIN2:
    
    for (i=0; i<f_v; i++) {
        
        printf("\nUsing space between values, enter the suitable information for Row %d:", i+1);
        for (j=0; j<f_h; j++) {
            
            scanf("%d", &inp);
            matrix2[i][j] = inp;
        }
    }
    
WHAT2:
    
    printf("\n\nIs this the matrix you have requested?:\n");
    
    for (i=0; i<f_v; i++) {
        putchar('|');
        for (j=0; j<f_h; j++) {
            if (j == f_h-1) {
                printf("%d|", matrix2[i][j]);
            } else
            { printf("%d ", matrix2[i][j]);
            }
        }
        putchar('\n');
    }
    
    printf("\nEnter '1' for yes and '0' for no: ");
    
    scanf("%d", &conf);
    
    if (conf == 1) {
        printf("\nVery well done!..\n\n");
    } else if (conf == 0) {
        for (as=0;as<100;++as) {
            putchar('\n');
        }
        
        printf("Oh, no, here we go again!\n");
        goto AGAIN2;
    } else {
        printf("\n\nWhaaa-- Again??\n");
        goto WHAT2;
    }
    
    for (as=0;as<100;++as) {
        putchar('\n');
    }
    // Same thing over now!
    
    printf("Now, Operations!\n"
           "Possible arithmethical operations for the matrices you have just defined"
           "can be found below (1 means 'Suitable', and 0 not.):\n\n\n");
    
    int sum=0, mul_f=0, mul_b=0;		//We are now determining which operations can be done!
    
    if (f_h == i_h && f_v == i_v) {    //Remember the rules for matrix operations?
        sum = 1;
    }
    if (i_h == f_v) {
        mul_f = 1;
    }
    if (i_v == f_h) {
        mul_b = 1;
    }
    
    printf("Matrix 1 + Matrix 2 : %d\n"
           "Matrix 1 - Matrix 2 : %d\n"
           "Matrix 2 - Matrix 1 : %d\n"
           "Matrix 1 * Matrix 2 : %d\n"
           "Matrix 2 * Matrix 1 : %d\n", sum, sum, sum, mul_f, mul_b);
    
ETIKET:
    
    printf("\n\n\nEnter '1' for addition, '2' for forward subtraction, '3' for backward subtraction, '4' for "
           "forward multiplication and '5' for inverse multiplication! You can enter 6 if you wish to restart the program.\n");
    
    int val, k, top, toplam[i_h][i_v];    //FYI, toplam = sum in Turkish
    
    scanf("%d", &val);
    
    switch (val) {
        case 1:
            
            if (sum == 1) {
                for (i=0; i<i_v; i++) {
                    for (j=0; j<i_h; j++) {
                        
                        toplam[i][j] = matrix1[i][j] + matrix2[i][j];
                    }
                }
                
                putchar('\n');
                
                for (i=0; i<i_v; i++) {
                    putchar('|');
                    for (j=0; j<i_h; j++) {
                        if (j == i_h-1) {
                            printf("%d|", toplam[i][j]);
                        } else
                        { printf("%d ", toplam[i][j]);
                        }
                    }
                    putchar('\n');
                }
            } else {
                for (as=0;as<100;++as) {
                    putchar('\n');
                }
                printf("\nWe are terribly sorry, but it seems like the matrices are not eligible for addition. \n\n");
                goto ETIKET;
            }
            break;
            
        case 2:
            
            if (sum == 1) {
                for (i=0; i<i_v; i++) {
                    for (j=0; j<i_h; j++) {
                        
                        toplam[i][j] = matrix1[i][j] - matrix2[i][j];
                    }
                }
                
                putchar('\n');
                
                for (i=0; i<i_v; i++) {
                    putchar('|');
                    for (j=0; j<i_h; j++) {
                        if (j == i_h-1) {
                            printf("%d|", toplam[i][j]);
                        } else
                        { printf("%d ", toplam[i][j]);
                        }
                    }
                    putchar('\n');
                }
            } else {
                for (as=0;as<100;++as) {
                    putchar('\n');
                }
                printf("\nWe are terribly sorry, but it seems like the matrices are not eligible for subtraction. \n\n");
                goto ETIKET;
            }
            break;
            
        case 3:
            
            if (sum == 1) {
                for (i=0; i<i_v; i++) {
                    for (j=0; j<i_h; j++) {
                        
                        toplam[i][j] = matrix2[i][j] - matrix1[i][j];
                    }
                }
                
                putchar('\n');
                
                for (i=0; i<i_v; i++) {
                    putchar('|');
                    for (j=0; j<i_h; j++) {
                        if (j == i_h-1) {
                            printf("%d|", toplam[i][j]);
                        } else
                        { printf("%d ", toplam[i][j]);
                        }
                    }
                    putchar('\n');
                }
            } else {
                for (as=0;as<100;++as) {
                    putchar('\n');
                }
                printf("\nWe are terribly sorry, but it seems like the matrices are not eligible for subtraction. \n\n");
                goto ETIKET;
            }
            break;
            
        case 4:
            
            if (mul_f == 1) {
                
                for (i=0; i<i_v; i++) {
                    for (j=0; j<f_h; j++) {
                        
                        top = 0;
                        for (k=0; k<i_h; k++) {
                            top += matrix1[i][k]*matrix2[k][j];
                        }
                        toplam[i][j] = top;
                        
                    }
                }
                
                for (i=0; i<i_v; i++) {
                    putchar('|');
                    for (j=0; j<f_h; j++) {
                        if (j == f_h-1) {
                            printf("%d|", toplam[i][j]);
                        } else
                        { printf("%d ", toplam[i][j]);
                        }
                    }
                    putchar('\n');
                }
            } else {
                for (as=0;as<100;++as) {
                    putchar('\n');
                }
                printf("\nWe are terribly sorry, but it seems like the matrices are not eligible for multiplication. \n\n");
                goto ETIKET;
            }
            break;
            
        case 5:
            
            if (mul_b == 1) {
                
                for (i=0; i<f_v; i++) {
                    for (j=0; j<i_h; j++) {
                        
                        top = 0;
                        for (k=0; k<f_h; k++) {
                            top += matrix2[i][k]*matrix1[k][j];
                        }
                        toplam[i][j] = top;
                        
                    }
                }
                
                for (i=0; i<f_v; i++) {
                    putchar('|');
                    for (j=0; j<i_h; j++) {
                        if (j == i_h-1) {
                            printf("%d|", toplam[i][j]);
                        } else
                        { printf("%d ", toplam[i][j]);
                        }
                    }
                    putchar('\n');
                }
            } else {
                for (as=0;as<100;++as) {
                    putchar('\n');
                }
                printf("\nWe are terribly sorry, but it seems like the matrices are not eligible for multiplication. \n\n");
                goto ETIKET;
            }
            break;
            
        case 6:
            goto PRON;
            break;
            
        default:
            for (as=0;as<100;++as) {
                putchar('\n');
            }
            printf("\nInput is not valid.\n\n");
            goto ETIKET;
            break;
    }
    
    printf("\n\nThe result is above!\n\n"
           "Thank you for using Matrixulator TM. Would you like to restart the program? "
           "(Type 1 for Yes and anything else for No.)\n");
    int mehmettugrulic;
    scanf("%d", &mehmettugrulic);
    
    if (mehmettugrulic == 1) {
    PRON:
        for (as=0;as<100;++as) {
            putchar('\n');
        }
        printf("\a");
        goto ULTIMATE;
    } else {
        return 0;
    }
    
}




