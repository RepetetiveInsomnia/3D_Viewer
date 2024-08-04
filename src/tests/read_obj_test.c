#include "s21_ed_viewer_test.h"

START_TEST(read_from_obj_1) {
  objData_t data;
  data.count_of_facets = 1;
  data.count_of_vertexes = 1;
  data.oneLine_array = NULL;
  ck_assert_int_eq(parcer("./objFiles/test.obj", &data), OK);
  free_3d(&data);
}
END_TEST

START_TEST(read_from_obj_2) {
  objData_t data;
  data.count_of_facets = 1;
  data.count_of_vertexes = 1;
  data.oneLine_array = NULL;
  ck_assert_int_eq(parcer("./objFiles/cube.obj", &data), OK);
  free_3d(&data);
}
END_TEST

START_TEST(read_from_obj_error) {
  objData_t data;
  data.count_of_facets = 1;
  data.count_of_vertexes = 1;
  data.oneLine_array = NULL;
  ck_assert_int_eq(parcer("./objFiles/error.obj", &data), ERROR);
}
END_TEST

START_TEST(read_from_obj_NULL) {
  objData_t data;
  data.count_of_facets = 1;
  data.count_of_vertexes = 1;
  data.oneLine_array = NULL;
  ck_assert_int_eq(parcer(NULL, &data), ERROR);
}
END_TEST

Suite *suite_read_obj(void) {
  Suite *s = suite_create("suite_read_file");
  TCase *tc = tcase_create("case_read_file");

  tcase_add_test(tc, read_from_obj_1);
  tcase_add_test(tc, read_from_obj_2);
  tcase_add_test(tc, read_from_obj_error);
  tcase_add_test(tc, read_from_obj_NULL);
  suite_add_tcase(s, tc);
  return s;
}
