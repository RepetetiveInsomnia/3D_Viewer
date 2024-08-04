#include "s21_ed_viewer_test.h"

START_TEST(move_x_test_1) {
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
  move_x(&data, cof);
  int result = OK;

  for (unsigned int m = 0; m < data.count_of_vertexes * 3; m += 3) {
    if (data_2.vertexes_arr[X] + cof != data.vertexes_arr[X]) {
      result = ERROR;
    }
  }
  ck_assert_int_eq(result, OK);
  free_3d(&data);
  free_3d(&data_2);
}
END_TEST

START_TEST(move_x_test_2) {
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
  move_x(&data, cof);
  int result = OK;
  for (unsigned int m = 0; m < data.count_of_vertexes * 3; m += 3) {
    if (data_2.vertexes_arr[X] + cof != data.vertexes_arr[X]) {
      result = ERROR;
    }
  }
  ck_assert_int_eq(result, OK);
  free_3d(&data);
  free_3d(&data_2);
}

END_TEST

START_TEST(move_x_test_3) {
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
  float cof = -3;
  move_x(&data, cof);
  int result = OK;
  for (unsigned int m = 0; m < data.count_of_vertexes * 3; m += 3) {
    if (data_2.vertexes_arr[X] + cof != data.vertexes_arr[X]) {
      result = ERROR;
    }
  }
  ck_assert_int_eq(result, OK);
  free_3d(&data);
  free_3d(&data_2);
}

END_TEST

START_TEST(move_x_test_4) {
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
  float cof = 200.2;
  move_x(&data, cof);
  int result = OK;
  for (unsigned int m = 0; m < data.count_of_vertexes * 3; m += 3) {
    if (data_2.vertexes_arr[X] + cof != data.vertexes_arr[X]) {
      result = ERROR;
    }
  }
  ck_assert_int_eq(result, OK);
  free_3d(&data);
  free_3d(&data_2);
}

END_TEST

START_TEST(move_x_test_5) {
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
  float cof = 785;
  move_x(&data, cof);
  int result = OK;
  for (unsigned int m = 0; m < data.count_of_vertexes * 3; m += 3) {
    if (data_2.vertexes_arr[X] + cof != data.vertexes_arr[X]) {
      result = ERROR;
    }
  }
  ck_assert_int_eq(result, OK);
  free_3d(&data);
  free_3d(&data_2);
}

END_TEST

START_TEST(move_x_test_6) {
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
  float cof = 0.03;
  move_x(&data, cof);
  int result = OK;
  for (unsigned int m = 0; m < data.count_of_vertexes * 3; m += 3) {
    if (data_2.vertexes_arr[X] + cof != data.vertexes_arr[X]) {
      result = ERROR;
    }
  }
  ck_assert_int_eq(result, OK);
  free_3d(&data);
  free_3d(&data_2);
}

END_TEST

START_TEST(move_x_test_7) {
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
  float cof = 73;
  move_x(&data, cof);
  int result = OK;
  for (unsigned int m = 0; m < data.count_of_vertexes * 3; m += 3) {
    if (data_2.vertexes_arr[X] + cof != data.vertexes_arr[X]) {
      result = ERROR;
    }
  }
  ck_assert_int_eq(result, OK);
  free_3d(&data);
  free_3d(&data_2);
}

END_TEST

START_TEST(move_x_test_8) {
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
  float cof = -15.5;
  move_x(&data, cof);
  int result = OK;
  for (unsigned int m = 0; m < data.count_of_vertexes * 3; m += 3) {
    if (data_2.vertexes_arr[X] + cof != data.vertexes_arr[X]) {
      result = ERROR;
    }
  }
  ck_assert_int_eq(result, OK);
  free_3d(&data);
  free_3d(&data_2);
}

END_TEST

START_TEST(move_x_test_9) {
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
  float cof = 1000000;
  move_x(&data, cof);
  int result = OK;
  for (unsigned int m = 0; m < data.count_of_vertexes * 3; m += 3) {
    if (data_2.vertexes_arr[X] + cof != data.vertexes_arr[X]) {
      result = ERROR;
    }
  }
  ck_assert_int_eq(result, OK);
  free_3d(&data);
  free_3d(&data_2);
}

END_TEST

START_TEST(move_x_test_10) {
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
  float cof = 0.0003;
  move_x(&data, cof);
  int result = OK;
  for (unsigned int m = 0; m < data.count_of_vertexes * 3; m += 3) {
    if (data_2.vertexes_arr[X] + cof != data.vertexes_arr[X]) {
      result = ERROR;
    }
  }
  ck_assert_int_eq(result, OK);
  free_3d(&data);
  free_3d(&data_2);
}

END_TEST

START_TEST(move_x_test_error) {
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
  move_x(&data, cof);
  int result = OK;
  for (unsigned int m = 0; m < data.count_of_vertexes * 3; m += 3) {
    if (data_2.vertexes_arr[X] + cof != data.vertexes_arr[X]) {
      result = ERROR;
    }
  }
  ck_assert_int_eq(result, OK);
  free_3d(&data);
  free_3d(&data_2);
}
END_TEST

START_TEST(move_x_test_NULL) {
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
  move_x(&data, cof);
  int result = OK;
  for (unsigned int m = 0; m < data.count_of_vertexes * 3; m += 3) {
    if (data_2.vertexes_arr[X] + cof != data.vertexes_arr[X]) {
      result = ERROR;
    }
  }
  ck_assert_int_eq(result, OK);
  free_3d(&data);
  free_3d(&data_2);
}
END_TEST

Suite *suite_move_x(void) {
  Suite *s = suite_create("suite_move_x");
  TCase *tc = tcase_create("case_move_x");

  tcase_add_test(tc, move_x_test_1);
  tcase_add_test(tc, move_x_test_2);
  tcase_add_test(tc, move_x_test_3);
  tcase_add_test(tc, move_x_test_4);
  tcase_add_test(tc, move_x_test_5);
  tcase_add_test(tc, move_x_test_6);
  tcase_add_test(tc, move_x_test_7);
  tcase_add_test(tc, move_x_test_8);
  tcase_add_test(tc, move_x_test_9);
  tcase_add_test(tc, move_x_test_10);
  tcase_add_test(tc, move_x_test_error);
  tcase_add_test(tc, move_x_test_NULL);
  suite_add_tcase(s, tc);
  return s;
}
