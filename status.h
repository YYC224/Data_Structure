#ifndef STATUS_H
#define STATUS_H

//function return Status Code
# define TRUE 1
# define FALSE 0

# define OK 1
# define ERROR 0
# define INFEASBLE -1
# define OVERFLOW -2

//Status is the type of a function, the value is one of the Status Code
typedef int Status;

//choose int as the element type
typedef int Elemtype;

#endif