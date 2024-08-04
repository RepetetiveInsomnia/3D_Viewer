#ifndef SRC_3DVIEWER_VIEWERLIB_VIEWERLIB_H_
#define SRC_3DVIEWER_VIEWERLIB_VIEWERLIB_H_

#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifdef __cplusplus
extern "C" {
#endif

#define BUFF_SIZE 1000
#define SUCCESS 1
#define FAILURE 0
#define X m
#define Y m + 1
#define Z m + 2
#define MAX_V_NUM 1000000
typedef enum { OK = 0, ERROR } EerrorCodes;

typedef struct facets {
  int* vertexes;
  unsigned int numbers_of_vertexes_in_facets;
} polygon_t;

typedef struct data {
  unsigned int count_of_vertexes;
  unsigned int count_of_facets;
  double* vertexes_arr;
  polygon_t* polygons;
  unsigned int oneLine_size;
  int* oneLine_array;
} objData_t;

int can_i_buff(char ch, char tmp);
int can_i_write(char ch, char tmp);
int can_i_continue(char ch);
void reader(objData_t* data);

int s21_alloc_vertex_arr(int length, double* arr);

int parcer(char* fileName, objData_t* data);

int first_read(char* fileName, objData_t* data);
int second_read(char* fileName, objData_t* data);
void to_oneLine(objData_t* data);
unsigned int count_number_of_vertexes(char* reference);
void move_left(unsigned int position, int* array, unsigned int size);

void fill_vertexes(char* reference, int* array);
void negate_vertexes(int* array, unsigned int size,
                     unsigned int number_of_points);
void normalize_vertexes(int* array, unsigned int size);

void move_x(objData_t* A, float a);
void move_y(objData_t* A, float a);
void move_z(objData_t* A, float a);
void find_middle(objData_t* A, float* x_mid, float* y_mid, float* z_mid);
void minus_middle(objData_t* A, float x_mid, float y_mid, float z_mid);
void plus_middle(objData_t* A, float x_mid, float y_mid, float z_mid);
void zoom_in_out(objData_t* A, float a);
void rotation_by_ox(objData_t* A, float angle);
void rotation_by_oy(objData_t* A, float angle);
void rotation_by_oz(objData_t* A, float angle);
void free_3d(objData_t* data);

#ifdef __cplusplus
}
#endif
#endif  // SRC_3DVIEWER_VIEWERLIB_VIEWERLIB_H_
