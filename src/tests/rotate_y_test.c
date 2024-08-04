#include "s21_ed_viewer_test.h"

START_TEST(rotation_by_oy_test_1) {
  objData_t data;
  objData_t data_2;
  data.count_of_facets = 1;
  data.count_of_vertexes = 1;
  data.oneLine_array = NULL;
  data_2.count_of_facets = 1;
  data_2.count_of_vertexes = 1;
  data_2.oneLine_array = NULL;
  parcer("./objFiles/test.obj", &data);
  parcer("./objFiles/test.obj", &data_2);
  float cof = 0.1;
  float temp_x;
  float temp_z;
  rotation_by_oy(&data, cof);
  int result = OK;
  for (unsigned int m = 0; m < data.count_of_vertexes; m += 3) {
    temp_x = data_2.vertexes_arr[X];
    temp_z = data_2.vertexes_arr[Z];
    if (data.vertexes_arr[X] != sin(cof) * temp_z + cos(cof) * temp_x ||
        data.vertexes_arr[Z] != cos(cof) * temp_z - sin(cof) * temp_x) {
      result = ERROR;
    }
  }
  ck_assert_int_eq(result, OK);
  free_3d(&data);
  free_3d(&data_2);
}
END_TEST

START_TEST(rotation_by_oy_test_2) {
  objData_t data;
  objData_t data_2;
  data.count_of_facets = 1;
  data.count_of_vertexes = 1;
  data.oneLine_array = NULL;
  data_2.count_of_facets = 1;
  data_2.count_of_vertexes = 1;
  data_2.oneLine_array = NULL;
  parcer("./objFiles/cube.obj", &data);
  parcer("./objFiles/cube.obj", &data_2);
  float cof = 10;
  float temp_x;
  float temp_z;
  rotation_by_oy(&data, cof);
  int result = OK;
  for (unsigned int m = 0; m < data.count_of_vertexes; m += 3) {
    temp_x = data_2.vertexes_arr[X];
    temp_z = data_2.vertexes_arr[Z];
    if (data.vertexes_arr[X] != sin(cof) * temp_z + cos(cof) * temp_x ||
        data.vertexes_arr[Z] != cos(cof) * temp_z - sin(cof) * temp_x) {
      result = ERROR;
    }
  }
  ck_assert_int_eq(result, OK);
  free_3d(&data);
  free_3d(&data_2);
}

END_TEST

START_TEST(rotation_by_oy_test_3) {
  objData_t data;
  objData_t data_2;
  data.count_of_facets = 1;
  data.count_of_vertexes = 1;
  data.oneLine_array = NULL;
  data_2.count_of_facets = 1;
  data_2.count_of_vertexes = 1;
  data_2.oneLine_array = NULL;
  parcer("./objFiles/cube.obj", &data);
  parcer("./objFiles/cube.obj", &data_2);
  float cof = 15;
  float temp_x;
  float temp_z;
  rotation_by_oy(&data, cof);
  int result = OK;
  for (unsigned int m = 0; m < data.count_of_vertexes; m += 3) {
    temp_x = data_2.vertexes_arr[X];
    temp_z = data_2.vertexes_arr[Z];
    if (data.vertexes_arr[X] != sin(cof) * temp_z + cos(cof) * temp_x ||
        data.vertexes_arr[Z] != cos(cof) * temp_z - sin(cof) * temp_x) {
      result = ERROR;
    }
  }
  ck_assert_int_eq(result, OK);
  free_3d(&data);
  free_3d(&data_2);
}

END_TEST

START_TEST(rotation_by_oy_test_4) {
  objData_t data;
  objData_t data_2;
  data.count_of_facets = 1;
  data.count_of_vertexes = 1;
  data.oneLine_array = NULL;
  data_2.count_of_facets = 1;
  data_2.count_of_vertexes = 1;
  data_2.oneLine_array = NULL;
  parcer("./objFiles/cube.obj", &data);
  parcer("./objFiles/cube.obj", &data_2);
  float cof = -15;
  float temp_x;
  float temp_z;
  rotation_by_oy(&data, cof);
  int result = OK;
  for (unsigned int m = 0; m < data.count_of_vertexes; m += 3) {
    temp_x = data_2.vertexes_arr[X];
    temp_z = data_2.vertexes_arr[Z];
    if (data.vertexes_arr[X] != sin(cof) * temp_z + cos(cof) * temp_x ||
        data.vertexes_arr[Z] != cos(cof) * temp_z - sin(cof) * temp_x) {
      result = ERROR;
    }
  }
  ck_assert_int_eq(result, OK);
  free_3d(&data);
  free_3d(&data_2);
}

END_TEST

START_TEST(rotation_by_oy_test_5) {
  objData_t data;
  objData_t data_2;
  data.count_of_facets = 1;
  data.count_of_vertexes = 1;
  data.oneLine_array = NULL;
  data_2.count_of_facets = 1;
  data_2.count_of_vertexes = 1;
  data_2.oneLine_array = NULL;
  parcer("./objFiles/cube.obj", &data);
  parcer("./objFiles/cube.obj", &data_2);
  float cof = 90;
  float temp_x;
  float temp_z;
  rotation_by_oy(&data, cof);
  int result = OK;
  for (unsigned int m = 0; m < data.count_of_vertexes; m += 3) {
    temp_x = data_2.vertexes_arr[X];
    temp_z = data_2.vertexes_arr[Z];
    if (data.vertexes_arr[X] != sin(cof) * temp_z + cos(cof) * temp_x ||
        data.vertexes_arr[Z] != cos(cof) * temp_z - sin(cof) * temp_x) {
      result = ERROR;
    }
  }
  ck_assert_int_eq(result, OK);
  free_3d(&data);
  free_3d(&data_2);
}

END_TEST

START_TEST(rotation_by_oy_test_6) {
  objData_t data;
  objData_t data_2;
  data.count_of_facets = 1;
  data.count_of_vertexes = 1;
  data.oneLine_array = NULL;
  data_2.count_of_facets = 1;
  data_2.count_of_vertexes = 1;
  data_2.oneLine_array = NULL;
  parcer("./objFiles/cube.obj", &data);
  parcer("./objFiles/cube.obj", &data_2);
  float cof = 0.33;
  float temp_x;
  float temp_z;
  rotation_by_oy(&data, cof);
  int result = OK;
  for (unsigned int m = 0; m < data.count_of_vertexes; m += 3) {
    temp_x = data_2.vertexes_arr[X];
    temp_z = data_2.vertexes_arr[Z];
    if (data.vertexes_arr[X] != sin(cof) * temp_z + cos(cof) * temp_x ||
        data.vertexes_arr[Z] != cos(cof) * temp_z - sin(cof) * temp_x) {
      result = ERROR;
    }
  }
  ck_assert_int_eq(result, OK);
  free_3d(&data);
  free_3d(&data_2);
}

END_TEST

START_TEST(rotation_by_oy_test_7) {
  objData_t data;
  objData_t data_2;
  data.count_of_facets = 1;
  data.count_of_vertexes = 1;
  data.oneLine_array = NULL;
  data_2.count_of_facets = 1;
  data_2.count_of_vertexes = 1;
  data_2.oneLine_array = NULL;
  parcer("./objFiles/cube.obj", &data);
  parcer("./objFiles/cube.obj", &data_2);
  float cof = 111.11;
  float temp_x;
  float temp_z;
  rotation_by_oy(&data, cof);
  int result = OK;
  for (unsigned int m = 0; m < data.count_of_vertexes; m += 3) {
    temp_x = data_2.vertexes_arr[X];
    temp_z = data_2.vertexes_arr[Z];
    if (data.vertexes_arr[X] != sin(cof) * temp_z + cos(cof) * temp_x ||
        data.vertexes_arr[Z] != cos(cof) * temp_z - sin(cof) * temp_x) {
      result = ERROR;
    }
  }
  ck_assert_int_eq(result, OK);
  free_3d(&data);
  free_3d(&data_2);
}

END_TEST

START_TEST(rotation_by_oy_test_8) {
  objData_t data;
  objData_t data_2;
  data.count_of_facets = 1;
  data.count_of_vertexes = 1;
  data.oneLine_array = NULL;
  data_2.count_of_facets = 1;
  data_2.count_of_vertexes = 1;
  data_2.oneLine_array = NULL;
  parcer("./objFiles/cube.obj", &data);
  parcer("./objFiles/cube.obj", &data_2);
  float cof = 79;
  float temp_x;
  float temp_z;
  rotation_by_oy(&data, cof);
  int result = OK;
  for (unsigned int m = 0; m < data.count_of_vertexes; m += 3) {
    temp_x = data_2.vertexes_arr[X];
    temp_z = data_2.vertexes_arr[Z];
    if (data.vertexes_arr[X] != sin(cof) * temp_z + cos(cof) * temp_x ||
        data.vertexes_arr[Z] != cos(cof) * temp_z - sin(cof) * temp_x) {
      result = ERROR;
    }
  }
  ck_assert_int_eq(result, OK);
  free_3d(&data);
  free_3d(&data_2);
}

END_TEST

START_TEST(rotation_by_oy_test_9) {
  objData_t data;
  objData_t data_2;
  data.count_of_facets = 1;
  data.count_of_vertexes = 1;
  data.oneLine_array = NULL;
  data_2.count_of_facets = 1;
  data_2.count_of_vertexes = 1;
  data_2.oneLine_array = NULL;
  parcer("./objFiles/cube.obj", &data);
  parcer("./objFiles/cube.obj", &data_2);
  float cof = 99;
  float temp_x;
  float temp_z;
  rotation_by_oy(&data, cof);
  int result = OK;
  for (unsigned int m = 0; m < data.count_of_vertexes; m += 3) {
    temp_x = data_2.vertexes_arr[X];
    temp_z = data_2.vertexes_arr[Z];
    if (data.vertexes_arr[X] != sin(cof) * temp_z + cos(cof) * temp_x ||
        data.vertexes_arr[Z] != cos(cof) * temp_z - sin(cof) * temp_x) {
      result = ERROR;
    }
  }
  ck_assert_int_eq(result, OK);
  free_3d(&data);
  free_3d(&data_2);
}

END_TEST

START_TEST(rotation_by_oy_test_10) {
  objData_t data;
  objData_t data_2;
  data.count_of_facets = 1;
  data.count_of_vertexes = 1;
  data.oneLine_array = NULL;
  data_2.count_of_facets = 1;
  data_2.count_of_vertexes = 1;
  data_2.oneLine_array = NULL;
  parcer("./objFiles/cube.obj", &data);
  parcer("./objFiles/cube.obj", &data_2);
  float cof = 0.1;
  float temp_x;
  float temp_z;
  rotation_by_oy(&data, cof);
  int result = OK;
  for (unsigned int m = 0; m < data.count_of_vertexes; m += 3) {
    temp_x = data_2.vertexes_arr[X];
    temp_z = data_2.vertexes_arr[Z];
    if (data.vertexes_arr[X] != sin(cof) * temp_z + cos(cof) * temp_x ||
        data.vertexes_arr[Z] != cos(cof) * temp_z - sin(cof) * temp_x) {
      result = ERROR;
    }
  }
  ck_assert_int_eq(result, OK);
  free_3d(&data);
  free_3d(&data_2);
}

END_TEST

START_TEST(rotation_by_oy_test_error) {
  objData_t data;
  objData_t data_2;
  data.count_of_facets = 1;
  data.count_of_vertexes = 1;
  data.oneLine_array = NULL;
  data_2.count_of_facets = 1;
  data_2.count_of_vertexes = 1;
  data_2.oneLine_array = NULL;
  parcer("./objFiles/test.obj", &data);
  parcer("./objFiles/test.obj", &data_2);
  float cof = -3;
  float temp_x;
  float temp_z;
  rotation_by_oy(&data, cof);
  int result = OK;
  for (unsigned int m = 0; m < data.count_of_vertexes; m += 3) {
    temp_x = data_2.vertexes_arr[X];
    temp_z = data_2.vertexes_arr[Z];
    if (data.vertexes_arr[X] != sin(cof) * temp_z + cos(cof) * temp_x ||
        data.vertexes_arr[Z] != cos(cof) * temp_z - sin(cof) * temp_x) {
      result = ERROR;
    }
  }
  ck_assert_int_eq(result, OK);
  free_3d(&data);
  free_3d(&data_2);
}
END_TEST

START_TEST(rotation_by_oy_test_NULL) {
  objData_t data;
  objData_t data_2;
  data.count_of_facets = 1;
  data.count_of_vertexes = 1;
  data.oneLine_array = NULL;
  data_2.count_of_facets = 1;
  data_2.count_of_vertexes = 1;
  data_2.oneLine_array = NULL;
  parcer("./objFiles/cube.obj", &data);
  parcer("./objFiles/cube.obj", &data_2);
  float cof = 0;
  float temp_x;
  float temp_z;
  rotation_by_oy(&data, cof);
  int result = OK;
  for (unsigned int m = 0; m < data.count_of_vertexes; m += 3) {
    temp_x = data_2.vertexes_arr[X];
    temp_z = data_2.vertexes_arr[Z];
    if (data.vertexes_arr[X] != sin(cof) * temp_z + cos(cof) * temp_x ||
        data.vertexes_arr[Z] != cos(cof) * temp_z - sin(cof) * temp_x) {
      result = ERROR;
    }
  }
  ck_assert_int_eq(result, OK);
  free_3d(&data);
  free_3d(&data_2);
}
END_TEST

Suite *suite_rotation_by_oy(void) {
  Suite *s = suite_create("suite_rotation_by_oy");
  TCase *tc = tcase_create("case_rotation_by_oy");

  tcase_add_test(tc, rotation_by_oy_test_1);
  tcase_add_test(tc, rotation_by_oy_test_2);
  tcase_add_test(tc, rotation_by_oy_test_3);
  tcase_add_test(tc, rotation_by_oy_test_4);
  tcase_add_test(tc, rotation_by_oy_test_5);
  tcase_add_test(tc, rotation_by_oy_test_6);
  tcase_add_test(tc, rotation_by_oy_test_7);
  tcase_add_test(tc, rotation_by_oy_test_8);
  tcase_add_test(tc, rotation_by_oy_test_9);
  tcase_add_test(tc, rotation_by_oy_test_10);
  tcase_add_test(tc, rotation_by_oy_test_error);
  tcase_add_test(tc, rotation_by_oy_test_NULL);
  suite_add_tcase(s, tc);
  return s;
}
