#include "s21_ed_viewer_test.h"

START_TEST(zoom_obj_test_1) {
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
  zoom_in_out(&data_2, cof);
  int result = OK;
  for (unsigned int m = 0; m < data.count_of_vertexes * 3; m += 3) {
    if (data.vertexes_arr[X] * cof != data_2.vertexes_arr[X] ||
        data.vertexes_arr[Y] * cof != data_2.vertexes_arr[Y] ||
        data.vertexes_arr[Z] * cof != data_2.vertexes_arr[Z]) {
      result = ERROR;
    }
  }
  ck_assert_int_eq(result, OK);
  free_3d(&data);
  free_3d(&data_2);
}
END_TEST

START_TEST(zoom_obj_test_2) {
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
  zoom_in_out(&data_2, cof);
  int result = OK;
  for (unsigned int m = 0; m < data.count_of_vertexes * 3; m += 3) {
    if (data.vertexes_arr[X] * cof != data_2.vertexes_arr[X] ||
        data.vertexes_arr[Y] * cof != data_2.vertexes_arr[Y] ||
        data.vertexes_arr[Z] * cof != data_2.vertexes_arr[Z]) {
      result = ERROR;
    }
  }
  ck_assert_int_eq(result, OK);
  free_3d(&data);
  free_3d(&data_2);
}

END_TEST

START_TEST(zoom_obj_test_3) {
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
  float cof = 1.2;
  zoom_in_out(&data_2, cof);
  int result = OK;
  for (unsigned int m = 0; m < data.count_of_vertexes * 3; m += 3) {
    if (data.vertexes_arr[X] * cof != data_2.vertexes_arr[X] ||
        data.vertexes_arr[Y] * cof != data_2.vertexes_arr[Y] ||
        data.vertexes_arr[Z] * cof != data_2.vertexes_arr[Z]) {
      result = ERROR;
    }
  }
  ck_assert_int_eq(result, OK);
  free_3d(&data);
  free_3d(&data_2);
}

END_TEST

START_TEST(zoom_obj_test_4) {
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
  float cof = 55.55;
  zoom_in_out(&data_2, cof);
  int result = OK;
  for (unsigned int m = 0; m < data.count_of_vertexes * 3; m += 3) {
    if (data.vertexes_arr[X] * cof != data_2.vertexes_arr[X] ||
        data.vertexes_arr[Y] * cof != data_2.vertexes_arr[Y] ||
        data.vertexes_arr[Z] * cof != data_2.vertexes_arr[Z]) {
      result = ERROR;
    }
  }
  ck_assert_int_eq(result, OK);
  free_3d(&data);
  free_3d(&data_2);
}

END_TEST

START_TEST(zoom_obj_test_5) {
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
  float cof = 99.001;
  zoom_in_out(&data_2, cof);
  int result = OK;
  for (unsigned int m = 0; m < data.count_of_vertexes * 3; m += 3) {
    if (data.vertexes_arr[X] * cof != data_2.vertexes_arr[X] ||
        data.vertexes_arr[Y] * cof != data_2.vertexes_arr[Y] ||
        data.vertexes_arr[Z] * cof != data_2.vertexes_arr[Z]) {
      result = ERROR;
    }
  }
  ck_assert_int_eq(result, OK);
  free_3d(&data);
  free_3d(&data_2);
}

END_TEST

START_TEST(zoom_obj_test_6) {
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
  float cof = 0.0001;
  zoom_in_out(&data_2, cof);
  int result = OK;
  for (unsigned int m = 0; m < data.count_of_vertexes * 3; m += 3) {
    if (data.vertexes_arr[X] * cof != data_2.vertexes_arr[X] ||
        data.vertexes_arr[Y] * cof != data_2.vertexes_arr[Y] ||
        data.vertexes_arr[Z] * cof != data_2.vertexes_arr[Z]) {
      result = ERROR;
    }
  }
  ck_assert_int_eq(result, OK);
  free_3d(&data);
  free_3d(&data_2);
}

END_TEST

START_TEST(zoom_obj_test_7) {
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
  float cof = 7894;
  zoom_in_out(&data_2, cof);
  int result = OK;
  for (unsigned int m = 0; m < data.count_of_vertexes * 3; m += 3) {
    if (data.vertexes_arr[X] * cof != data_2.vertexes_arr[X] ||
        data.vertexes_arr[Y] * cof != data_2.vertexes_arr[Y] ||
        data.vertexes_arr[Z] * cof != data_2.vertexes_arr[Z]) {
      result = ERROR;
    }
  }
  ck_assert_int_eq(result, OK);
  free_3d(&data);
  free_3d(&data_2);
}

END_TEST

START_TEST(zoom_obj_test_8) {
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
  float cof = 0.43;
  zoom_in_out(&data_2, cof);
  int result = OK;
  for (unsigned int m = 0; m < data.count_of_vertexes * 3; m += 3) {
    if (data.vertexes_arr[X] * cof != data_2.vertexes_arr[X] ||
        data.vertexes_arr[Y] * cof != data_2.vertexes_arr[Y] ||
        data.vertexes_arr[Z] * cof != data_2.vertexes_arr[Z]) {
      result = ERROR;
    }
  }
  ck_assert_int_eq(result, OK);
  free_3d(&data);
  free_3d(&data_2);
}

END_TEST

START_TEST(zoom_obj_test_9) {
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
  float cof = 13;
  zoom_in_out(&data_2, cof);
  int result = OK;
  for (unsigned int m = 0; m < data.count_of_vertexes * 3; m += 3) {
    if (data.vertexes_arr[X] * cof != data_2.vertexes_arr[X] ||
        data.vertexes_arr[Y] * cof != data_2.vertexes_arr[Y] ||
        data.vertexes_arr[Z] * cof != data_2.vertexes_arr[Z]) {
      result = ERROR;
    }
  }
  ck_assert_int_eq(result, OK);
  free_3d(&data);
  free_3d(&data_2);
}

END_TEST

START_TEST(zoom_obj_test_10) {
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
  float cof = 111.111;
  zoom_in_out(&data_2, cof);
  int result = OK;
  for (unsigned int m = 0; m < data.count_of_vertexes * 3; m += 3) {
    if (data.vertexes_arr[X] * cof != data_2.vertexes_arr[X] ||
        data.vertexes_arr[Y] * cof != data_2.vertexes_arr[Y] ||
        data.vertexes_arr[Z] * cof != data_2.vertexes_arr[Z]) {
      result = ERROR;
    }
  }
  ck_assert_int_eq(result, OK);
  free_3d(&data);
  free_3d(&data_2);
}

END_TEST

START_TEST(middle_obj_test) {
  objData_t data;
  objData_t data_2;
  data.count_of_facets = 1;
  data.count_of_vertexes = 1;
  data.oneLine_array = NULL;
  data_2.count_of_facets = 1;
  data_2.count_of_vertexes = 1;
  data_2.oneLine_array = NULL;
  float x, y, z;
  parcer("./objFiles/cube.obj", &data);
  parcer("./objFiles/cube.obj", &data_2);
  find_middle(&data, &x, &y, &z);
  minus_middle(&data, x, y, z);
  plus_middle(&data, x, y, z);
  int result = OK;
  for (unsigned int m = 0; m < data.count_of_vertexes * 3; m += 3) {
    if (data.vertexes_arr[X] != data_2.vertexes_arr[X] ||
        data.vertexes_arr[Y] != data_2.vertexes_arr[Y] ||
        data.vertexes_arr[Z] != data_2.vertexes_arr[Z]) {
      result = ERROR;
    }
  }
  ck_assert_int_eq(result, OK);
  free_3d(&data);
  free_3d(&data_2);
}

END_TEST

START_TEST(zoom_obj_test_error) {
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
  zoom_in_out(&data_2, cof);
  int result = OK;
  for (unsigned int m = 0; m < data.count_of_vertexes * 3; m += 3) {
    if (data.vertexes_arr[X] * cof == data_2.vertexes_arr[X] ||
        data.vertexes_arr[Y] * cof == data_2.vertexes_arr[Y] ||
        data.vertexes_arr[Z] * cof == data_2.vertexes_arr[Z]) {
      result = ERROR;
    }
  }
  ck_assert_int_eq(result, OK);
  free_3d(&data);
  free_3d(&data_2);
}
END_TEST

START_TEST(zoom_obj_test_NULL) {
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
  zoom_in_out(&data_2, cof);
  int result = OK;
  for (unsigned int m = 0; m < data.count_of_vertexes * 3; m += 3) {
    if (data.vertexes_arr[X] * cof == data_2.vertexes_arr[X] ||
        data.vertexes_arr[Y] * cof == data_2.vertexes_arr[Y] ||
        data.vertexes_arr[Z] * cof == data_2.vertexes_arr[Z]) {
      result = ERROR;
    }
  }
  ck_assert_int_eq(result, OK);
  free_3d(&data);
  free_3d(&data_2);
}
END_TEST

Suite *suite_zoom_obj(void) {
  Suite *s = suite_create("suite_zoom_file");
  TCase *tc = tcase_create("case_zoom_file");

  tcase_add_test(tc, zoom_obj_test_1);
  tcase_add_test(tc, zoom_obj_test_2);
  tcase_add_test(tc, zoom_obj_test_3);
  tcase_add_test(tc, zoom_obj_test_4);
  tcase_add_test(tc, zoom_obj_test_5);
  tcase_add_test(tc, zoom_obj_test_6);
  tcase_add_test(tc, zoom_obj_test_7);
  tcase_add_test(tc, zoom_obj_test_8);
  tcase_add_test(tc, zoom_obj_test_9);
  tcase_add_test(tc, zoom_obj_test_10);
  tcase_add_test(tc, middle_obj_test);
  tcase_add_test(tc, zoom_obj_test_error);
  tcase_add_test(tc, zoom_obj_test_NULL);
  suite_add_tcase(s, tc);
  return s;
}
