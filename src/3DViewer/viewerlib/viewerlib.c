#include "viewerlib.h"

void reader(objData_t* data) {
  // printf("V %d\n", data->count_of_vertexes);
  // printf("F %d\n", data->count_of_facets);

  for (unsigned int m = 0; m < data->count_of_vertexes * 3; m += 3) {
    // printf("m is %d is: X %f  Y %f Z %f\n", m, data->vertexes_arr[X],
    //           data->vertexes_arr[Y], data->vertexes_arr[Z]);
  }
  for (unsigned int j = 0; j < data->count_of_facets; j++) {
    // printf("Number of is %d\n",
    //           data->polygons[j].numbers_of_vertexes_in_facets);
    for (unsigned int i = 0;
         i < data->polygons[j].numbers_of_vertexes_in_facets * 2; i++) {
      // printf("array is %d\n", data->polygons[j].vertexes[i]);
    }
  }
  for (unsigned int i = 0; i < data->oneLine_size; i++) {
    // printf("%d ", data->oneLine_array[i]);
  }
  // printf("\n");
}
int parcer(char* fileName, objData_t* data) {
  EerrorCodes result = OK;
  if (!fileName) {
    result = ERROR;
  } else {
    data->count_of_facets = 0;
    data->count_of_vertexes = 0;
    data->vertexes_arr = NULL;
    result = first_read(fileName, data);
    if (result != ERROR) {
      if (data->count_of_vertexes > MAX_V_NUM) {
        printf("WARNING: FILE IS TOO BIG!\n");
        //      result = ERROR;
      }
      data->vertexes_arr =
          (double*)calloc(data->count_of_vertexes * 3, sizeof(double));
      data->polygons =
          (polygon_t*)calloc(data->count_of_facets, sizeof(polygon_t));
      result = second_read(fileName, data);
      to_oneLine(data);
      reader(data);
    }
  }

  return result;
}

int first_read(char* fileName, objData_t* data) {
  EerrorCodes result = OK;
  char buffer[BUFF_SIZE];

  FILE* file = fopen(fileName, "r");
  if (file != NULL) {
    while (fgets(buffer, BUFF_SIZE, file) != NULL) {
      if (!strncmp(buffer, "v ", 2) /*|| !strncmp(buffer, "vn ", 2)*/) {
        data->count_of_vertexes++;
      } else if (!strncmp(buffer, "f ", 2)) {
        data->count_of_facets++;
      }
    }

    rewind(file);
    fclose(file);
  } else {
    result = ERROR;
  }
  return result;
}

int second_read(char* fileName, objData_t* data) {
  EerrorCodes result = OK;
  char buffer[BUFF_SIZE];
  unsigned int m = 0;
  unsigned int F = 0;
  unsigned int count_negate_ind = 0;
  FILE* file = fopen(fileName, "r");
  if (file != NULL) {
    while (fgets(buffer, BUFF_SIZE, file) != NULL) {
      if (!strncmp(buffer, "v ", 2) /*|| !strncmp(buffer, "vn ", 2)*/) {
        sscanf(buffer, "v %lf %lf %lf", &data->vertexes_arr[X],
               &data->vertexes_arr[Y], &data->vertexes_arr[Z]);

        m += 3;
        count_negate_ind++;

      } else if (!strncmp(buffer, "f ", 2)) {
        data->polygons[F].numbers_of_vertexes_in_facets =
            count_number_of_vertexes(buffer);
        data->polygons[F].vertexes = (int*)calloc(
            data->polygons[F].numbers_of_vertexes_in_facets * 2, sizeof(int));
        fill_vertexes(buffer, data->polygons[F].vertexes);
        negate_vertexes(data->polygons[F].vertexes,
                        data->polygons[F].numbers_of_vertexes_in_facets,
                        count_negate_ind);
        normalize_vertexes(data->polygons[F].vertexes,
                           data->polygons[F].numbers_of_vertexes_in_facets * 2);
        F++;
      }
    }
    rewind(file);
    fclose(file);
  } else {
    result = ERROR;
  }
  return result;
}

unsigned int count_number_of_vertexes(char* reference) {
  unsigned int result = 0;
  for (int i = 0; reference[i] != '\0'; i++) {
    if (reference[i] == ' ' &&
        (isdigit(reference[i + 1]) || reference[i + 1] == '-')) {
      result++;
    }
  }
  return result;
}

int can_i_buff(char ch, char tmp) {
  int result = FAILURE;
  if ((isdigit(tmp)) &&
      (isspace(ch) || isdigit(ch) || ch == '/' || ch == '\0')) {
    result = SUCCESS;
  }
  if (tmp == '-' && isdigit(ch)) {
    result = SUCCESS;
  }
  return result;
}

int can_i_write(char ch, char tmp) {
  int result = FAILURE;
  if ((isdigit(tmp) || tmp == '/' || tmp == '-') &&
      (ch == '/' || ch == ' ' || ch == '\n' || ch == '\0' || ch == EOF)) {
    result = SUCCESS;
  }
  return result;
}

int can_i_continue(char ch) {
  int result = FAILURE;
  if (ch != '\n' || ch != '\0' || ch != EOF) {
    result = SUCCESS;
  }
  return result;
}

void fill_vertexes(char* reference, int* array) {
  char* buffer = NULL;
  buffer = (char*)calloc(12, sizeof(char));
  int counter = 0;
  char ch = *reference;

  char tmp = *reference;
  int number_flag = 0;
  while (can_i_continue(ch) || reference != NULL) {
    if (ch == '\0') {
      break;
    }
    reference++;
    tmp = ch;
    ch = *reference;
    if (number_flag == 0) {
      if (can_i_buff(ch, tmp)) {
        buffer[counter] = tmp;
        counter++;
      }
    }
    if (number_flag == 0) {
      if (can_i_write(ch, tmp)) {
        number_flag = 1;
        *array = atoi(buffer);
        free(buffer);
        buffer = (char*)calloc(12, sizeof(char));
        counter = 0;
        array++;
      }
    }
    if (isspace(tmp) || isspace(ch)) {
      number_flag = 0;
    }
  }
  free(buffer);
}

void move_left(unsigned int position, int* array, unsigned int size) {
  unsigned int tmp = array[position];
  unsigned int mem = array[position + 1];
  if (position + 1 < size - 2) {
    for (unsigned int i = position + 1; i < size - 2; i++) {
      array[i] = tmp;
      i++;
      tmp = array[i];
      array[i] = mem;
      mem = array[i + 1];
    }
  } else {
    array[position + 1] = array[position];
    array[size - 1] = array[0];
  }
}

void normalize_vertexes(int* array, unsigned int size) {
  unsigned int a = 1;

  while (a < size - 1) {
    move_left(a, array, size);
    a += 2;
  }
}

void negate_vertexes(int* array, unsigned int size,
                     unsigned int number_of_points) {
  for (unsigned int i = 0; i < size; i++) {
    if (array[i] > 0) {
      array[i] -= 1;
    } else if (array[i] < 0) {
      array[i] = (int)number_of_points + (array[i]);
    }
  }
}

void to_oneLine(objData_t* data) {
  data->oneLine_size = 0;
  for (int i = 0; (unsigned)i < data->count_of_facets; i++) {
    data->oneLine_size += data->polygons[i].numbers_of_vertexes_in_facets * 2;
  }
  // printf("size is %d\n", data->oneLine_size);
  data->oneLine_array = (int*)calloc(data->oneLine_size, sizeof(int));
  unsigned int count = 0;
  for (unsigned i = 0; i < data->count_of_facets; i++) {
    for (unsigned j = 0;
         j < data->polygons[i].numbers_of_vertexes_in_facets * 2; j++) {
      data->oneLine_array[count] = data->polygons[i].vertexes[j];
      count++;
    }
  }
}

void move_x(objData_t* A, float a) {
  for (unsigned int m = 0; m < A->count_of_vertexes * 3; m += 3) {
    A->vertexes_arr[X] += a;
  }
}

void move_y(objData_t* A, float a) {
  for (unsigned int m = 0; m < A->count_of_vertexes * 3; m += 3) {
    A->vertexes_arr[Y] += a;
  }
}

void move_z(objData_t* A, float a) {
  for (unsigned int m = 0; m < A->count_of_vertexes * 3; m += 3) {
    A->vertexes_arr[Z] += a;
  }
}

void zoom_in_out(objData_t* A, float a) {
  if (a > 0) {
    for (unsigned int m = 0; m < A->count_of_vertexes * 3; m += 3) {
      A->vertexes_arr[X] *= a;
      A->vertexes_arr[Y] *= a;
      A->vertexes_arr[Z] *= a;
    }
  }
}
void find_middle(objData_t* A, float* x_mid, float* y_mid, float* z_mid) {
  if (A->vertexes_arr != NULL) {
    double upper_x = A->vertexes_arr[0];
    double lower_x = A->vertexes_arr[0];
    double upper_y = A->vertexes_arr[1];
    double lower_y = A->vertexes_arr[1];
    double upper_z = A->vertexes_arr[2];
    double lower_z = A->vertexes_arr[2];
    for (unsigned int m = 0; m < A->count_of_vertexes * 3; m += 3) {
      if (A->vertexes_arr[X] <= lower_x) {
        lower_x = A->vertexes_arr[X];
      }
      if (A->vertexes_arr[X] >= upper_x) {
        upper_x = A->vertexes_arr[X];
      }
      if (A->vertexes_arr[Y] <= lower_y) {
        lower_y = A->vertexes_arr[Y];
      }
      if (A->vertexes_arr[Y] >= upper_y) {
        upper_y = A->vertexes_arr[Y];
      }
      if (A->vertexes_arr[Z] <= lower_z) {
        lower_z = A->vertexes_arr[Z];
      }
      if (A->vertexes_arr[Z] >= upper_z) {
        upper_z = A->vertexes_arr[Z];
      }
    }
    *x_mid = (upper_x + lower_x) / 2;
    *y_mid = (upper_y + lower_y) / 2;
    *z_mid = (upper_z + lower_z) / 2;
  }
}

void minus_middle(objData_t* A, float x_mid, float y_mid, float z_mid) {
  for (unsigned int m = 0; m < A->count_of_vertexes * 3; m += 3) {
    A->vertexes_arr[X] = A->vertexes_arr[X] - x_mid;
    A->vertexes_arr[Y] = A->vertexes_arr[Y] - y_mid;
    A->vertexes_arr[Z] = A->vertexes_arr[Z] - z_mid;
  }
}

void plus_middle(objData_t* A, float x_mid, float y_mid, float z_mid) {
  for (unsigned int m = 0; m < A->count_of_vertexes * 3; m += 3) {
    A->vertexes_arr[X] = A->vertexes_arr[X] + x_mid;
    A->vertexes_arr[Y] = A->vertexes_arr[Y] + y_mid;
    A->vertexes_arr[Z] = A->vertexes_arr[Z] + z_mid;
  }
}

void rotation_by_ox(objData_t* A, float angle) {
  if (angle != 0) {
    for (unsigned int m = 0; m < A->count_of_vertexes * 3; m += 3) {
      float temp_y = A->vertexes_arr[Y];
      float temp_z = A->vertexes_arr[Z];
      A->vertexes_arr[Y] = cos(angle) * temp_y - sin(angle) * temp_z;
      A->vertexes_arr[Z] = sin(angle) * temp_y + cos(angle) * temp_z;
    }
  }
}

void rotation_by_oy(objData_t* A, float angle) {
  if (angle != 0) {
    for (unsigned int m = 0; m < A->count_of_vertexes * 3; m += 3) {
      float temp_x = A->vertexes_arr[X];
      float temp_z = A->vertexes_arr[Z];
      A->vertexes_arr[X] = sin(angle) * temp_z + cos(angle) * temp_x;
      A->vertexes_arr[Z] = cos(angle) * temp_z - sin(angle) * temp_x;
    }
  }
}

void rotation_by_oz(objData_t* A, float angle) {
  if (angle != 0) {
    for (unsigned int m = 0; m < A->count_of_vertexes * 3; m += 3) {
      float temp_x = A->vertexes_arr[X];
      float temp_y = A->vertexes_arr[Y];
      A->vertexes_arr[X] = cos(angle) * temp_x - sin(angle) * temp_y;
      A->vertexes_arr[Y] = sin(angle) * temp_x + cos(angle) * temp_y;
    }
  }
}

void free_3d(objData_t* data) {
  if (data != NULL) {
    if (data->polygons != NULL) {
      for (unsigned int i = 0; i < data->count_of_facets; i++) {
        data->polygons[i].numbers_of_vertexes_in_facets = 0;
        if (data->polygons[i].vertexes != NULL) {
          free(data->polygons[i].vertexes);
        }
      }
      if (data->polygons != NULL) {
        free(data->polygons);
      }
      if (data->vertexes_arr != NULL) {
        free(data->vertexes_arr);
      }
      if (data->oneLine_array != NULL) {
        free(data->oneLine_array);
      }
      data->count_of_facets = 0;
      data->count_of_vertexes = 0;
      data->oneLine_size = 0;
    }
  }
}
